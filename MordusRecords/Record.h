///////////////////////////////////////////////////////////
//  Record.h
//  Implementation of the Class Record
//  Created on:      11-mars-2023 10:47:26
//  Original author: franc
///////////////////////////////////////////////////////////

#if !defined(EA_FCA3994A_3542_410a_8C19_AD6A5D86DF50__INCLUDED_)
#define EA_FCA3994A_3542_410a_8C19_AD6A5D86DF50__INCLUDED_

#include "DateProperty.h"
#include "IntProperty.h"
#include "FloatProperty.h"
#include "SectionProperty.h"
#include "StringProperty.h"
#include "URLProperty.h"

/**
 * La classe <i>Record</i> représente une fiche générique, qui regroupe un certain
 * nombre de propriétés, formant collectivement une description d’une entité
 * conservée dans la base de connaissance. Dans le contexte de la musique, la
 * classe <i>Record</i> sera spécialisée pour décrire les musiciens, les œuvres,
 * les ensembles, les instruments, les évènements et les lieux.
 */
#include "RecordContainer.h"

class Record
{

public:
	Record(std::string title);
	virtual ~Record() = default;
	virtual RecordPtr clone() const;

	virtual std::string getTitle(void) const { return m_properties.getName(); };
	virtual void setTitle(std::string title) { m_properties.setName(title); };

	virtual DateProperty& addProperty(std::string name, int day, int month, int year);
	virtual IntProperty& addProperty(std::string name, int value);
	virtual FloatProperty& addProperty(std::string name, float value);
	virtual SectionProperty& addProperty(std::string name);
	virtual StringProperty& addProperty(std::string name, std::string value);
	virtual URLProperty& addProperty(std::string name, std::string displayText, std::string URL);

	virtual PropertyIterator begin();
	virtual PropertyIterator end();
	virtual PropertyIterator_const cbegin() const;
	virtual PropertyIterator_const cend() const;
	virtual void deleteProperty(PropertyIterator_const child);

	virtual void accept(class BasePropertyVisitor& vis);
	virtual void accept(class BasePropertyVisitor& vis) const;

protected:
	friend std::ostream& operator<<(std::ostream& o, const Record& rec);

	SectionProperty m_properties;
};
#endif // !defined(EA_FCA3994A_3542_410a_8C19_AD6A5D86DF50__INCLUDED_)
