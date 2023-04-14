///////////////////////////////////////////////////////////
//  LinkContainer.h
//  Implementation of the Class LinkContainer
//  Created on:      26-oct.-2019
//  Original author: p482457
///////////////////////////////////////////////////////////

#if !defined(EA_1A8475D5_4734_484c_8758_A92F295DDED0_LINK_INCLUDED_)
#define EA_1A8475D5_4734_484c_8758_A92F295DDED0_LINK_INCLUDED_

#include <memory>
#include <list>

// Configuration du stockage des objets Link
using LinkPtr = std::unique_ptr<class Link>;
using LinkContainer = std::list<LinkPtr>;
using LinkBaseIterator = LinkContainer::iterator;
using LinkBaseIterator_const = LinkContainer::const_iterator;

class LinkIterator : public LinkBaseIterator
{
public:
	LinkIterator(const LinkContainer::iterator& it) : LinkBaseIterator(it) {}

	// Operateurs simplifiant l'acces a l'objet 3D sur lequel pointe l'iterateur
	// pour LinkIterator it;
	//    *it est l'objet 3D
	//    it-> permet d'invoquer une methode sur l'objet 3D
	class Link& operator*() { return *((*(LinkBaseIterator(*this))).get()); }
	class Link* operator->() { return (*(LinkBaseIterator(*this))).get(); }
};

class LinkIterator_const : public LinkBaseIterator_const
{
public:
	LinkIterator_const(const LinkContainer::const_iterator& it) : LinkBaseIterator_const(it) {}

	// Operateurs simplifiant l'acces a l'objet 3D sur lequel pointe l'iterateur
	// pour LinkIterator_const it;
	//    *it est l'objet 3D constant
	//    it-> permet d'invoquer une methode const sur l'objet 3D
	const class Link& operator*() { return *((*(LinkBaseIterator_const(*this))).get()); }
	const class Link* operator->() { return (*(LinkBaseIterator_const(*this))).get(); }
};

#endif // !defined(EA_1A8475D5_4734_484c_8758_A92F295DDED0__INCLUDED_)
