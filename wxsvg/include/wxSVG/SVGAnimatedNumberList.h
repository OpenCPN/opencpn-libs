//////////////////////////////////////////////////////////////////////////////
// Name:        SVGAnimatedNumberList.h
// Author:      Alex Thuering
// Copyright:   (c) 2005 Alex Thuering
// Licence:     wxWindows licence
// Notes:       generated by genAnimated.py
//////////////////////////////////////////////////////////////////////////////

#ifndef WX_SVG_ANIMATED_NUMBER_LIST_H
#define WX_SVG_ANIMATED_NUMBER_LIST_H

#include "SVGNumberList.h"

class wxSVGAnimatedNumberList {
public:
  wxSVGAnimatedNumberList() : m_animVal(NULL) {}
  wxSVGAnimatedNumberList(const wxSVGNumberList& value)
      : m_baseVal(value), m_animVal(NULL) {}
  wxSVGAnimatedNumberList(const wxSVGAnimatedNumberList& value)
      : m_baseVal(value.m_baseVal), m_animVal(NULL) {
    if (value.m_animVal != NULL)
      m_animVal = new wxSVGNumberList(*value.m_animVal);
  }
  ~wxSVGAnimatedNumberList() { ResetAnimVal(); }

  inline wxSVGAnimatedNumberList& operator=(
      const wxSVGAnimatedNumberList& value) {
    m_baseVal = value.m_baseVal;
    m_animVal =
        value.m_animVal != NULL ? new wxSVGNumberList(*value.m_animVal) : NULL;
    return *this;
  }

  inline wxSVGNumberList& GetBaseVal() { return m_baseVal; }
  inline const wxSVGNumberList& GetBaseVal() const { return m_baseVal; }
  inline void SetBaseVal(const wxSVGNumberList& value) {
    m_baseVal = value;
    ResetAnimVal();
  }

  inline wxSVGNumberList& GetAnimVal() {
    if (!m_animVal) m_animVal = new wxSVGNumberList(m_baseVal);
    return *m_animVal;
  }
  inline const wxSVGNumberList& GetAnimVal() const {
    return m_animVal ? *m_animVal : m_baseVal;
  }
  inline void SetAnimVal(const wxSVGNumberList& value) {
    if (!m_animVal)
      m_animVal = new wxSVGNumberList(value);
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
  inline operator const wxSVGNumberList&() const { return GetAnimVal(); }

protected:
  wxSVGNumberList m_baseVal;
  wxSVGNumberList* m_animVal;
};

#endif  // WX_SVG_ANIMATED_NUMBER_LIST_H
