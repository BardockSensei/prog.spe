#include "Personnage.h"
#include "CompteBancaire.h"
#include "Magicien.h"

void simulationCombat(Personnage &p1, Personnage &p2) {
    std::cout << "Début combat" <<std::endl;
    int vie = 
}

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
    std::cout << "Après opérateur << :\n" + p0.stat() << std::endl;
    
    ++p2;
    std::cout << "Après opérateur ++ :\n" + p2.stat() << std::endl;
    
    p1.changeVie(28);
    std::cout << "Appel changeVie :\n" + p1.stat() << std::endl;
    p2.changeVie(-6);
    std::cout << "Appel changeVie :\n" + p2.stat() << std::endl;

    // pas très utile ici
    //std::cout << "Destructeur Mendoza" << std::endl;
    //delete p0;

    std::cout << "\nExercice 4.3 (Compte Bancaire)" << std::endl;
    CompteBancaire cb = CompteBancaire("Guillaume", 19072002, 35);
    std::cout << cb.consulterSolde() << std::endl;

    cb.deposerArgent(1465);
    cb.retirerArgent(500.0);

    std::cout << "\nAprès opérations : \n" << cb.consulterSolde() << std::endl;
    
    std::cout << "\nExercice 4.4 (Analyse de code et polymorphisme)" << std::endl;
    Magicien gandalf = Magicien("Gandalf le Gris", 185, 300);
    Personnage aragorn = Personnage("Aragorn", 225);

    std::cout << gandalf.stat() << std::endl;
    std::cout<< aragorn.stat() << std::endl;
    return EXIT_SUCCESS;
}