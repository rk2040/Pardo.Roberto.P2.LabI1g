#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "peliculas.h"
#include "parser.h"

/** \brief Parsea los datos los datos de los elementos desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayList LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayList)
{
	int todoOk = 0;
	//int bufferint;
	char id[50];
	char titulo[50];
	char genero[50];
	char duracion[50];
	//int maxId = -1;
	int cantidadElementos;
	eMovie* aux;
	aux = NULL;

	if(pFile != NULL && pArrayList != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,titulo,genero,duracion);

		do{
			cantidadElementos = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",id,titulo,genero,duracion);

			if(cantidadElementos == 4)
			{
                aux = pelicula_newParametros(id,titulo,genero,duracion);

                if(aux != NULL)
                {
                    ll_add(pArrayList, aux);
                    aux = NULL;
                    todoOk = 1;
                }

            }
			else{
				break;
			}
		}while(!feof(pFile));

		fclose(pFile);
	}

	return todoOk;
}
