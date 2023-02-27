#include <iostream>
#include <vector>
#include <map>
#include <exception>

#include "User.h"
#include "Bank.h"

Bank::Bank() = default;
Bank::Bank(const int mony)
{
	if (mony < 0)
	{
		throw std::logic_error("You put wrong number\n");
	}
	else {
		_mony = mony;
	}
}

void Bank::set_user(const User& oth)
{
	int size = _users.size();
	_users[size] = oth;
	_debt[oth.get_debt()] = 0;
}

void Bank::set_mony(const int mony)
{
	if (mony < 0)
	{
		throw std::logic_error("You put wrong value:\n");
	}
	else {
		_mony = mony;
	}
}
int Bank::get_mony()const
{
	return _mony;
}

void Bank::give_debt(User& user, int mony)
{
	if (mony <= 0)
	{
		throw std::logic_error("You wont wrong number\n");
	}
	else if (_mony < mony)
	{
		std::cout << "Sorry we haven't mony:\n";
		return;
	}
	bool b = false;
	for (int i = 0; i < _debt.size(); ++i)
	{
		if (_users[i] == user)
		{
			b = true;
		}
	}
	if (b == false)
	{
		this -> set_user(user);
	}
	_debt[user.get_ID()] = mony;
	_mony -= mony;
	user.set_mony(mony);
	user.set_debt(mony);
}
void Bank::take_mony(User& user, int mony)
{
	if (mony <= 0)
	{
		throw std::logic_error("You put wrong number:\n");
	}
	bool b = false;
     	for (int i = 0; i < _users.size(); ++i)
      	{
              	if (_users[i] == user)
        	{
 	          	b = true;
              	}
      	}
	if (b == false)
	{
		throw std::logic_error("You can not pay outher debt:\n");
	}
	_debt[user.get_ID()] -= mony;
	_mony += mony;
	user.set_mony(-1 * mony);
	user.set_debt(-1 * mony);
}
	
