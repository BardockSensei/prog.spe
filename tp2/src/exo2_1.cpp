#include "exo2_1.h"

void exo2_1a() {
    std::cout << "Premiere partie :" << std::endl;

    std::ofstream fichier_sortie;
    // ouverture du fichier en mode écriture
    fichier_sortie.open("fichier_test.txt", std::fstream::out);
    fichier_sortie << "Ouais ouais ouais !" << std::endl;
    fichier_sortie << "on écrit dans notre fichier !" << std::endl;
    fichier_sortie.close();

    std::ifstream fichier_entree;
    std::string contenu = "";
    //ouverture en mode lecture
    fichier_entree.open("fichier_test.txt", std::fstream::in);
    fichier_entree >> contenu;

    std::cout << "Premier mot lu dans le fichier : " << contenu << std::endl;
}

void exo2_1b() {
    std::cout << "\nDeuxieme partie :" << std::endl;
    std::string prenom, nom;
    int age;

    std::cout << "Quel est votre prenom ?" << std::endl; std::cin >> prenom;

    std::cout << "Quel est votre nom ?" << std::endl; std::cin >> nom;

    std::cout << "Quel est votre age ?" << std::endl; std::cin >> age;

    std::ofstream fichier_sortie;
    fichier_sortie.open("mon_fichier.txt", std::fstream::out);
    fichier_sortie << "Bonjour " + prenom + " " + nom + " !" << std::endl;;
    fichier_sortie << "Vous avez " << age << " ans !\n";
    fichier_sortie.close();

    std::cout << "Bravo ! Regarde le fichier texte maintenant ..." << std::endl;
}

int exo2_1c() {
    std::cout << "\nDerniere partie :" << std::endl;
    std::string nom_fichier;
    char caractere;

    std::cout << "Entrez un nom de fichier : "; std::cin >> nom_fichier;

    std::ifstream fichier;
    fichier.open(nom_fichier, std::fstream::in);
    // petite gestion d'erreur
    if (!fichier.is_open()) {
        return -1;
    }
    // lecture intégrale du fichier, caractère par caractère
    while (fichier.get(caractere)) {
        std::cout << caractere;
    }
    fichier.close();

    return 0;
}