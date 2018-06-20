/*
** EPITECH PROJECT, 2018
** graphics
** File description:
** parser
*/

#include <iostream>
#include <vector>
#include <criterion/criterion.h>
#include "Parser.hpp"
#include "ParserEngine.hpp"

Test(Parser, basic)
{
	std::vector<std::string> cmd;
	cmd.push_back("bct 120 555 0 1 2 3 4 5 6");
	auto ret = gi::Parser::parseCmd(cmd, gi::ParsingType::FULL_MAP);
	cr_assert_eq(ret.front().getCoord().x, 120);
	cr_assert_eq(ret.size(), 1);
	cr_assert_eq(ret.front().getCoord().y, 555);
	auto list = ret.front().getObjList();
	cr_assert_eq(list.size(), 21);
	int linemate = 0;
	for (auto i = list.begin(); i != list.end(); i++) {
		if ((*i) == gi::ObjectType::LINEMATE)
			linemate++;
	}
	cr_assert_eq(linemate, 1);

	int DERAUMERE = 0;
	for (auto i = list.begin(); i != list.end(); i++) {
		if ((*i) == gi::ObjectType::DERAUMERE)
			DERAUMERE++;
	}
	cr_assert_eq(DERAUMERE, 2);

	int SIBUR = 0;
	for (auto i = list.begin(); i != list.end(); i++) {
		if ((*i) == gi::ObjectType::SIBUR)
			SIBUR++;
	}
	cr_assert_eq(SIBUR, 3);

	int MENDIANE = 0;
	for (auto i = list.begin(); i != list.end(); i++) {
		if ((*i) == gi::ObjectType::MENDIANE)
			MENDIANE++;
	}
	cr_assert_eq(MENDIANE, 4);

	int PHIRAS = 0;
	for (auto i = list.begin(); i != list.end(); i++) {
		if ((*i) == gi::ObjectType::PHIRAS)
			PHIRAS++;
	}
	cr_assert_eq(PHIRAS, 5);

	int THYSTAME = 0;
	for (auto i = list.begin(); i != list.end(); i++) {
		if ((*i) == gi::ObjectType::THYSTAME)
			THYSTAME++;
	}
	cr_assert_eq(THYSTAME, 6);
}

Test(Parser, getObjType)
{
	cr_assert_eq(gi::Parser::getObjType(gi::FullMapDef::DERAUMERE), gi::ObjectType::DERAUMERE);
	cr_assert_eq(gi::Parser::getObjType(gi::FullMapDef::LINEMATE), gi::ObjectType::LINEMATE);
	cr_assert_eq(gi::Parser::getObjType(gi::FullMapDef::SIBUR), gi::ObjectType::SIBUR);
	cr_assert_eq(gi::Parser::getObjType(gi::FullMapDef::MENDIANE), gi::ObjectType::MENDIANE);
	cr_assert_eq(gi::Parser::getObjType(gi::FullMapDef::PHIRAS), gi::ObjectType::PHIRAS);
	cr_assert_eq(gi::Parser::getObjType(gi::FullMapDef::THYSTAME), gi::ObjectType::THYSTAME);
}
