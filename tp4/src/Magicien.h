#include "Personnage.h"

class Magicien : public Personnage {
    public:
        Magiciel(std::string nom, int vie, int mana);
        int get_mana();
    protected:
        int mana;
}