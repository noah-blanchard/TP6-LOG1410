///////////////////////////////////////////////////////////
//  LinkManager.h
//  Implementation of the Class LinkManager
//  Created on:      11-mars-2023 10:47:26
//  Original author: franc
///////////////////////////////////////////////////////////

#if !defined(EA_C2A3376D_AFE7_4f5c_913F_8944BD1D38D6__INCLUDED_)
#define EA_C2A3376D_AFE7_4f5c_913F_8944BD1D38D6__INCLUDED_

#include "Link.h"

class LinkManager
{

public:
	LinkManager();
	virtual ~LinkManager() = default;

	virtual Link& addLink(std::string linkType, const Record& rec1, const Record& rec2, bool bidirectional = false);
	virtual Link& addLink(const Link& link);
	virtual LinkIterator begin();
	virtual LinkIterator end();
	virtual LinkIterator_const cbegin() const;
	virtual LinkIterator_const cend() const;
	virtual void deleteLink(LinkIterator_const child);
	virtual LinkIterator findLinkName(std::string name);
	virtual LinkIterator_const findLinkName(std::string name) const;
	virtual LinkIterator findLinkType(std::string linkType);
	virtual LinkIterator_const findLinkType(std::string linkType) const;

protected:
	LinkContainer m_links;
};
#endif // !defined(EA_C2A3376D_AFE7_4f5c_913F_8944BD1D38D6__INCLUDED_)
