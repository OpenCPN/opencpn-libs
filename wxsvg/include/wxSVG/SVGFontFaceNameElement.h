//////////////////////////////////////////////////////////////////////////////
// Name:        SVGFontFaceNameElement.h
// Author:      Alex Thuering
// Copyright:   (c) 2005 Alex Thuering
// Licence:     wxWindows licence
// Notes:       generated by generate.py
//////////////////////////////////////////////////////////////////////////////

#ifndef WX_SVG_FONT_FACE_NAME_ELEMENT_H
#define WX_SVG_FONT_FACE_NAME_ELEMENT_H

#include "SVGElement.h"
#include "String_wxsvg.h"
#include "Element.h"

class wxSVGFontFaceNameElement : public wxSVGElement {
public:
  wxSVGFontFaceNameElement(wxString tagName = wxT("font-face-name"))
      : wxSVGElement(tagName) {}
  virtual ~wxSVGFontFaceNameElement() {}
  wxSvgXmlNode* CloneNode(bool deep = true) {
    return new wxSVGFontFaceNameElement(*this);
  }
  bool HasAttribute(const wxString& name) const;
  wxString GetAttribute(const wxString& name) const;
  bool SetAttribute(const wxString& name, const wxString& value);
  wxSvgXmlAttrHash GetAttributes() const;
  virtual wxSVGDTD GetDtd() const { return wxSVG_FONT_FACE_NAME_ELEMENT; }
};

#endif  // WX_SVG_FONT_FACE_NAME_ELEMENT_H
