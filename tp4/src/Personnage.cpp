#include "Personnage.h"

// Définition complète du constructeur
Personnage::Personnage(std::string nomPerso, int viePerso)
    :nom(nomPerso), vie(viePerso){};

std::string Personnage::stat() {
    return "[Personnage]\n" + this->nom + "\n Vie : " + std::to_string(this->vie);
}

void Personnage::operator<<(Personnage& autres) {
    this->vie += autres.vie;
}

void Personnage::operator++() {
    this->vie += 10;
}

void Personnage::changeVie(int vie) {
    if (vie < 0) {
        std::wcout << "Erreur, on ne peut pas ajouter une valeur négatif" << std::endl;
    } else {
        std::cout << "pas de soucis" << std::endl;
        this->vie = vie;
    }
}
/*
Personnage::~Personnage() {
    std::cout << "Destruction en cours \n";
}*/