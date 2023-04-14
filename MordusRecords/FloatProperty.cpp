///////////////////////////////////////////////////////////
//  FloatProperty.cpp
//  Implementation of the Class FloatProperty
//  Created on:      11-mars-2023 10:47:25
//  Original author: franc
///////////////////////////////////////////////////////////

#include "FloatProperty.h"
#include "BasePropertyVisitor.h"

FloatProperty::FloatProperty(std::string name, float f)
	: BaseProperty(name), m_value(f)
{
}

PropertyPtr FloatProperty::clone() const
{
	return PropertyPtr(new FloatProperty(*this));
}

void FloatProperty::accept(BasePropertyVisitor& v)
{
	v.visitFloatProperty(*this);
}

void FloatProperty::accept(BasePropertyVisitor& v) const
{
	v.visitFloatProperty(*this);
}

std::string FloatProperty::getValueAsString() const
{
	return std::to_string(m_value);
}
