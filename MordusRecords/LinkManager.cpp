///////////////////////////////////////////////////////////
//  LinkManager.cpp
//  Implementation of the Class LinkManager
//  Created on:      11-mars-2023 10:47:26
//  Original author: franc
///////////////////////////////////////////////////////////

#include "LinkManager.h"

LinkManager::LinkManager()
{
}

Link& LinkManager::addLink(std::string linkType, const Record& rec1, const Record& rec2, bool bidirectional)
{
	m_links.push_back(LinkPtr(new Link(linkType, rec1, rec2, bidirectional)));
	return *(m_links.back());
}

Link& LinkManager::addLink(const Link& link)
{
	m_links.push_back(LinkPtr(link.clone()));
	return *(m_links.back());
}

LinkIterator LinkManager::begin()
{
	return m_links.begin();
}

LinkIterator LinkManager::end()
{
	return m_links.end();
}

LinkIterator_const LinkManager::cbegin() const
{
	return m_links.cbegin();
}

LinkIterator_const LinkManager::cend() const
{
	return m_links.cend();
}

void LinkManager::deleteLink(LinkIterator_const child)
{
	m_links.erase(child);
}

LinkIterator LinkManager::findLinkName(std::string name)
{
	return std::find_if(m_links.begin(), m_links.end(), [&](const LinkPtr& link) { return (link->getRecord1().getTitle() == name) || (link->getRecord2().getTitle() == name); });
}

LinkIterator_const LinkManager::findLinkName(std::string name) const
{
	return std::find_if(m_links.begin(), m_links.end(), [&](const LinkPtr& link) { return (link->getRecord1().getTitle() == name) || (link->getRecord2().getTitle() == name); });
}

LinkIterator LinkManager::findLinkType(std::string linkType)
{
	return std::find_if(m_links.begin(), m_links.end(), [&](const LinkPtr& link) { return (link->getLinkType() == linkType); });
}

LinkIterator_const LinkManager::findLinkType(std::string linkType) const
{
	return std::find_if(m_links.begin(), m_links.end(), [&](const LinkPtr& link) { return (link->getLinkType() == linkType); });
}

