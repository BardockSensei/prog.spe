/*
    Programmation de spécialité - C++
    Séance 2 - 05/10/2023
    Auteur : Guillaume Hostache
*/

#include <iostream>
#include <string>
#include <limits>
#include <time.h>
#include<vector>

// limite du nombre de tentatives autorisés pour l'exercie 1.3 (Juste Prix)
const int limite = 10;

void exo1_1()
{
    std::cout << "Bienvenue Guillaume !" << std::endl;
    int nb1 = 19;
    double nb2 = 7.2002;
    std::string chaine = "Ceci est une chaine de caractere !";

    printf("Mon entier : %d\n", nb1);
    std::cout << "Mon double : " << nb2 << std::endl;
    std::cout << "Voila : " << chaine << std::endl;

    std::cout << "\nint type [" << std::numeric_limits<int>::min() << "; ";
    std::cout << std::numeric_limits<int>::max() << "]" << std::endl;

    std::cout << "float type [" << std::numeric_limits<float>::min() << "; ";
    std::cout << std::numeric_limits<float>::max() << "]" << std::endl;
}

void exo1_2()
{
    std::string prenom = "";
    std::string etat = "";

    std::cout << "Entrez votre prenom : ";
    std::cin >> prenom;

    std::cout << "Bonjour " << prenom << " ! Comment allez vous ? " << std::endl;
    std::cin >> etat;

    if (etat.compare("bien") == 0)
    {
        std::cout << "Super ! Allons faire du C++ maintenant, ca va etre le fun !" << std::endl;
    }
    else if (etat.compare("bof") == 0)
    {
        std::cout << "Allez courage ! On va quand meme faire du C++ parce qu'il y a pas trop le choix !" << std::endl;
    }
}

// recherche une valeur dans un vecteur d'entier, retourne vrai ou faux ...
bool recherche(int valeur, std::vector<int> tableau)
{
    for (int i = 0; i < tableau.size(); i++)
    {
        if (tableau.at(i) == valeur)
        {
            return true;
        }
    }
    return false;
}

// Jeu du juste prix, trop bien !
void exo1_3()
{
    int proposition, nb_secret, nb_tentatives = limite, difficulte, cnt = 0;
    std::vector<int> propositions(limite);

    // nb secret aléatoire entre [0; 100]
    srand((unsigned int)time(NULL));
    nb_secret = (rand() % 100) + 1;

    std::cout << "Choix de la difficulte : Entrez 0 (Normal) ou 1 (Difficile)" << std::endl;
    std::cin >> difficulte;

    do
    {
        std::cout << "(" << nb_tentatives << " tentatives) Entrez un nombre entier positif : ";
        std::cin >> proposition;

        if (nb_tentatives != limite && recherche(proposition, propositions))
        {
            std::cout << "Attention, tu te repetes ..." << std::endl;
        }
        else
        {
            propositions.push_back(proposition);
            nb_tentatives--;

            if (difficulte == 1 && cnt == 2)
            {
                // On ment ...
                if (proposition > nb_secret) {
                    std::cout << "Votre nombre est trop petit ..." << std::endl;
                }
                else if (proposition < nb_secret) {
                    std::cout << "Votre nombre est trop grand ..." << std::endl;
                }
                cnt = 0;
            }
            else
            {
                if (proposition > nb_secret) {
                    std::cout << "Votre nombre est trop grand ..." << std::endl;
                }
                else if (proposition < nb_secret) {
                    std::cout << "Votre nombre est trop petit ..." << std::endl;
                }
                /* Il sera incrémenté peut importe la difficulté mais
                il n'aura d'utilité que dans la difficulté (1) */
                cnt++;
            }
        }
    } while (proposition != nb_secret && nb_tentatives != 0);

    if (nb_tentatives >= 7) {
        std::cout << "Vous etes exceptionnel !" << std::endl;
    }
    else if (nb_tentatives >= 3) {
        std::cout << "Pas trop mal, bonne strategie ..." << std::endl;
    }
    else if (nb_tentatives > 0) {
        std::cout << "Peut mieux faire ..." << std::endl;
    }
    else {
        std::cout << "Desole, tu n'as pas reussi ..." << std::endl;
        std::cout << "Le nombre secret etait : " << nb_secret << std::endl;
    }
}

bool estNombrePremier(int n)
{
    if (n == 0 || n == 1)
    {
        return false;
    }

    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

void exo1_4()
{
    int nb;
    std::cout << "Entrez un nombre entier positif :";
    std::cin >> nb;
    bool estPremier = estNombrePremier(nb);

    // opérateur ternaire
    (estPremier) ? printf("Votre nombre %d est premier !\n", nb) : printf("Votre nombre %d n'est pas premier !\n", nb);
    std::cout << "\nListe des nombres premiers compris entre 1 et 100 : \n{ ";
    for (int i = 0; i <= 100; i++)
    {
        if (estNombrePremier(i))
        {
            std::cout << i << " ";
        }

    }
    std::cout << "}" << std::endl;
}

void exo1_5()
{
    std::string num_insee, nom;

    std::cout << "Entrez votre numero insee :";
    std::cin >> num_insee;
    if (num_insee[0] == '1')
    {
        std::cout << "Vous etes un homme ne en 19" << num_insee[1] << num_insee[2]<< std::endl;
    }
    else
    {
        std::cout << "Vous etes une femme nee en 19" << num_insee[1] << num_insee[2] << std::endl;
    }

    std::cout << "Entrer votre nom : ";
    std::cin >> nom;

    for (int i=0; i < nom.length(); i++) 
    {
        std::cout << " " << nom[i] ;
    }
    
    std::cout << "\n";
    for (int i = 0; i < nom.length(); i++) 
    {
        for(int j = 0; j < i; j++) 
        {
            std::cout << " ";
        }
        std::cout << nom[i];
    }

    std::cout << "\n";
    for (int i = 0; i < nom.length(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            std::cout << " ";
        }
        std::cout << nom[i] <<"\n";
    }
}


int main()
{
    std::cout << "Exercice 1.1 :" << std::endl;
    exo1_1();
    std::cout << "\nExercice 1.2 :" << std::endl;
    //exo1_2();
    std::cout << "\nExercice 1.3 :" << std::endl;
    //exo1_3();
    std::cout << "\nExercice 1.4 :" << std::endl;
    //exo1_4();
    std::cout << "\nExercice 1.5 :" << std::endl;
    //exo1_5(); 

    return EXIT_SUCCESS;
}