#include <iostream>
#include <stdlib.h>
#include <locale.h>
using namespace std;
struct Producto
    {
        int id,stock,stockMinimo;
        char nombre[30];
        float precio;
    };

#include "codigo.h"
#include "funciones.h"

int main()
{
    setlocale(LC_ALL, "spanish");
    menuProducto();
    return 0;
}
