#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nota.h"

void new_ListaNota(listaNota** lst)
{
    (*lst)->cola = NULL;
    (*lst)->ultimoB = NULL;
    (*lst)->ultimoM = NULL;
    (*lst)->ultimoU = NULL;
    (*lst)->primero = NULL;
}

nodoNota* new_NodoNota(char* tema, char* contenido, char* prioridad)
{
    nodoNota* n = (nodoNota*)malloc(sizeof(nodoNota));
    char* p = (char*)malloc(sizeof(char));
    if (strcmp(prioridad, "U") == 0)
    {
        strcpy(p, "Urgente");
        n->idPrioridad = 1;
    } else if (strcmp(prioridad, "M") == 0)
    {
        strcpy(p, "Media");
        n->idPrioridad = 2;
    } else if (strcmp(prioridad, "B") == 0)
    {
        strcpy(p, "Baja");
        n->idPrioridad = 3;
    } else
    {
        n->idPrioridad = 4;
    }
    n->tema = tema;
    n->contenido = contenido;
    n->prioridad = p;
    n->siguiente = NULL;
    
    return n;
}

void addListaNota(listaNota** lst, char* tema, char* contenido, char* prioridad)
{
    nodoNota* nuevo = new_NodoNota(tema, contenido, prioridad);
    
    if (nuevo->idPrioridad == 1) /*URGENTE*/
    {
        if ((*lst)->ultimoU != NULL)
        {
            if ((*lst)->ultimoU->siguiente != NULL)
            {
                nuevo->siguiente = (*lst)->ultimoU->siguiente;
            }
            
            (*lst)->ultimoU->siguiente = nuevo;
        }
        (*lst)->ultimoU = nuevo;
    } else if (nuevo->idPrioridad == 2) /*MEDIO*/
    {
        
    } else if (nuevo->idPrioridad == 3) /*BAJO*/
    {
        if ((*lst)->ultimoB != NULL)
        {
            if ((*lst)->ultimoB->siguiente != NULL)
            {
                nuevo->siguiente = (*lst)->ultimoB->siguiente;
            } else
            {
                (*lst)->cola = nuevo;
            }
            
            (*lst)->ultimoB->siguiente = nuevo;
        }
        (*lst)->ultimoB = nuevo;
    } else if (nuevo->idPrioridad == 4) /*NORMAL*/
    {
        
    }
}

void removeListaNota(listaNota** lst)
{
    
}

void listaNotatoString(listaNota* lst)
{
    char* cadena = (char*)malloc(sizeof(char));
    strcpy(cadena, "");
    nodoNota* tmp = lst->primero;
    
    while (tmp != NULL)
    {
        strcat(cadena, "\nTema: ");
        strcat(cadena, tmp->tema);
        strcat(cadena, "\nContenido: ");
        strcat(cadena, tmp->contenido);
        strcat(cadena, "\nPrioridad: ");
        strcat(cadena, tmp->prioridad);
        
        printf("%s", cadena);
        tmp = tmp->siguiente;
        strcpy(cadena, "");
    }
}