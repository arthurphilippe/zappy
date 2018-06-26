/*
** EPITECH PROJECT, 2018
** graphics
** File description:
** ParsingTools
*/

#ifndef PARSERENGINE_HPP_
	#define PARSERENGINE_HPP_

	#include <vector>
	#include <string>

namespace pl {
class ParsingTools {
public:
	ParsingTools() = delete;
	~ParsingTools() = delete;
	static std::string getStringFromArgNb(std::string string, int nb);
	static std::vector<std::string> createVectorString(std::string string, char delim);
	static std::string extractFirstString(std::string &string);
protected:
private:
};
}

#endif /* !PARSERENGINE_HPP_ */
