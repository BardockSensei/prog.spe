#include "calculatrice.h"

void displayStack(const std::vector<double>& vect) {
	std::string border = "\033[1;47m  \033[0em";
	std::string line = "\033[1;47m    \033[0m"; 
	std::cout << line << std::endl;
	for (int i = 0; i < 5; i++) {
		std::cout << border << 5 - i - 1 << ":";
		std::cout.width(18);
		// Attention, il faut se d�barasser du unsigned int / vect.size()
		if ((int) vect.size() - 5 + i >= 0) {
			std::cout << vect[vect.size() - 5 + i] << border << std::endl;
		}
		else {
			std::cout << "--" << border << std::endl;
		}
	}
	std::cout << line << std::endl;
}
/*
l'erreur est classique :,vect.size() est un unsigned int, donc si on fait - 5 + i, 
erreur, problème, si la taile est a 2, 3 (ou, plus)
*/

void empiler(const std::vector<double>& vect, int valeur) {

}

void operateur_test(std::string str) {

}