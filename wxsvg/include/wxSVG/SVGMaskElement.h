//////////////////////////////////////////////////////////////////////////////
// Name:        SVGMaskElement.h
// Author:      Alex Thuering
// Copyright:   (c) 2005 Alex Thuering
// Licence:     wxWindows licence
// Notes:       generated by generate.py
//////////////////////////////////////////////////////////////////////////////

#ifndef WX_SVG_MASK_ELEMENT_H
#define WX_SVG_MASK_ELEMENT_H

#include "SVGElement.h"
#include "SVGTests.h"
#include "SVGLangSpace.h"
#include "SVGExternalResourcesRequired.h"
#include "SVGStylable.h"
#include "SVGUnitTypes.h"
#include "SVGAnimatedEnumeration.h"
#include "SVGAnimatedLength.h"
#include "SVGSVGElement.h"
#include "String_wxsvg.h"
#include "Element.h"
#include "SVGAnimatedType.h"

class wxSVGMaskElement : public wxSVGElement,
                         public wxSVGTests,
                         public wxSVGLangSpace,
                         public wxSVGExternalResourcesRequired,
                         public wxSVGStylable,
                         public wxSVGUnitTypes {
protected:
  wxSVGAnimatedEnumeration m_maskUnits;
  wxSVGAnimatedEnumeration m_maskContentUnits;
  wxSVGAnimatedLength m_x;
  wxSVGAnimatedLength m_y;
  wxSVGAnimatedLength m_width;
  wxSVGAnimatedLength m_height;

public:
  inline const wxSVGAnimatedEnumeration& GetMaskUnits() const {
    return m_maskUnits;
  }
  inline void SetMaskUnits(const wxSVGAnimatedEnumeration& n) {
    m_maskUnits = n;
  }
  inline void SetMaskUnits(unsigned char n) { m_maskUnits.SetBaseVal(n); }

  inline const wxSVGAnimatedEnumeration& GetMaskContentUnits() const {
    return m_maskContentUnits;
  }
  inline void SetMaskContentUnits(const wxSVGAnimatedEnumeration& n) {
    m_maskContentUnits = n;
  }
  inline void SetMaskContentUnits(unsigned char n) {
    m_maskContentUnits.SetBaseVal(n);
  }

  inline const wxSVGAnimatedLength& GetX() const {
    WX_SVG_ANIM_LENGTH_CALC_WIDTH(m_x, GetViewportElement());
    return m_x;
  }
  inline void SetX(const wxSVGAnimatedLength& n) { m_x = n; }
  inline void SetX(const wxSVGLength& n) { m_x.SetBaseVal(n); }

  inline const wxSVGAnimatedLength& GetY() const {
    WX_SVG_ANIM_LENGTH_CALC_HEIGHT(m_y, GetViewportElement());
    return m_y;
  }
  inline void SetY(const wxSVGAnimatedLength& n) { m_y = n; }
  inline void SetY(const wxSVGLength& n) { m_y.SetBaseVal(n); }

  inline const wxSVGAnimatedLength& GetWidth() const {
    WX_SVG_ANIM_LENGTH_CALC_WIDTH(m_width, GetViewportElement());
    return m_width;
  }
  inline void SetWidth(const wxSVGAnimatedLength& n) { m_width = n; }
  inline void SetWidth(const wxSVGLength& n) { m_width.SetBaseVal(n); }

  inline const wxSVGAnimatedLength& GetHeight() const {
    WX_SVG_ANIM_LENGTH_CALC_HEIGHT(m_height, GetViewportElement());
    return m_height;
  }
  inline void SetHeight(const wxSVGAnimatedLength& n) { m_height = n; }
  inline void SetHeight(const wxSVGLength& n) { m_height.SetBaseVal(n); }

public:
  wxSVGMaskElement(wxString tagName = wxT("mask")) : wxSVGElement(tagName) {}
  virtual ~wxSVGMaskElement() {}
  wxSvgXmlNode* CloneNode(bool deep = true) {
    return new wxSVGMaskElement(*this);
  }
  bool HasAttribute(const wxString& name) const;
  wxString GetAttribute(const wxString& name) const;
  bool SetAttribute(const wxString& name, const wxString& value);
  wxSvgXmlAttrHash GetAttributes() const;
  bool SetAnimatedValue(const wxString& name, const wxSVGAnimatedType& value);
  virtual wxSVGDTD GetDtd() const { return wxSVG_MASK_ELEMENT; }
};

#endif  // WX_SVG_MASK_ELEMENT_H
