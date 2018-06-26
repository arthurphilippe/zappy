/*
** EPITECH PROJECT, 2018
** player
** File description:
** ILink
*/

#ifndef ILINK_HPP_
	#define ILINK_HPP_

	#include <string>

namespace pl {

class ILink {
public:
	virtual ~ILink() = default;
	virtual void operator<<(const std::string &string) = 0;
	virtual void operator<<(const int i) = 0;
	virtual bool read(std::string &buff) = 0;
};

}

#endif /* !ILINK_HPP_ */
