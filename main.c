/* 
 * File:   main.c
 * Author: marco
 *
 * Created on 9 de diciembre de 2016, 09:41 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contacto.h"
#include "actividad.h"
#include "nota.h"
#include "mensaje.h"

char* deliminardor(char* TIPOARCHIVO)
{
    char* dl = (char*)malloc(sizeof(char));
    if (strcmp(TIPOARCHIVO, "contactos.ac") == 0)
    {
        strcpy(dl, " ,:;");
    } else if (strcmp(TIPOARCHIVO, "actividades.aa") == 0)
    {
        strcpy(dl, ",:;");
    } else if (strcmp(TIPOARCHIVO, "mensajes.am") == 0)
    {
        strcpy(dl, ",;");
    } else if (strcmp(TIPOARCHIVO, "notas.an") == 0)
    {
        strcpy(dl, ",:;");
    } else
    {
        strcpy(dl, ",:;");
    }
        return dl;
}

/**
 * @param char* fileName
 */
void leerArchivo(char* fileName)
{
    FILE* archivo;
    archivo = fopen(fileName, "r");
    char* texto = (char*)malloc(sizeof(char) * 256);
    char* token = (char*)malloc(sizeof(char) * 50);
    
    if (archivo != NULL)
    {
        while (!feof(archivo))
        {
            texto = fgets(texto, 256, archivo);
            printf("Texto a separar: %s\n", texto);
            token = strtok(texto, deliminardor(fileName));
            while (token != NULL)
            {
                printf("Token: %s\n", token);
                token = strtok(NULL, deliminardor(fileName));
            }
            fflush(archivo);
        }
    } else
    {
        printf("No se puede abrir el archivo.\n");
    }
    if (archivo != NULL)
    {
        fclose(archivo);
    }
}

/**
 * @param char* fileName
 */
void crearArchivo(char* fileName, char* texto)
{
   FILE* archivo;
   archivo = fopen(fileName, "w");
//   char* texto = "Archivo creado con éxito.\n"
//                    "Prueba de creación de archivo";
   
   if (archivo != NULL)
   {
       fputs(texto, archivo);
   } else
   {
       printf("No se puede crear el archivo\n");
   }
   if (archivo != NULL)
   {
       fclose(archivo);
   }
}

void gestorContacto()
{
    int opcion = 0;
    int sub_opcion = 0;
    char* ingreso = (char*)malloc(sizeof(char) * 15);
    
    do
    {
        printf("--------------------------------\n");
        printf("         MENU CONTACTO          \n");
        printf("--------------------------------\n");
        printf("[0] Salir\n");
        printf("[1] Agregar\n");
        printf("[2] Editar\n");
        printf("[-] Eliminar\n");
        printf("[3] Listar\n");
        printf("[4] Importar\n\n");
        printf("--------------------------------\n");
        printf("Seleccione una opción: ");    
        scanf("%d", &opcion);
        printf("--------------------------------\n\n");

        switch(sub_opcion)
        {
            case 1:
                //AGREGAR CONTACTOS
                
                break;
            case 2:
                //EDITAR CONTACTOS
                
                break;
            case 3:
                //ELIMINAR CONTACTOS
                
                break;
            case 4:
                //LISTAR CONTACTOS
                
                break;
            case 5:
                //IMPORTAR CONTACTOS
                printf("Direccion del archivo: [*.ac]");
                scanf("%s", ingreso);
                
                break;
            default:
                printf("Opción no reconocida\n\n");
                break;
        }
    } while (opcion != 0);
}

gestorActividad()
{
    int opcion = 0;
    int sub_opcion = 0;
    char* ingreso = (char*)malloc(sizeof(char) * 15);
    
    do
    {
        printf("--------------------------------\n");
        printf("         MENU ACTIVIDAD         \n");
        printf("--------------------------------\n");
        printf("[0] Salir\n");
        printf("[1] Agregar\n");
        printf("[2] Editar\n");
        printf("[-] Eliminar\n");
        printf("[3] Listar\n");
        printf("[4] Importar\n\n");
        printf("--------------------------------\n");
        printf("Seleccione una opción: ");    
        scanf("%d", &opcion);
        printf("--------------------------------\n\n");

        switch(sub_opcion)
        {
            case 1:
                //AGREGAR ACTIVIDAD
                
                break;
            case 2:
                //EDITAR ACTIVIDAD
                
                break;
            case 3:
                //ELIMINAR ACTIVIDAD
                
                break;
            case 4:
                //LISTAR ACTIVIDAD
                
                break;
            case 5:
                //IMPORTAR ACTIVIDAD
                printf("Direccion del archivo: [*.aa]");
                scanf("%s", ingreso);
                
                break;
            default:
                printf("Opción no reconocida\n\n");
                break;
        }
    } while (opcion != 0);
}

gestorNotaRapida()
{
    int opcion = 0;
    int sub_opcion = 0;
    char* ingreso = (char*)malloc(sizeof(char) * 15);
    
    do
    {
        printf("--------------------------------\n");
        printf("       MENU NOTA RAPIDA         \n");
        printf("--------------------------------\n");
        printf("[0] Salir\n");
        printf("[1] Agregar\n");
        printf("[2] Editar\n");
        printf("[-] Eliminar\n");
        printf("[3] Listar\n");
        printf("[4] Importar\n\n");
        printf("--------------------------------\n");
        printf("Seleccione una opción: ");    
        scanf("%d", &opcion);
        printf("--------------------------------\n\n");

        switch(sub_opcion)
        {
            case 1:
                //AGREGAR NOTAS RAPIDAS
                
                break;
            case 2:
                //EDITAR NOTAS RAPIDAS
                
                break;
            case 3:
                //ELIMINAR NOTAS RAPIDAS
                
                break;
            case 4:
                //LISTAR NOTAS RAPIDAS
                
                break;
            case 5:
                //IMPORTAR NOTAS RAPIDAS
                printf("Direccion del archivo: [*.an]");
                scanf("%s", ingreso);
                
                break;
            default:
                printf("Opción no reconocida\n\n");
                break;
        }
    } while (opcion != 0);
}

