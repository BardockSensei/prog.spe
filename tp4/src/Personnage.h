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

    friend std::ostream& operator<<(std::ostream& os, const Personnage& perso);
};