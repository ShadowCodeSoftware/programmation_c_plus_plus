#include <iostream>
#include <string>

using namespace std;

int main ()
{
 
 string nom;
 int cpt = 0; 
 cout << "Entrez votre nom " << endl;
 getline(cin, nom);

 for (int i =0; i < nom.length(); i++)
 {
  if(!isspace(nom[i]))
   {
    cpt++;
   }
 }
 cout << "Votre nom compte  " << cpt << " Caracteres " << endl;
 return 0;
}
