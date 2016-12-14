#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "actividad.h"

void new_ListaActividad(listaActividad** lst)
{
    (*lst)->primero = NULL;
}

nodoActividad* new_NodoActividad(char* fecha, char* nombre, char* descripcion)
{
    nodoActividad* nuevo = (nodoActividad*)malloc(sizeof(nodoActividad));
    if (nuevo != NULL)
    {
        nuevo->fecha = fecha;
        nuevo->nombre = nombre;
        nuevo->descripcion = descripcion;
        nuevo->contacto = NULL;
        nuevo->anterior = NULL;
        nuevo->siguiente = NULL;

        return nuevo;
    } else
    {
        printf("No hay espacio en memoria");
        return NULL;
    }
}

nodoActividad* insertarActividad(listaActividad** lst,
        char* fecha, char* nombre, char* descripcion)
{
    nodoActividad* nuevo = new_NodoActividad(fecha, nombre, descripcion);
    
    if ((*lst)->primero != NULL && nuevo != NULL)
    {
        nodoActividad* tmp = (*lst)->primero;
        while (tmp->siguiente != NULL)
        {
            tmp = tmp->siguiente;
        }
        tmp->siguiente = nuevo;
        nuevo->anterior = tmp;
    } else if (nuevo != NULL)
    {
        (*lst)->primero = nuevo;
    }
    
    return nuevo;
}

nodoActividad* buscarActividad(listaActividad* lst, char* nombre)
{
    nodoActividad* tmp = lst->primero;
    while (strcmp(tmp->nombre, nombre) != 0 && tmp->siguiente != NULL)
    {
        tmp = tmp->siguiente;
    }
    if (strcmp(tmp->nombre, nombre) == 0)
    {
        return tmp;
    } else
    {
        return NULL;
    }
}

void actividadToString(listaActividad* lst)
{
    char* cadena = (char*)malloc(sizeof(char));
    strcpy(cadena, "");
    nodoActividad* tmp = lst->primero;
    while (tmp != NULL)
    {
        strcat(cadena, "\nNombre ");
        strcat(cadena, tmp->nombre);
        strcat(cadena, "\nDescripcion ");
        strcat(cadena, tmp->descripcion);
        strcat(cadena, "\nFecha ");
        strcat(cadena, tmp->fecha);
        tmp = tmp->siguiente;
        
        printf("%s", cadena);
        strcpy(cadena, "");
    }
}