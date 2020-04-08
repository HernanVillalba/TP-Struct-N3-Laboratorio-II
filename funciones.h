#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

void menuProducto()
{
    const int TAM=10;
    Producto vecPro[TAM]= {0};
    int opcion,contPro=0; //contador de productos
    bool salir=false;

    do{
        system("COLOR 02");
        dibujarMenu();
        cin>>opcion;
        system("cls");

        switch(opcion)
        {
        case 0:
            salir=opcionSalir(salir);
            if(salir)
            {
                return;
            }
            break;

        case 1:
            cargarProducto(vecPro,&contPro,TAM);
            break;

        case 2:
            editarProducto(vecPro,TAM);
            break;

        case 3:
            listarProductosPorID(vecPro,TAM);
            break;

        case 4:
            listarProductosPorPrecio(vecPro,TAM);
            break;

        default:
            system("cls");
            system("color 04");
            cout<<"Opcion incorrecta!!!"<<endl;
            break;
        }

        system("pause");
        system("cls");

    }while(!salir);
}


#endif // FUNCIONES_H_INCLUDED
