#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "mensaje.h"

void new_ListaMensaje(listaMensaje** lst)
{
    (*lst)->cima = NULL;
}

nodoMensaje* new_NodoMensaje(char* mensaje, char* telefono)
{
    nodoMensaje* n = (nodoMensaje*)malloc(sizeof(nodoMensaje));
    
    if (n != NULL)
    {
        n->mensaje = mensaje;
        n->nombre = NULL;
        n->telefono = telefono;
        n->siguiente = NULL;
        
        return n;
    } else
    {
        printf("[e] No hay espacio en memoria\n");
        return NULL;
    }
}

int empty_listaMensaje(listaMensaje* lst)
{
    if (lst->cima != NULL)
        return 1;
    else
        return 0;
}

int size_listaMensaje(listaMensaje* lst)
{
    int size = 0;
    nodoMensaje* tmp = lst->cima;
    
    if (empty_listaMensaje(lst) != 0)
    {
        while (tmp != NULL)
        {
            size = size + 1;
            tmp = tmp->siguiente;
        }
        
        return size;
    } else
    {
        return size;
    }
}

void push_listaMensaje(listaMensaje** lst, char* mensaje, char* telefono)
{
    nodoMensaje* nuevo = new_NodoMensaje(mensaje, telefono);
    
    if (empty_listaMensaje((*lst)) != 0)
    {
        nuevo->siguiente = (*lst)->cima;
        (*lst)->cima = nuevo;
    } else
    {
        (*lst)->cima = nuevo;
    }
}

void pop_listaMensaje(listaMensaje** lst)
{
    nodoMensaje* tmp;
    
    if (empty_listaMensaje((*lst)) != 0)
    {
        tmp = (*lst)->cima;
        (*lst)->cima = tmp->siguiente;
        
        free(tmp);
        
        printf("[i] Mensaje liberado");
    } else
    {
        printf("[e] Lista vacía\n");
    }
}

nodoMensaje* peek_listaMensaje(listaMensaje* lst)
{
    if (empty_listaMensaje(lst) != 0)
        return lst->cima;
    else
        return NULL;
}

int search_listaMensaje(listaMensaje* lst, char* mensaje)
{
    int indice = 0;
    nodoMensaje* tmp = lst->cima;
    if (empty_listaMensaje(lst) != 0)
    {
        for (int i = 0; i <= size_listaMensaje(lst); i++)
        {
            if (strcmp(tmp->mensaje, mensaje) != 0)
            {
                indice = indice + 1;
                tmp = tmp->siguiente;
            } else
            {
                indice = indice + 1;
                break;
            }
        }
        
        return indice;
    }
    else
        return indice;
}

void toString_listaMensaje(listaMensaje* lst)
{
    char* cadena = (char*)malloc(sizeof(char));
    nodoMensaje* tmp = lst->cima;
    strcpy(cadena, "");
    
    while(tmp != NULL)
    {
        strcat(cadena, "\nMensaje: ");
        strcat(cadena, tmp->mensaje);
        strcat(cadena, "\nNombre: ");
        strcat(cadena, tmp->nombre);
        strcat(cadena, "\nTelefono: ");
        strcat(cadena, tmp->telefono);

        printf("%s", cadena);
        tmp = tmp->siguiente;
        strcpy(cadena, "");
    }
}