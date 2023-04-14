///////////////////////////////////////////////////////////
//  Date.cpp
//  Implementation of the Class Date
//  Created on:      11-mars-2023 22:44:22
//  Original author: franc
///////////////////////////////////////////////////////////

#include <string>

#include "Date.h"

Date::Date(int day, int month, int year)
	: m_day(day), m_month(month), m_year(year)
{
}

void Date::setDate(int day, int month, int year)
{
	m_day = day;
	m_month = month;
	m_year = year;
}

std::string Date::toString() const
{
	std::string res = std::to_string(m_day) + "/" + std::to_string(m_month) + "/" + std::to_string(m_year);
	return res;
}

bool operator ==(const Date& lhs, const Date& rhs) 
{ 
	return (lhs.getDay() == rhs.getDay() && lhs.getMonth() == rhs.getMonth() && lhs.getYear() == rhs.getYear()); 
}
