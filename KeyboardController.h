// KeyboardController.h

#ifndef KEYBOARDCONTROLLER_H
#define KEYBOARDCONTROLLER_H
#include <iostream>
#include <string>
#include "Subject.h"

class KeyboardController: public Subject {
public:
	explicit KeyboardController() {}
	~KeyboardController() {}

	void start();							// start the loop to get user commands
	std::string getCommand() const;			// return the command

private:
	std::string cmd_;
};

inline void
KeyboardController::start() {
	std::string line;
	char c;
	std::cout << "Input a command:" << std::endl;
	while (std::getline(std::cin, line)) {
		c = line[0];
		if (c == 's') {
			cmd_ = "start";
		} else if (c == 'h') {
			cmd_ = "halt";
		} else if (c == 'r') {
			cmd_ = "reset";
		} else {
			continue;
		}
		notify();
	}
}

inline std::string
KeyboardController::getCommand() const {
	return cmd_;
}
#endif