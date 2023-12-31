//////////////////////////////////////////////////////////////////////////////
// Name:        SVGTitleElement.h
// Author:      Alex Thuering
// Copyright:   (c) 2005 Alex Thuering
// Licence:     wxWindows licence
// Notes:       generated by generate.py
//////////////////////////////////////////////////////////////////////////////

#ifndef WX_SVG_TITLE_ELEMENT_H
#define WX_SVG_TITLE_ELEMENT_H

#include "SVGElement.h"
#include "SVGLangSpace.h"
#include "SVGStylable.h"
#include "String_wxsvg.h"
#include "Element.h"
#include "SVGAnimatedType.h"

class wxSVGTitleElement : public wxSVGElement,
                          public wxSVGLangSpace,
                          public wxSVGStylable {
public:
  wxSVGTitleElement(wxString tagName = wxT("title")) : wxSVGElement(tagName) {}
  virtual ~wxSVGTitleElement() {}
  wxSvgXmlNode* CloneNode(bool deep = true) {
    return new wxSVGTitleElement(*this);
  }
  bool HasAttribute(const wxString& name) const;
  wxString GetAttribute(const wxString& name) const;
  bool SetAttribute(const wxString& name, const wxString& value);
  wxSvgXmlAttrHash GetAttributes() const;
  bool SetAnimatedValue(const wxString& name, const wxSVGAnimatedType& value);
  virtual wxSVGDTD GetDtd() const { return wxSVG_TITLE_ELEMENT; }
};

#endif  // WX_SVG_TITLE_ELEMENT_H
