/*
** EPITECH PROJECT, 2018
** graphics
** File description:
** ParserEngine
*/

#ifndef PARSERENGINE_HPP_
	#define PARSERENGINE_HPP_

	#include <iostream>
	#include <string>

namespace gi {
class ParserEngine {
public:
	ParserEngine() = default;
	~ParserEngine() = default;
	static std::string getStringFromArgNb(std::string string, int nb);
protected:
private:
};
}

#endif /* !PARSERENGINE_HPP_ */
