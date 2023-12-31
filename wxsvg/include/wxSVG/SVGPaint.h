//////////////////////////////////////////////////////////////////////////////
// Name:        SVGPaint.h
// Author:      Alex Thuering
// Copyright:   (c) 2005 Alex Thuering
// Licence:     wxWindows licence
// Notes:       generated by generate.py
//////////////////////////////////////////////////////////////////////////////

#ifndef WX_SVG_PAINT_H
#define WX_SVG_PAINT_H

#include "SVGColor.h"
#include "String_wxsvg.h"

enum wxSVG_PAINTTYPE {
  wxSVG_PAINTTYPE_UNKNOWN = 0,
  wxSVG_PAINTTYPE_RGBCOLOR = 1,
  wxSVG_PAINTTYPE_RGBCOLOR_ICCCOLOR = 2,
  wxSVG_PAINTTYPE_NONE = 101,
  wxSVG_PAINTTYPE_CURRENTCOLOR = 102,
  wxSVG_PAINTTYPE_URI_NONE = 103,
  wxSVG_PAINTTYPE_URI_CURRENTCOLOR = 104,
  wxSVG_PAINTTYPE_URI_RGBCOLOR = 105,
  wxSVG_PAINTTYPE_URI_RGBCOLOR_ICCCOLOR = 106,
  wxSVG_PAINTTYPE_URI = 107
};

class wxSVGPaint : public wxSVGColor {
protected:
  wxSVG_PAINTTYPE m_paintType;
  wxString m_uri;

public:
  inline wxSVG_PAINTTYPE GetPaintType() const { return m_paintType; }
  inline void SetPaintType(const wxSVG_PAINTTYPE& n) { m_paintType = n; }

public:
  wxSVGPaint() : m_paintType(wxSVG_PAINTTYPE_NONE) {
    m_cssValueType = wxCSS_SVG_PAINT;
  }
  wxSVGPaint(unsigned char r, unsigned char g, unsigned char b)
      : wxSVGColor(r, g, b), m_paintType(wxSVG_PAINTTYPE_RGBCOLOR) {
    m_cssValueType = wxCSS_SVG_PAINT;
  }
  wxSVGPaint(wxRGBColor color)
      : wxSVGColor(color), m_paintType(wxSVG_PAINTTYPE_RGBCOLOR) {
    m_cssValueType = wxCSS_SVG_PAINT;
    if (!color.Ok()) m_paintType = wxSVG_PAINTTYPE_NONE;
  }
  virtual ~wxSVGPaint() {}
  wxCSSValue* Clone() const { return new wxSVGPaint(*this); }

  wxString GetCSSText() const;
  inline const wxString& GetUri() const { return m_uri; }
  virtual void SetUri(const wxString& uri);
  virtual void SetRGBColor(const wxRGBColor& rgbColor);
  virtual void SetICCColor(const wxSVGICCColor& iccColor);

  inline bool Ok() const {
    return m_paintType != wxSVG_PAINTTYPE_UNKNOWN &&
           m_paintType != wxSVG_PAINTTYPE_NONE;
  }

  virtual void SetPaint(wxSVG_PAINTTYPE paintType, const wxString& uri,
                        const wxString& rgbColor, const wxString& iccColor);
};

#endif  // WX_SVG_PAINT_H
