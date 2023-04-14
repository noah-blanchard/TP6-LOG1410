///////////////////////////////////////////////////////////
//  SectionProperty.cpp
//  Implementation of the Class SectionProperty
//  Created on:      11-mars-2023 10:47:26
//  Original author: franc
///////////////////////////////////////////////////////////

#include "SectionProperty.h"
#include "BasePropertyVisitor.h"

SectionProperty::SectionProperty(std::string name)
	: BaseProperty(name)
{
}

SectionProperty::SectionProperty(const SectionProperty& rhs)
	: BaseProperty(rhs)
{
	for (auto it = rhs.cbegin(); it != rhs.cend(); ++it)
		addProperty(*it);
}

SectionProperty::~SectionProperty()
{
}

PropertyPtr SectionProperty::clone() const
{
	return PropertyPtr(new SectionProperty(*this));
}

void SectionProperty::accept(BasePropertyVisitor& v)
{
	v.visitSectionProperty(*this);
}

void SectionProperty::accept(BasePropertyVisitor& v) const
{
	v.visitSectionProperty(*this);
}

std::string SectionProperty::getValueAsString(void) const
{
	return std::string();
}

BaseProperty& SectionProperty::addProperty(const BaseProperty& prop)
{
	m_propertyContainer.push_back(PropertyPtr(prop.clone()));
	return *(m_propertyContainer.back());
}

PropertyIterator SectionProperty::begin()
{
	return m_propertyContainer.begin();
}

PropertyIterator SectionProperty::end()
{
	return m_propertyContainer.end();
}

PropertyIterator_const SectionProperty::cbegin() const
{
	return m_propertyContainer.cbegin();
}

PropertyIterator_const SectionProperty::cend() const
{
	return m_propertyContainer.cend();
}

void SectionProperty::deleteProperty(PropertyIterator_const child)
{
	m_propertyContainer.erase(child);
}
