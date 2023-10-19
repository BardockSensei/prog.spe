/*
    Programmation de spécialité - C++
    Séance 3 - 19/10/2023
    Auteur : Guillaume Hostache
    état d'avancement : Exercice 2, question 3 (générer le .PPM avec toute les couleurs)
*/

#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <time.h>


const int TAILLE = 255;

void exo1_v1() {
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

    std::cout << "premier mot lu dans le fichier : " << contenu << std::endl;
}

void exo1_v2() {
    std::cout << "Deuxieme partie :" << std::endl;
    int age;
    std::string prenom, nom;
   
    std::cout << "Quel est votre prenom ?" << std::endl;
    std::cin >> prenom;

    std::cout << "Quel est votre nom ?" << std::endl;
    std::cin >> nom;

    std::cout << "Quel est votre age ?" << std::endl;
    std::cin >> age;

    std::ofstream fichier_sortie;
    fichier_sortie.open("mon_fichier.txt", std::fstream::out);
    fichier_sortie << "Bonjour " + prenom + " " + nom + " !" << std::endl;;
    fichier_sortie << "Vous avez " << age << " ans !\n";
    fichier_sortie.close();

    std::cout << "Bravo ! Regarde le fichier texte maintenant ..." << std::endl;
}

// TODO : ajouter la gestion d'erreur ...
void exo1_v3() {
    std::cout << "Derniere partie :" << std::endl;
    std::string nom_fichier;

    std::cout << "Entrez un nom de fichier : ";
    std::cin >> nom_fichier;

    std::ifstream fichier;
    fichier.open(nom_fichier, std::fstream::in);
    // lecture du contenu du fichier en entier
    // caractère par caractère ...
    char caractere;
    while (fichier.get(caractere)) {
        std::cout << caractere;
    }

    fichier.close();
}

void exo2_1() {
    std::ofstream img_1;
    img_1.open("image_1.PGM", std::fstream::out);
    img_1 << "P2" << std::endl;
    img_1 << TAILLE << " " << TAILLE << std::endl;
    img_1 << "255" << std::endl;
    for (int i = 0; i < TAILLE; i++) { // Pour chaques colonnes
        for (int j = 0; j < TAILLE; j++) { // pour chaques lignes
            img_1 << j << " "; 
        }
        img_1 << std::endl;
    }
    img_1.close();

    std::ofstream img_2;
    img_2.open("image_2.PGM", std::fstream::out);
    img_2 << "P2" << std::endl;
    img_2 << TAILLE << " " << TAILLE << std::endl;
    img_2 << "255" << std::endl;
    // Pour chaques colonnes
    for (int i = 0; i < TAILLE; i++) {
        for (int j = 0; j < TAILLE; j++) {
            img_2 << std::to_string(255 - (int)(sqrt( (i - 128)*(i - 128) + (j - 128)*(j - 128) ))) + " ";
        }
        img_2 << std::endl;
    }
    img_2.close();
    /*
    std::ofstream img_3;
    img_3.open("image_3.PPM", std::fstream::out);
    img_3 << "P3" << std::endl;
    img_3 << TAILLE << " " << TAILLE << std::endl;
    img_3 << "255" << std::endl;
    // Pour chaques colonnes
    for (int i = 0; i < TAILLE; i++) {
        for (int j = 0; j < TAILLE; j++) {
            img_3 << i + " " + j + std::to_string(255 - (int)(sqrt((i - 128) * (i - 128) + (j - 128) * (j - 128))));
        }
        img_3 << std::endl;
    }
    img_3.close();
    */
}   

int main()
{
    std::cout << "Exercice 1" << std::endl;
    exo1_v1();
    exo1_v2();
    exo1_v3();
    std::cout << "Exercice 2" << std::endl;
    exo2_1();
    return EXIT_SUCCESS;
}
