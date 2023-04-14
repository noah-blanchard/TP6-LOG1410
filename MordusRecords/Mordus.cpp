///////////////////////////////////////////////////////////
//  Mordus.cpp
//  Implementation of the main function
//  Created on:      12-mars-2023 10:47:26
//  Original author: franc
///////////////////////////////////////////////////////////

#include <iostream>

#include "RecordManager.h"
#include "LinkManager.h"
#include "SaveToStreamVisitor.h"
#include "SimpleSearchVisitor.h"

void addDisk(RecordManager& manager, std::string title, std::string genre, int year, std::string label)
{
	Record& disk = manager.addRecord(title);
	disk.addProperty("year", year);
	disk.addProperty("genre", "Jazz");
	disk.addProperty("label", label);
}

void populateMilesDavisWorks(RecordManager& manager)
{
	addDisk(manager, "Dig", "Jazz", 1956, "Prestige");
	addDisk(manager, "Birth of the Cool", "Jazz", 1957, "Capitol");
	addDisk(manager, "Cookin'", "Jazz", 1957, "Prestige");
	addDisk(manager, "Porgy and Bess", "Jazz", 1959, "Columbia");
	addDisk(manager, "Kind of Blue", "Jazz", 1959, "Columbia");
	addDisk(manager, "Sketches of Spain", "Jazz", 1960, "Columbia");
}

void addPrize(BaseProperty& section, std::string award, int year, std::string category, std::string work)
{
	BaseProperty& prize = section.addProperty(SectionProperty(award));
	prize.addProperty(IntProperty("year", year));
	prize.addProperty(StringProperty("category", category));
	prize.addProperty(StringProperty("work", work));
}

void populateMilesDavisRecord(RecordManager& manager)
{
	Record& miles_davis = manager.addRecord("Miles Davis");
	miles_davis.addProperty("first_name", "Miles");
	miles_davis.addProperty("last_name", "Davis");
	miles_davis.addProperty("birth_name", "Miles Dewey Davis III");
	miles_davis.addProperty("birth_date", 26, 5, 1926);
	miles_davis.addProperty("birth_place", "Alton, Illinois, USA");
	miles_davis.addProperty("death_date", 28, 9, 1991);
	miles_davis.addProperty("main_instrument", "trumpet");
	miles_davis.addProperty("other_instrument", "flugelhorn");
	miles_davis.addProperty("other_instrument", "cornet");
	miles_davis.addProperty("other_instrument", "piano");
	miles_davis.addProperty("other_instrument", "electric organ");

	BaseProperty& award = miles_davis.addProperty("Awards");
	BaseProperty& grammys = award.addProperty(SectionProperty("Grammys"));
	addPrize(grammys, "Grammy", 1960, "Best Jazz Composition of More Than Five Minutes Duration", "Sketches of Spain");
	addPrize(grammys, "Grammy", 1970, "Best Jazz Performance, Large Group or Soloist with Large Group", "Bitches Brew");
	addPrize(grammys, "Grammy", 1982, "Best Jazz Instrumental Performance, Soloist", "We Want Miles");
	addPrize(grammys, "Grammy", 1986, "Best Jazz Instrumental Performance, Soloist", "Tutu");
	addPrize(grammys, "Grammy", 1989, "Best Jazz Instrumental Performance, Soloist", "Aura");
	addPrize(grammys, "Grammy", 1989, "Best Jazz Instrumental Performance, Big Band", "Aura");
	addPrize(grammys, "Grammy", 1990, "Lifetime Achievement Award", "");
	addPrize(grammys, "Grammy", 1992, "Best R&B Instrumental Performance", "Doo-Bop");
	addPrize(grammys, "Grammy", 1992, "Best Large Jazz Ensemble Performance", "Miles & Quincy Live at Montreux");

	BaseProperty& otherAwards = award.addProperty(SectionProperty("Other Awards"));
	addPrize(otherAwards, "DownBeat Readers' Poll", 1955, "Best Trumpeter", "");
	addPrize(otherAwards, "DownBeat Readers' Poll ", 1957, "Best Trumpeter", "");
	addPrize(otherAwards, "DownBeat Readers' Poll", 1961, "Best Trumpeter", "");

	miles_davis.addProperty("Website", "https://www.milesdavis.com/");
}

