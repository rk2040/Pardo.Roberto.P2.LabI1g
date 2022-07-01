#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "LinkedList.h"
#include "peliculas.h"


// Constructor ----------------------------------------------------------------------------------------------------
eMovie* pelicula_new()
{

	eMovie* nuevaPelicula;

	nuevaPelicula = (eMovie*) malloc(sizeof(eMovie));

	if(nuevaPelicula != NULL)
	{
		nuevaPelicula->id_peli = 0;
		strcpy(nuevaPelicula->titulo, "");
		strcpy(nuevaPelicula->genero, "");
		nuevaPelicula->duracion = 0;
	}

    return nuevaPelicula;
}

eMovie* pelicula_newParametros(char* idStr, char* tituloStr, char* generoStr, char* duracionStr)
{
	eMovie* nuevaPelicula;
	nuevaPelicula = NULL;
	nuevaPelicula = pelicula_new();

    if(nuevaPelicula != NULL)
    {
        pelicula_setId(nuevaPelicula,atoi(idStr));
		pelicula_setTitulo(nuevaPelicula, tituloStr);
		pelicula_setGenero(nuevaPelicula, generoStr);
		pelicula_setDuracion(nuevaPelicula, atoi(duracionStr) );
	}

    return nuevaPelicula;
}


// Destructor ------------------------------------------------------------------------------------------------------
void pelicula_delete(eMovie* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

// Setters y Getters -----------------------------------------------------------------------------------------------
int pelicula_setId(eMovie* this, int id)
{
    int todoOk = 0;

    if(this != NULL && id > 0)
    {
        this->id_peli = id;
        todoOk = 1;
    }
    return todoOk;
}

int pelicula_getId(eMovie* this, int* id)
{
    int todoOk = 0;

    if(this != NULL && id != NULL)
    {
        *id = this->id_peli;
        todoOk = 1;
    }
    return todoOk;
}

int pelicula_setTitulo(eMovie* this, char* titulo)
{
    int todoOk = 0;

    if(this != NULL && titulo != NULL && strlen(titulo) > 0 && strlen(titulo) < 50)
    {
        strcpy(this->titulo, titulo);
        todoOk = 1;
    }
    return todoOk;
}

int pelicula_getTitulo(eMovie* this, char* titulo)
{
    int todoOk = 0;

    if(this != NULL && titulo != NULL)
    {
        strcpy(titulo, this->titulo);
        todoOk =1;
    }
    return todoOk;
}

int pelicula_setGenero(eMovie* this, char* genero)
{
    int todoOk = 0;

    if(this != NULL && genero != NULL && strlen(genero) > 0 && strlen(genero) < 50)
    {
        strcpy(this->genero, genero);
        todoOk =1;
    }
    return todoOk;
}

int pelicula_getGenero(eMovie* this, char* genero)
{
    int todoOk = 0;

    if(this != NULL && genero != NULL)
    {
        strcpy(genero, this->genero);
        todoOk =1;
    }
    return todoOk;
}


int pelicula_setDuracion(eMovie* this, int duracion)
{
    int todoOk = 0;

    if(this != NULL && duracion > 0)
    {
        this->duracion = duracion;
        todoOk =1;
    }
    return todoOk;
}

int pelicula_getDuracion(eMovie* this, int* duracion)
{
    int todoOk = 0;

    if(this != NULL && duracion != NULL)
    {
        *duracion = this->duracion;
        todoOk =1;
    }
    return todoOk;
}

// -----------------------------------------------------------------
int mostrarPeliculaLinea(eMovie* pelicula)
{
    int todoOk = 0;
    int id;
    char titulo[50];
    char genero[50];
    int duracion = 0;


        if(	pelicula_getId(pelicula, &id) &&
            pelicula_getTitulo(pelicula, titulo) &&
            pelicula_getGenero(pelicula, genero) &&
            pelicula_getDuracion(pelicula, &duracion)	)
        {
			printf(" %3d   %-30s%-12s %3d \n", id, titulo, genero, duracion);

            todoOk = 1;
        }

    return todoOk;
}


// Carga duracion ----------------------------------------------------------------------------------------------
int asignarDuracion(void* pelicula)
{
    int todoOk = 0;
    int max = 240;
    int min = 100;
    int duracion;

    eMovie* aux;

    if(pelicula != NULL)
    {
        todoOk = 1;
        aux = (eMovie*) pelicula;
        duracion = (float) (rand() % (max - min + 1) + min); //valores de 0 a 10 aleatoreos con rand()
        pelicula_setDuracion(aux, duracion);
    }
    return todoOk;
}

// Funciones para usar con filter() ----------------------------------------------------------------------------------
int filtrarGeneroAction(void* pelicula)
{
    int todoOk = 0;

    eMovie* aux = NULL;

    if(pelicula != NULL)
    {
        aux = (eMovie*) pelicula;

        if( stricmp(aux->genero, "Action") == 0 )
        {
            todoOk = 1;
        }
    }
    return todoOk;
}

int filtrarGeneroAdventure(void* pelicula)
{
    int todoOk = 0;

    eMovie* aux = NULL;

    if(pelicula != NULL)
    {
        aux = (eMovie*) pelicula;

        if( stricmp(aux->genero, "Adventure") == 0 )
        {
            todoOk = 1;
        }
    }
    return todoOk;
}

int filtrarGeneroAnimation(void* pelicula)
{
    int todoOk = 0;

    eMovie* aux = NULL;

    if(pelicula != NULL)
    {
        aux = (eMovie*) pelicula;

        if( stricmp(aux->genero, "Animation") == 0 )
        {
            todoOk = 1;
        }
    }
    return todoOk;
}

int filtrarGeneroComedy(void* pelicula)
{
    int todoOk = 0;

    eMovie* aux = NULL;

    if(pelicula != NULL)
    {
        aux = (eMovie*) pelicula;

        if( stricmp(aux->genero, "Comedy") == 0 )
        {
            todoOk = 1;
        }
    }
    return todoOk;
}

int filtrarGeneroDocumentary(void* pelicula)
{
    int todoOk = 0;

    eMovie* aux = NULL;

    if(pelicula != NULL)
    {
        aux = (eMovie*) pelicula;

        if( stricmp(aux->genero, "Documentary") == 0 )
        {
            todoOk = 1;
        }
    }
    return todoOk;
}

int filtrarGeneroDrama(void* pelicula)
{
    int todoOk = 0;

    eMovie* aux = NULL;

    if(pelicula != NULL)
    {
        aux = (eMovie*) pelicula;

        if( stricmp(aux->genero, "Drama") == 0 )
        {
            todoOk = 1;
        }
    }
    return todoOk;
}

int filtrarGeneroHorror(void* pelicula)
{
    int todoOk = 0;

    eMovie* aux = NULL;

    if(pelicula != NULL)
    {
        aux = (eMovie*) pelicula;

        if( stricmp(aux->genero, "Horror") == 0 )
        {
            todoOk = 1;
        }
    }
    return todoOk;
}

int filtrarGeneroMusical(void* pelicula)
{
    int todoOk = 0;

    eMovie* aux = NULL;

    if(pelicula != NULL)
    {
        aux = (eMovie*) pelicula;

        if( stricmp(aux->genero, "Musical") == 0 )
        {
            todoOk = 1;
        }
    }
    return todoOk;
}

int filtrarGeneroThriller(void* pelicula)
{
    int todoOk = 0;

    eMovie* aux = NULL;

    if(pelicula != NULL)
    {
        aux = (eMovie*) pelicula;

        if( stricmp(aux->genero, "Thriller") == 0 )
        {
            todoOk = 1;
        }
    }
    return todoOk;
}


// Funciones para usar con sort() ----------------------------------------------------------------------------------
int ordenGeneroDuracion(void* pelicula1, void* pelicula2)
{
    int todoOk = 0;

    if( (stricmp( ((eMovie*)pelicula1)->genero, ((eMovie*)pelicula2)->genero) > 0 ) ||
      ( (stricmp( ((eMovie*)pelicula1)->genero, ((eMovie*)pelicula2)->genero) == 0 ) &&
               ( ((eMovie*)pelicula1)->duracion < ((eMovie*)pelicula2)->duracion )   )  )
    {
        todoOk = 1;
    }

    if( (stricmp( ( (eMovie*)pelicula1)->genero, ( (eMovie*)pelicula2)->genero) < 0 ) ||
      ( (stricmp( ( (eMovie*)pelicula1)->genero, ( (eMovie*)pelicula2)->genero) == 0 ) &&
               ( ( (eMovie*)pelicula1)->duracion > ((eMovie*)pelicula2)->duracion )   )  )
    {
        todoOk = -1;
    }
    return todoOk;
}
