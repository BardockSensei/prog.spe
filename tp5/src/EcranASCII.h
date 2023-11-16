#ifndef  ECRAN_HEADER
#define ECRAN_HEADER
#include <string>
#include <vector>

class EcranASCII {
public:
  enum TypePixels {Balle, Fond};

private:
  std::vector<TypePixels> monMatAffichage;
  std::string monSousTitre = "";
  std::string monSurTitre = "";

public:
  std::string monSymboleBord = "\033[1;47m  \033[0m";
  std::string monSymboleFond = "\033[1;43m  \033[0m";
  std::string monSymboleBalle = "\033[1;46m  \033[0m";

  int monLargeur;
  int monHauteur;
  EcranASCII(int largeur, int hauteur);

  void reglePixel (int i, int j, TypePixels val);
  void rafraichir();
  void regleSousTitre(std::string s);
  void regleSurTitre(std::string s);
  
};

#endif