void populateSonnyRollinsRecord(RecordManager& manager)
{
	Record& sonny_rollins = manager.addRecord("Sonny Rollins");
	sonny_rollins.addProperty("first_name", "Sonny");
	sonny_rollins.addProperty("last_name", "Rollins");
	sonny_rollins.addProperty("birth_name", "Walter Theodore Rollins");
	sonny_rollins.addProperty("birth_date", 7, 9, 1930);
	sonny_rollins.addProperty("birth_place", "New York City, USA");
	sonny_rollins.addProperty("main_instrument", "tenor saxophone");
	sonny_rollins.addProperty("other_instrument", "soprano saxophone");

	BaseProperty& award = sonny_rollins.addProperty("Awards");
	BaseProperty& grammys = award.addProperty(SectionProperty("Grammys"));
	addPrize(grammys, "Grammy", 2004, "Lifetime Achievement Award", "");

	BaseProperty& otherAwards = award.addProperty(SectionProperty("Other Awards"));
	addPrize(otherAwards, "DownBeat Magazine", 1973, "Hall of Fame", "");

	sonny_rollins.addProperty("Website", "https://www.sonnyrollins.com/");
}


void populateWithRecords(RecordManager& manager)
{
	populateMilesDavisRecord(manager);
	populateMilesDavisWorks(manager);
	populateSonnyRollinsRecord(manager);
}

const Record& safeFindRecord(RecordManager& manager, std::string name)
{
	auto recIt = manager.findRecord(name);
	if (recIt == manager.cend())
		throw std::runtime_error("record not found");
	return *recIt;
}

void establishLinks(RecordManager& manager, LinkManager& linkManager )
{
	const Record& miles_davis = safeFindRecord(manager, "Miles Davis");
	const Record& sonny_rollins = safeFindRecord(manager, "Sonny Rollins");

	linkManager.addLink("played with", miles_davis, sonny_rollins, true);

	const Record& disk1 = safeFindRecord(manager, "Dig");
	linkManager.addLink("played on", miles_davis, disk1, false);
	linkManager.addLink("played on", sonny_rollins, disk1, false);

	const Record& disk2 = safeFindRecord(manager, "Birth of the Cool");
	linkManager.addLink("played on", miles_davis, disk2, false);

	const Record& disk3 = safeFindRecord(manager, "Cookin'");
	linkManager.addLink("played on", miles_davis, disk3, false);

	const Record& disk4 = safeFindRecord(manager, "Porgy and Bess");
	linkManager.addLink("played on", miles_davis, disk4, false);

	const Record& disk5 = safeFindRecord(manager, "Kind of Blue");
	linkManager.addLink("played on", miles_davis, disk5, false);

	const Record& disk6 = safeFindRecord(manager, "Sketches of Spain");
	linkManager.addLink("played on", miles_davis, disk6, false);
}

int main(int argc, char** argv)
{
	RecordManager theRecordManager;
	populateWithRecords(theRecordManager);
	SaveToStreamVisitor streamVis(std::cout); // Cette ligne peut être ajustée pour sauver dans un fichier
	for (auto it = theRecordManager.cbegin(); it != theRecordManager.cend(); ++it)
		it->accept(streamVis);

	LinkManager theLinkManager;
	establishLinks(theRecordManager, theLinkManager);
	for (auto it = theLinkManager.cbegin(); it != theLinkManager.cend(); ++it)
		streamVis.getStream() << *it;

	DateProperty miles_davis_birth("birth_date", 26, 5, 1926);
	for (auto itrec = theRecordManager.cbegin(); itrec != theRecordManager.cend(); ++itrec)
	{
		SimpleSearchVisitor<std::less<const BaseProperty&>> searchVis(miles_davis_birth);
		itrec->accept(searchVis);
		for (auto itprop = searchVis.cbegin(); itprop != searchVis.cend(); ++itprop)
			itprop->accept(streamVis);
	}

	IntProperty year1970("year", 1970);
	for (auto itrec = theRecordManager.cbegin(); itrec != theRecordManager.cend(); ++itrec)
	{
		SimpleSearchVisitor<std::less<const BaseProperty&>> searchVis(year1970);
		itrec->accept(searchVis);
		if (searchVis.cbegin() != searchVis.cend())
			itrec->accept(streamVis);
	}
}
