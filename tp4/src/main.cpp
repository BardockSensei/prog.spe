#include "Personnage.h"

int main() {
    std::cout << "Exercice 4.1 (Première classe)" << std::endl;
    
    Personnage p0 = Personnage("Mendoza", 20);
    Personnage p1 = Personnage("Pedro", 18);
    Personnage p2 = Personnage("Sancho", 18);

    std::cout << p0.stat() << std::endl << std::endl;
    std::cout << p1.stat() << std::endl << std::endl << p2.stat() << std::endl << std::endl;

    /* Question 6 : Non, ça ne marche pas car il y a une erreur d'encapsulation
    par défaut, C++ met les attributs en private ... */
    
    p0 << p1;
    p0 << p2;
    std::cout << "Après opérateur << :\n" + p0.stat() << std::endl;
    

    std::cout << "Exercice 4.3 (Compte Bancaire)" << std::endl;
    
    return EXIT_SUCCESS;
}