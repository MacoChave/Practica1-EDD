/* 
 * File:   mensaje.h
 * Author: marco
 *
 * Created on 11 de diciembre de 2016, 11:45 AM
 */

#ifndef MENSAJE_H
#define MENSAJE_H

typedef struct nodoMensaje
{
    char* mensaje;
    char* telefono;
    char* nombre;
    struct nodoMensaje* siguiente;
}nodoMensaje;

typedef struct listaMensaje
{
    nodoMensaje* cima;
}listaMensaje;

void new_ListaMensaje(listaMensaje** lst);
nodoMensaje* new_NodoMensaje(char* mensaje, char* telefono);

int empty_listaMensaje(listaMensaje* lst);
int size_listaMensaje(listaMensaje* lst);
void push_listaMensaje(listaMensaje** lst, char* mensaje, char* telefono);
void pop_listaMensaje(listaMensaje** lst);
nodoMensaje* peek_listaMensaje(listaMensaje* lst);

int search_listaMensaje(listaMensaje* lst, char* mensaje);
void toString_listaMensaje(listaMensaje* lst);

#endif /* MENSAJE_H */

