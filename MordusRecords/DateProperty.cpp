///////////////////////////////////////////////////////////
//  DateProperty.cpp
//  Implementation of the Class DateProperty
//  Created on:      11-mars-2023 10:47:25
//  Original author: franc
///////////////////////////////////////////////////////////

#include "DateProperty.h"
#include "BasePropertyVisitor.h"

DateProperty::DateProperty(std::string name, int day, int month, int year)
	: BaseProperty(name), m_date(day,month,year)
{
}

PropertyPtr DateProperty::clone() const
{
	return  PropertyPtr(new DateProperty(*this));
}

void DateProperty::accept(BasePropertyVisitor& v)
{
	v.visitDateProperty(*this);
}

void DateProperty::accept(BasePropertyVisitor& v) const
{
	v.visitDateProperty(*this);
}

std::string DateProperty::getValueAsString() const {

	return  m_date.toString();
}
