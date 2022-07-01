#include <stdio.h>
#include <stdlib.h>
#include "menu.h"
#include "misFunciones.h"

int menu(int*pOpcionMenu)
{
    int error = 1;
    int opcion;

    if(pOpcionMenu != NULL)
    {

        system("cls");
        do
        {
        	printf("-------------------------------------\n");
			printf("     *** Menu de Peliculas ***       \n");
			printf("-------------------------------------\n");
            printf(" 1 Cargar los datos de las peliculas \n");
            printf(" 2 Mostrar lista de peliculas \n");
            printf(" 3 Asignar tiempo a las peliculas \n");
            printf(" 4 Filtrar peliculas por genero \n");
            printf(" 5 Mostrar lista ordenada por Genero y duracion (orden descendente) \n");
            printf(" 6 Guardar lista de peliculas \n");
            printf(" 7 Salir\n");

            validarEntero(&opcion,"\nIngrese la opcion deseada\n","Error, opcion invalida\n",0,8,1);

            error = 0;
        }while(opcion<1 || opcion>8);
        *pOpcionMenu = opcion;
    }
    return error;
}



int menuFiltroGenero(int*pOpcion)
{
    int error = 1;
    int opcion;

    if(pOpcion != NULL)
    {

        system("cls");
        do
        {
        	printf("-------------------------------------\n");
			printf("    *** Filtrado por genero ***      \n");
			printf("-------------------------------------\n");
            printf(" 1 Action\n");
            printf(" 2 Adventure\n");
            printf(" 3 Animation\n");
            printf(" 4 Comedy\n");
            printf(" 5 Documentary\n");
            printf(" 6 Drama\n");
            printf(" 7 Horror\n");
            printf(" 8 Musical\n");
            printf(" 9 Thriller\n");

            validarEntero(&opcion,"\nIngrese la opcion deseada\n","Error, opcion invalida\n",0,9,1);

            error = 0;
        }while(opcion<1 || opcion>9);
        *pOpcion = opcion;
    }
    return error;
}

//int menuOrdenar(int*pOpcionMenu)	//usado en la funcion   controller_editPassenger()
//{
//    int error = 1;
//	int opcion;
//
//	system("cls");
//	do{
//		printf("-------------------------------------\n");
//		printf("   *** Lista Pasajeros ***       \n");
//		printf("-------------------------------------\n");
//		printf("1- Ordenar por Id \n");
//		printf("2- Ordenar por nombre del pasajero \n");
//		printf("3- Ordenar por apellido del pasajero \n");
//		printf("4- Ordenar por precio del pasaje \n");
//		validarEntero(&opcion,"\nIngrese la opcion deseada\n","Error, opcion invalida\n",0,5,4);
//		error = 0;
//	}while(opcion<1 || opcion>7);
//	*pOpcionMenu = opcion;
//
//    return error;
//}
