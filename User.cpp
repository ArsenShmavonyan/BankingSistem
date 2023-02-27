#include <iostream>
#include <cstdlib>
#include <exception>

#include "User.h"

User::User(std::string name, std::string surname, std::string adres, int age)
{
	if (name == "" || surname == "" || adres == "" || age < 18)
	{
		throw std::logic_error("You put wrong value:\n");
	}
	else {
		_name = name;
		_surname = surname;
		_age = age;
		_adres = adres;
		_ID = rand();
	}
}

void User::set_mony(const int mony)
{
	if (mony <= 0)	
	{
		 throw std::logic_error("You put wrong value:");
	}
	else {
		_mony = mony;
	}
}

int User::know_mony()const
{
	return _mony;
}
	
void User::set_debt(const int mony)
{
	_debt += mony;
}

int User::get_debt()const
{
	return _debt;
}

int User::get_ID()const
{
	return _ID;
}

std::ostream& operator<<(std::ostream& of, const User& obj)
{
	of << "Name: " << obj._name << std::endl;
	of << "Surname: " << obj._surname << std::endl;
	of << "Age: " << obj._age << std::endl;
	of << "Adres: "<< obj._adres << std::endl;
	return of;
}

User& User::operator=(const User& oth)
{
	this -> _name = oth._name;
	this -> _surname = oth._surname;
	this -> _adres = oth._adres;
	this -> _debt = oth._debt;
	this -> _mony = oth._mony;
	this -> _age = oth._age;
	return *this;
}
bool User::operator==(const User& oth)
{
	if (this -> get_ID() == oth.get_ID())
	{
		return true;
	}
	return false;
}
