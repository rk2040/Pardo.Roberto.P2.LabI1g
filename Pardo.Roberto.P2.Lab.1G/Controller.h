

/**
 * @brief Carga los datos del archivo data.csv en modo texto
 *
 * @param  path ruta del archivo que tiene los datos
 * @param  pArrayList puntero al archivo de lista de elementos
 * @return 0 si salio ok -1 si salio mal
 */
int controller_loadFromText(LinkedList* pArrayList);

/**
 * @brief Realiza el guardado de los datos en modo texto con los que se opero luego de abrir el archivo
 * recibe el puntero a la lista y la ruta al archivo con el que trabajamos (data.csv)
 *
 * @param path ruta al archivo csv
 * @param pArrayList punteroa la lista de elementos
 * @return 0 si salio ok -1 si hubo error
 */
int controller_saveAsText(LinkedList* pArrayList);

//---------------------------------------------------------------------------------------------------------

/**
 * @brief Realiza la muestra de los elementos cargados en la lista
 *
 * @param pArrayList punteroa la lista de elementos
 * @return 0 si salio ok -1 si hubo error
 */
int controller_ListPeliculas(LinkedList* pArrayList);


// Funciones usando la funcion ll_map() ----------------------------------------------------------
int controller_mapDuracion(LinkedList* pArrayList);


// Funciones usando la funcion ll_filter() ----------------------------------------------------------
int controller_filtrarPorGenero(LinkedList* pArrayList);

/**
 * @brief ordena las peliculas por genero y rating
 *
 * @param pArrayPelicula LinkedList*
 * @return int
 *
 */
int controller_sortPeliculas(LinkedList* pArrayList);
