/*
    Programmation de spécialité - C++
    Séance 3 - 19/10/2023
    Séance 4 - 26/10/2023
    Auteur : Guillaume Hostache
*/

#include <iostream>
#include "exo2_1.h"
#include "exo2_2.h"
#include "exo2_3.h"

int main() {
    std::cout << "Exercice (entree/sortie fichier) :" << std::endl;
    exo2_1a();
    //exo2_1b();
    //exo2_1c();
    std::cout << "\nExercice (generations d'images) :" << std::endl;
    //exo2_2a();
    exo2_2b();
    //exo2_2c();
    std::cout << "\nExercice (manipulations d'images) :" << std::endl;
    //exo2_3a();
    //exo2_3b();
    exo2_3c();
    std::cout << "\nExercice (filtres d'images) :" << std::endl;
    // TODO : Bonus
    return EXIT_SUCCESS;
}