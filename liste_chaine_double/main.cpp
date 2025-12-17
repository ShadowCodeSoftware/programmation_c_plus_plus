#include <iostream>

using namespace std;

// Définition de la structure pour une liste doublement chaînée
struct Liste {
    int elt;          // L'élément (type int)
    Liste* prev;      // Pointeur vers le nœud précédent
    Liste* next;      // Pointeur vers le nœud suivant
};

// Déclaration de la tête de liste
Liste* tete = nullptr;

// Fonction pour ajouter un élément en tête de liste doublement chaînée
void ajoutTete(Liste*& head, int newData) {
    Liste* nouveau = new Liste;
    nouveau->elt = newData;
    nouveau->prev = nullptr;
    nouveau->next = head;

    if (head != nullptr) {
        head->prev = nouveau;
    }

    head = nouveau;
}

// Fonction pour ajouter un élément au milieu de la liste doublement chaînée
void ajoutMilieu(Liste* previous, int newData) {
    if (previous == nullptr) {
        cerr << "Nœud précédent invalide" << endl;
        return;
    }
    Liste* nouveau = new Liste;
    nouveau->elt = newData;
    nouveau->prev = previous;
    nouveau->next = previous->next;

    if (previous->next != nullptr) {
        previous->next->prev = nouveau;
    }
    previous->next = nouveau;
}

// Fonction pour ajouter un élément en queue de liste doublement chaînée
void ajoutQueue(Liste*& head, int newData) {
    Liste* nouveau = new Liste;
    nouveau->elt = newData;
    nouveau->prev = nullptr;
    nouveau->next = nullptr;

    if (head == nullptr) {
        head = nouveau;
    } else {
        Liste* courant = head;
        while (courant->next != nullptr) {
            courant = courant->next;
        }
        courant->next = nouveau;
        nouveau->prev = courant;
    }
}

// Fonction pour afficher la liste doublement chaînée
void afficherListe(Liste* head) {
    Liste* courant = head;
    cout << "Liste: ";
    while (courant != nullptr) {
        cout << courant->elt << " <-> ";
        courant = courant->next;
    }
    cout << "NULL" << endl;
}

// Programme principal
int main() {
    cout << "=== Liste Doublement Chainee ===" << endl << endl;

    // Ajout en tête de liste
    ajoutTete(tete, 3);
    cout << "Apres ajout de 3 en tete : ";
    afficherListe(tete);

    ajoutTete(tete, 2);
    cout << "Apres ajout de 2 en tete : ";
    afficherListe(tete);

    ajoutTete(tete, 1);
    cout << "Apres ajout de 1 en tete : ";
    afficherListe(tete);

    cout << endl;

    // Ajout en queue de liste
    ajoutQueue(tete, 4);
    cout << "Apres ajout de 4 en queue : ";
    afficherListe(tete);

    ajoutQueue(tete, 5);
    cout << "Apres ajout de 5 en queue : ";
    afficherListe(tete);

    cout << endl;

    // Ajout au milieu de la liste (après le 2e nœud)
    Liste* noeudMilieu = tete->next; // Pointeur vers le 2e nœud
    ajoutMilieu(noeudMilieu, 10);
    cout << "Apres ajout de 10 au milieu : ";
    afficherListe(tete);

    cout << endl;

    // Libération de la mémoire
    while (tete != nullptr) {
        Liste* temp = tete;
        tete = tete->next;
        delete temp;
    }

    return 0;
}
