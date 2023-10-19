/*
    Programmation de spécialité - C++
    Séance 3 - 19/10/2023
    Auteur : Guillaume Hostache
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <time.h>

// Taille des images que l'on génère pour le début de l'exercice 2
const int TAILLE = 255;

void exo2_p1() {
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

void exo2_p2() {
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

int exo2_p3() {
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

// génération d'images
void exo2_p4() {
    // image (a)
    std::ofstream img_1;
    img_1.open("image_1.PGM", std::fstream::out);
    img_1 << "P2\n" << TAILLE << " " << TAILLE << "\n" << "255\n";
    
    for (int i = 0; i < TAILLE; i++) { // Pour chaques colonnes
        for (int j = 0; j < TAILLE; j++) { // pour chaques lignes
            img_1 << j << " "; 
        }
        img_1 << std::endl;
    }

    img_1.close();

    // image (b)
    std::ofstream img_2;
    img_2.open("image_2.PGM", std::fstream::out);
    img_2 << "P2\n" << TAILLE << " " << TAILLE << "\n" << "255\n";

    for (int i = 0; i < TAILLE; i++) {
        for (int j = 0; j < TAILLE; j++) {
            // formule de la distance entre deux points
            img_2 << 255 - (int)(sqrt( (i - 128)*(i - 128) + (j - 128)*(j - 128) )) << " ";
        }
        img_2 << std::endl;
    }

    img_2.close();

    std::ofstream img_3;
    img_3.open("image_3.PPM", std::fstream::out);
    img_3 << "P3\n" << TAILLE << " " << TAILLE << "\n" << "255\n";
    
    for (int i = 0; i < TAILLE; i++) {
        for (int j = 0; j < TAILLE; j++) {
            img_3 << i << " " << j << " " << 255 - (int)(sqrt((i - 128) * (i - 128) + (j - 128) * (j - 128))) << std::endl;
        }
    }

    img_3.close();
}   

int main()
{
    std::cout << "Exercice (entree/sortie fichier) :" << std::endl;
    //exo2_p1();
    //exo2_p2();
    //exo2_p3();
    std::cout << "\nExercice (generations d'images) :" << std::endl;
    exo2_p4();
    std::cout << "\nExercice (manipulations d'images) :" << std::endl;
    // à venir
    std::cout << "\nExercice (filtres d'images) :" << std::endl;
    // à venir
    return EXIT_SUCCESS;
}
