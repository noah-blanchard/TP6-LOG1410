///////////////////////////////////////////////////////////
//  SaveToStreamVisitor.cpp
//  Implementation of the Class SaveToStreamVisitor
//  Created on:      30-mars-2023 17:49:25
//  Original author: franc
///////////////////////////////////////////////////////////

#include "SaveToStreamVisitor.h"
#include "DateProperty.h"
#include "FloatProperty.h"
#include "IntProperty.h"
#include "SectionProperty.h"
#include "StringProperty.h"
#include "URLProperty.h"

int SaveToStreamVisitor::m_indent = 0;

SaveToStreamVisitor::SaveToStreamVisitor()
	: m_stream(std::cout)
{
}

SaveToStreamVisitor::SaveToStreamVisitor(std::ostream& stream)
	: m_stream(stream)
{
}

SaveToStreamVisitor::SaveToStreamVisitor(std::string fname)
	: m_file(fname), m_stream(m_file.is_open() ? m_file : std::cout)
{
}

void SaveToStreamVisitor::visitDateProperty(DateProperty& prop)
{
	// À compléter: traiter la propriété
	indent(m_stream);
	m_stream << prop.getName() << ": " << prop.getValueAsString() << std::endl;
	
}

void SaveToStreamVisitor::visitDateProperty(const DateProperty& prop)
{
	// À compléter: traiter la propriété
	indent(m_stream);
	m_stream << prop.getName() << ": " << prop.getValueAsString() << std::endl;
}

void SaveToStreamVisitor::visitFloatProperty(FloatProperty& prop)
{
	// À compléter: traiter la propriété
	indent(m_stream);
	m_stream << prop.getName() << ": " << prop.getValueAsString() << std::endl;
}

void SaveToStreamVisitor::visitFloatProperty(const FloatProperty& prop)
{
	// À compléter: traiter la propriété
	indent(m_stream);
	m_stream << prop.getName() << ": " << prop.getValueAsString() << std::endl;
}

void SaveToStreamVisitor::visitIntProperty(IntProperty& prop)
{
	// À compléter: traiter la propriété
	indent(m_stream);
	m_stream << prop.getName() << ": " << prop.getValueAsString() << std::endl;
}

void SaveToStreamVisitor::visitIntProperty(const IntProperty& prop)
{
	// À compléter: traiter la propriété
	indent(m_stream);
	m_stream << prop.getName() << ": " << prop.getValueAsString() << std::endl;
}

void SaveToStreamVisitor::visitSectionProperty(SectionProperty& prop)
{
	// À compléter: traiter la propriété
}

void SaveToStreamVisitor::visitSectionProperty(const SectionProperty& prop)
{
	// À compléter: afficher le titre de la section, indenter et traiter chaque propriété de la section
	indent(m_stream);
	m_stream << prop.getName() << std::endl;
	m_indent++;
	for (auto it = prop.cbegin(); it != prop.cend(); ++it){
		it->accept(*this);
	}
	m_indent--;
}

void SaveToStreamVisitor::visitStringProperty(StringProperty& prop)
{
	// À compléter: traiter la propriété
	indent(m_stream);
	m_stream << prop.getName() << ": " << prop.getValueAsString() << std::endl;
}

void SaveToStreamVisitor::visitStringProperty(const StringProperty& prop)
{
	// À compléter: traiter la propriété
	indent(m_stream);
	m_stream << prop.getName() << ": " << prop.getValueAsString() << std::endl;
}

void SaveToStreamVisitor::visitURLProperty(URLProperty& prop)
{
	// À compléter: traiter la propriété
	indent(m_stream);

	m_stream << prop.getName() << ": " << prop.getValueAsString() << std::endl;
}

void SaveToStreamVisitor::visitURLProperty(const URLProperty& prop)
{
	// À compléter: traiter la propriété
	indent(m_stream);
	m_stream << prop.getName() << ": " << prop.getValueAsString() << std::endl;
}

void SaveToStreamVisitor::indent(std::ostream& o) const
{
	for (int i = 0; i < m_indent; ++i)
		o << '\t';
}

void SaveToStreamVisitor::defaultVisitProperty(const BaseProperty& prop)
{
	// À compléter: méthode par défaut permettant de traiter une propriété
	indent(m_stream);
	m_stream << prop.getName() << ": " << prop.getValueAsString() << std::endl;
}

