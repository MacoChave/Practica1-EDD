#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contacto.h"
#include "actividad.h"

void new_ListaContacto(listaContacto** lst)
{
    (*lst)->primero = NULL;
    (*lst)->ultimo = NULL;
}

nodoContacto* new_NodoContacto(char* nombre, char* mail, char* genero, char* edad)
{
    nodoContacto* nuevo = (nodoContacto*)malloc(sizeof(nodoContacto));
    
    if (nuevo != NULL)
    {
        nuevo->nombre = nombre;
        nuevo->mail = mail;
        nuevo->genero = genero;
        nuevo->edad = edad;
        nuevo->telefono = NULL;
        nuevo->anterior = NULL;
        nuevo->siguiente = NULL;

        return nuevo;
    } else
    {
        printf("No hay espacion en memoria");
        return NULL;
    }
}

nodoTelefono* new_NodoTelefono(char* numero, char* compania)
{
    nodoTelefono* nuevo = (nodoTelefono*)malloc(sizeof(nodoTelefono));
    
    if (nuevo != NULL)
    {
        nuevo->numero = numero;
        nuevo->compania = compania;
        nuevo->siguiente = NULL;
    
        return nuevo;
    } else
    {
        printf("No hay espacio en memoria");
        
        return NULL;
    }
    
}

int listaTelefonoisEmpty(nodoContacto* nd)
{
    if (nd->telefono != NULL)
        return 1;
    else
        return 0;
}

int listaContactoisEmpty(listaContacto* lst)
{
    if (lst->primero != NULL)
        return 1;
    else
        return 0;
}

nodoContacto* insertarContacto(listaContacto** lst, 
        char*nombre, char* mail, char* genero, char* edad)
{
    nodoContacto* nuevo = new_NodoContacto(nombre, mail, genero, edad);
    
    if (listaContactoisEmpty((*lst)) != 0 && nuevo != NULL)
    {
        nodoContacto* tmp = (*lst)->primero;
        
        while (tmp != (*lst)->ultimo)
        {
            tmp = tmp->siguiente;
        }
        
        tmp->siguiente = nuevo;
        nuevo->anterior = tmp;
        
    } else if (nuevo != NULL)
    {
        (*lst)->primero = nuevo;
    }
    (*lst)->ultimo = nuevo;
    (*lst)->ultimo->siguiente = (*lst)->primero;
    (*lst)->primero->anterior = (*lst)->ultimo;
    
    return nuevo;
}

void insertarTelefono(nodoContacto** ndCt, char* numero, char* compania)
{
    nodoTelefono* nuevo = new_NodoTelefono(numero, compania);
    
    if (listaTelefonoisEmpty((*ndCt)) != 0 && nuevo != NULL)
    {
        nodoTelefono* tmp = (*ndCt)->telefono;
        
        while (tmp->siguiente != NULL)
        {
            tmp = tmp->siguiente;
        }
        
        tmp->siguiente = nuevo;
        
    } else if (nuevo != NULL)
    {
        (*ndCt)->telefono = nuevo;
    }
}

nodoContacto* buscarContactoNombre(listaContacto* lst, char* nombre)
{
    nodoContacto* tmp = lst->primero;
    while (strcmp(tmp->nombre, nombre) != 0 && tmp != lst->ultimo )
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

nodoContacto* buscarContactoNumero(nodoContacto* p, nodoContacto* a, char* numero)
{
    if (a != NULL)
    {
        if (a->siguiente == p)
        {
            if (buscarTelefono(a, numero) == 1)
                return a;
            else
                return NULL;
        } else
        {
            if (buscarTelefono(a, numero) == 1)
                return a;
            else
                return buscarContactoNumero(p, a->siguiente, numero);
        }
    } else
    {
        return NULL;
    }
}

int buscarTelefono(nodoContacto* ndCt, char* numero)
{
    nodoTelefono* tmp = ndCt->telefono;
    
    while (tmp->siguiente != NULL && tmp->numero != numero)
        tmp = tmp->siguiente;
    
    if (tmp->numero = numero)
        return 1;
    else
        return 0;
    
}

void toString_contacto(listaContacto* lst)
{
    char* cadena = (char*)malloc(sizeof(char));
    strcpy(cadena, "");
    nodoContacto* tmp = lst->primero;
    while (tmp->siguiente != lst->primero)
    {
        strcat(cadena, "\nNombre: ");
        strcat(cadena, tmp->nombre);
        strcat(cadena, "\nMail: ");
        strcat(cadena, tmp->mail);
        strcat(cadena, "\nGenero: ");
        strcat(cadena, tmp->genero);
        strcat(cadena, "\nEdad: ");
        strcat(cadena, tmp->edad);
        strcat(cadena, "\nTelefono: ");
        strcat(cadena, toString_telefono(tmp));
        tmp = tmp->siguiente;
        
        printf("%s", cadena);
        strcpy(cadena, "");
    }
}

char* toString_telefono(nodoContacto* ndCt)
{
    char* cadena = (char*)malloc(sizeof(char));
    strcpy(cadena, "");
    nodoTelefono* tmp = ndCt->telefono;
    while (tmp != NULL)
    {
        strcat(cadena, "\n->Compania: ");
        strcat(cadena, tmp->compania);
        strcat(cadena, "\n->Numero: ");
        strcat(cadena, tmp->numero);
        tmp = tmp->siguiente;
    }
    
    return cadena;
}