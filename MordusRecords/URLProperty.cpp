///////////////////////////////////////////////////////////
//  URLProperty.cpp
//  Implementation of the Class URLProperty
//  Created on:      11-mars-2023 10:47:26
//  Original author: franc
///////////////////////////////////////////////////////////

#include "URLProperty.h"
#include "BasePropertyVisitor.h"


URLProperty::URLProperty(std::string name, std::string displayText, std::string URL)
	: BaseProperty(name), m_displayText(displayText), m_URL(URL)
{
}

PropertyPtr URLProperty::clone() const
{
	return PropertyPtr(new URLProperty(*this));
}

void URLProperty::accept(BasePropertyVisitor& v)
{
	v.visitURLProperty(*this);
}

void URLProperty::accept(BasePropertyVisitor& v) const
{
	v.visitURLProperty(*this);
}

std::string URLProperty::getValueAsString() const
{
	return m_displayText;
}

