///////////////////////////////////////////////////////////
//  BaseProperty.cpp
//  Implementation of the Class BaseProperty
//  Created on:      11-mars-2023 10:47:25
//  Original author: franc
///////////////////////////////////////////////////////////

#include "BaseProperty.h"

PropertyContainer BaseProperty::m_emptyContainer;

BaseProperty& BaseProperty::addProperty(const BaseProperty& prop)
{
	return *(*(m_emptyContainer.begin()));
}

PropertyIterator BaseProperty::begin()
{
	return m_emptyContainer.begin();
}

PropertyIterator BaseProperty::end()
{
	return m_emptyContainer.end();
}

PropertyIterator_const BaseProperty::cbegin() const
{
	return m_emptyContainer.cbegin();
}

PropertyIterator_const BaseProperty::cend() const
{
	return m_emptyContainer.cend();
}

void BaseProperty::deleteProperty(PropertyIterator_const child)
{
	// Echoue silencieusement
}

bool operator ==(const BaseProperty& lhs, const BaseProperty& rhs)
{
	return (lhs.getValueAsString() == rhs.getValueAsString());
}

bool operator <(const BaseProperty& lhs, const BaseProperty& rhs)
{
	return (lhs.getValueAsString() < rhs.getValueAsString());
}
