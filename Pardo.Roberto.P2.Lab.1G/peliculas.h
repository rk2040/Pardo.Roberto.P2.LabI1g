#ifndef PELICULAS_H_INCLUDED
#define PELICULAS_H_INCLUDED

typedef struct
{
    int id_peli;
    char titulo[50];
    char genero[50];
    int duracion;
}eMovie;

#endif // PELICULAS_H_INCLUDED


eMovie* pelicula_new();

eMovie* pelicula_newParametros(char* idStr, char* tituloStr, char* generoStr, char* ratingStr);

// Destructor ------------------------------------------------------------------------------------------------------
void pelicula_delete(eMovie* this);

// Setters y Getters -----------------------------------------------------------------------------------------------
int pelicula_setId(eMovie* this, int id);

int pelicula_getId(eMovie* this, int* id);

int pelicula_setTitulo(eMovie* this, char* titulo);

int pelicula_getTitulo(eMovie* this, char* titulo);

int pelicula_setGenero(eMovie* this, char* genero);

int pelicula_getGenero(eMovie* this, char* genero);

int pelicula_setDuracion(eMovie* this, int duracion);

int pelicula_getDuracion(eMovie* this, int* duracion);

int mostrarPeliculaLinea(eMovie* pelicula);

// -----------------------------------------------------------------
int mostrarPeliculaLinea(eMovie* pelicula);


// Carga duracion ----------------------------------------------------------------------------------------------------
int asignarDuracion(void* pelicula);

// Funciones para usar con filter() ----------------------------------------------------------------------------------

int filtrarGeneroAction(void* pelicula);

int filtrarGeneroAdventure(void* pelicula);

int filtrarGeneroAnimation(void* pelicula);

int filtrarGeneroComedy(void* pelicula);

int filtrarGeneroDocumentary(void* pelicula);

int filtrarGeneroDrama(void* pelicula);

int filtrarGeneroHorror(void* pelicula);

int filtrarGeneroMusical(void* pelicula);

int filtrarGeneroThriller(void* pelicula);

int filtrarGeneroWestern(void* pelicula);


// Funciones para usar con sort() ----------------------------------------------------------------------------------
int ordenGeneroDuracion(void* pelicula1, void* pelicula2);
