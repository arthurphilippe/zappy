/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** Client's AI
*/

#ifndef AI_HPP_
	#define AI_HPP_
	#include <iostream>
	#include <vector>
	#include "Socket.hpp"

namespace pl {

	class AI {
	public:
		AI();
		~AI() {};
		void look(Socket &socket);
		void setMapX(int X)
		{
			_mapX = X;
		}
		void setMapY(int Y)
		{
			_mapX = Y;
		}
	private:
		void clearVision();
		int	_mapX;
		int	_mapY;
		std::vector<std::string>	_vision;
	};

}

#endif /* !AI_HPP_ */