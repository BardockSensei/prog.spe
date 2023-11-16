#include "Personnage.h"

// Définition complète du constructeur
Personnage::Personnage(std::string nomPerso, int viePerso)
    :nom(nomPerso), vie(viePerso){};

std::string Personnage::stat() {
    return ">> Personnage : " + this->nom + "\n>> Vie : " + std::to_string(this->vie);
}

void Personnage::operator<<(Personnage& autres) {
    this->vie += autres.vie;
}

void Personnage::operator++() {
    this->vie += 10;
}