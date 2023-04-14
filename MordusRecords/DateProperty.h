///////////////////////////////////////////////////////////
//  DateProperty.h
//  Implementation of the Class DateProperty
//  Created on:      11-mars-2023 10:47:25
//  Original author: franc
///////////////////////////////////////////////////////////

#if !defined(EA_1B223F1D_8867_44e0_A7BB_AE360E67F9C7__INCLUDED_)
#define EA_1B223F1D_8867_44e0_A7BB_AE360E67F9C7__INCLUDED_

#include "BaseProperty.h"
#include "Date.h"

class DateProperty : public BaseProperty
{

public:
	DateProperty(std::string name, int day, int month, int year);
	virtual ~DateProperty() = default;
	virtual PropertyPtr clone() const;

	virtual void accept(class BasePropertyVisitor& v);
	virtual void accept(class BasePropertyVisitor& v) const;

	virtual std::string getValueAsString() const;
	virtual const Date& getDate() const { return m_date; }
	virtual void setDate(int day, int month, int year) { m_date.setDate(day, month, year); }

private:
	Date m_date;
};

#endif // !defined(EA_1B223F1D_8867_44e0_A7BB_AE360E67F9C7__INCLUDED_)
