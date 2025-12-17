#include <iostream>
using namespace std;
int main()
{
    int a = 0;
    int b =  0;
    cout << "Entrez deux nombres" << endl;
    cin >> a >> b;
     cout << "les valeurs avant la permut. "  << a << " et " <<  b << endl;
    a = a + b; 
    b = a - b; 
    a = a - b;
    cout << "les valeurs après la permut. "  << a << " et " <<  b << endl;

return 0;
}
