//////////////////////////////////////////////////////////////////////////////
// Name:        SVGFEFuncBElement.h
// Author:      Alex Thuering
// Copyright:   (c) 2005 Alex Thuering
// Licence:     wxWindows licence
// Notes:       generated by generate.py
//////////////////////////////////////////////////////////////////////////////

#ifndef WX_SVG_FE_FUNC_B_ELEMENT_H
#define WX_SVG_FE_FUNC_B_ELEMENT_H

#include "SVGComponentTransferFunctionElement.h"
#include "String_wxsvg.h"
#include "Element.h"
#include "SVGAnimatedType.h"

class wxSVGFEFuncBElement : public wxSVGComponentTransferFunctionElement {
public:
  wxSVGFEFuncBElement(wxString tagName = wxT("feFuncB"))
      : wxSVGComponentTransferFunctionElement(tagName) {}
  virtual ~wxSVGFEFuncBElement() {}
  wxSvgXmlNode* CloneNode(bool deep = true) {
    return new wxSVGFEFuncBElement(*this);
  }
  bool HasAttribute(const wxString& name) const;
  wxString GetAttribute(const wxString& name) const;
  bool SetAttribute(const wxString& name, const wxString& value);
  wxSvgXmlAttrHash GetAttributes() const;
  bool SetAnimatedValue(const wxString& name, const wxSVGAnimatedType& value);
  virtual wxSVGDTD GetDtd() const { return wxSVG_FEFUNCB_ELEMENT; }
};

#endif  // WX_SVG_FE_FUNC_B_ELEMENT_H
