/* 
 * File:   nota.h
 * Author: marco
 *
 * Created on 10 de diciembre de 2016, 11:08 PM
 */

#ifndef NOTA_H
#define NOTA_H

typedef struct nodoNota
{
    int idPrioridad; //1.URGUENTE 2.MEDIA 3.BAJA 4.NINGUNA
    char* tema;
    char* contenido;
    char* prioridad;
    struct nodoNota* siguiente;
}nodoNota;

typedef struct listaNota
{
    nodoNota* primero;
    nodoNota* ultimoU;
    nodoNota* ultimoM;
    nodoNota* ultimoB;
    nodoNota* cola;
}listaNota;

void new_ListaNota(listaNota** lst);
nodoNota* new_NodoNota(char* tema, char* contenido, char* prioridad);

void addListaNota(listaNota** lst, char* tema, char* contenido, char* prioridad);
void removeListaNota(listaNota** lst);

void listaNotatoString(listaNota* lst);

#endif /* NOTA_H */