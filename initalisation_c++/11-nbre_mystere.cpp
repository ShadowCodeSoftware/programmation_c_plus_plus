#include <iostream>
#include <cstdlib>   // Pour rand() et srand()
#include <ctime>     // Pour time()

using namespace std;

int main()
{
    // Initialisation du générateur de nombres aléatoires
    // time(0) permet d'obtenir une valeur différente à chaque exécution
    srand(time(0));

    // Génération du nombre mystère entre 1 et 100
    int nbreMystere = rand() % 100 + 1;

    int nbre = 0;
    int cpt = 0;

    cout << "NOMBRE MYSTERE" << endl;
    cout << "Entrez un nombre compris entre 1 et 100" << endl;

    // Boucle tant que le nombre n'est pas trouvé
    while (nbre != nbreMystere)
    {
        cout << "Entrez votre nombre : ";
        cin >> nbre;

        // Incrémenter le nombre d'essai
        cpt++;

        if (nbre < nbreMystere)
        {
            cout << "Trop petit !" << endl;
        }
        else if (nbre > nbreMystere)
        {
            cout << "Trop grand !" << endl;
        }
        else
        {
            cout << "Bravo ! Vous avez trouve le nombre mystere." << endl;
            cout << "Vous avez trouvé en : " << cpt << " nombres de fois" << endl;
        }
    }

    return 0;
}
