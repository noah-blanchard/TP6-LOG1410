///////////////////////////////////////////////////////////
//  Date.h
//  Implementation of the Class Date
//  Created on:      11-mars-2023 22:44:22
//  Original author: franc
///////////////////////////////////////////////////////////

#if !defined(EA_B86E6831_97C9_4b7e_A49B_EC1E9CF1B6F3__INCLUDED_)
#define EA_B86E6831_97C9_4b7e_A49B_EC1E9CF1B6F3__INCLUDED_

class Date
{

public:
	Date(int day, int month, int year);
	virtual ~Date() = default;

	int getDay() const { return m_day; };
	int getMonth() const { return m_month; };
	int getYear() const { return m_year; };
	void setDate(int day, int month, int year);
	std::string toString() const;

private:
	int m_day;
	int m_month;
	int m_year;

};

bool operator ==(const Date& lhs, const Date& rhs);


#endif // !defined(EA_B86E6831_97C9_4b7e_A49B_EC1E9CF1B6F3__INCLUDED_)
