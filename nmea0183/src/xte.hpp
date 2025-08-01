/***************************************************************************
 *
 * Project:  OpenCPN
 * Purpose:  NMEA0183 Support Classes
 * Author:   Samuel R. Blackburn, David S. Register, Jon Gough
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


#if ! defined( XTE_CLASS_HEADER )
#define XTE_CLASS_HEADER

/*
** Author: Samuel R. Blackburn
** CI$: 76300,326
** Internet: sammy@sed.csc.com
**
** You can use it any way you like.
*/

class XTE : public RESPONSE
{


   public:

      XTE();
     ~XTE();

      /*
      ** Data
      */

      NMEA0183_BOOLEAN IsLoranBlinkOK;
      NMEA0183_BOOLEAN IsLoranCCycleLockOK;
      double           CrossTrackErrorDistance;
      LEFTRIGHT        DirectionToSteer;
      wxString          CrossTrackUnits;
      wxString          FAAModeIndicator;

      /*
      ** Methods
      */

      virtual void Empty( void );
      virtual bool Parse( const SENTENCE& sentence );
      virtual bool Write( SENTENCE& sentence );
      /*
      ** Operators
      */

      virtual const XTE& operator = ( const XTE& source );
};

#endif // XTE_CLASS_HEADER
