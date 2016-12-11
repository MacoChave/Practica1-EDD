/* 
 * File:   contacto.h
 * Author: marco
 *
 * Created on 10 de diciembre de 2016, 12:36 AM
 */

#ifndef CONTACTO_H
#define CONTACTO_H

typedef struct nodoTelefono
{
    char* numero;
    char* compania;
    struct nodoTelefono* siguiente;
}nodoTelefono;

typedef struct nodoContacto
{
    char* nombre;
    char* mail;
    char* genero;
    char* edad;
    nodoTelefono* telefono;
    struct nodoContacto* anterior;
    struct nodoContacto* siguiente;
}nodoContacto;

typedef struct listaContacto
{
    nodoContacto* primero;
    nodoContacto* ultimo;
}listaContacto;

void new_ListaContacto(listaContacto** lst);
nodoContacto* new_NodoContacto(char* nombre, char* mail, char* genero, char* edad);
nodoTelefono* new_NodoTelefono(char* numero, char* compania);

int ListaTelefonoisEmpty(nodoContacto* ct);
int ListaContactoisEmpty(listaContacto* lst);
nodoContacto* insertarContacto(listaContacto** lst, 
        char*nombre, char* mail, char* genero, char* edad);
void insertarTelefono(nodoContacto** ndCt, char* numero, char* compania);

nodoContacto* buscarContactoNombre(listaContacto* lst, char* nombre);
nodoContacto* buscarContactoNumero(nodoContacto* p, nodoContacto* a, char* numero);
int buscarTelefono(nodoContacto* ndCt, char* numero);

void toString_contacto(listaContacto* lst);
char* toString_telefono(nodoContacto* ndCt);

#endif /* CONTACTO_H */

