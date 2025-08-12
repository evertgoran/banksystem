#include <iostream>
#include "clear_console.h"
#include "./menu_components/register.h"

int show_menu() {

	std::cout << "\n";
	std::cout << "Welcome to East Street Bank!" << '\n';
	std::cout << "Menu: " << '\n';
	std::string menuOptions[10] = {
		"Register",
		"Log in",
		"Log out",
		"Create account",
		"Show account information",
		"Deposit", 
		"Withdrawal",
		"Transfer between accounts",
		"Transfer history",
		"Exit"
	};
	int menuSize = sizeof(menuOptions) / sizeof(menuOptions[0]);

	for (int i = 0; i < menuSize; i++) {
		std::cout << (i + 1) << ". " << menuOptions[i] << '\n';
	}
	std::cout << "\n";
	int choice = 0;
	std::cout << "Choice: ";
	std::cin >> choice;
	


	/*if (choice > 10 || choice < 1) {
		std::cout << "Invalid choice" << "\n";
	}*/
	clear_console();

	switch (choice) {
		case 1:
			show_register();
			break;
		case 2:
			//Log in/out();
			break;
		case 3:
			//create_account();
			break;
		case 4:
			//show_account_info();
			break;
		case 5:
			std::cout << "New stage" << "\n";
			//deposit();
			break;
		case 6:
			//withdrawal();
			break;
		case 7:
			//transfer();
			break;
		case 8:
			//transfer_history();
			break;
		default:
			std::cout << "Invalid choice... Try again!" << "\n";
			break;
	}

	return choice;
}