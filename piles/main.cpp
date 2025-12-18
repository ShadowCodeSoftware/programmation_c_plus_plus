#include <iostream>

using namespace std;

// Définition de la structure
struct Pile {
    int elt;              // L'élément (type int)
    Pile* suivant;        // Pointeur vers le nœud suivant
};

// Déclaration du sommet de la pile
Pile* sommet = nullptr;

// Fonction pour empiler un élément
void empiler(Pile*& sommet, int val) {
    Pile* E = new Pile;
    if (E) {
        E->elt = val;
        E->suivant = sommet;
        sommet = E;
    }
}

// Fonction pour dépiler un élément (version sans retour)
void depiler(Pile*& sommet) {
    if (sommet == nullptr) {
        cerr << "La pile est vide" << endl;
        return;
    } else {
        Pile* p = sommet;
        sommet = sommet->suivant;
        delete p;
    }
}

// Fonction pour obtenir le sommet de la pile (version avec retour)
int depiler(Pile* sommet) {
    if (sommet == nullptr) {
        cerr << "La pile est vide" << endl;
        return -1;  // Valeur par défaut
    } else {
        return sommet->elt;
    }
}

// Fonction pour afficher la pile
void afficherPile(Pile* sommet) {
    Pile* courant = sommet;
    cout << "Pile: ";
    while (courant != nullptr) {
        cout << courant->elt << " -> ";
        courant = courant->suivant;
    }
    cout << "NULL" << endl;
}

// Fonction pour obtenir la taille de la pile
int taillePile(Pile* sommet) {
    int taille = 0;
    Pile* courant = sommet;
    while (courant != nullptr) {
        taille++;
        courant = courant->suivant;
    }
    return taille;
}

// Fonction pour vérifier si la pile est vide
bool estVide(Pile* sommet) {
    return sommet == nullptr;
}

// Fonction pour libérer la mémoire
void supprimerPile(Pile*& sommet) {
    while (sommet != nullptr) {
        Pile* temp = sommet;
        sommet = sommet->suivant;
        delete temp;
    }
}

// Programme principal
int main() {
    cout << "=== Pile ===" << endl << endl;

    // Empilage de plusieurs éléments
    empiler(sommet, 10);
    empiler(sommet, 20);
    empiler(sommet, 30);
    empiler(sommet, 40);

    // Affichage de la pile après empilage
    cout << "Pile apres empilage : ";
    afficherPile(sommet);
    cout << "Taille: " << taillePile(sommet) << endl << endl;

    // Affichage du sommet de la pile
    cout << "Element au sommet: " << depiler(sommet) << endl << endl;

    // Dépilage d'un élément
    depiler(sommet);

    // Affichage de la pile après dépilage
    cout << "Pile apres depilage : ";
    afficherPile(sommet);
    cout << "Taille: " << taillePile(sommet) << endl << endl;

    // Dépilage de plusieurs éléments
    depiler(sommet);
    depiler(sommet);

    // Affichage après dépilages multiples
    cout << "Pile apres depilages multiples : ";
    afficherPile(sommet);
    cout << "Taille: " << taillePile(sommet) << endl << endl;

    // Vérification si la pile est vide
    if (estVide(sommet)) {
        cout << "La pile est vide" << endl;
    } else {
        cout << "La pile n'est pas vide" << endl;
    }
    cout << endl;

    // Empilage après vérification
    empiler(sommet, 50);
    empiler(sommet, 60);

    cout << "Pile apres nouvel empilage : ";
    afficherPile(sommet);
    cout << "Taille: " << taillePile(sommet) << endl << endl;

    // Libération de la mémoire
    supprimerPile(sommet);

    return 0;
}
