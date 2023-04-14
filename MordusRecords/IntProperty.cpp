///////////////////////////////////////////////////////////
//  IntProperty.cpp
//  Implementation of the Class IntProperty
//  Created on:      11-mars-2023 10:47:26
//  Original author: franc
///////////////////////////////////////////////////////////

#include "IntProperty.h"
#include "BasePropertyVisitor.h"

IntProperty::IntProperty(std::string name, int i)
	: BaseProperty(name), m_value(i)
{
}

PropertyPtr IntProperty::clone() const
{
	return PropertyPtr(new IntProperty(*this));
}

void IntProperty::accept(BasePropertyVisitor& v)
{
	v.visitIntProperty(*this);
}

void IntProperty::accept(BasePropertyVisitor& v) const
{
	v.visitIntProperty(*this);
}

std::string IntProperty::getValueAsString() const
{
	return std::to_string(m_value);
}
