#include "Personnage.h"
#include "Magicien.h"

// constructeur magicien qui utilise le constructeur de son parent, Personnage, pour gagner en temps/efficacité
Magicien::Magicien(std::string nomMage, int vieMage, int manaMage)
    :Personnage(nomMage, vieMage), mana(manaMage){};

int Magicien::get_mana() {
    return mana;
}

std::string Magicien::stat() {
    std::string s = Personnage::stat();
    return "[Magicien]\n" + s + "\nmana : " + std::to_string(get_mana());
}

void Magicien::changeVie(int vie) {
    std::cout << "[En mode Magicien]\n";
    Personnage::changeVie(vie);
}