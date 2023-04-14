///////////////////////////////////////////////////////////
//  RecordManager.cpp
//  Implementation of the Class RecordManager
//  Created on:      11-mars-2023 10:47:26
//  Original author: franc
///////////////////////////////////////////////////////////

#include <algorithm>

#include "RecordManager.h"

RecordManager::RecordManager()
{
}

Record& RecordManager::addRecord(std::string name)
{
    m_records.push_back(RecordPtr(new Record(name)));
    return *(m_records.back());
}

Record& RecordManager::addRecord(const Record& rec)
{
    m_records.push_back(RecordPtr(rec.clone()));
    return *(m_records.back());
}

RecordIterator RecordManager::begin()
{
    return m_records.begin();
}

RecordIterator RecordManager::end()
{
    return m_records.end();
}

RecordIterator_const RecordManager::cbegin() const
{
    return m_records.cbegin();
}

RecordIterator_const RecordManager::cend() const
{
    return m_records.cend();
}

void RecordManager::deleteRecord(RecordIterator_const child)
{
    m_records.erase(child);
}

RecordIterator RecordManager::findRecord(std::string name)
{
    return std::find_if(m_records.begin(), m_records.end(), [&](const RecordPtr& rec) { return rec->getTitle() == name; });
}

RecordIterator_const RecordManager::findRecord(std::string name) const
{
    return std::find_if(m_records.cbegin(), m_records.cend(), [&](const RecordPtr& rec) { return rec->getTitle() == name; });
}
