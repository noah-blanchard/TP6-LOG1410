///////////////////////////////////////////////////////////
//  IntProperty.h
//  Implementation of the Class IntProperty
//  Created on:      11-mars-2023 10:47:26
//  Original author: franc
///////////////////////////////////////////////////////////

#if !defined(EA_6A4DA9EF_58FC_4a0f_8F6A_CDC9604ED820__INCLUDED_)
#define EA_6A4DA9EF_58FC_4a0f_8F6A_CDC9604ED820__INCLUDED_

#include "BaseProperty.h"

class IntProperty : public BaseProperty
{

public:
	IntProperty(std::string name, int i);
	virtual ~IntProperty() = default;
	virtual PropertyPtr clone() const;

	virtual void accept(class BasePropertyVisitor& v);
	virtual void accept(class BasePropertyVisitor& v) const;

	virtual std::string getValueAsString() const;

private:
	int m_value;

};

#endif // !defined(EA_6A4DA9EF_58FC_4a0f_8F6A_CDC9604ED820__INCLUDED_)
