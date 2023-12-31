//////////////////////////////////////////////////////////////////////////////
// Name:        SVGComponentTransferFunctionElement.h
// Author:      Alex Thuering
// Copyright:   (c) 2005 Alex Thuering
// Licence:     wxWindows licence
// Notes:       generated by generate.py
//////////////////////////////////////////////////////////////////////////////

#ifndef WX_SVG_COMPONENT_TRANSFER_FUNCTION_ELEMENT_H
#define WX_SVG_COMPONENT_TRANSFER_FUNCTION_ELEMENT_H

#include "SVGElement.h"
#include "SVGAnimatedEnumeration.h"
#include "SVGAnimatedNumberList.h"
#include "SVGAnimatedNumber.h"
#include "String_wxsvg.h"
#include "Element.h"
#include "SVGAnimatedType.h"

enum wxSVG_FECOMPONENTTRANSFER_TYPE {
  wxSVG_FECOMPONENTTRANSFER_TYPE_UNKNOWN = 0,
  wxSVG_FECOMPONENTTRANSFER_TYPE_IDENTITY = 1,
  wxSVG_FECOMPONENTTRANSFER_TYPE_TABLE = 2,
  wxSVG_FECOMPONENTTRANSFER_TYPE_DISCRETE = 3,
  wxSVG_FECOMPONENTTRANSFER_TYPE_LINEAR = 4,
  wxSVG_FECOMPONENTTRANSFER_TYPE_GAMMA = 5
};

class wxSVGComponentTransferFunctionElement : public wxSVGElement {
protected:
  wxSVGAnimatedEnumeration m_type;
  wxSVGAnimatedNumberList m_tableValues;
  wxSVGAnimatedNumber m_slope;
  wxSVGAnimatedNumber m_intercept;
  wxSVGAnimatedNumber m_amplitude;
  wxSVGAnimatedNumber m_exponent;
  wxSVGAnimatedNumber m_offset;

public:
  inline const wxSVGAnimatedEnumeration& GetType() const { return m_type; }
  inline void SetType(const wxSVGAnimatedEnumeration& n) { m_type = n; }
  inline void SetType(unsigned char n) { m_type.SetBaseVal(n); }

  inline const wxSVGAnimatedNumberList& GetTableValues() const {
    return m_tableValues;
  }
  inline void SetTableValues(const wxSVGAnimatedNumberList& n) {
    m_tableValues = n;
  }
  inline void SetTableValues(const wxSVGNumberList& n) {
    m_tableValues.SetBaseVal(n);
  }

  inline const wxSVGAnimatedNumber& GetSlope() const { return m_slope; }
  inline void SetSlope(const wxSVGAnimatedNumber& n) { m_slope = n; }
  inline void SetSlope(float n) { m_slope.SetBaseVal(n); }

  inline const wxSVGAnimatedNumber& GetIntercept() const { return m_intercept; }
  inline void SetIntercept(const wxSVGAnimatedNumber& n) { m_intercept = n; }
  inline void SetIntercept(float n) { m_intercept.SetBaseVal(n); }

  inline const wxSVGAnimatedNumber& GetAmplitude() const { return m_amplitude; }
  inline void SetAmplitude(const wxSVGAnimatedNumber& n) { m_amplitude = n; }
  inline void SetAmplitude(float n) { m_amplitude.SetBaseVal(n); }

  inline const wxSVGAnimatedNumber& GetExponent() const { return m_exponent; }
  inline void SetExponent(const wxSVGAnimatedNumber& n) { m_exponent = n; }
  inline void SetExponent(float n) { m_exponent.SetBaseVal(n); }

  inline const wxSVGAnimatedNumber& GetOffset() const { return m_offset; }
  inline void SetOffset(const wxSVGAnimatedNumber& n) { m_offset = n; }
  inline void SetOffset(float n) { m_offset.SetBaseVal(n); }

public:
  wxSVGComponentTransferFunctionElement(wxString tagName = wxT(""))
      : wxSVGElement(tagName) {}
  virtual ~wxSVGComponentTransferFunctionElement() {}
  bool HasAttribute(const wxString& name) const;
  wxString GetAttribute(const wxString& name) const;
  bool SetAttribute(const wxString& name, const wxString& value);
  wxSvgXmlAttrHash GetAttributes() const;
  bool SetAnimatedValue(const wxString& name, const wxSVGAnimatedType& value);
};

#endif  // WX_SVG_COMPONENT_TRANSFER_FUNCTION_ELEMENT_H
