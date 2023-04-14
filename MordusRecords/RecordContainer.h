///////////////////////////////////////////////////////////
//  RecordContainer.h
//  Implementation of the Class RecordContainer
//  Created on:      26-oct.-2019
//  Original author: p482457
///////////////////////////////////////////////////////////

#if !defined(EA_1A8475D5_4734_484c_8758_A92F295DDED0_RECORD_INCLUDED_)
#define EA_1A8475D5_4734_484c_8758_A92F295DDED0_RECORD_INCLUDED_

#include <memory>
#include <list>

// Configuration du stockage des objets Record
using RecordPtr = std::unique_ptr<class Record>;
using RecordContainer = std::list<RecordPtr>;
using RecordBaseIterator = RecordContainer::iterator;
using RecordBaseIterator_const = RecordContainer::const_iterator;

class RecordIterator : public RecordBaseIterator
{
public:
	RecordIterator(const RecordContainer::iterator& it) : RecordBaseIterator(it) {}

	// Operateurs simplifiant l'acces a l'objet 3D sur lequel pointe l'iterateur
	// pour RecordIterator it;
	//    *it est l'objet 3D
	//    it-> permet d'invoquer une methode sur l'objet 3D
	class Record& operator*() { return *((*(RecordBaseIterator(*this))).get()); }
	class Record* operator->() { return (*(RecordBaseIterator(*this))).get(); }
};

class RecordIterator_const : public RecordBaseIterator_const
{
public:
	RecordIterator_const(const RecordContainer::const_iterator& it) : RecordBaseIterator_const(it) {}

	// Operateurs simplifiant l'acces a l'objet 3D sur lequel pointe l'iterateur
	// pour RecordIterator_const it;
	//    *it est l'objet 3D constant
	//    it-> permet d'invoquer une methode const sur l'objet 3D
	const class Record& operator*() { return *((*(RecordBaseIterator_const(*this))).get()); }
	const class Record* operator->() { return (*(RecordBaseIterator_const(*this))).get(); }
};

#endif // !defined(EA_1A8475D5_4734_484c_8758_A92F295DDED0__INCLUDED_)
