/*
    Copyright (C) 2004, 2005, 2008 Nikolas Zimmermann <zimmermann@kde.org>
                  2004, 2005, 2006, 2008 Rob Buis <buis@kde.org>

    This file is part of the KDE project

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
    Boston, MA 02110-1301, USA.
*/

#ifndef SVGTextContentElement_h
#define SVGTextContentElement_h

#if ENABLE(SVG)
#include "SVGExternalResourcesRequired.h"
#include "SVGLangSpace.h"
#include "SVGStyledElement.h"
#include "SVGTests.h"

namespace WebCore
{
class SVGLength;

class SVGTextContentElement : public SVGStyledElement,
    public SVGTests,
    public SVGLangSpace,
    public SVGExternalResourcesRequired
{
public:
    enum SVGLengthAdjustType {
        LENGTHADJUST_UNKNOWN            = 0,
        LENGTHADJUST_SPACING            = 1,
        LENGTHADJUST_SPACINGANDGLYPHS   = 2
    };

    SVGTextContentElement(const QualifiedName &, Document *);
    virtual ~SVGTextContentElement();

    bool isValid() const override
    {
        return SVGTests::isValid();
    }
    bool isTextContent() const override
    {
        return true;
    }

    long getNumberOfChars() const;
    float getComputedTextLength() const;
    float getSubStringLength(long charnum, long nchars, ExceptionCode &) const;
    FloatPoint getStartPositionOfChar(long charnum, ExceptionCode &) const;
    FloatPoint getEndPositionOfChar(long charnum, ExceptionCode &) const;
    FloatRect getExtentOfChar(long charnum, ExceptionCode &) const;
    float getRotationOfChar(long charnum, ExceptionCode &) const;
    long getCharNumAtPosition(const FloatPoint &) const;
    void selectSubString(long charnum, long nchars, ExceptionCode &) const;

    void parseMappedAttribute(MappedAttribute *) override;

    bool isKnownAttribute(const QualifiedName &);

private:
    ANIMATED_PROPERTY_FORWARD_DECLARATIONS(SVGExternalResourcesRequired, bool, ExternalResourcesRequired, externalResourcesRequired)

    ANIMATED_PROPERTY_DECLARATIONS(SVGTextContentElement, SVGLength, SVGLength, TextLength, textLength)
    ANIMATED_PROPERTY_DECLARATIONS(SVGTextContentElement, int, int, LengthAdjust, lengthAdjust)
};

} // namespace WebCore

#endif // ENABLE(SVG)
#endif
