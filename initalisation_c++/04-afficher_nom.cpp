#include <iostream>
#include <string>

using namespace std;

int main()
{

  string nom;
  int longueur = 0;
  cout << "Entrez votre nom complet "<< endl;
  getline (cin, nom);

  cout << "Vous vous appelez " << nom << endl;
  longueur = nom.length();
  cout << "Votre nom compte  " << longueur << " caractères"<< endl;

  return 0;
}
