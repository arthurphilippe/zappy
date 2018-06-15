/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** backgroundMap
*/

#include <criterion/criterion.h>
#include "BackgroundMap.hpp"

#include <iostream>
using namespace gi;

Test(BackgroundMap, generate_map)
{
	int tilesize = 2;
	int width = 10;
	int height = 5;
	std::vector<sf::Vector2f> coor;
	BackgroundMap map(width, height, tilesize);
	cr_assert_eq(map.getMap().size(), width * height);

	for (int i = 0; i < width; i++)
		for (int j = 0; j < height; j++) {
			sf::Vector2f vec((tilesize / 2) + (tilesize * i),
				(tilesize / 2) + (tilesize * j));
			coor.push_back(vec);
		}
	cr_assert_eq(coor.size(), width * height);
	bool test = false;
	for (auto it = map.getMap().begin(); it != map.getMap().end(); ++it) {
		for (auto k = coor.begin(); k != coor.end(); k++) {
			if (k->x == it->getCoord().x && k->y == it->getCoord().y) {
				test = true;
				break;
			}
		}
	cr_assert(test);
	test = false;
	}
}

Test(BackgroundMap, generate_map2)
{
	int tilesize = 15;
	int width = 109;
	int height = 57;
	std::vector<sf::Vector2f> coor;
	BackgroundMap map(width, height, tilesize);
	cr_assert_eq(map.getMap().size(), width * height);

	for (int i = 0; i < width; i++)
		for (int j = 0; j < height; j++) {
			sf::Vector2f vec((tilesize / 2) + (tilesize * i),
				(tilesize / 2) + (tilesize * j));
			coor.push_back(vec);
		}
	cr_assert_eq(coor.size(), width * height);
	bool test = false;
	for (auto it = map.getMap().begin(); it != map.getMap().end(); ++it) {
		for (auto k = coor.begin(); k != coor.end(); k++) {
			if (k->x == it->getCoord().x && k->y == it->getCoord().y) {
				test = true;
				break;
			}
		}
	cr_assert(test);
	test = false;
	}
}

