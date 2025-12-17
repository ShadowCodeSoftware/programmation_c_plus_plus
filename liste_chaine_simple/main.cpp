#include <iostream>

using namespace std;

// Définition de la structure
struct Liste {
    int elt;              // L'élément (type int)
    Liste* suivant;       // Pointeur vers le nœud suivant
};

// Déclaration de la tête de liste
Liste* tete = nullptr;

// Fonction pour ajouter un élément en tête de liste
void ajoutTete(Liste*& head, int newData) {
    Liste* nouveau = new Liste;
    nouveau->elt = newData;
    nouveau->suivant = head;
    head = nouveau;
}

// Fonction pour ajouter un élément en queue de liste
void ajoutQueue(Liste*& head, int newData) {
    Liste* nouveau = new Liste;
    nouveau->elt = newData;
    nouveau->suivant = nullptr;

    if (head == nullptr) {
        head = nouveau;
    } else {
        Liste* courant = head;
        while (courant->suivant != nullptr) {
            courant = courant->suivant;
        }
        courant->suivant = nouveau;
    }
}

// Fonction pour ajouter un élément à une position quelconque
void ajoutMilieu(Liste*& head, int newData, int position) {
    if (position < 1) {
        cerr << "Position invalide" << endl;
        return;
    }

    Liste* nouveau = new Liste;
    nouveau->elt = newData;

    if (position == 1) {
        nouveau->suivant = head;
        head = nouveau;
    } else {
        Liste* courant = head;
        int currentPosition = 1;

        while (courant != nullptr && currentPosition < position - 1) {
            courant = courant->suivant;
            currentPosition++;
        }

        if (courant != nullptr) {
            nouveau->suivant = courant->suivant;
            courant->suivant = nouveau;
        } else {
            cerr << "Position invalide" << endl;
        }
    }
}

// Fonction pour supprimer le nœud en tête de liste
void suppressionTete(Liste*& head) {
    if (head == nullptr) {
        cerr << "La liste est vide" << endl;
        return;
    }

    Liste* temp = head;
    head = head->suivant;
    delete temp;
}

// Fonction pour supprimer le nœud en queue de liste
void suppressionQueue(Liste*& head) {
    if (head == nullptr) {
        cerr << "La liste est vide" << endl;
        return;
    }

    if (head->suivant == nullptr) {
        delete head;
        head = nullptr;
    } else {
        Liste* courant = head;
        while (courant->suivant->suivant != nullptr) {
            courant = courant->suivant;
        }
        delete courant->suivant;
        courant->suivant = nullptr;
    }
}

// Fonction pour supprimer un nœud à une position quelconque
void suppressionPositionX(Liste*& head, int position) {
    if (position < 1 || head == nullptr) {
        cerr << "Position invalide" << endl;
        return;
    }

    if (position == 1) {
        Liste* temp = head;
        head = head->suivant;
        delete temp;
    } else {
        Liste* courant = head;
        int currentPosition = 1;

        while (courant != nullptr && currentPosition < position - 1) {
            courant = courant->suivant;
            currentPosition++;
        }

        if (courant != nullptr && courant->suivant != nullptr) {
            Liste* temp = courant->suivant;
            courant->suivant = courant->suivant->suivant;
            delete temp;
        } else {
            cerr << "Position invalide" << endl;
        }
    }
}

// Fonction pour afficher la liste
void afficherListe(Liste* head) {
    Liste* courant = head;
    cout << "Liste: ";
    while (courant != nullptr) {
        cout << courant->elt << " -> ";
        courant = courant->suivant;
    }
    cout << "NULL" << endl;
}

// Fonction pour rechercher un élément
bool rechercheElement(Liste* head, int valeur) {
    Liste* courant = head;
    while (courant != nullptr) {
        if (courant->elt == valeur) {
            return true;
        }
        courant = courant->suivant;
    }
    return false;
}

// Fonction pour obtenir la longueur de la liste
int longueurListe(Liste* head) {
    int longueur = 0;
    Liste* courant = head;
    while (courant != nullptr) {
        longueur++;
        courant = courant->suivant;
    }
    return longueur;
}

// Fonction pour libérer la mémoire
void supprimerListe(Liste*& head) {
    while (head != nullptr) {
        Liste* temp = head;
        head = head->suivant;
        delete temp;
    }
}

// Programme principal
int main() {
    cout << "=== Liste Chainee Simple ===" << endl << endl;

    // Ajout en tête de liste
    ajoutTete(tete, 3);
    ajoutTete(tete, 2);
    ajoutTete(tete, 1);

    // Affichage de la liste après ajout en tête
    cout << "Liste apres ajout en tete : ";
    afficherListe(tete);
    cout << "Longueur: " << longueurListe(tete) << endl << endl;

    // Ajout en queue de liste
    ajoutQueue(tete, 4);
    ajoutQueue(tete, 5);

    // Affichage de la liste après ajout en queue
    cout << "Liste apres ajout en queue : ";
    afficherListe(tete);
    cout << "Longueur: " << longueurListe(tete) << endl << endl;

    // Ajout à une position quelconque (position 3, avec valeur 7)
    ajoutMilieu(tete, 7, 3);

    // Affichage de la liste après ajout à une position quelconque
    cout << "Liste apres ajout a une position quelconque : ";
    afficherListe(tete);
    cout << "Longueur: " << longueurListe(tete) << endl << endl;

    // Recherche d'un élément
    if (rechercheElement(tete, 7)) {
        cout << "L'element 7 est trouve dans la liste" << endl;
    }
    cout << endl;

    // Suppression à une position quelconque (position 4)
    suppressionPositionX(tete, 4);

    // Affichage après suppression à une position quelconque
    cout << "Liste apres suppression a la position 4 : ";
    afficherListe(tete);
    cout << "Longueur: " << longueurListe(tete) << endl << endl;

    // Suppression en queue
    suppressionQueue(tete);

    // Affichage après suppression en queue
    cout << "Liste apres suppression en queue : ";
    afficherListe(tete);
    cout << "Longueur: " << longueurListe(tete) << endl << endl;

    // Suppression en tête
    suppressionTete(tete);

    // Affichage après suppression en tête
    cout << "Liste apres suppression en tete : ";
    afficherListe(tete);
    cout << "Longueur: " << longueurListe(tete) << endl << endl;

    // Libération de la mémoire
    supprimerListe(tete);

    return 0;
}
