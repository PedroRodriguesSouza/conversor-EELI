#include <iostream>

using namespace std;

void conversor_generico(int n, int base);

int main()
{
     int n;

    cout << "Digite um numero: ";
    cin >> n;

    conversor_generico(n, 2);

    return 0;
}

void conversor_generico(int n, int base)
{
    int resto;

    if(base < 11)
    {
        while(n > base - 1)
        {
            resto = n % base;
            cout << resto;
            n = (n - resto) / base;
        }
        cout << n << endl << endl;
    }
    else
    {
        char lista[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
        while(n > base - 1)
        {
            resto = n % base;
            cout << lista[resto];
            n = (n - resto) / base;
        }
        cout << lista[n] << endl << endl;
    }
}