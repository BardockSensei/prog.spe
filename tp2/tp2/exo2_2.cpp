#include "exo2_2.h"

void exo2_2a() {
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
}

void exo2_2b() {
    // image (b)
    std::ofstream img_2;
    img_2.open("image_2.PGM", std::fstream::out);
    img_2 << "P2\n" << TAILLE << " " << TAILLE << "\n" << "255\n";

    for (int i = 0; i < TAILLE; i++) {
        for (int j = 0; j < TAILLE; j++) {
            // formule de la distance entre deux points
            img_2 << 255 - (int)(sqrt((i - 128) * (i - 128) + (j - 128) * (j - 128))) << " ";
        }
        img_2 << std::endl;
    }

    img_2.close();
}

void exo2_2c() {
    // image (c)
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