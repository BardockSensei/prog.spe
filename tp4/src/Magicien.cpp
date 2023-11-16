#include "Personnage.h"
#include "Magicien.h"

Magicien::Magicien(std::string nomMage, int vieMage, int manaMage):
    Personnage(nomMage, vieMage), mana(manaMage){};

int Magicien::get_mana() {
    return mana;
}