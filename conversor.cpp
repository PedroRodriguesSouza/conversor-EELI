#include <iostream>
#include <string.h>


using namespace std;

void conversor_generico(float, int, int);
void conversor_float(float, int, int);

int main()
{
    int base = 2, precisao = 8;
    float n;
    char resp1, resp2;
    string nstring, bstring, hex;

    cout << "\n\nO numero que voce deseja converter eh um numero:\n\n1 - decimal\n2 - binario\n3 - octal\n4 - hexadecimal\n\n";
    cin >> resp1;

    switch (resp1)
    {
    case '1':
        nstring = "decimal";
        break;
    
    case '2':
        nstring = "binario";
        break;

    case '3':
        nstring = "octal";
        break;

    case '4':
        nstring = "hexadecimal";
        break;

    default:
        break;
    }

    cout << "\nDigite o numero " << nstring << " que voce deseja converter: ";
    if(resp1 == '4')
        cin >> hex;
    else
        cin >> n;

    cout << "\nVoce deseja converter o " << nstring << " "; if(resp1 == '4')cout << hex; else cout << n; cout << " para a base:\n\n1 - decimal\n2 - binario\n3 - octal\n4 - hexadecimal\n\n";
    cin >> resp2;

    if(resp1 != resp2)
    {
        switch (resp2)
        {
        case '1':
            base = 10;
            bstring = "decimal";
            break;
        
        case '2':
            base = 2;
            bstring = "binario";
            break;

        case '3':
            base = 8;
            bstring = "octal";
            break;

        case '4':
            base = 16;
            bstring = "hexadecimal";
            break;

        default:
            break;
        }
    }
    else
    {

    }

    cout << "\nO numero "; if(resp1 == '4')cout << hex; else cout << n; cout << " eh representado como: ";
    conversor_generico(n, base, precisao);

    cout << " em " << bstring << endl << endl;

    return 0;
}

void conversor_generico(float n, int base, int precisao)
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
            conversor_generico(n, base, precisao);

        cout << lista[resto];
    }

    if(f)
    {
        cout << ",";
        conversor_float(f, base, precisao);
    }
}

void conversor_float(float n, int base, int precisao)
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