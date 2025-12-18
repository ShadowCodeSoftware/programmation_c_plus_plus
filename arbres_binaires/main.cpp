#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

// Définition de la structure
struct Noeud {
    int elt;              // L'élément (type int)
    Noeud* gauche;        // Pointeur vers le fils gauche
    Noeud* droit;         // Pointeur vers le fils droit
};

// Déclaration de la racine de l'arbre
Noeud* racine = nullptr;

// ===== FONCTIONS DE BASE =====

// Fonction pour vérifier si l'arbre est vide
bool estVide(Noeud* r) {
    return (r == nullptr);
}

// Fonction pour obtenir le sous-arbre gauche
Noeud* getSousArbreGauche(Noeud* r) {
    if (estVide(r)) return nullptr;
    else return r->gauche;
}

// Fonction pour obtenir le sous-arbre droit
Noeud* getSousArbreDroit(Noeud* r) {
    if (estVide(r)) return nullptr;
    else return r->droit;
}

// Fonction pour vérifier si un nœud est une feuille
bool estFeuille(Noeud* r) {
    if (estVide(r)) return false;
    else {
        if (estVide(r->gauche) && estVide(r->droit)) return true;
        else return false;
    }
}

// Fonction pour vérifier si un nœud est interne
bool estInterne(Noeud* r) {
    return (!estFeuille(r) && !estVide(r));
}

// ===== FONCTIONS DE CALCUL =====

// Fonction pour calculer la hauteur de l'arbre
unsigned int hauteur(Noeud* racine) {
    if (estVide(racine)) return 0;
    else
        return 1 + max(hauteur(getSousArbreGauche(racine)), 
                       hauteur(getSousArbreDroit(racine)));
}

// Fonction pour compter le nombre de nœuds
unsigned int nbNoeuds(Noeud* racine) {
    if (estVide(racine)) return 0;
    else
        return 1 + nbNoeuds(getSousArbreGauche(racine)) + 
                   nbNoeuds(getSousArbreDroit(racine));
}

// Fonction pour compter le nombre de feuilles
unsigned int nbFeuilles(Noeud* racine) {
    if (estVide(racine)) return 0;
    else {
        if (estFeuille(racine)) return 1;
        else
            return nbFeuilles(getSousArbreGauche(racine)) + 
                   nbFeuilles(getSousArbreDroit(racine));
    }
}

// ===== FONCTIONS DE PARCOURS =====

// Parcours en profondeur - Préfixe (Racine, Gauche, Droit)
void parcoursProfondeurPrefixe(Noeud* racine) {
    if (!estVide(racine)) {
        cout << racine->elt << " ";
        parcoursProfondeurPrefixe(getSousArbreGauche(racine));
        parcoursProfondeurPrefixe(getSousArbreDroit(racine));
    }
}

// Parcours en profondeur - Infixe (Gauche, Racine, Droit)
void parcoursProfondeurInfixe(Noeud* racine) {
    if (!estVide(racine)) {
        parcoursProfondeurInfixe(getSousArbreGauche(racine));
        cout << racine->elt << " ";
        parcoursProfondeurInfixe(getSousArbreDroit(racine));
    }
}

// Parcours en profondeur - Suffixe (Gauche, Droit, Racine)
void parcoursProfondeurSuffixe(Noeud* racine) {
    if (!estVide(racine)) {
        parcoursProfondeurSuffixe(getSousArbreGauche(racine));
        parcoursProfondeurSuffixe(getSousArbreDroit(racine));
        cout << racine->elt << " ";
    }
}

// Parcours en largeur (BFS - par niveaux)
void parcoursLargeur(Noeud* racine) {
    if (estVide(racine)) return;

    queue<Noeud*> q;
    q.push(racine);

    while (!q.empty()) {
        Noeud* temp = q.front();
        q.pop();

        cout << temp->elt << " ";

        if (!estVide(getSousArbreGauche(temp))) {
            q.push(getSousArbreGauche(temp));
        }
        if (!estVide(getSousArbreDroit(temp))) {
            q.push(getSousArbreDroit(temp));
        }
    }
}

// ===== FONCTION D'AFFICHAGE =====

// Fonction pour afficher l'arbre de manière visuelle (avec structure hiérarchique)
void afficherArbreVisuel(Noeud* racine, string prefixe = "", bool estDroit = true) {
    if (estVide(racine)) return;

    cout << prefixe;
    cout << (estDroit ? "└── " : "├── ");
    cout << racine->elt << endl;

    if (!estVide(racine->gauche) || !estVide(racine->droit)) {
        if (!estVide(racine->gauche)) {
            afficherArbreVisuel(racine->gauche, prefixe + (estDroit ? "    " : "│   "), false);
        }
        if (!estVide(racine->droit)) {
            afficherArbreVisuel(racine->droit, prefixe + (estDroit ? "    " : "│   "), true);
        }
    }
}

// ===== FONCTIONS DE CRÉATION =====

// Fonction pour créer un nouveau nœud
Noeud* creerNoeud(int val) {
    Noeud* r = new Noeud;
    if (r == nullptr) {
        cerr << "Mémoire insuffisante!" << endl;
    } else {
        r->elt = val;
        r->gauche = nullptr;
        r->droit = nullptr;
    }
    return r;
}

// Fonction pour créer une racine avec ses enfants
Noeud* creerRacine(int val, Noeud* g, Noeud* d) {
    Noeud* r = new Noeud;
    if (r == nullptr) {
        cerr << "Mémoire insuffisante!" << endl;
    } else {
        r->elt = val;
        r->gauche = g;
        r->droit = d;
    }
    return r;
}

