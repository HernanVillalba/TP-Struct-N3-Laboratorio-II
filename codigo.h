#ifndef CODIGO_H_INCLUDED
#define CODIGO_H_INCLUDED

void dibujarMenu()
{
    cout<<"*---------------------------------------------------*"<<endl;
    cout<<"|                  MENU PRODUCTOS.                  |"<<endl;
    cout<<"*---------------------------------------------------*"<<endl;
    cout<<"| 1 - CARGAR PRODUCTO.                              |"<<endl;
    cout<<"| 2 - EDITAR PRODUCTO POR ID.                       |"<<endl;
    cout<<"| 3 - LISTAR PRODUCTO POR ID.                       |"<<endl;
    cout<<"| 4 - LISTAR PRODUCTOS (ORDENADOS POR PRECIO).      |"<<endl;
    cout<<"*---------------------------------------------------*"<<endl;
    cout<<"0 - SALIR DEL PROGRAMA."<<endl;

    cout<<"Opcion: ";
}

void cargarProducto(struct Producto *vecPro,int *contPro,int tam)
{
    int auxID; //uso este auxiliar para no guardar el dato una vez el usuario lo ingrese ya que primero tengo que saber si existe
    bool existe=false; //
    if(*contPro<10)
    {
        cout<<"INGRESE EL 'ID' DEL PRODUCTO: ";
        cin>>auxID;
        for(int i=0; i<tam; i++) //para recorrer los productos ya guardados del vector de struct
        {
            if(auxID==vecPro[i].id) //si sale del for sin que se haya cumplido la condicion,significa que id no existe
            {
                existe=true;
            }
        }
        if(existe) //si existe, aviso al usuario y no cambio el valor de "contPro"
        {
            system("cls");
            system("COLOR 04");
            cout<<"                     * ERROR * "<<endl;
            cout<<"*** EL ID INGRESADO YA EXISTE. INGRESE UNO DIFERENTE ***"<<endl;
        }
        else  //si no existe, guardo los valores que ingrese el usuario
        {
            vecPro[*contPro].id=auxID;
            cout<<"INGRESE EL NOMBRE DEL PRODUCTO: ";
            cin>>vecPro[*contPro].nombre;
            cout<<"INGRESE EL PRECIO DEL PRODUCTO: $";
            cin>>vecPro[*contPro].precio;
            cout<<"INGRESE EL STOCK DEL PRODUCTO: ";
            cin>>vecPro[*contPro].stock;
            cout<<"INGRESE EL STOCK MINIMO DEL PRODUCTO: ";
            cin>>vecPro[*contPro].stockMinimo;
            *contPro+=1;
            system("cls");
            cout<<"***PRODUCTO CARGADO CORRECTAMENTE***"<<endl;
        }
    }
    else
    {
        system("COLOR 04");
        cout<<"                 ERROR!!!"<<endl;
        cout<<"***NO PUEDE INGRESAR UN NUEVO PRODUCTO PORQUE YA ALCANZÓ EL LÍMITE***"<<endl;
    }
}

void editarProducto(struct Producto*vecPro,int tam)
{
    int auxID,posicionID,editPro;
    bool existe=false;
    cout<<"INGRESE EL 'ID' DEL PRODUCTO: ";
    cin>>auxID;
    for(int i=0; i<tam; i++)
    {
        if(auxID==vecPro[i].id)
        {
            existe=true;
            posicionID=i;
        }
    }
    if(existe)
    {
        cout<<"*=================================================================*"<<endl;
        cout<<"°   ID   °   NOMBRE   °   PRECIO   °   STOCK   °   STOCK MINIMO   °"<<endl;
        cout<<"*=================================================================*"<<endl;
        cout<<"°   "<<vecPro[auxID-1].id;
        cout<<"        "<<vecPro[auxID-1].nombre;
        cout<<"        $"<<vecPro[auxID-1].precio;
        cout<<"         "<<vecPro[auxID-1].stock;
        cout<<"              "<<vecPro[auxID-1].stockMinimo<<endl;
        cout<<"*=================================================================*"<<endl;
        cout<<endl;
        cout<<"¿QUIERE EDITAR ESE PRODUCTO?"<<endl;
        cout<<" 1 - SI."<<endl;
        cout<<" 2 - NO."<<endl;
        cout<<"OPCION: ";
        cin>>editPro;
        switch(editPro)
        {

        case 1:
        {
            cout<<endl<<endl;
            cout<<"INGRESE EL NUEVO NOMBRE DEL PRODUCTO: ";
            cin>>vecPro[posicionID].nombre;
            cout<<"INGRESE EL NUEVO PRECIO DEL PRODUCTO: $";
            cin>>vecPro[posicionID].precio;
            cout<<"INGRESE EL NUEVO STOCK DEL PRODUCTO: ";
            cin>>vecPro[posicionID].stock;
            cout<<"INGRESE EL NUEVO STOCK MINIMO DEL PRODUCTO: ";
            cin>>vecPro[posicionID].stockMinimo;
            system("pause");
            system("cls");
            cout<<"***PRODUCTO EDITADO CORRECTAMENTE***"<<endl;
        }
        break;

        case 2:
            break;

        default:
        {
            system("cls");
            system("COLOR 04");
            cout<<"OPCION INCORRECTA!!!"<<endl;
        }
        break;
        }
    }
    else
    {
        system("cls");
        system("COLOR 04");
        cout<<"                 ERROR"<<endl;
        cout<<"***EL PRODUCTO QUE QUIERE EDITAR NO EXISTE***"<<endl;
    }
}


