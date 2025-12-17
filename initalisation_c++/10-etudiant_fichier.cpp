#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Definition de la structure Etudiant
struct Etudiant
{
    string nom;
    string matricule;
    int age;
    float moyenne;
};

// Fonction pour enregistrer les etudiants dans un fichier
void enregistrerEtudiants()
{
    ofstream fichier("etudiants.txt", ios::app); // ouverture en ajout

    if (!fichier)
    {
        cout << "Erreur d'ouverture du fichier." << endl;
        return;
    }

    Etudiant e;
    char continuer;
    
    cin.ignore();

    do
    {
        cout << "\nNom : ";
	getline(cin, e.nom);
 
        cout << "\nMatricule : ";
	getline(cin, e.matricule);

        cout << "Age : ";
        cin >> e.age;

        cout << "Moyenne : ";
        cin >> e.moyenne;

        // Ecriture dans le fichier
        fichier << e.nom <<  ";"
                << e.matricule << ";"
                << e.age << ";"
                << e.moyenne << endl;

        cout << "Ajouter un autre etudiant ? (o/n) : ";
        cin >> continuer;
        cin.ignore();

    } while (continuer == 'o' || continuer == 'O');

    fichier.close();
}

// Fonction pour lire et afficher les etudiants depuis le fichier
void afficherEtudiants()
{
    ifstream fichier("etudiants.txt");

    if (!fichier)
    {
        cout << "Aucun fichier trouve." << endl;
        return;
    }

    cout << "\n--- Liste des etudiants enregistres ---" << endl;

    string ligne;
    // Lecture du fichier ligne par ligne
    while (getline(fichier, ligne))
    {
        cout << ligne  << endl;
    }

    fichier.close();
}

int main()
{
    int choix;

    do
    {
        cout << "\n=== MENU ===" << endl;
        cout << "1. Enregistrer des etudiants" << endl;
        cout << "2. Afficher les etudiants" << endl;
        cout << "0. Quitter" << endl;
        cout << "Votre choix : ";
        cin >> choix;

        switch (choix)
        {
            case 1:
                enregistrerEtudiants();
                break;
            case 2:
                afficherEtudiants();
                break;
            case 0:
                cout << "Fin du programme." << endl;
                break;
            default:
                cout << "Choix invalide." << endl;
        }

    } while (choix != 0);

    return 0;
}