// Fonction pour ajouter un élément à l'arbre (insertion par largeur)
void ajouterElement(Noeud*& racine, int val) {
    if (racine == nullptr) {
        racine = creerNoeud(val);
        return;
    }

    queue<Noeud*> q;
    q.push(racine);

    while (!q.empty()) {
        Noeud* temp = q.front();
        q.pop();

        if (estVide(temp->gauche)) {
            temp->gauche = creerNoeud(val);
            return;
        } else {
            q.push(temp->gauche);
        }

        if (estVide(temp->droit)) {
            temp->droit = creerNoeud(val);
            return;
        } else {
            q.push(temp->droit);
        }
    }
}

// Fonction pour rechercher un élément
bool rechercher(Noeud* racine, int val) {
    if (estVide(racine)) return false;
    if (racine->elt == val) return true;
    return rechercher(getSousArbreGauche(racine), val) || 
           rechercher(getSousArbreDroit(racine), val);
}

// Fonction pour libérer la mémoire
void supprimerArbre(Noeud*& racine) {
    if (!estVide(racine)) {
        supprimerArbre(racine->gauche);
        supprimerArbre(racine->droit);
        delete racine;
        racine = nullptr;
    }
}

// Programme principal
int main() {
    cout << "=== Arbre Binaire ===" << endl << endl;

    // Création de l'arbre et ajout d'éléments
    cout << "Ajout d'elements dans l'arbre : 5, 6, -12, -3, 11, 4, 2" << endl << endl;
    int tab[] = {5, 6, -12, -3, 11, 4, 2};
    for (int i = 0; i <= 6; i++) {
        ajouterElement(racine, tab[i]);
    }

    // ===== AFFICHAGE VISUEL DE L'ARBRE =====
    cout << "=== Structure de l'arbre ===" << endl;
    afficherArbreVisuel(racine);
    cout << endl;

    // ===== AFFICHAGE DES INFORMATIONS =====
    cout << "=== Informations sur l'arbre ===" << endl;
    cout << "Nombre de noeuds: " << nbNoeuds(racine) << endl;
    cout << "Nombre de feuilles: " << nbFeuilles(racine) << endl;
    cout << "Hauteur de l'arbre: " << hauteur(racine) << endl << endl;

    // Affichage de la racine
    cout << "=== Element a la racine ===" << endl;
    cout << "Element a la racine: " << racine->elt << endl;
    if (!estVide(racine->gauche)) {
        cout << "Element du fils gauche: " << racine->gauche->elt << endl;
    }
    if (!estVide(racine->droit)) {
        cout << "Element du fils droit: " << racine->droit->elt << endl;
    }
    cout << endl;

    // Vérification des propriétés
    cout << "=== Verification des noeuds ===" << endl;
    cout << "La racine est une feuille: " << (estFeuille(racine) ? "Oui" : "Non") << endl;
    cout << "La racine est un noeud interne: " << (estInterne(racine) ? "Oui" : "Non") << endl;
    cout << endl;

    // ===== AFFICHAGE DES PARCOURS =====
    cout << "=== PARCOURS EN PROFONDEUR ===" << endl << endl;

    cout << "1. Prefixe (Racine, Gauche, Droit): ";
    parcoursProfondeurPrefixe(racine);
    cout << endl << endl;

    cout << "2. Infixe (Gauche, Racine, Droit): ";
    parcoursProfondeurInfixe(racine);
    cout << endl << endl;

    cout << "3. Suffixe (Gauche, Droit, Racine): ";
    parcoursProfondeurSuffixe(racine);
    cout << endl << endl;

    cout << "=== PARCOURS EN LARGEUR (BFS) ===" << endl;
    cout << "Parcours par niveaux: ";
    parcoursLargeur(racine);
    cout << endl << endl;

    // ===== RECHERCHE D'ÉLÉMENTS =====
    cout << "=== Recherche d'elements ===" << endl;
    if (rechercher(racine, 11)) {
        cout << "L'element 11 est trouve dans l'arbre" << endl;
    } else {
        cout << "L'element 11 n'est pas trouve dans l'arbre" << endl;
    }

    if (rechercher(racine, 100)) {
        cout << "L'element 100 est trouve dans l'arbre" << endl;
    } else {
        cout << "L'element 100 n'est pas trouve dans l'arbre" << endl;
    }
    cout << endl;

    // ===== AJOUT D'UN NOUVEL ÉLÉMENT =====
    cout << "=== Ajout d'un nouvel element ===" << endl;
    cout << "Ajout de l'element 99..." << endl;
    ajouterElement(racine, 99);
    cout << "Nombre de noeuds apres ajout: " << nbNoeuds(racine) << endl;
    cout << "Nombre de feuilles apres ajout: " << nbFeuilles(racine) << endl;
    cout << "Hauteur apres ajout: " << hauteur(racine) << endl << endl;

    cout << "Structure de l'arbre apres ajout:" << endl;
    afficherArbreVisuel(racine);
    cout << endl;

    cout << "Parcours en largeur (apres ajout): ";
    parcoursLargeur(racine);
    cout << endl << endl;

    // ===== LIBÉRATION DE LA MÉMOIRE =====
    cout << "Liberation de la memoire..." << endl;
    supprimerArbre(racine);

    if (estVide(racine)) {
        cout << "L'arbre a ete supprime avec succes" << endl;
    }

    return 0;
}
