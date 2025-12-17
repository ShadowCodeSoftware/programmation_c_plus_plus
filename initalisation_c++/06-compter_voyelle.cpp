#include <iostream>
#include <string>

using namespace std;

int main ()
{
  
  string nom;
  int voyelle = 0;

  cout << "Entrez notre nom complet " << endl;
  getline(cin, nom);

  for (int i = 0; i < nom.length(); i++)
  {
    char n = tolower(nom[i]);
   if (n == 'a' || n == 'e' || n == 'i' || n == 'o' || n == 'u' || n == 'y')
   {
    voyelle++;
    }
  }
 cout << "Votre nom comporte " << voyelle << " voyelles" << endl;
  return 0;

}
