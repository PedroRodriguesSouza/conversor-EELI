#include <iostream>

using namespace std;

void conversor_generico(float, int, int);
void conversor_float(float, int, int);

int main()
{
    float n, base = 2, precisao = 8;
    cout << "Digite um numero: ";
    cin >> n;

    conversor_generico(n, base, precisao);

    return 0;
}

void conversor_generico(float n, int base = 2, int precisao = 8)
{
    int resto;
    float f = n - int(n);
    int i = int(n);

    if(base < 11)
    {
        resto = i % base;
        i = (i - resto) / base;
        if(i)
            conversor_generico(i, base, 8);

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
        conversor_float(f, base, precisao);
        cout << "\n\n";
    }
}

void conversor_float(float n, int base = 2, int precisao = 8)
{
    int aux;
    int cont = 0;

    if(base < 11)
    {
        while(n != 0 && cont < precisao)
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

    else
    {
        char lista[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

        while (n != 0 && cont < precisao)
        {
            n *= base;
            if(n)
            {
                aux = int(n);
                n -= aux;
                cout << lista[aux];
            }
            else
                cout << "0";
            cont++;
    
        }
    }
}