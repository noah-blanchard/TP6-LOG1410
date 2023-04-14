///////////////////////////////////////////////////////////
//  Record.cpp
//  Implementation of the Class Record
//  Created on:      11-mars-2023 10:47:26
//  Original author: franc
///////////////////////////////////////////////////////////

#include "Record.h"
#include "SaveToStreamVisitor.h"

Record::Record(std::string title)
	: m_properties(title)
{
}

RecordPtr Record::clone() const
{
	return RecordPtr(new Record(*this));
}

DateProperty& Record::addProperty(std::string name, int day, int month, int year)
{
	return dynamic_cast<DateProperty&>(m_properties.addProperty(DateProperty(name, day, month, year)));
}

IntProperty& Record::addProperty(std::string name, int value)
{
	return dynamic_cast<IntProperty&>(m_properties.addProperty(IntProperty(name, value)));
}

FloatProperty& Record::addProperty(std::string name, float value)
{
	return dynamic_cast<FloatProperty&>(m_properties.addProperty(FloatProperty(name, value)));
}

SectionProperty& Record::addProperty(std::string name)
{
	return dynamic_cast<SectionProperty&>(m_properties.addProperty(SectionProperty(name)));
}

StringProperty& Record::addProperty(std::string name, std::string value)
{
	return dynamic_cast<StringProperty&>(m_properties.addProperty(StringProperty(name,value)));
}

URLProperty& Record::addProperty(std::string name, std::string displayText, std::string URL)
{
	return dynamic_cast<URLProperty&>(m_properties.addProperty(URLProperty(name, displayText, URL)));
}

PropertyIterator Record::begin()
{
	return m_properties.begin();
}

PropertyIterator Record::end()
{
	return m_properties.end();
}

PropertyIterator_const Record::cbegin() const
{
	return m_properties.cbegin();
}

PropertyIterator_const Record::cend() const
{
	return m_properties.cend();
}

void Record::deleteProperty(PropertyIterator_const child)
{
	m_properties.deleteProperty(child);
}

void Record::accept(BasePropertyVisitor& vis)
{
	m_properties.accept(vis);
}

void Record::accept(BasePropertyVisitor& vis) const
{
	m_properties.accept(vis);
}

std::ostream& operator<<(std::ostream& o, const Record& rec)
{
	SaveToStreamVisitor vis(o);
	rec.m_properties.accept(vis);
	return o << std::endl;
}
