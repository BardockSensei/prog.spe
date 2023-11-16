#pragma once
#include "Personnage.h"

/* De façon générale : 
class A : class B - classe A hérite de classe B */

class Magicien : public Personnage {
protected:
    int mana;

public:
    Magicien(std::string nom, int vie, int mana);
    int get_mana();
    std::string stat();
    void changeVie(int vie);
};