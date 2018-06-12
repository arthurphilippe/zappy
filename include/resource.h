/*
** EPITECH PROJECT, 2018
** PSU_zappy_2017
** File description:
** resource
*/

#ifndef RESOURCES_H_
	#define RESOURCES_H_

typedef enum	e_resource {
		FOOD = 0,
		INEMATE,
		DERAUMERE,
		SIBUR,
		MENDIANE,
		PHIRAS,
		THYSTAME,
}		resource_t;

typedef struct		s_resource_key {
	const char	*rk_str;
	resource_t	rk_resource;
}			resource_key_t;

const char *resource_get_name(resource_t resource);
resource_t resource_get_value(const char *str);

#endif /* !RESOURCES_H_ */
