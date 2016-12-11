/* 
 * File:   actividad.h
 * Author: marco
 *
 * Created on 10 de diciembre de 2016, 04:46 PM
 */

#ifndef ACTIVIDAD_H
#define ACTIVIDAD_H

typedef struct nodoActividad
{
    char* fecha;
    char* nombre;
    char* descripcion;
    struct nodoContacto* contacto;
    struct nodoActividad* anterior;
    struct nodoActividad* siguiente;
}nodoActividad;

typedef struct listaActividad
{
    nodoActividad* primero;
}listaActividad;

void new_ListaActividad(listaActividad** lst);
nodoActividad* new_NodoActividad(char* fecha, char* nombre, char* descripcion);

nodoActividad* insertarActividad(listaActividad** lst,
        char* fecha, char* nombre, char* descripcion);

nodoActividad* buscarActividad(listaActividad* lst, char* nombre);

void actividadToString(listaActividad* lst);

#endif /* ACTIVIDAD_H */

