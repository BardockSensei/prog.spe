#pragma once
#include <iostream>
#include <string>

// Prototype de notre classe
class Personnage {
    // Attributs
    std::string nom; 
    int vie; 

public:
    // Constructeur de la classe
    Personnage(std::string nom, int vie);

    std::string stat();

    void operator<<(Personnage& autres);

    void operator++();

    // Question n°9
    //std::ostream& operator<<(std::ostream& os, const Personnage& perso);

    void changeVie(int vie);

    //Destructeur de la classe
    //~Personnage();
};