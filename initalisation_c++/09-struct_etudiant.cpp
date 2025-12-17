#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Etudiant 
{
 string nom;
 int age;
 float moy;
};

int main()
{

  int nbre_etudiant;
  cout << "Entrez le nombre d'étudiants que vous voulez enregistrer : ";
  cin >> nbre_etudiant;
  cin.ignore();

  vector<Etudiant>  ets(nbre_etudiant);

  for(int i = 0; i < nbre_etudiant; i++)
  {
    cout << "Entrez le nom de l'étudiant N° : " << i+1 << " " ;
    getline(cin, ets[i].nom);

    cout << "Entrez l'age de l'étudiant :" << i+1 << " ";
    cin>>ets[i].age; 
    cin.ignore();
   
   cout << "Entrez la moyenne de l'étudiant :" <<i+1 << " ";
   cin >> ets[i].moy;
   cin.ignore();

  }

  cout <<" Nom\t\t\t" <<   "Age\t" << "Moyenne" << endl;

  for (int i = 0; i < nbre_etudiant; i++)
  {
     cout << ets[i].nom  << "\t\t\t" << ets[i].age << "\t" << ets[i].moy << endl;
  }
 
 return 0;
}
