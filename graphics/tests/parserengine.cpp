/*
** EPITECH PROJECT, 2018
** graphics
** File description:
** parserengine
*/

#include <iostream>
#include <criterion/criterion.h>
#include "ParserEngine.hpp"

Test(ParserEngine, basic)
{
	std::string str("Don't Blame Me Love Me Make Me Crazy");
	cr_assert_eq(gi::ParserEngine::getStringFromArgNb(str, 0), "Don't");
	cr_assert_eq(gi::ParserEngine::getStringFromArgNb(str, 1), "Blame");
	cr_assert_eq(gi::ParserEngine::getStringFromArgNb(str, 2), "Me");
	cr_assert_eq(gi::ParserEngine::getStringFromArgNb(str, 3), "Love");
	cr_assert_eq(gi::ParserEngine::getStringFromArgNb(str, 4), "Me");
	cr_assert_eq(gi::ParserEngine::getStringFromArgNb(str, 5), "Make");
	cr_assert_eq(gi::ParserEngine::getStringFromArgNb(str, 6), "Me");
	cr_assert_eq(gi::ParserEngine::getStringFromArgNb(str, 7), "Crazy");
}
