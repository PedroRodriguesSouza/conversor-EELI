#include <iostream>

using namespace std;

void conversor_generico(float n, int base);
void conversor_float(float n, int base);

int main()
{
    float n;

    cout << "Digite um numero: ";
    cin >> n;

    conversor_generico(n,2);

    return 0;
}

void conversor_generico(float n, int base)
{
    int resto;
    float f = n - int(n);
    int i = int(n);

    if(base < 11)
    {
        resto = i % base;
        i = (i - resto) / base;
        if(i)
            conversor_generico(i, base);
        cout << resto;
    }

    else
    {
        char lista[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
        resto = i % base;
        i = (i - resto) / base;

        if(i)
            conversor_generico(n, base);
            
        cout << lista[resto];
    }

    if(f)
    {
        cout << ",";
        conversor_float(f, base);
        cout << "\n\n";
    }
}

void conversor_float(float n, int base)
{
    int aux;
    int cont = 0;
    while(n != 0 && cont < 8)
    {
        n *= base;
        if(n)
        {
            aux = int(n);
            n -= aux;
            cout << aux;
        }
        else
            cout << "0";
        cont++;
    }
}