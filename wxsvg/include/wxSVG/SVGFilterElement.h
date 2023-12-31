//////////////////////////////////////////////////////////////////////////////
// Name:        SVGFilterElement.h
// Author:      Alex Thuering
// Copyright:   (c) 2005 Alex Thuering
// Licence:     wxWindows licence
// Notes:       generated by generate.py
//////////////////////////////////////////////////////////////////////////////

#ifndef WX_SVG_FILTER_ELEMENT_H
#define WX_SVG_FILTER_ELEMENT_H

#include "SVGElement.h"
#include "SVGURIReference.h"
#include "SVGLangSpace.h"
#include "SVGExternalResourcesRequired.h"
#include "SVGStylable.h"
#include "SVGUnitTypes.h"
#include "SVGAnimatedEnumeration.h"
#include "SVGAnimatedLength.h"
#include "SVGAnimatedInteger.h"
#include "SVGSVGElement.h"
#include "String_wxsvg.h"
#include "Element.h"
#include "SVGAnimatedType.h"

class wxSVGFilterElement : public wxSVGElement,
                           public wxSVGURIReference,
                           public wxSVGLangSpace,
                           public wxSVGExternalResourcesRequired,
                           public wxSVGStylable,
                           public wxSVGUnitTypes {
protected:
  wxSVGAnimatedEnumeration m_filterUnits;
  wxSVGAnimatedEnumeration m_primitiveUnits;
  wxSVGAnimatedLength m_x;
  wxSVGAnimatedLength m_y;
  wxSVGAnimatedLength m_width;
  wxSVGAnimatedLength m_height;
  wxSVGAnimatedInteger m_filterResX;
  wxSVGAnimatedInteger m_filterResY;

public:
  inline const wxSVGAnimatedEnumeration& GetFilterUnits() const {
    return m_filterUnits;
  }
  inline void SetFilterUnits(const wxSVGAnimatedEnumeration& n) {
    m_filterUnits = n;
  }
  inline void SetFilterUnits(unsigned char n) { m_filterUnits.SetBaseVal(n); }

  inline const wxSVGAnimatedEnumeration& GetPrimitiveUnits() const {
    return m_primitiveUnits;
  }
  inline void SetPrimitiveUnits(const wxSVGAnimatedEnumeration& n) {
    m_primitiveUnits = n;
  }
  inline void SetPrimitiveUnits(unsigned char n) {
    m_primitiveUnits.SetBaseVal(n);
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

  inline const wxSVGAnimatedInteger& GetFilterResX() const {
    return m_filterResX;
  }
  inline void SetFilterResX(const wxSVGAnimatedInteger& n) { m_filterResX = n; }
  inline void SetFilterResX(long n) { m_filterResX.SetBaseVal(n); }

  inline const wxSVGAnimatedInteger& GetFilterResY() const {
    return m_filterResY;
  }
  inline void SetFilterResY(const wxSVGAnimatedInteger& n) { m_filterResY = n; }
  inline void SetFilterResY(long n) { m_filterResY.SetBaseVal(n); }

public:
  wxSVGFilterElement(wxString tagName = wxT("filter"))
      : wxSVGElement(tagName) {}
  virtual ~wxSVGFilterElement() {}
  wxSvgXmlNode* CloneNode(bool deep = true) {
    return new wxSVGFilterElement(*this);
  }
  virtual void SetFilterRes(unsigned long filterResX, unsigned long filterResY);
  bool HasAttribute(const wxString& name) const;
  wxString GetAttribute(const wxString& name) const;
  bool SetAttribute(const wxString& name, const wxString& value);
  wxSvgXmlAttrHash GetAttributes() const;
  bool SetAnimatedValue(const wxString& name, const wxSVGAnimatedType& value);
  virtual wxSVGDTD GetDtd() const { return wxSVG_FILTER_ELEMENT; }
};

#endif  // WX_SVG_FILTER_ELEMENT_H
