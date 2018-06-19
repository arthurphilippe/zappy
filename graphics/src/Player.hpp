/*
** EPITECH PROJECT, 2018
** graphics
** File description:
** Player
*/

#ifndef PLAYER_HPP_
	#define PLAYER_HPP_

	#include <SFML/Graphics.hpp>


namespace gi
{

enum class Orientation {
	NORTH,
	EAST,
	SOUTH,
	WEST,
};

class Player {
	public:
		Player(sf::Vector2f pos, Orientation ori, std::string teamname, unsigned int id)
			: _pos(pos), _ori(ori), _teamname(teamname), _id(id) {}
		~Player() = default;
		sf::Vector2f &getPos() noexcept {return _pos;};
		Orientation &getOri() noexcept {return _ori;};
		std::string &getTeamName() noexcept {return _teamname;};
		unsigned int &getID() noexcept {return _id;};
	protected:
	private:
		sf::Vector2f _pos;
		Orientation _ori;
		std::string _teamname;
		unsigned int _id;
};

} // gi

#endif /* !PLAYER_HPP_ */
