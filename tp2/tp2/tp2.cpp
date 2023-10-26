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

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include "stb_image.h"
#include "stb_image_write.h"

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

// manipulation d'images
void exo2_p5() {
    int width, height, channels;
    unsigned char* img = stbi_load("lena.png", &width, &height, &channels, 0);

    std::cout << "Dimension de l'image : (" << width << ", " << height << ")" << std::endl;
    std::cout << "Nombres de cannaux : " << channels << std::endl;
    
    stbi_write_png("lena_a.png", width, height, channels, (void*)img, 0);
    stbi_image_free(img);

    unsigned char* lena_b = stbi_load("lena.png", &width, &height, &channels, 0);
    for (int i = height / 3; i < 2 * (height / 3); i++) {
        for (int j = width / 3; j < 2 * (width / 3); j++) {
            int ipixel = (i * width + j) * channels;
            lena_b[ipixel] = 0;
            lena_b[ipixel + 1] = 0;
            lena_b[ipixel + 2] = 0;
        }
    }
    stbi_write_png("lena_b.png", width, height, channels, (void*)lena_b, 0);
    stbi_image_free(lena_b);

    unsigned char* lena_c = stbi_load("lena.png", &width, &height, &channels, 0);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            int ipixel = (i * width + j) * channels;
            int moyenne = (lena_c[ipixel] + lena_c[ipixel + 1] + lena_c[ipixel + 2] + lena_c[ipixel + 3]) / 4;
            if (100 < moyenne && moyenne < 150) {
                lena_c[ipixel] = 255;
                lena_c[ipixel + 1] = 255;
                lena_c[ipixel + 2] = 255;
                lena_c[ipixel + 3] = 255;
            }
        }
    }
    stbi_write_png("lena_c.png", width, height, channels, (void*)lena_c, 0);
    stbi_image_free(lena_c);
}

int main()
{
    std::cout << "Exercice (entree/sortie fichier) :" << std::endl;
    //exo2_p1();
    //exo2_p2();
    //exo2_p3();
    std::cout << "\nExercice (generations d'images) :" << std::endl;
    //exo2_p4();
    std::cout << "\nExercice (manipulations d'images) :" << std::endl;
    exo2_p5(); // fini
    std::cout << "\nExercice (filtres d'images) :" << std::endl;
    // bonus
    return EXIT_SUCCESS;
}
