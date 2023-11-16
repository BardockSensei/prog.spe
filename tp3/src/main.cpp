/*
    Programmation de spécialité - C++
    Séance 4 - 26/10/2023
    Auteur : Guillaume Hostache
*/

#include <iostream>
#include "tp3.h"
#include "calculatrice.h"

int main()
{
    std::cout << "Exercice 3.1 (Base des vecteurs)" << std::endl;
    exo3_1();
    std::cout << "\nExercice 3.2, 3.3 (Fonctions et vecteurs)" << std::endl;
    exo3_2();
    std::cout << "\nExercice 3.4 (Passage en parametre des vecteurs)" << std::endl;
    exo3_4_v1();
    std::cout << "\nExperience sur vecteur d'entier" << std::endl;
    exo3_4_v2();
    std::cout << "\nExercice 3.5 (Calculatrice)" << std::endl;
    // todo : à finir
    std::vector<double> maPile = { 1.0, 2.0, 3.0 };
    displayStack(maPile);

    return EXIT_SUCCESS;
}