gestorMensaje()
{
    int opcion = 0;
    int sub_opcion = 0;
    char* ingreso = (char*)malloc(sizeof(char) * 15);
    
    do
    {
        printf("--------------------------------\n");
        printf("          MENU MENSAJE          \n");
        printf("--------------------------------\n");
        printf("[0] Salir\n");
        printf("[1] Agregar\n");
        printf("[2] Editar\n");
        printf("[-] Eliminar\n");
        printf("[3] Listar\n");
        printf("[4] Importar\n\n");
        printf("--------------------------------\n");
        printf("Seleccione una opción: ");    
        scanf("%d", &opcion);
        printf("--------------------------------\n\n");

        switch(sub_opcion)
        {
            case 1:
                //AGREGAR MENSAJES
                
                break;
            case 2:
                //EDITAR MENSAJES
                
                break;
            case 3:
                //ELIMINAR MENSAJES
                
                break;
            case 4:
                //LISTAR MENSAJES
                
                break;
            case 5:
                //IMPORTAR MENSAJES
                printf("Direccion del archivo: [*.am]");
                scanf("%s", ingreso);
                
                break;
            default:
                printf("Opción no reconocida\n\n");
                break;
        }
    } while (opcion != 0);
}

gestorReporte()
{
    int opcion = 0;
    int sub_opcion = 0;
    char* ingreso = (char*)malloc(sizeof(char) * 15);
    
    do
    {
        printf("--------------------------------\n");
        printf("         MENU REPORTES          \n");
        printf("--------------------------------\n");
        printf("[0] Salir\n");
        printf("[1] Grafico estructura contactos\n");
        printf("[2] Grafico estructura actividades\n");
        printf("[3] Grafico estructura mensajes\n");
        printf("[4] Grafico estructura notas rapidas\n");
        printf("[5] Ver todos los graficos\n\n");
        printf("--------------------------------\n");
        printf("Seleccione una opción: ");    
        scanf("%d", &opcion);
        printf("--------------------------------\n\n");

        switch(sub_opcion)
        {
            case 1:
                //GRAFICO CONTACTOS
                
                break;
            case 2:
                //GRAFICO ACTIVIDADES
                
                break;
            case 3:
                //GRAFICO MENSAJES
                
                break;
            case 4:
                //GRAFICO NOTAS RAPIDAS
                
                break;
            case 5:
                //VER GRAFICOS
                
                break;
            default:
                printf("Opción no reconocida\n\n");
                break;
        }
    } while (opcion != 0);
}

/**
 * @param argc
 * @param argv
 * @return 
 */
int main(int argc, char** argv)
{
 
    listaContacto* lstContacto;
    listaActividad* lstActividad;
    listaNota* lstNota;
    listaMensaje* lstMensaje;

    lstContacto = (listaContacto*) malloc(sizeof(listaContacto));
    new_ListaContacto(&lstContacto);
    lstActividad = (listaActividad*) malloc(sizeof(listaActividad));
    new_ListaActividad(&lstActividad);
    lstNota = (listaNota*) malloc(sizeof(listaNota));
    new_ListaNota(&lstNota);
    lstMensaje = (listaMensaje*) malloc(sizeof(listaMensaje));
    new_ListaMensaje(&lstMensaje);
    
    nodoContacto* tmp;
    
    int opcion = 0;
    do
    {
        printf("--------------------------------\n");
        printf(" PRACTICA #1: Agenda Telefónica\n");
        printf("--------------------------------\n");
        printf("        MENU PRINCIPAL          \n");
        printf("--------------------------------\n");
        printf("[0] Salir\n");
        printf("[1] Contactos\n");
        printf("[2] Actividades\n");
        printf("[3] Notas rápidas\n");
        printf("[4] Mensajes\n");
        printf("[5] Reportes\n\n");
        printf("--------------------------------\n");
        printf("Seleccione una opción: ");
        
        scanf("%d", &opcion);
        printf("--------------------------------\n\n");

        switch(opcion)
        {
            case 1:
                //METODO CONTACTOS
                gestorContacto();
                break;
            case 2:
                //METOD ACTIVIDADES
                gestorActividad();
                break;
            case 3:
                //METODO NOTAS RAPIDAS
                gestorNotaRapida();
                break;
            case 4:
                //METODO MENSAJES
                gestorMensaje();
                break;
            case 5:
                //METODO REPORTE
                gestorReporte();
                break;
            default:
                printf("Opción no reconocida\n\n");
                break;
        }
    } while (opcion != 0);
    
    
//    char* texto = (char*)malloc(sizeof(char) * 256);
//    printf("Ingrese un texto: ");
//    scanf("%s", texto);
//    gets(texto);
//    fflush(stdin);
    
//    crearArchivo("prueba.txt", texto);
    
//    strcpy(texto, "");
//    printf("Ingrese el path del archivo: ");
//    scanf("%s", texto);
//    gets(texto);
//    fflush(stdin);
    
//    leerArchivo(texto);
    
    return (EXIT_SUCCESS);
}