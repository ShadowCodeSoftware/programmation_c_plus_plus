# Structure des Données Avancées et Implémentation - TIC 2025-2026

## 📋 Description

Ce dépôt contient une collection de travaux pratiques et d'exercices en **C++** couvrant les concepts fondamentaux et avancés des **structures de données**. Les programmes sont progressifs, du plus basique au plus complexe.

---

## 📁 Structure du Projet

### 1. **initalisation_c++** - Concepts de Base
Exercices d'introduction à C++ et programmation structurée.

| Fichier | Concept |
|---------|---------|
| `01-somme.cpp` | Opérations de base et entrée/sortie |
| `02-permut.cpp` | Permutation et manipulation de variables |
| `03-utilisation_condition_if.cpp` | Structures conditionnelles |
| `04-afficher_nom.cpp` | Affichage et interaction utilisateur |
| `05-compter_caractere_sans_espace.cpp` | Manipulation de chaînes de caractères |
| `06-compter_voyelle.cpp` | Traitement de chaînes et conditions |
| `07-tableau_simple.cpp` | Tableaux unidimensionnels |
| `08-tableau_fusion.cpp` | Fusion de tableaux |
| `09-struct_etudiant.cpp` | Structures et vecteurs |
| `10-etudiant_fichier.cpp` | Gestion de fichiers et structures |
| `11-nbre_mystere.cpp` | Jeu interactif avec boucles |

---

### 2. **liste_chaine_simple** - Listes Chaînées Simples
Implémentation complète d'une liste chaînée simple avec opérations fondamentales.

**Fichier:** `main.cpp`

**Fonctionnalités:**
- ✅ Ajout en tête de liste
- ✅ Ajout en queue de liste
- ✅ Ajout à une position quelconque
- ✅ Suppression en tête
- ✅ Suppression en queue
- ✅ Suppression à une position quelconque
- ✅ Recherche d'un élément
- ✅ Affichage de la liste
- ✅ Calcul de la longueur

**Structure:**
```cpp
struct Liste {
    int elt;              // L'élément
    Liste* suivant;       // Pointeur vers le nœud suivant
};
```

---

### 3. **liste_chaine_double** - Listes Chaînées Doubles
Implémentation d'une liste chaînée doublement liée (bidirectionnelle).

**Fichier:** `main.cpp`

**Caractéristiques:**
- Navigation dans les deux sens (avant/arrière)
- Insertion et suppression efficaces
- Opérations complètes sur les listes doubles

**Structure:**
```cpp
struct Liste {
    int elt;              // L'élément
    Liste* suivant;       // Pointeur vers le nœud suivant
    Liste* precedent;     // Pointeur vers le nœud précédent
};
```

---

### 4. **piles** - Piles (Stack)
Implémentation complète d'une structure de pile avec opérations LIFO (Last In, First Out).

**Fichier:** `main.cpp`

**Opérations:**
- 📥 **Empiler:** Ajouter un élément au sommet
- 📤 **Dépiler:** Retirer un élément du sommet
- 👁️ **Consulter:** Voir l'élément au sommet
- 📊 **Taille:** Obtenir le nombre d'éléments
- 🔍 **Vérification:** Tester si la pile est vide

**Structure:**
```cpp
struct Pile {
    int elt;              // L'élément
    Pile* suivant;        // Pointeur vers le nœud suivant
};
```

---

### 5. **arbres_binaires** - Arbres Binaires
*Section réservée pour l'implémentation des arbres binaires.*

---

### 6. **files** - Dossier Utilitaire
*Dossier réservé pour les fichiers de données ou fichiers d'entrée/sortie.*

---

## 🚀 Comment Compiler et Exécuter

### Compilation (avec Microsoft Visual C++)
```bash
cl.exe /EHsc /Zi /Fe:programme.exe fichier.cpp
```

### Compilation (avec MinGW/GCC)
```bash
g++ -o programme.exe fichier.cpp
```

### Exécution
```bash
programme.exe
```

### Utilisation avec VS Code
1. Ouvrir le fichier `.cpp`
2. Utiliser la tâche de compilation intégrée : `Ctrl+Shift+B`
3. Exécuter l'executable généré

---

## 📚 Concepts Couverts

| Concept | Fichiers |
|---------|----------|
| Variables et opérations | `initalisation_c++/01-02` |
| Structures conditionnelles | `initalisation_c++/03` |
| Chaînes de caractères | `initalisation_c++/05-06` |
| Tableaux | `initalisation_c++/07-08` |
| Structures (struct) | `initalisation_c++/09-10` |
| Listes chaînées | `liste_chaine_simple/`, `liste_chaine_double/` |
| Piles | `piles/` |
| Arbres | `arbres_binaires/` |

---

## 💡 Points Clés de l'Apprentissage

✓ **Gestion de la mémoire** - Allocation dynamique (`new`/`delete`)  
✓ **Pointeurs** - Manipulation de références mémoire  
✓ **Structures de données** - Concepts fondamentaux  
✓ **Récursion** - Approche algorithmique  
✓ **Algorithmes** - Insertion, suppression, recherche  
✓ **Bonnes pratiques** - Code lisible et bien documenté  

---

## 📖 Recommandations d'Étude

1. **Commencer par** `initalisation_c++` pour maîtriser les bases
2. **Progresser vers** `liste_chaine_simple` pour comprendre les pointeurs
3. **Approfondir avec** `liste_chaine_double` et `piles` pour les structures avancées
4. **Terminer par** les arbres binaires pour les concepts complexes

---

## 🔧 Prérequis

- **Compilateur C++** : Visual Studio, MinGW, GCC, ou Clang
- **Éditeur** : VS Code recommandé
- **Système** : Windows, Linux, ou macOS

---

## 📝 Notes Importantes

- ⚠️ Toujours libérer la mémoire allouée avec `delete`
- ⚠️ Vérifier les pointeurs null avant d'y accéder
- ⚠️ Respecter l'ordre des opérations dans les structures chaînées
- ⚠️ Tester avec des cas limites (listes vides, un seul élément, etc.)

---

## 📧 Contact & Support

Pour toute question ou clarification, consulter la documentation commentée dans les fichiers `.cpp`.

---

**Année Académique:** 2025-2026  
**Licence:** Voir [LICENSE](LICENSE)

