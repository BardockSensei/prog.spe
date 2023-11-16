#include "tp3.h"

// Exercice 3.1 (Base des vecteurs)
void exo3_1() {
	std::vector<int> v1;
	v1.push_back(19);
	v1.push_back(7);
	v1.push_back(2002);

	/*std::cout << v1.back() << std::endl;
	std::cout << v1[0] << std::endl;*/

	std::cout << "v1 : [";
	for (auto elt : v1) {
		std::cout << elt;
		if (elt != v1.back()) {
			std::cout << ", ";
		}
	}
	std::cout << "] (taille = " << v1.size() << ") \n" << std::endl;

	std::vector<std::string> v2 = { "Alphone", "Bernard", "Charlie", "Didier", "Eleonore", "Fanny" };
	for (int i = 0; i < v2.size(); i++) {
		std::cout << "v2[" << i << "] = " << v2[i] << std::endl;
	}
}

/*
	Exercice 3.2 (Fonctions et vecteurs)
	Exercice 3.3 (Fonctions et vecteurs)
*/
int calculNombreChiffre(int n) {
	int cpt = 0;

	if (n == 0) {
		return 1;
	}

	while (n != 0) {
		n /= 10;
		cpt++;
	}

	return cpt;
}

int calculLargeurMax(std::vector<std::string> v) {
	int largeurMax = v[0].length();
	for (int i = 1; i < v.size(); i++) {
		if (v[i].length() > largeurMax) {
			largeurMax = v[i].length();
		}
	}
	return largeurMax;
}

void afficheVecteur(std::vector<std::string> v, bool affIndice) {
	int cnt = 0, cadre = 0, largeurMax = calculLargeurMax(v);

	// Op�rateur ternaire, bien pratique je trouve ...
	(affIndice) ? cadre = largeurMax + 11 : cadre = largeurMax + 4;

	for (int i = 0; i < cadre; i++) {
		std::cout << "-";
	}
	printf("\n");

	for (int j = 0; j < v.size(); j++) {
		std::cout << "| ";
		if (affIndice) {
			std::cout << "v[" << j << "] = ";
			cnt += calculNombreChiffre(j) + 6;
		}
		std::cout << v[j];
		cnt += v[j].length() + 2;

		// adapter les espaces apr�s le mot
		while (cnt < cadre - 1) {
			std::cout << " ";
			cnt++;
		}
		std::cout << "|" << std::endl;
		cnt = 0;
	}

	for (int k = 0; k < cadre; k++) {
		std::cout << "-";
	}
	printf("\n");
}

void exo3_2() {
	std::vector<std::string> v = { "Alfred", "Bruno", "Charlotte", "Damien", "Ernestine", "Florian" };
	afficheVecteur(v);
	printf("\n");

	//afficheVecteur(v, true);
	//printf("\n");

	v.push_back("Florentinus");
	afficheVecteur(v, true);
}

// Exercice 3.4 (Passage en param�tre des vecteurs)
void testParamCopie(int i) {
	i = 42;
}

void testParamRef(int& i) {
	i = 42;
}

void testVecteurCopie(std::vector<int> v) {
	v[8] = 88;
}

void testVecteurRef(std::vector<int>& v) {
	v[8] = 88;	
}


void exo3_4_v1() {
	int x = 3, y = 7;
	std::cout << "Passage par reference :" << std::endl;
	std::cout << "valeur de x avant : " << x << std::endl;
	testParamRef(x);
	std::cout << "valeur de x apres : " << x << "\n" << std::endl;

	std::cout << "Passage par copie :" << std::endl;
	std::cout << "valeur de y avant : " << y << std::endl;
	testParamCopie(y);
	std::cout << "valeur de y apres : " << y << std::endl;
}

void exo3_4_v2() {
	std::vector<int> v;
	for (int i = 0; i < 100000; i++) {
		v.push_back(i);
	}
	std::cout << "Passage par copie :" << std::endl;
	std::cout << "valeur de v[8] avant : " << v[8] << std::endl;
	auto start = std::chrono::high_resolution_clock::now();
	testVecteurCopie(v);
	auto stop = std::chrono::high_resolution_clock::now();
	std::cout << "valeur de v[8] apres : " << v[8] << std::endl;
	std::cout << "temps par copie : " << (stop - start).count() << std::endl;

	std::cout << "\nPassage par reference :" << std::endl;
	std::cout << "valeur de v[8] avant : " << v[8] << std::endl;
	start = std::chrono::high_resolution_clock::now();
	testVecteurRef(v);
	stop = std::chrono::high_resolution_clock::now();
	std::cout << "valeur de v[8] apres : " << v[8] << std::endl;
	std::cout << "temps par reference : " << (stop - start).count() << std::endl;
}



