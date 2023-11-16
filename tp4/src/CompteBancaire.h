#pragma once
#include <iostream>
#include <string>

// Prototype de notre classe
class CompteBancaire {
protected:
    // Attributs
    std::string nomClient;
    int numeroCompte; 
    double soldeCompte;

public:
    // Constructeur de la classe
    CompteBancaire(std::string nomClient, int numeroCompte, int soldeCompte);
    
    // Accesseurs : getter et setter 
    void setNomClient(std::string nouveauNomClient);
    void setNumeroCompte(int nouveauNumeroCompte);
    void setSoldeCompte(double nouveauSoldeCompte);

    std::string getNomClient();
    int getNumeroCompte();
    double getSoldeCompte();

    // autres méthodes
    void deposerArgent(double montant);
    void retirerArgent(double montant);

    std::string consulterSolde();
};