///////////////////////////////////////////////////////////
//  BasePropertyVisitor.h
//  Implementation of the Class BasePropertyVisitor
//  Created on:      30-mars-2023 17:49:21
//  Original author: franc
///////////////////////////////////////////////////////////

#if !defined(EA_E577CD7E_D22C_4bf8_B004_5B6189BC37CA__INCLUDED_)
#define EA_E577CD7E_D22C_4bf8_B004_5B6189BC37CA__INCLUDED_

class BasePropertyVisitor
{

public:
	BasePropertyVisitor() = default;
	virtual ~BasePropertyVisitor() = default;

	virtual void visitDateProperty(class DateProperty& prop) =0;
	virtual void visitFloatProperty(class FloatProperty& prop) =0;
	virtual void visitIntProperty(class IntProperty& prop) =0;
	virtual void visitSectionProperty(class SectionProperty& prop) =0;
	virtual void visitStringProperty(class StringProperty& prop) =0;
	virtual void visitURLProperty(class URLProperty& prop) =0;

	virtual void visitDateProperty(const class DateProperty& prop) = 0;
	virtual void visitFloatProperty(const class FloatProperty& prop) = 0;
	virtual void visitIntProperty(const class IntProperty& prop) = 0;
	virtual void visitSectionProperty(const class SectionProperty& prop) = 0;
	virtual void visitStringProperty(const class StringProperty& prop) = 0;
	virtual void visitURLProperty(const class URLProperty& prop) = 0;
};
#endif // !defined(EA_E577CD7E_D22C_4bf8_B004_5B6189BC37CA__INCLUDED_)
