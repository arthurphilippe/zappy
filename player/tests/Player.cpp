/*
** EPITECH PROJECT, 2018
** player
** File description:
** Player
*/

#include <sstream>
#include "criterion/criterion.h"
#include "criterion/assert.h"
#include "Player.hpp"

namespace pl::tests {

class DumbLink : public ILink {
public:
	void operator<<(const std::string &string) override
	{
		_oss << string;
	}
	void operator<<(const int i) override
	{
		_oss << i;
	}
	bool read(std::string &buff) override
	{
		auto size =_iss.str().size();
		if (size) {
			buff = _iss.str();
			_iss.str("");
		}
		return (size);
	}

	void appendInput(const std::string &string)
	{
		_oss << string;
	}
	bool readOutput(std::string &buff)
	{
		auto size =_oss.str().size();
		if (size) {
			buff = _oss.str();
			_oss.str("");
		}
		return (size);
	}


private:
	std::stringstream _oss;
	std::stringstream _iss;
};

}

Test(Player, 1_sernario)
{
	pl::tests::DumbLink dumblink;
	pl::ILink &link(dumblink);
	pl::Player pl(link);

	pl.doAction(pl::Action::FORWARD);
	pl.doAction(pl::Action::FORWARD);
	pl.doAction(pl::Action::FORWARD);
	pl.doAction(pl::Action::FORWARD);
	pl.doAction(pl::Action::FORWARD);
	pl.offloadActions();

	std::string buffer;
	dumblink.readOutput(buffer);
	cr_assert_str_eq(buffer.c_str(),
		"Forward\n""Forward\n""Forward\n""Forward\n""Forward\n");


	pl.doAction(pl::Action::LEFT);
	pl.doAction(pl::Action::FORWARD);
	pl.doAction(pl::Action::EJECT);
	pl.doAction(pl::Action::EJECT);
	pl.doAction(pl::Action::BROADCAST,
		std::string{"vehicule de tourisme de categorie A"});
	pl.offloadActions();

	dumblink.readOutput(buffer);
	cr_assert_str_eq(buffer.c_str(),
		"Left\n""Forward\n""Eject\n""Eject\n"
		"Broadcast vehicule de tourisme de categorie A\n");
}
