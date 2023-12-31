//////////////////////////////////////////////////////////////////////////////
// Name:        SVGAnimationElement.h
// Author:      Alex Thuering
// Copyright:   (c) 2005 Alex Thuering
// Licence:     wxWindows licence
// Notes:       generated by generate.py
//////////////////////////////////////////////////////////////////////////////

#ifndef WX_SVG_ANIMATION_ELEMENT_H
#define WX_SVG_ANIMATION_ELEMENT_H

#include "SVGElement.h"
#include "SVGTests.h"
#include "SVGExternalResourcesRequired.h"
#include "ElementTimeControl.h"
#include "EventTarget.h"
#include "String_wxsvg.h"
#include "SVGAnimatedType.h"
#include "Element.h"

enum wxSVG_ANIMATION_FILL {
  wxSVG_ANIMATION_FILL_UNKNOWN = 0,
  wxSVG_ANIMATION_FILL_REMOVE = 1,
  wxSVG_ANIMATION_FILL_FREEZE = 2
};

enum wxSVG_ANIMATION_ADDITIVE {
  wxSVG_ANIMATION_ADDITIVE_UNKNOWN = 0,
  wxSVG_ANIMATION_ADDITIVE_REPLACE = 1,
  wxSVG_ANIMATION_ADDITIVE_SUM = 2
};

enum wxSVG_ANIMATION_ACCUMULATE {
  wxSVG_ANIMATION_ACCUMULATE_UNKNOWN = 0,
  wxSVG_ANIMATION_ACCUMULATE_NONE = 1,
  wxSVG_ANIMATION_ACCUMULATE_SUM = 2
};

class wxSVGAnimationElement : public wxSVGElement,
                              public wxSVGTests,
                              public wxSVGExternalResourcesRequired,
                              public wxElementTimeControl,
                              public wxEventTarget {
protected:
  wxString m_href;
  wxString m_attributeName;
  double m_begin;
  double m_dur;
  wxSVGAnimatedType m_from;
  wxSVGAnimatedType m_to;
  wxSVG_ANIMATION_FILL m_fill;
  wxSVG_ANIMATION_ADDITIVE m_additive;
  wxSVG_ANIMATION_ACCUMULATE m_accumulate;
  int m_repeatCount;
  wxSVGStringList m_values;
  bool HasCustomAttribute(const wxString& name) const;
  wxString GetCustomAttribute(const wxString& name) const;
  bool SetCustomAttribute(const wxString& name, const wxString& value);
  wxSvgXmlAttrHash GetCustomAttributes() const;

public:
  inline const wxString& GetHref() const { return m_href; }
  inline void SetHref(const wxString& n) { m_href = n; }

  inline const wxString& GetAttributeName() const { return m_attributeName; }
  inline void SetAttributeName(const wxString& n) { m_attributeName = n; }

  inline double GetBegin() const { return m_begin; }
  inline void SetBegin(double n) { m_begin = n; }

  inline double GetDur() const { return m_dur; }
  inline void SetDur(double n) { m_dur = n; }

  inline const wxSVGAnimatedType& GetFrom() const { return m_from; }
  inline void SetFrom(const wxSVGAnimatedType& n) { m_from = n; }

  inline const wxSVGAnimatedType& GetTo() const { return m_to; }
  inline void SetTo(const wxSVGAnimatedType& n) { m_to = n; }

  inline wxSVG_ANIMATION_FILL GetFill() const { return m_fill; }
  inline void SetFill(const wxSVG_ANIMATION_FILL& n) { m_fill = n; }

  inline wxSVG_ANIMATION_ADDITIVE GetAdditive() const { return m_additive; }
  inline void SetAdditive(const wxSVG_ANIMATION_ADDITIVE& n) { m_additive = n; }

  inline wxSVG_ANIMATION_ACCUMULATE GetAccumulate() const {
    return m_accumulate;
  }
  inline void SetAccumulate(const wxSVG_ANIMATION_ACCUMULATE& n) {
    m_accumulate = n;
  }

public:
  wxSVGAnimationElement(wxString tagName = wxT(""))
      : wxSVGElement(tagName),
        m_begin(0),
        m_dur(0),
        m_fill(wxSVG_ANIMATION_FILL(0)),
        m_additive(wxSVG_ANIMATION_ADDITIVE(0)),
        m_accumulate(wxSVG_ANIMATION_ACCUMULATE(0)),
        m_repeatCount(1) {}
  virtual ~wxSVGAnimationElement() {}

  virtual void ApplyAnimation();
  wxSVGElement* GetTargetElement() const;
  virtual double GetStartTime();
  virtual double GetCurrentTime();
  virtual double GetSimpleDuration();
  bool HasAttribute(const wxString& name) const;
  wxString GetAttribute(const wxString& name) const;
  bool SetAttribute(const wxString& name, const wxString& value);
  wxSvgXmlAttrHash GetAttributes() const;
};

#endif  // WX_SVG_ANIMATION_ELEMENT_H
