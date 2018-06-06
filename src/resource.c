/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** resource
*/

#include "resource.h"

const resource_key_t RESOURCES_MAP[] = {
	{"inemate", INEMATE},
	{"deraumere", DERAUMERE},
	{"sibur", SIBUR},
	{"mendiane", MENDIANE},
	{"phiras", PHIRAS},
	{"thystame", THYSTAME},
	{"", 0}
};

const char *resource_get_name(resource_t resource)
{
	unsigned int i;

	for (i = 0; RESOURCES_MAP[i].rk_resource
		&& RESOURCES_MAP[i].rk_resource != resource; i++);
	return (RESOURCES_MAP[i].rk_str);
}
