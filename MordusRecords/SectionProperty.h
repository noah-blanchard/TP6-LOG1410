///////////////////////////////////////////////////////////
//  SectionProperty.h
//  Implementation of the Class SectionProperty
//  Created on:      11-mars-2023 10:47:26
//  Original author: franc
///////////////////////////////////////////////////////////

#if !defined(EA_A455AA12_5B85_421c_8204_A2CC5B2D46B3__INCLUDED_)
#define EA_A455AA12_5B85_421c_8204_A2CC5B2D46B3__INCLUDED_

#include "BaseProperty.h"

class SectionProperty : public BaseProperty
{

public:
	SectionProperty(std::string name);
	SectionProperty(const SectionProperty& rhs);
	virtual ~SectionProperty();
	virtual PropertyPtr clone() const;

	virtual void accept(class BasePropertyVisitor& v);
	virtual void accept(class BasePropertyVisitor& v) const;

	virtual std::string getValueAsString(void) const;

	virtual BaseProperty& addProperty(const BaseProperty& prop);
	virtual PropertyIterator begin();
	virtual PropertyIterator end();
	virtual PropertyIterator_const cbegin() const;
	virtual PropertyIterator_const cend() const;
	virtual void deleteProperty(PropertyIterator_const child);

private:
	PropertyContainer m_propertyContainer;
};

#endif // !defined(EA_A455AA12_5B85_421c_8204_A2CC5B2D46B3__INCLUDED_)
