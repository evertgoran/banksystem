#include <iostream>
#include <string>
#include <ios>
#include <limits>


int show_register() {
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::string fullname = "";
	std::string ssn = "";
	std::string user_password = "";
	std::string user_re_password = "";
	
	std::cout << "Enter fullname: ";
	std::getline(std::cin, fullname);
	std::cout << "Enter social security number: ";
	std::cin >> ssn;
	if (ssn.length() == 12) {
		std::cout << "Enter password: ";
		std::cin >> user_password;
		std::cout << "Enter password again: ";
		std::cin >> user_re_password;

		if (user_password == user_re_password) {
			std::cout << fullname << "\n";
			std::cout << ssn << "\n";
			std::cout << user_password << "\n";
			std::cout << user_re_password << "\n";
			return 0;
		}
		std::cout << "Passwords don't match, try again." << "\n";
		show_register();

		
	}
	else {
		std::cout << "Incorrect social security number, try again." << "\n";
		show_register();
	
	}


}

