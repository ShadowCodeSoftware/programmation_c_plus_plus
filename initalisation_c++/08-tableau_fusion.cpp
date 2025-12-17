#include <iostream>
#include <vector>

using namespace std;

void afficherTableau(const vector<int>& tab)
{
    for (int val : tab)
    {
        cout << val << " ";
    }
    cout << endl;
}

void triSelection(vector<int>& tab)
{
    int n = tab.size();

    for (int i = 0; i < n - 1; i++)
    {
        int indiceMin = i;

        // Recherche du plus petit element
        for (int j = i + 1; j < n; j++)
        {
            if (tab[j] < tab[indiceMin])
            {
                indiceMin = j;
            }
        }

        // Echange
        int temp = tab[i];
        tab[i] = tab[indiceMin];
        tab[indiceMin] = temp;
    }
}

int main()
{
    // Creation et initialisation des deux tableaux
    vector<int> tableau1 = {12, 7, 25, 3, 18};
    vector<int> tableau2 = {9, 30, 4, 15, 21, 6};

    // Affichage des tableaux initiaux
    cout << "Tableau 1 : ";
    afficherTableau(tableau1);

    cout << "Tableau 2 : ";
    afficherTableau(tableau2);

    // Fusion (concatenation) des deux tableaux
    vector<int> tableauFusionne;

    for (int val : tableau1)
        tableauFusionne.push_back(val);

    for (int val : tableau2)
        tableauFusionne.push_back(val);

    // Affichage du tableau fusionne
    cout << "Tableau fusionne : ";
    afficherTableau(tableauFusionne);

    // Tri du tableau fusionne par selection
    triSelection(tableauFusionne);

    // Affichage du tableau trie
    cout << "Tableau fusionne trie (tri par selection) : ";
    afficherTableau(tableauFusionne);

    return 0;
}
