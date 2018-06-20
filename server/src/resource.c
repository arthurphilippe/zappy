/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** resource
*/

#include <string.h>
#include "resource.h"

const resource_key_t RESOURCES_MAP[] = {
	{"food", FOOD},
	{"linemate", LINEMATE},
	{"deraumere", DERAUMERE},
	{"sibur", SIBUR},
	{"mendiane", MENDIANE},
	{"phiras", PHIRAS},
	{"thystame", THYSTAME},
	{"", RES_COUNT},
};

/*
** returns the string associated with the resource.
*/
const char *resource_get_name(resource_t resource)
{
	unsigned int i;

	for (i = 0; strcmp(RESOURCES_MAP[i].rk_str, "")
		&& RESOURCES_MAP[i].rk_resource != resource; i++);
	return (RESOURCES_MAP[i].rk_str);
}

/*
** From a string, will give you the associated resource value.
*/
resource_t resource_get_value(const char *str)
{
	unsigned int i;

	for (i = 0; strcmp(RESOURCES_MAP[i].rk_str, "")
		&& strcmp(RESOURCES_MAP[i].rk_str, str); i++);
	return (RESOURCES_MAP[i].rk_resource);
}
