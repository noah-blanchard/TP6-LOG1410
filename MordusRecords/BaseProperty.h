///////////////////////////////////////////////////////////
//  BaseProperty.h
//  Implementation of the Class BaseProperty
//  Created on:      11-mars-2023 10:47:25
//  Original author: franc
///////////////////////////////////////////////////////////

#if !defined(EA_29F118CC_9846_4689_B4D8_668537EC7D26__INCLUDED_)
#define EA_29F118CC_9846_4689_B4D8_668537EC7D26__INCLUDED_

/**
 * La classe <i>BaseProperty</i> représente un élément d’information d’un type donné.
 * Cette classe regroupe un type de donnée et une valeur. Chaque élément
 * d’information peut être vu comme un attribut d’une entité représentée par un
 * objet de la classe <i>Record</i> dans la base de connaissance. Par exemple, la
 * fiche d’un musicien pourrait contenir une propriété ‘ArtistLastName’ de type
 * string et une propriété ‘DateOfBirth’ de type Date, alors que la fiche d’une
 * œuvre pourrait, par exemple, contenir une propriété ‘Title’ de type string. Le
 * nombre de propriétés contenues dans une fiche donnée n’est pas fixé a priori.
 * Un utilisateur peut ajouter autant de propriétés qu’il le souhaite dans une
 * fiche.
 */

#include <ostream>
#include <string>

#include "PropertyContainer.h"

class BaseProperty
{

public:
	BaseProperty(std::string name) : m_name(name) {};
	virtual ~BaseProperty() = default;
	virtual PropertyPtr clone() const = 0;

	virtual std::string getName(void) const { return m_name; };
	virtual void setName(std::string name) { m_name = name; };
	virtual std::string getValueAsString(void) const = 0;

	virtual void accept(class BasePropertyVisitor& v) = 0;
	virtual void accept(class BasePropertyVisitor& v) const = 0;

	virtual BaseProperty& addProperty(const BaseProperty& prop);
	virtual PropertyIterator begin();
	virtual PropertyIterator end();
	virtual PropertyIterator_const cbegin() const;
	virtual PropertyIterator_const cend() const;
	virtual void deleteProperty(PropertyIterator_const child);

protected:
	std::string m_name;

private:
	static PropertyContainer m_emptyContainer;
};

bool operator ==(const BaseProperty& lhs, const BaseProperty& rhs);
bool operator <(const BaseProperty& lhs, const BaseProperty& rhs);

#endif // !defined(EA_29F118CC_9846_4689_B4D8_668537EC7D26__INCLUDED_)
