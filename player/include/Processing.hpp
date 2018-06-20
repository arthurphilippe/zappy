/*
** EPITECH PROJECT, 2018
** zappy
** File description:
** Client's Processing
*/

#ifndef PROCESSING_HPP_
	#define PROCESSING_HPP_
	#include <string>
	#include <stdexcept>
	#include <vector>
	#include <unordered_map>

namespace pl {

	class Processing {
	public:
		Processing();
		~Processing() noexcept;
		bool checkWelcome(const std::string &welcome)
			const noexcept;
		void coordinates(const std::string &coordinates,
			int &X, int &Y) noexcept;
		void vision(const std::string &reply,
			std::vector<std::vector<std::string>> &vision) const noexcept;
		void inventory(const std::string &reply,
			std::unordered_map<std::string, int> &inventory)
			const;
		void catchMessage(const std::string &reply);
	private:
		void parseTileContent(std::string &content,
			std::vector<std::vector<std::string>> &vision)
			const;
		void parseResources(std::string &info,
			std::unordered_map<std::string, int> &inventory)
			const;
	};

}

#endif /* !PROCESSING_HPP_ */