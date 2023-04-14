///////////////////////////////////////////////////////////
//  SaveToStreamVisitor.h
//  Implementation of the Class SaveToStreamVisitor
//  Created on:      30-mars-2023 17:49:25
//  Original author: franc
///////////////////////////////////////////////////////////

#if !defined(EA_19FB811F_6A1A_4c2d_8441_11F14DC6A0D3__INCLUDED_)
#define EA_19FB811F_6A1A_4c2d_8441_11F14DC6A0D3__INCLUDED_

#include <iostream>
#include <fstream>
#include <string>

#include "BasePropertyVisitor.h"

class SaveToStreamVisitor : public BasePropertyVisitor
{

public:
	SaveToStreamVisitor();
	SaveToStreamVisitor(std::ostream& stream);
	SaveToStreamVisitor(std::string fname);
	virtual ~SaveToStreamVisitor() = default;

	virtual void visitDateProperty(DateProperty& prop);
	virtual void visitFloatProperty(FloatProperty& prop);
	virtual void visitIntProperty(IntProperty& prop);
	virtual void visitSectionProperty(SectionProperty& prop);
	virtual void visitStringProperty(StringProperty& prop);
	virtual void visitURLProperty(URLProperty& prop);

	virtual void visitDateProperty(const class DateProperty& prop);
	virtual void visitFloatProperty(const class FloatProperty& prop);
	virtual void visitIntProperty(const class IntProperty& prop);
	virtual void visitSectionProperty(const class SectionProperty& prop);
	virtual void visitStringProperty(const class StringProperty& prop);
	virtual void visitURLProperty(const class URLProperty& prop);

	virtual std::ostream& getStream() const { return m_stream; }
private:
	static int m_indent;
	void indent(std::ostream& o) const;
	void defaultVisitProperty(const class BaseProperty& prop);

	std::ofstream m_file; 
	std::ostream& m_stream;
};
#endif // !defined(EA_19FB811F_6A1A_4c2d_8441_11F14DC6A0D3__INCLUDED_)
