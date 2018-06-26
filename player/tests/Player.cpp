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
		_ioss << string;
	}
	void operator<<(const int i) override
	{
		_ioss << i;
	}
	bool read(std::string &buff)
	{
		auto size =_ioss.str().size();
		if (size) {
			buff = _ioss.str();
			_ioss.str("");
		}
		return (size);
	}

private:
	std::stringstream _ioss;
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
	link.read(buffer);
	cr_assert_str_eq(buffer.c_str(),
		"Forward\n""Forward\n""Forward\n""Forward\n""Forward\n");


	pl.doAction(pl::Action::LEFT);
	pl.doAction(pl::Action::FORWARD);
	pl.doAction(pl::Action::EJECT);
	pl.doAction(pl::Action::EJECT);
	pl.doAction(pl::Action::BROADCAST, std::string{"vehicule de tourisme de categorie A"});
	pl.offloadActions();

	link.read(buffer);
	cr_assert_str_eq(buffer.c_str(),
		"Left\n""Forward\n""Eject\n""Eject\n"
		"Broadcast vehicule de tourisme de categorie A\n");
}
