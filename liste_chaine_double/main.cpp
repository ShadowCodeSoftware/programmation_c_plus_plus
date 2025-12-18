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

// Fonction pour supprimer un élément en tête de liste
void suppressionTete(Liste*& head) {
    if (head == nullptr) {
        cerr << "La liste est vide" << endl;
        return;
    }

    Liste* temp = head;
    head = head->next;
    
    if (head != nullptr) {
        head->prev = nullptr;
    }
    
    delete temp;
}

// Fonction pour supprimer un élément au milieu de la liste
void suppressionMilieu(Liste*& head, int position) {
    if (position < 1 || head == nullptr) {
        cerr << "Position invalide" << endl;
        return;
    }

    if (position == 1) {
        suppressionTete(head);
    } else {
        Liste* courant = head;
        int currentPosition = 1;

        while (courant != nullptr && currentPosition < position) {
            courant = courant->next;
            currentPosition++;
        }

        if (courant != nullptr) {
            if (courant->prev != nullptr) {
                courant->prev->next = courant->next;
            }
            if (courant->next != nullptr) {
                courant->next->prev = courant->prev;
            }
            delete courant;
        } else {
            cerr << "Position invalide" << endl;
        }
    }
}

// Fonction pour supprimer un élément en queue de liste
void suppressionQueue(Liste*& head) {
    if (head == nullptr) {
        cerr << "La liste est vide" << endl;
        return;
    }

    if (head->next == nullptr) {
        delete head;
        head = nullptr;
    } else {
        Liste* courant = head;
        while (courant->next != nullptr) {
            courant = courant->next;
        }
        
        if (courant->prev != nullptr) {
            courant->prev->next = nullptr;
        }
        delete courant;
    }
}

// Fonction pour obtenir la longueur de la liste
int longueurListe(Liste* head) {
    int longueur = 0;
    Liste* courant = head;
    while (courant != nullptr) {
        longueur++;
        courant = courant->next;
    }
    return longueur;
}

// Fonction pour rechercher un élément
bool rechercheElement(Liste* head, int valeur) {
    Liste* courant = head;
    while (courant != nullptr) {
        if (courant->elt == valeur) {
            return true;
        }
        courant = courant->next;
    }
    return false;
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

    // Affichage de la longueur
    cout << "Longueur de la liste : " << longueurListe(tete) << endl << endl;

    // Recherche d'éléments
    if (rechercheElement(tete, 10)) {
        cout << "L'element 10 est trouve dans la liste" << endl;
    } else {
        cout << "L'element 10 n'est pas trouve" << endl;
    }

    if (rechercheElement(tete, 100)) {
        cout << "L'element 100 est trouve dans la liste" << endl;
    } else {
        cout << "L'element 100 n'est pas trouve" << endl;
    }

    cout << endl;

    // Suppression en tête
    suppressionTete(tete);
    cout << "Apres suppression en tete : ";
    afficherListe(tete);
    cout << "Longueur : " << longueurListe(tete) << endl << endl;

    // Suppression en queue
    suppressionQueue(tete);
    cout << "Apres suppression en queue : ";
    afficherListe(tete);
    cout << "Longueur : " << longueurListe(tete) << endl << endl;

    // Suppression au milieu (position 2)
    suppressionMilieu(tete, 2);
    cout << "Apres suppression a la position 2 : ";
    afficherListe(tete);
    cout << "Longueur : " << longueurListe(tete) << endl << endl;

    // Libération de la mémoire
    while (tete != nullptr) {
        Liste* temp = tete;
        tete = tete->next;
        delete temp;
    }

    return 0;
}
