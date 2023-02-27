#ifndef User_h
#define User_h

#include <iostream>

class User
{
public:
	User(std::string,std::string,std::string,int);
public:
	void set_mony(const int);
	void set_debt(const int);
	int know_mony()const;
	int get_ID()const;
	int get_debt()const;
public:
	bool operator==(const User&);
	User& operator=(const User&);
	friend std::ostream& operator<<(std::ostream&, const User&);
private:
	std::string _name;
	std::string _surname;
	std::string _adres;
	int _age;
	int _ID;
	int _mony;
	int _debt; //partq
};

#endif // USER_H
