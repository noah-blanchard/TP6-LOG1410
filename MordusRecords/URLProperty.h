///////////////////////////////////////////////////////////
//  URLProperty.h
//  Implementation of the Class URLProperty
//  Created on:      11-mars-2023 10:47:26
//  Original author: franc
///////////////////////////////////////////////////////////

#if !defined(EA_55651189_2F7C_4820_A90E_1318E5E5853E__INCLUDED_)
#define EA_55651189_2F7C_4820_A90E_1318E5E5853E__INCLUDED_

#include "BaseProperty.h"

class URLProperty : public BaseProperty
{

public:
	URLProperty(std::string name, std::string displayText, std::string URL);
	virtual ~URLProperty() = default;
	virtual PropertyPtr clone() const;

	virtual void accept(class BasePropertyVisitor& v);
	virtual void accept(class BasePropertyVisitor& v) const;

	virtual std::string getValueAsString() const;

private:
	std::string m_displayText;
	std::string m_URL;
};
#endif // !defined(EA_55651189_2F7C_4820_A90E_1318E5E5853E__INCLUDED_)
