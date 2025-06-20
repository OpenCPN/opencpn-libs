/***************************************************************************
 *
 * Project:  OpenCPN
 * Purpose:  NMEA0183 Support Classes
 * Author:   Samuel R. Blackburn, David S. Register
 *
 ***************************************************************************
 *   Copyright (C) 2010 by Samuel R. Blackburn, David S Register           *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA 02110-1301,  USA.         *
 ***************************************************************************
 *                                                                         *
 *   S Blackburn's original source license:                                *
 *         "You can use it any way you like."                              *
 *   More recent (2010) license statement:                                 *
 *         "It is BSD license, do with it what you will"                   *
 */

#include "nmea0183.h"

/*
** Author: Samuel R. Blackburn
** CI$: 76300,326
** Internet: sammy@sed.csc.com
**
** You can use it any way you like.
*/

XTE::XTE() {
  Mnemonic = _T("XTE");
  Empty();
}

XTE::~XTE() {
  Mnemonic.Empty();
  Empty();
}

void XTE::Empty(void) {
  //   ASSERT_VALID( this );

  CrossTrackErrorDistance = 0.0;
  DirectionToSteer = LR_Unknown;
  FAAModeIndicator.Empty();
}

bool XTE::Parse(const SENTENCE& sentence) {
  //   ASSERT_VALID( this );

  wxString field_data;

  /*
  ** XTE - Cross Track Error, Measured
  **
  **        1 2 3   4 5 6
  **        | | |   | | |
  ** $--XTE,A,A,x.x,a,N*hh<CR><LF>
  **
  ** NMEA 2.3:
  **        1 2 3   4 5 6 7
  **        | | |   | | | |
  ** $--XTE,A,A,x.x,a,N,m*hh<CR><LF>
  **
  ** Field Number:
  **  1) Status - A = Valid, V = Loran-C Blink or SNR warning
  **  2) Status - V = Loran-C Cycle Lock warning flag, A = Valid
  **  3) Cross Track Error Magnitude
  **  4) Direction to steer, L or R
  **  5) Cross Track Units, N = Nautical Miles
  **  6) FAA mode indicator (NMEA 2.3 and later, optional)
  **  7) Checksum
  */

  /*
  ** First we check the checksum...
  */

  wxString field6 = sentence.Field(6);
  if (sentence.IsChecksumBad(6) == TRUE) {
    /*
     * This may be an NMEA Version 2.3 sentence, with "FAA Mode Indicator" field
     */
    if (field6.StartsWith("*"))  // Field is a valid erroneous checksum
    {
      SetErrorMessage("Invalid Checksum");
      return (FALSE);
    } else {
      if (sentence.IsChecksumBad(7) == TRUE) {
        SetErrorMessage("Invalid Checksum");
        return (FALSE);
      }
    }
  }

  /*
  ** Line has already been checked for checksum validity
  */

  IsLoranBlinkOK = sentence.Boolean(1);
  IsLoranCCycleLockOK = sentence.Boolean(2);
  CrossTrackErrorDistance = sentence.Double(3);
  DirectionToSteer = sentence.LeftOrRight(4);
  CrossTrackUnits = sentence.Field(5);

  // Check if FAA Mode Indicator is present (NMEA 2.3 and later)
  if (!field6.StartsWith(_T("*"))) {
    // Field 6 is not the checksum, so it should be FAA Mode Indicator
    FAAModeIndicator = field6;
  } else {
    // Field 6 is the checksum, no FAA Mode Indicator
    FAAModeIndicator.Empty();
  }

  return (TRUE);
}

bool XTE::Write(SENTENCE& sentence) {
  //   ASSERT_VALID( this );

  /*
  ** Let the parent do its thing
  */

  RESPONSE::Write(sentence);

  sentence += IsLoranBlinkOK;
  sentence += IsLoranCCycleLockOK;
  sentence += CrossTrackErrorDistance;

  if (DirectionToSteer == Left)
    sentence += _T("L");
  else
    sentence += _T("R");

  sentence += CrossTrackUnits;

  // Add FAA Mode Indicator if present
  if (!FAAModeIndicator.IsEmpty()) {
    sentence += FAAModeIndicator;
  }

  sentence.Finish();

  return (TRUE);
}

const XTE& XTE::operator=(const XTE& source) {
  //   ASSERT_VALID( this );

  IsLoranBlinkOK = source.IsLoranBlinkOK;
  IsLoranCCycleLockOK = source.IsLoranCCycleLockOK;
  CrossTrackErrorDistance = source.CrossTrackErrorDistance;
  DirectionToSteer = source.DirectionToSteer;
  CrossTrackUnits = source.CrossTrackUnits;
  FAAModeIndicator = source.FAAModeIndicator;

  return (*this);
}
