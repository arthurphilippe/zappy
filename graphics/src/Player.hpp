/*
** EPITECH PROJECT, 2018
** graphics
** File description:
** Player
*/

#ifndef PLAYER_HPP_
	#define PLAYER_HPP_

	#include <SFML/Graphics.hpp>
	#include "AChampion.hpp"

namespace gi
{

enum class Orientation {
	NORTH,
	EAST,
	SOUTH,
	WEST,
	DEAD,
};

class Player : public AChampion {
public:
	Player(sf::Vector2f pos, Orientation ori, std::string teamname, unsigned int id)
		: AChampion(pos, id), _ori(ori), _teamname(teamname){}
	~Player() = default;
	Orientation &getOri() noexcept {return _ori;};
	void setOri(Orientation ori) {_ori = ori;};
	std::string &getTeamName() noexcept {return _teamname;};
protected:
private:
	Orientation _ori;
	std::string _teamname;
};

} // gi

#endif /* !PLAYER_HPP_ */
