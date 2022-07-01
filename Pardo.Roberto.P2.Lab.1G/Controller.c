#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "LinkedList.h"
#include "peliculas.h"
#include "Controller.h"
#include "parser.h"
#include "menu.h"
#include "misFunciones.h"


int controller_loadFromText(LinkedList* pArrayList)
{
	int todoOK = 0;
	FILE* f;
	char path[25];

	if(pArrayList != NULL)
	{
	    system("cls");
	    printf("------------------------------------\n");
	    printf("        Listado de Peliculas        \n");
	    printf("------------------------------------\n");

	    printf("Ingrese el nombre del archivo que quiere cargar (movies.csv): ");
	    fflush(stdin);
	    scanf("%s", path);

	    while( strcmp(path, "movies.csv") != 0 )    //Valido que ingrese el nombre bien
        {
            printf("Error. Ingrese el nombre del archivo que quiere cargar (movies.csv): ");
            scanf("%s", path);
        }

		f = fopen(path,"r");
		if(f != NULL && parser_PassengerFromText(f, pArrayList))
		{
			printf("\nArchivo cargado exitosamente\n");
			todoOK = 1;
		}
		else
		{
			printf("\nError al cargar el archivo\n");
		}
	}

	fclose(f);

	return todoOK;
}


int controller_saveAsText(LinkedList* pArrayList)
{
    int todoOk = 0;
    char path[50];
    int id;
    char titulo[50];
    char genero[50];
    int duracion;
    int tam;

    eMovie* aux;
    FILE* f;


    if(pArrayList != NULL && path != NULL)
    {

        system("cls");
        printf("Ingrese el nombre del archivo que quiere guardar. (nombreArchivo.csv): ");
	    fflush(stdin);
	    scanf("%s", path);
        //pedirCadenaMix(path, "Ingrese el nombre del archivo que quiere guardar. (nombreArchivo.csv): ", 50);    //nombre de archivo a crear

        f = fopen(path, "w");   //abro el nuevo archivo donde se va a guardar la nueva lista


        if(f != NULL)
        {
            tam = ll_len(pArrayList);
            fprintf(f,"id,titulo,genero,rating\n");     //primer linea del archivo - (lo que seria la "lectura fantasma" cuando se lee)
            for(int i = 0; i<tam; i++)
            {
                aux = (eMovie*) ll_get(pArrayList,i);

                if(	pelicula_getId( aux, &id ) &&
                    pelicula_getTitulo( aux, titulo ) &&
                    pelicula_getGenero( aux, genero) &&
                    pelicula_getDuracion( aux, &duracion) )
                {

                    fprintf(f,"%d,%s,%s,%d\n",id,titulo,genero,duracion);
                    todoOk = 1;
                }
            }
        }
        fclose(f);
    }
    return todoOk;
}


int controller_ListPeliculas(LinkedList* pArrayList)
{
    int todoOk = 0;;
    int flag = 1;
    int tam;
    eMovie* auxPeli;

    if(pArrayList != NULL)
    {
        todoOk = 1;

        printf("-----------------------------------------------------------\n");
        printf("  ID        TITULO                    GENERO     DURACION  \n");
        printf("-----------------------------------------------------------\n\n");

        tam = ll_len(pArrayList);

        for(int i = 0; i<tam; i++)
        {
            auxPeli = (eMovie*) ll_get(pArrayList, i);
            mostrarPeliculaLinea(auxPeli);
                flag = 0;
//            if( ( (eMovie*) ll_get(pArrayList,i) )!= NULL )
//            {
//            	auxPeli = (eMovie*) ll_get(pArrayList, i);
//            	mostrarPeliculaLinea(auxPeli);
//
//            }
        }


        if(flag )
        {
            printf("\nNo hay peliculas en la lista\n");
        }
    }

    return todoOk;
}


// Funciones usando la funcion ll_map() ----------------------------------------------------------
int controller_mapDuracion(LinkedList* pArrayList)
{
    int todoOk = 0;

    pArrayList = ll_map(pArrayList, asignarDuracion);

    if(pArrayList != NULL)
    {
        controller_ListPeliculas(pArrayList);
        todoOk = 1;
    }
    return todoOk;
}

// Funciones usando la funcion ll_filter() ----------------------------------------------------------
int controller_filtrarPorGenero(LinkedList* pArrayList)
{
    int todoOk = 0;
    int opcion = 0;
    char guardar;
    //char nombreArchivo[50];

    menuFiltroGenero(&opcion);

    switch (opcion)
    {
    case 1:
        pArrayList = ll_filter(pArrayList, filtrarGeneroAction);
        break;
    case 2:
        pArrayList = ll_filter(pArrayList, filtrarGeneroAdventure);
        break;
    case 3:
        pArrayList = ll_filter(pArrayList, filtrarGeneroAnimation);
        break;
    case 4:
        pArrayList = ll_filter(pArrayList, filtrarGeneroComedy);
        break;
    case 5:
        pArrayList = ll_filter(pArrayList, filtrarGeneroDocumentary);
        break;
    case 6:
        pArrayList = ll_filter(pArrayList, filtrarGeneroDrama);
        break;
    case 7:
        pArrayList = ll_filter(pArrayList, filtrarGeneroHorror);
        break;
    case 8:
        pArrayList = ll_filter(pArrayList, filtrarGeneroMusical);
        break;
    case 9:
        pArrayList = ll_filter(pArrayList, filtrarGeneroThriller);
        break;
    }

    if ( pArrayList != NULL  )
    {
        controller_ListPeliculas(pArrayList);

        guardar = opcionConfirmar("Quiere guardar la lista en un nuevo archivo? s/n ", "Quiere guardar la lista en un nuevo archivo? s/n ");
        if(guardar == 's')
        {
            controller_saveAsText(pArrayList);
        }
        //system("pause");
        todoOk = 1;
    }
    return todoOk;
}

int controller_sortPeliculas(LinkedList* pArrayList)
{
    int todoOk = 0;

    if ( pArrayList != NULL )
    {
        todoOk = 1;
        system("cls");
        printf("-----------------------------------------\n");
        printf(" Ordenar por genero y duracion descendente \n");
        printf("-----------------------------------------\n");
        ll_sort( pArrayList, ordenGeneroDuracion, 1 );
        controller_ListPeliculas(pArrayList);
    }
    return todoOk;

}
