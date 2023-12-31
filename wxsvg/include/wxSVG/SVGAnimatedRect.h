//////////////////////////////////////////////////////////////////////////////
// Name:        SVGAnimatedRect.h
// Author:      Alex Thuering
// Copyright:   (c) 2005 Alex Thuering
// Licence:     wxWindows licence
// Notes:       generated by genAnimated.py
//////////////////////////////////////////////////////////////////////////////

#ifndef WX_SVG_ANIMATED_RECT_H
#define WX_SVG_ANIMATED_RECT_H

#include "SVGRect.h"

class wxSVGAnimatedRect {
public:
  wxSVGAnimatedRect() : m_animVal(NULL) {}
  wxSVGAnimatedRect(const wxSVGRect& value)
      : m_baseVal(value), m_animVal(NULL) {}
  wxSVGAnimatedRect(const wxSVGAnimatedRect& value)
      : m_baseVal(value.m_baseVal), m_animVal(NULL) {
    if (value.m_animVal != NULL) m_animVal = new wxSVGRect(*value.m_animVal);
  }
  ~wxSVGAnimatedRect() { ResetAnimVal(); }

  inline wxSVGAnimatedRect& operator=(const wxSVGAnimatedRect& value) {
    m_baseVal = value.m_baseVal;
    m_animVal =
        value.m_animVal != NULL ? new wxSVGRect(*value.m_animVal) : NULL;
    return *this;
  }

  inline wxSVGRect& GetBaseVal() { return m_baseVal; }
  inline const wxSVGRect& GetBaseVal() const { return m_baseVal; }
  inline void SetBaseVal(const wxSVGRect& value) {
    m_baseVal = value;
    ResetAnimVal();
  }

  inline wxSVGRect& GetAnimVal() {
    if (!m_animVal) m_animVal = new wxSVGRect(m_baseVal);
    return *m_animVal;
  }
  inline const wxSVGRect& GetAnimVal() const {
    return m_animVal ? *m_animVal : m_baseVal;
  }
  inline void SetAnimVal(const wxSVGRect& value) {
    if (!m_animVal)
      m_animVal = new wxSVGRect(value);
    else
      *m_animVal = value;
  }
  inline void ResetAnimVal() {
    if (m_animVal) {
      delete m_animVal;
      m_animVal = NULL;
    }
  }

public:
  inline operator const wxSVGRect&() const { return GetAnimVal(); }

protected:
  wxSVGRect m_baseVal;
  wxSVGRect* m_animVal;
};

#endif  // WX_SVG_ANIMATED_RECT_H
