#include "EcranASCII.h"
#include <iostream>


EcranASCII::EcranASCII(int largeur, int hauteur){
  // Question 1.2
  // Constructeur doit initialiser l'écran en fonction de la largeur
  // et hauteur et initialiser l'écran à partir du symbole de fond
  // Trois attributs à initialiser: monHauteur, monLargeur et monMatAffichage


  
}

void
EcranASCII::regleSousTitre(std::string s){
  monSousTitre = s;
}

void
EcranASCII::regleSurTitre(std::string s){
  monSurTitre = s;
}

void
EcranASCII::reglePixel(int i, int j, EcranASCII::TypePixels val){
  // Doit mettre à jour la valeur du pixel
  
}


void
EcranASCII::rafraichir(){
  std::system("clear");
  std::cout << monSousTitre << std::endl;
  for (auto i = 0; i <monLargeur+2; i++){
    std::cout << monSymboleBord;
  }
  std::cout<< std::endl;
  for (auto i = 0; i <monHauteur; i++){
    std::cout << monSymboleBord;
    for (auto j = 0; j <monLargeur; j++){
      unsigned int index = (monHauteur-i-1)*monLargeur+j;
      EcranASCII::TypePixels estAllume = monMatAffichage[index];
      switch (estAllume) {
        case EcranASCII::TypePixels::Fond:
          std::cout<< monSymboleFond;
          break;
        case EcranASCII::TypePixels::Balle:
          std::cout<< monSymboleBalle;
          break;
        default:
          break;
      }
    }
    std::cout << monSymboleBord<<std::endl;
  }
  for (auto i = 0; i <monLargeur+2; i++){
    std::cout << monSymboleBord;
  }
  std::cout<< std::endl;
  std::cout << monSurTitre << std::endl;
  
}



