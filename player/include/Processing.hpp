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

namespace pl {

	class Processing {
	public:
		Processing();
		~Processing() noexcept;
		bool checkWelcome(const std::string &welcome)
			const noexcept;
		void coordinates(const std::string &coordinates,
			int &X, int &Y) noexcept;
	private:
	};

}

#endif /* !PROCESSING_HPP_ */