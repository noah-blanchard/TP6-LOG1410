///////////////////////////////////////////////////////////
//  StringProperty.cpp
//  Implementation of the Class StringProperty
//  Created on:      11-mars-2023 10:47:26
//  Original author: franc
///////////////////////////////////////////////////////////

#include "StringProperty.h"
#include "BasePropertyVisitor.h"

StringProperty::StringProperty(std::string name, std::string value)
	: BaseProperty(name), m_value(value)
{
}

PropertyPtr StringProperty::clone() const
{
	return PropertyPtr(new StringProperty(*this));
}

void StringProperty::accept(BasePropertyVisitor& v)
{
	v.visitStringProperty(*this);
}

void StringProperty::accept(BasePropertyVisitor& v) const
{
	v.visitStringProperty(*this);
}

std::string StringProperty::getValueAsString() const {

	return  m_value;
}
