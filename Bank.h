#ifndef Bank_h
#define Bank_h

#include <iostream>
#include <map>
#include <vector>

#include "User.h"

class Bank
{
public:
	Bank();
	Bank(const int);//set mony
public:
	void set_user(const User&);
	void set_mony(const int);
	int get_mony()const;
public:
	void give_debt(User&, int);
	void take_mony(User&, int);
private:
	std::vector<User> _users;
	std::map<int, int> _debt; // partq 
	int _mony;
};

#endif // Bank_h
