///////////////////////////////////////////////////////////
//  Link.h
//  Implementation of the Class Link
//  Created on:      11-mars-2023 10:47:26
//  Original author: franc
///////////////////////////////////////////////////////////

#if !defined(EA_E24EF797_B87C_4969_B7BC_C6D132AD2625__INCLUDED_)
#define EA_E24EF797_B87C_4969_B7BC_C6D132AD2625__INCLUDED_

#include "Record.h"
#include "LinkContainer.h"

/**
 * La classe <i>Link</i> représente un lien d’un type quelconque entre deux fiches,
 * c’est-à-dire entre deux objets de la classe <i>Record</i>. L’attribut ‘m_type’
 * précise la nature de la relation qui relie les deux fiches. Par exemple, un
 * lien ayant un attribut m_type dont la valeur est ‘Member’ indique qu’un
 * musicien est, ou a été, membre d’un ensemble. Un lien conserve également une
 * date de début et une date de fin, qui indiquent respectivement le moment ou la
 * relation a commencé et le moment ou la relation a pris fin. Un lien contient
 * aussi un indicateur logique ‘m_bidirectional’ qui est vrai si la relation entre
 * les fiches peut être interprétée de façon symétrique, et faux si la relation
 * doit uniquement être interprétée comme reliant la fiche 1 à la fiche 2.
 */
class Link
{

public:
	Link(std::string linkType, const Record& rec1, const Record& rec2, bool bidirectional = false);
	virtual ~Link() = default;
	virtual LinkPtr clone() const;

	virtual std::string getLinkType() const { return m_linkType; }
	virtual const Record& getRecord1() const { return m_record1; }
	virtual const Record& getRecord2() const { return m_record2; }

protected:
	std::string m_linkType;
	const Record& m_record1;
	const Record& m_record2;
	bool m_bidirectional;

	friend std::ostream& operator<<(std::ostream& o, const Link& link);
};
#endif // !defined(EA_E24EF797_B87C_4969_B7BC_C6D132AD2625__INCLUDED_)
