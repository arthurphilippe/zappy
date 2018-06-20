/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** Core
*/

#ifndef CORE_HPP_
	#define CORE_HPP_

	#include "Server.hpp"
	#include "Display.hpp"

namespace gi {

class Core {
	public:
		Core(int ac, char **av);
		~Core();
		bool loop();
	protected:
	private:
	Server _serv;
	Display _display;
};

} // gi


#endif /* !CORE_HPP_ */
