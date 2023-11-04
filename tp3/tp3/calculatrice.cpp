#include "calculatrice.h"

void displayStack(const std::vector<double>& vect) {
	std::string border = "\033[1;47m \033[0em";
	std::string line = "\033[1;47m                         \033[0m"; // ? 
	std::cout << line << std::endl;
	for (int i = 0; i < 5; i++) {
		std::cout << border << 5 - i - 1 << ":";
		std::cout.width(18);
		if ((i < 5) && (vect.size() - 5 + i >= 0)) {
			std::cout << vect[vect.size() - 5 + i] << border << std::endl;
		}
		else {
			std::cout << "--" << border << std::endl;
		}
	}
	std::cout << line << std::endl;
}