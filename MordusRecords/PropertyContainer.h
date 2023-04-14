///////////////////////////////////////////////////////////
//  PropertyContainer.h
//  Implementation of the Class PropertyContainer
//  Created on:      26-oct.-2019
//  Original author: p482457
///////////////////////////////////////////////////////////

#if !defined(EA_1A8475D5_4734_484c_8758_A92F295DDED0__INCLUDED_)
#define EA_1A8475D5_4734_484c_8758_A92F295DDED0__INCLUDED_

#include <memory>
#include <list>

// Configuration du stockage des enfants des objets composites
using PropertyPtr = std::unique_ptr<class BaseProperty>;
using PropertyContainer = std::list<PropertyPtr>;
using PropertyBaseIterator = PropertyContainer::iterator;
using PropertyBaseIterator_const = PropertyContainer::const_iterator;

class PropertyIterator : public PropertyBaseIterator
{
public:
	PropertyIterator(const PropertyContainer::iterator& it) : PropertyBaseIterator(it) {}

	// Operateurs simplifiant l'acces a l'objet 3D sur lequel pointe l'iterateur
	// pour PropertyIterator it;
	//    *it est l'objet 3D
	//    it-> permet d'invoquer une methode sur l'objet 3D
	class BaseProperty& operator*() { return *((*(PropertyBaseIterator(*this))).get()); }
	class BaseProperty* operator->() { return (*(PropertyBaseIterator(*this))).get(); }
};

class PropertyIterator_const : public PropertyBaseIterator_const
{
public:
	PropertyIterator_const(const PropertyContainer::const_iterator& it) : PropertyBaseIterator_const(it) {}

	// Operateurs simplifiant l'acces a l'objet 3D sur lequel pointe l'iterateur
	// pour PropertyIterator_const it;
	//    *it est l'objet 3D constant
	//    it-> permet d'invoquer une methode const sur l'objet 3D
	const class BaseProperty& operator*() { return *((*(PropertyBaseIterator_const(*this))).get()); }
	const class BaseProperty* operator->() { return (*(PropertyBaseIterator_const(*this))).get(); }
};

#endif // !defined(EA_1A8475D5_4734_484c_8758_A92F295DDED0__INCLUDED_)