void listarProductosPorID(struct Producto*vecPro,int tam)
{
    int ID,posicionID;
    bool existe=false;
    cout<<"Ingrese el ID para visualizar el producto: ";
    cin>>ID;
    system("cls");
    for(int i=0; i<tam; i++)
    {
        if(ID==vecPro[i].id)
        {
            existe=true;
            posicionID=i;
        }
    }

    if(existe)
    {
        cout<<"*=================================================================*"<<endl;
        cout<<"°   ID   °   NOMBRE   °   PRECIO   °   STOCK   °   STOCK MINIMO   °"<<endl;
        cout<<"*=================================================================*"<<endl;
        cout<<"°   "<<vecPro[posicionID].id;
        cout<<"        "<<vecPro[posicionID].nombre;
        cout<<"        $"<<vecPro[posicionID].precio;
        cout<<"         "<<vecPro[posicionID].stock;
        cout<<"              "<<vecPro[posicionID].stockMinimo<<endl;
        cout<<"*=================================================================*"<<endl;
    }
    else
    {
        system("COLOR 04");
        cout<<"         * ERROR *"<<endl;
        cout<<"*** EL ID INGRESADO NO EXISTE ***"<<endl;
    }
}

void listarProductosPorPrecio(struct Producto *vecPro,int tam)
{
    struct Producto auxPro;
    bool existeProducto=false;
    for(int j=0; j<tam; j++) //burbujeo del vector
    {
        for(int i=0; i<tam-1; i++)
        {
            if(vecPro[i].precio<vecPro[i+1].precio)
            {
                auxPro=vecPro[i];
                vecPro[i]=vecPro[i+1];
                vecPro[i+1]=auxPro;
            }
        }
    }
    for(int i=0; i<tam; i++)
    {
        if(vecPro[i].id!=0)
        {
            existeProducto=true;
        }
    }

    if(existeProducto)
    {
        cout<<"*=================================================================*"<<endl;
        cout<<"°   ID   °   NOMBRE   °   PRECIO   °   STOCK   °   STOCK MINIMO   °"<<endl;
        cout<<"*=================================================================*"<<endl;
        for(int i=0; i<tam; i++) //muestro si el id es distinto de 0
        {
            if(vecPro[i].id!=0)
            {
                cout<<"°   "<<vecPro[i].id;
                cout<<"        "<<vecPro[i].nombre;
                cout<<"        $"<<vecPro[i].precio;
                cout<<"         "<<vecPro[i].stock;
                cout<<"              "<<vecPro[i].stockMinimo<<endl;
                cout<<"*=================================================================*"<<endl;
            }
        }
    }
    else
    {
        system("cls");
        system("color 04");
        cout<<"         * ERROR *"<<endl;
        cout<<"*** NO EXISTEN PRODUCTOS PARA MOSTRAR ***"<<endl;
    }
}

bool opcionSalir(bool salir)
{
    system("cls");
    int opc;
    cout<<"¿ESTÁ SEGURO QUE DESEA SALIR?"<<endl;
    cout<<"1 - SI."<<endl;
    cout<<"2 - NO."<<endl;
    cout<<"OPCION: ";
    cin>>opc;
    switch(opc)
    {
    case 1:
        salir=true;
        break;

    case 2:
        salir=false;
        break;

    default:
    {
        system("cls");
        system("color 04");
        cout<<"OPCION INCORRECTA!!!"<<endl;
        salir=false;
        break;
    }
    }
    return salir;
}

#endif // CODIGO_H_INCLUDED
