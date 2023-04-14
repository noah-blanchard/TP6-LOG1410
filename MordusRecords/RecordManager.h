///////////////////////////////////////////////////////////
//  RecordManager.h
//  Implementation of the Class RecordManager
//  Created on:      11-mars-2023 10:47:26
//  Original author: franc
///////////////////////////////////////////////////////////

#if !defined(EA_74E98012_61B9_4d98_9AE0_44B7B6BC26B1__INCLUDED_)
#define EA_74E98012_61B9_4d98_9AE0_44B7B6BC26B1__INCLUDED_

#include "Record.h"

class RecordManager
{
public:
	RecordManager();
	virtual ~RecordManager() = default;

	virtual Record& addRecord(std::string name);
	virtual Record& addRecord(const Record& rec);
	virtual RecordIterator begin();
	virtual RecordIterator end();
	virtual RecordIterator_const cbegin() const;
	virtual RecordIterator_const cend() const;
	virtual void deleteRecord(RecordIterator_const child);
	virtual RecordIterator findRecord(std::string name);
	virtual RecordIterator_const findRecord(std::string name) const;

protected:
	RecordContainer m_records;
};

#endif // !defined(EA_74E98012_61B9_4d98_9AE0_44B7B6BC26B1__INCLUDED_)
