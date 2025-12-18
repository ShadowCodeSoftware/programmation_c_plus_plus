#include <iostream>

using namespace std;

// Définition de la structure
struct File {
    int elt;              // L'élément (type int)
    File* lien;           // Pointeur vers le nœud suivant
};

// Déclaration des pointeurs pour la file
File* premier = nullptr;  // Pointeur vers le premier élément
File* dernier = nullptr;  // Pointeur vers le dernier élément

// Fonction pour enfiler un élément
void enfiler(File*& dernier, File*& premier, int val) {
    File* E = new File;
    if (E) {
        E->elt = val;
        E->lien = nullptr;
        if (dernier == nullptr) {
            dernier = E;
            premier = dernier;
        } else {
            dernier->lien = E;
            dernier = E;
        }
    }
}

// Fonction pour défiler un élément
void defiler(File*& premier, File*& dernier) {
    File* p = premier;
    if (premier) {
        premier = premier->lien;
        delete p;
        if (premier == nullptr) {
            dernier = nullptr;
        }
    } else {
        cerr << "La file est vide" << endl;
    }
}

// Fonction pour consulter l'élément en début de file (FIFO)
int consulterDebut(File* premier) {
    if (premier == nullptr) {
        cerr << "La file est vide" << endl;
        return -1;  // Valeur par défaut
    } else {
        return premier->elt;
    }
}

// Fonction pour consulter l'élément en fin de file
int consulterFin(File* dernier) {
    if (dernier == nullptr) {
        cerr << "La file est vide" << endl;
        return -1;  // Valeur par défaut
    } else {
        return dernier->elt;
    }
}

// Fonction pour afficher la file
void afficherFile(File* premier) {
    File* courant = premier;
    cout << "File: ";
    while (courant != nullptr) {
        cout << courant->elt << " -> ";
        courant = courant->lien;
    }
    cout << "NULL" << endl;
}

// Fonction pour obtenir la taille de la file
int tailleFile(File* premier) {
    int taille = 0;
    File* courant = premier;
    while (courant != nullptr) {
        taille++;
        courant = courant->lien;
    }
    return taille;
}

// Fonction pour vérifier si la file est vide
bool estVide(File* premier) {
    return premier == nullptr;
}

// Fonction pour rechercher un élément dans la file
bool rechercheElement(File* premier, int valeur) {
    File* courant = premier;
    while (courant != nullptr) {
        if (courant->elt == valeur) {
            return true;
        }
        courant = courant->lien;
    }
    return false;
}

// Fonction pour libérer la mémoire
void supprimerFile(File*& premier, File*& dernier) {
    while (premier != nullptr) {
        File* temp = premier;
        premier = premier->lien;
        delete temp;
    }
    dernier = nullptr;
}

// Programme principal
int main() {
    cout << "=== File (FIFO - First In First Out) ===" << endl << endl;

    // Enfilage de plusieurs éléments
    enfiler(dernier, premier, 10);
    enfiler(dernier, premier, 20);
    enfiler(dernier, premier, 30);
    enfiler(dernier, premier, 40);
    enfiler(dernier, premier, 50);

    // Affichage de la file après enfilage
    cout << "File apres enfilage : ";
    afficherFile(premier);
    cout << "Taille: " << tailleFile(premier) << endl << endl;

    // Affichage des éléments en début et fin
    cout << "Element en debut de file: " << consulterDebut(premier) << endl;
    cout << "Element en fin de file: " << consulterFin(dernier) << endl << endl;

    // Défilage d'un élément
    cout << "Defilage du premier element..." << endl;
    defiler(premier, dernier);

    // Affichage après défilage
    cout << "File apres defilage : ";
    afficherFile(premier);
    cout << "Taille: " << tailleFile(premier) << endl << endl;

    // Défilage de plusieurs éléments
    cout << "Defilage de deux elements..." << endl;
    defiler(premier, dernier);
    defiler(premier, dernier);

    // Affichage après défilages multiples
    cout << "File apres defilages multiples : ";
    afficherFile(premier);
    cout << "Taille: " << tailleFile(premier) << endl << endl;

    // Affichage des nouveaux éléments en début et fin
    cout << "Element en debut de file: " << consulterDebut(premier) << endl;
    cout << "Element en fin de file: " << consulterFin(dernier) << endl << endl;

    // Recherche d'un élément
    if (rechercheElement(premier, 40)) {
        cout << "L'element 40 est trouve dans la file" << endl;
    } else {
        cout << "L'element 40 n'est pas trouve dans la file" << endl;
    }
    cout << endl;

    // Enfilage de nouveaux éléments
    cout << "Enfilage de nouveaux elements (60, 70, 80)..." << endl;
    enfiler(dernier, premier, 60);
    enfiler(dernier, premier, 70);
    enfiler(dernier, premier, 80);

    cout << "File apres nouvel enfilage : ";
    afficherFile(premier);
    cout << "Taille: " << tailleFile(premier) << endl << endl;

    // Affichage des éléments en début et fin
    cout << "Element en debut de file: " << consulterDebut(premier) << endl;
    cout << "Element en fin de file: " << consulterFin(dernier) << endl << endl;

    // Vérification si la file est vide
    if (estVide(premier)) {
        cout << "La file est vide" << endl;
    } else {
        cout << "La file n'est pas vide" << endl;
    }
    cout << endl;

    // Défilage de tous les éléments un par un
    cout << "Defilage progressif de tous les elements :" << endl;
    while (!estVide(premier)) {
        cout << "Defilage de: " << consulterDebut(premier) << endl;
        defiler(premier, dernier);
    }
    cout << endl;

    // Vérification finale
    cout << "File apres defilage de tous les elements : ";
    afficherFile(premier);
    cout << "Taille: " << tailleFile(premier) << endl << endl;

    if (estVide(premier)) {
        cout << "La file est maintenant vide" << endl;
    }

    // Libération de la mémoire
    supprimerFile(premier, dernier);

    return 0;
}
