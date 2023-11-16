#include "CompteBancaire.h"

// Constructeur de la classe
CompteBancaire::CompteBancaire(std::string nomClient, int numeroCompte, int soldeCompte) {
    this->nomClient = nomClient;
    this->numeroCompte = numeroCompte;
    this->soldeCompte = soldeCompte;
}
    
// Accesseurs : getter et setter 
void CompteBancaire::setNomClient(std::string nouveauNomClient) {
    this->nomClient = nouveauNomClient;
}

void CompteBancaire::setNumeroCompte(int nouveauNumeroCompte) {
    this->numeroCompte = nouveauNumeroCompte;
}

void CompteBancaire::setSoldeCompte(double nouveauSoldeCompte) {
    this->soldeCompte = nouveauSoldeCompte;
}

std::string CompteBancaire::getNomClient() {
    return this->nomClient;
}

int CompteBancaire::getNumeroCompte() {
    return this->numeroCompte;
}

double CompteBancaire::getSoldeCompte() {
    return this->soldeCompte;
}

// autres méthodes
void CompteBancaire::deposerArgent(double montant) {
    double solde = getSoldeCompte();
    solde += montant;
    setSoldeCompte(solde);
}

void CompteBancaire::retirerArgent(double montant) {
    double solde = getSoldeCompte();
    solde -= montant;
    setSoldeCompte(solde);
}

std::string CompteBancaire::consulterSolde() {
    return "Bonjour " + getNomClient() + "\nNuméro compte : " + std::to_string(getNumeroCompte())
    + "\nSolde Actuelle de votre compte : " + std::to_string(getSoldeCompte());
}