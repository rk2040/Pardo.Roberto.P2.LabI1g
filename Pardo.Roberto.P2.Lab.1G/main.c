#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

#include "LinkedList.h"
#include "peliculas.h"
#include "Controller.h"
#include "menu.h"
#include "misFunciones.h"

int main()
{
    srand(time(NULL));  //semilla a partir del cual  rand() va a empezar a calcular

    int opcion = 0;
    int flagArchivo = 0;
    //int flagBinario = 1;
    char salir = 'n';
    char guardar;

    LinkedList* listaPeliculas = ll_newLinkedList();


    do{
    	menu(&opcion);
        switch(opcion)
        {
            case 1:
            	if( flagArchivo )
                {
                    printf("Ya se abrio el archivo de peliculas.\n");
                }
                else
                {
                    if( !controller_loadFromText(listaPeliculas))
                    {
                        printf("Hubo un problema al cargar la lista de peliculas.\n");
                    }
                    else
                    {
                        flagArchivo = 1;
                        printf("Lista de peliculas cargada en modo texto exitosamente.\n");
                    }
                }
                break;
            case 2:
            	if( !flagArchivo )
            	{
            		printf("No se cargo ninguna lista para mostrar.\n");
            	}
            	else
            	{
					if( !controller_ListPeliculas(listaPeliculas) )
                    {
            			printf("Hubo un error al intentar mostrar la lista.\n");
                    }
				}
            	break;
            case 3:
            	if( !controller_mapDuracion(listaPeliculas) )
                {
                    printf("Hubo un error al intentar asignar un tiempo de duracion.\n");
                }
                else{
                    printf("Carga de tiempo de duracion exitosa.\n");
                }
            	break;
            case 4:
                if( !controller_filtrarPorGenero(listaPeliculas))  // ver y cambiar el menu
                {
                    printf("Hubo un error al intentar filtrar por genero.\n");
                }
            	break;
            case 5:
            	if( !controller_sortPeliculas(listaPeliculas) )
                {
                    printf("Hubo un error al intentar ordenar la lista de peliculas.\n");
                }
            	break;
            case 6:
            	guardar = opcionConfirmar("Quiere guardar la lista en un nuevo archivo? s/n ", "Quiere guardar la lista en un nuevo archivo? s/n ");
                if(guardar == 's')
                {
                    if( !controller_saveAsText(listaPeliculas) )
                    {
                        //flagTexto = 1;
                        printf("Ocurrio un problema al guardar el archivo de la lista en modo texto\n");
                    }
                    else
                    {
                        printf("\nLa lista se guardo en modo texto\n");
                    }
                }
            	break;
            case 7:
            	salir = opcionConfirmar("Seguro que quiere salir? s/n ", "Error, vuelva a intentarlo. Salir? s/n ");
            	break;
            default:
            	break;
        }
        system("pause");

    }while(salir == 'n');

    ll_deleteLinkedList(listaPeliculas);
    free(listaPeliculas);

    return 0;
}

