//////////////////////////////////////////////////////////////////////////////
// Name:        SVGFEDisplacementMapElement.h
// Author:      Alex Thuering
// Copyright:   (c) 2005 Alex Thuering
// Licence:     wxWindows licence
// Notes:       generated by generate.py
//////////////////////////////////////////////////////////////////////////////

#ifndef WX_SVG_FE_DISPLACEMENT_MAP_ELEMENT_H
#define WX_SVG_FE_DISPLACEMENT_MAP_ELEMENT_H

#include "SVGElement.h"
#include "SVGFilterPrimitiveStandardAttributes.h"
#include "SVGAnimatedString.h"
#include "SVGAnimatedNumber.h"
#include "SVGAnimatedEnumeration.h"
#include "String_wxsvg.h"
#include "Element.h"
#include "SVGAnimatedType.h"

enum wxSVG_CHANNEL {
  wxSVG_CHANNEL_UNKNOWN = 0,
  wxSVG_CHANNEL_R = 1,
  wxSVG_CHANNEL_G = 2,
  wxSVG_CHANNEL_B = 3,
  wxSVG_CHANNEL_A = 4
};

class wxSVGFEDisplacementMapElement
    : public wxSVGElement,
      public wxSVGFilterPrimitiveStandardAttributes {
protected:
  wxSVGAnimatedString m_in1;
  wxSVGAnimatedString m_in2;
  wxSVGAnimatedNumber m_scale;
  wxSVGAnimatedEnumeration m_xChannelSelector;
  wxSVGAnimatedEnumeration m_yChannelSelector;

public:
  inline const wxSVGAnimatedString& GetIn1() const { return m_in1; }
  inline void SetIn1(const wxSVGAnimatedString& n) { m_in1 = n; }
  inline void SetIn1(const wxString& n) { m_in1.SetBaseVal(n); }

  inline const wxSVGAnimatedString& GetIn2() const { return m_in2; }
  inline void SetIn2(const wxSVGAnimatedString& n) { m_in2 = n; }
  inline void SetIn2(const wxString& n) { m_in2.SetBaseVal(n); }

  inline const wxSVGAnimatedNumber& GetScale() const { return m_scale; }
  inline void SetScale(const wxSVGAnimatedNumber& n) { m_scale = n; }
  inline void SetScale(float n) { m_scale.SetBaseVal(n); }

  inline const wxSVGAnimatedEnumeration& GetXChannelSelector() const {
    return m_xChannelSelector;
  }
  inline void SetXChannelSelector(const wxSVGAnimatedEnumeration& n) {
    m_xChannelSelector = n;
  }
  inline void SetXChannelSelector(unsigned char n) {
    m_xChannelSelector.SetBaseVal(n);
  }

  inline const wxSVGAnimatedEnumeration& GetYChannelSelector() const {
    return m_yChannelSelector;
  }
  inline void SetYChannelSelector(const wxSVGAnimatedEnumeration& n) {
    m_yChannelSelector = n;
  }
  inline void SetYChannelSelector(unsigned char n) {
    m_yChannelSelector.SetBaseVal(n);
  }

public:
  wxSVGFEDisplacementMapElement(wxString tagName = wxT("feDisplacementMap"))
      : wxSVGElement(tagName) {}
  virtual ~wxSVGFEDisplacementMapElement() {}
  wxSvgXmlNode* CloneNode(bool deep = true) {
    return new wxSVGFEDisplacementMapElement(*this);
  }
  bool HasAttribute(const wxString& name) const;
  wxString GetAttribute(const wxString& name) const;
  bool SetAttribute(const wxString& name, const wxString& value);
  wxSvgXmlAttrHash GetAttributes() const;
  bool SetAnimatedValue(const wxString& name, const wxSVGAnimatedType& value);
  virtual wxSVGDTD GetDtd() const { return wxSVG_FEDISPLACEMENTMAP_ELEMENT; }
};

#endif  // WX_SVG_FE_DISPLACEMENT_MAP_ELEMENT_H
