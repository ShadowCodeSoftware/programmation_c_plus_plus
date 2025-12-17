#include <iostream>
#include <vector>

using  namespace std;

void Afficher(const vector<int>& tab)
{
   for(int nbre : tab)
   {
    cout << nbre << "  ";
   }
   cout << endl;
}

void triSelection(vector<int>& tab)
{
  int taille = tab.size();
  for (int i=0; i < taille-1; i++)
  {
   int indiceMin = i;

   for (int j = i +1; j < taille; j++)
   {
     if(tab[j] < tab[indiceMin])
     {
       indiceMin = j;
     }
   }
   int tmp = tab[i];
   tab[i] = tab[indiceMin];
   tab[indiceMin] = tmp;

  }
}

void triBulles(vector<int>& tab)
{
  int taille = tab.size();
  
  for(int i =0; i < taille - 1; i++)
  {
    for(int j = 0; j < taille - i - 1; j++)
    {
     if(tab[j] > tab[j+1])
     { 
      int tmp = tab[j];
      tab[j] = tab [j + 1];
      tab[j+1] = tmp;
     }

    }
  }
}

void triInsertion(vector<int>& tab)
{
   int taille = tab.size();
   
   for(int i = 1; i < taille; i++)
   {
       int position = tab[i];
       int j = i - 1;

        while (j >= 0 && tab[j] > position)
        {
            tab[j + 1] = tab[j];
            j--;
        }

        tab[j + 1] = position;
   }
}


int main()
{

 int taille = 0;
 cout << "Entrez la taille de votre tableau un nbre compris en 1 et 10" << endl;
 cin >> taille;

 vector<int> tab(taille) ;

 cout << "Entrez les elements de votre tableau :" << endl;
 for (int i =0; i<taille; i++)
 {
  cout << "element " << i+1 << " : ";
  cin >> tab[i];
 }
 cout << "Le tableau que vous avez  saisi est : " << endl;
 Afficher(tab);
  
 // tri  par selection
 cout << "Tableau trié par tri-selection " << endl;
 triSelection (tab);
 Afficher(tab);
 
 // tri  à bulles
 cout << "Tableau trié par tri a bulles " << endl;
 triBulles(tab);
 Afficher(tab);
 
 // trie par Insertion
 cout << "Tableau trie par Insertion " <<endl;
 triInsertion(tab);
 Afficher(tab);

 return 0;
}
