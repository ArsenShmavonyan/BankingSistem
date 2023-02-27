#include <iostream>

#include "User.h"
#include "Bank.h"

int main ()
{
	Bank bank;
	User user1("Karen", "Manukyan", "Kentron", 30);
	User user2("Vazgen", "Nikoxosyan", "Komitas", 32);
	bank.set_user(user1);
	bank.set_user(user2);
	bank.give_debt(user1, 2000);
	bank.take_mony(user1, 2000);
	std::cout << user1;	
}
