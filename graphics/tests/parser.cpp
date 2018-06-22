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

Test(Parser, getObjType)
{
	cr_assert_eq(gi::Parser::getObjType(gi::FullMapDef::DERAUMERE), gi::ObjectType::DERAUMERE);
	cr_assert_eq(gi::Parser::getObjType(gi::FullMapDef::LINEMATE), gi::ObjectType::LINEMATE);
	cr_assert_eq(gi::Parser::getObjType(gi::FullMapDef::SIBUR), gi::ObjectType::SIBUR);
	cr_assert_eq(gi::Parser::getObjType(gi::FullMapDef::MENDIANE), gi::ObjectType::MENDIANE);
	cr_assert_eq(gi::Parser::getObjType(gi::FullMapDef::PHIRAS), gi::ObjectType::PHIRAS);
	cr_assert_eq(gi::Parser::getObjType(gi::FullMapDef::THYSTAME), gi::ObjectType::THYSTAME);
}
