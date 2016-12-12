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
void leerContacto(listaContacto** lst, char* fileName)
{
    FILE* archivo;
    archivo = fopen(fileName, "r");
    char* texto = (char*)malloc(sizeof(char));
    char* token = (char*)malloc(sizeof(char));
    nodoContacto* tmp;
    char* nombre;
    char* mail;
    char* genero;
    char* edad;
    char* numero;
    char* compania;
    
    if (archivo != NULL)
    {
        while (!feof(archivo))
        {
            texto = fgets(texto, 128, archivo);
            printf("Texto a separar: %s\n", texto);
            
            if (texto != NULL)
            {
                char* nombre = (char*)malloc(sizeof(char));
                nombre = strtok(texto, " ,:;\n\r");
                char* mail = (char*)malloc(sizeof(char));
                mail = strtok(NULL, " ,:;\n\r");
                char* genero = (char*)malloc(sizeof(char));
                genero = strtok(NULL, " ,:;\n\r");
                char* edad = (char*)malloc(sizeof(char));
                edad = strtok(NULL, " ,:;\n\r");

                tmp = insertarContacto(lst, nombre, mail, genero, edad);

                int salir = 0;
                while (salir != 1)
                {
                    char* numero = (char*)malloc(sizeof(char));
                    numero = strtok(NULL, " ,:;\n\r");
                    if (numero != NULL)
                    {
                        char* compania = (char*)malloc(sizeof(char));
                        compania = strtok(NULL, " ,:;\n\r");

                        insertarTelefono(&tmp, numero, compania);
                    } else
                    {
                        salir = 1;
                    }
                }
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

void gestorContacto(listaContacto** lst)
{
    int opcion = 0;
    int sub_opcion;
    
    char* path;
    char* nombre;
    char* mail;
    char* genero;
    char* edad;
    char* numero;
    char* compania;
    
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
        printf("********************************\n\n");

        switch(opcion)
        {
            case 0:
                printf("[i] Volviendo al menú superior");
                break;
            case 1:
                //AGREGAR CONTACTOS
                sub_opcion = 0;
                
                do
                {
                    nodoContacto* tmp;
                    printf("[-- AGREGAR CONTACTOS --]\n");
                    
                    char* nombre = (char*)malloc(sizeof(char));
                    printf("Nombre: "); scanf("%s", nombre);
                    
                    char* mail = (char*)malloc(sizeof(char));
                    printf("Mail: "); scanf("%s", mail);
                    
                    char* genero = (char*)malloc(sizeof(char));
                    printf("Genero [M][F]: "); scanf("%s", genero);
                    
                    char* edad = (char*)malloc(sizeof(char));
                    printf("Edad: "); scanf("%s", edad);
                    
                    tmp = insertarContacto(lst, nombre, mail, genero, edad);
                    
                    int opcion_telefono = 0;
                    
                    do
                    {
                        printf("[-- AGREGAR TELEFONOS --]\n");
                        
                        char* numero = (char*)malloc(sizeof(char));
                        printf("Numero: "); scanf("%s", numero);
                        
                        char* compania = (char*)malloc(sizeof(char));
                        printf("Compania: "); scanf("%s", compania);
                        
                        insertarTelefono(&tmp, numero, compania);
                        
                        printf("\n-------------------\n"
                                "[0] Volver\n"
                                "[1] Seguir Ingresando telefonos\n"); scanf("%d", &opcion_telefono);
                    } while (opcion_telefono != 0);
                    
                    printf("\n-------------------\n"
                            "[0] Volver\n"
                            "[1] Seguir Ingresando contactos\n"); scanf("%d", &sub_opcion);
                } while (sub_opcion != 0);
              
                break;
            case 2:
                //EDITAR CONTACTOS
                
                break;
            case 3:
                //ELIMINAR CONTACTOS
                //LISTAR CONTACTOS
                    toString_contacto((*lst));
                break;
            case 4:
                //IMPORTAR CONTACTOS
                path = (char*)malloc(sizeof(char) * 10);
                printf("Direccion del archivo [*.ac]: ");
                scanf("%s", path);
                
                leerContacto(lst, path);
                
                break;
            default:
                printf("Opción no reconocida\n\n");
                break;
        }
    } while (opcion != 0);
}

void gestorActividad()
{
    int opcion = 0;
    int sub_opcion = 0;
    char* ingreso = (char*)malloc(sizeof(char));
    
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
        printf("********************************\n\n");

        switch(opcion)
        {
            case 0:
                printf("[i] Volviendo al menú superior");
                break;
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
                //IMPORTAR ACTIVIDAD
                printf("Direccion del archivo [*.aa]: ");
                scanf("%s", ingreso);
                
                break;
            default:
                printf("Opción no reconocida\n\n");
                break;
        }
    } while (opcion != 0);
}

void gestorNotaRapida()
{
    int opcion = 0;
    int sub_opcion = 0;
    char* ingreso = (char*)malloc(sizeof(char));
    
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
        printf("********************************\n\n");

        switch(opcion)
        {
            case 0:
                printf("[i] Volviendo al menú superior");
                break;
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
                //IMPORTAR NOTAS RAPIDAS
                printf("Direccion del archivo [*.an]: ");
                scanf("%s", ingreso);
                
                break;
            default:
                printf("Opción no reconocida\n\n");
                break;
        }
    } while (opcion != 0);
}

void gestorMensaje()
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
        printf("********************************\n\n");

        switch(opcion)
        {
            case 0:
                printf("[i] Volviendo al menú superior");
                break;
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
                //IMPORTAR MENSAJES
                printf("Direccion del archivo [*.am]: ");
                scanf("%s", ingreso);
                
                break;
            default:
                printf("Opción no reconocida\n\n");
                break;
        }
    } while (opcion != 0);
}

void gestorReporte()
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
        printf("********************************\n\n");

        switch(opcion)
        {
            case 0:
                printf("[i] Volviendo al menú superior");
                break;
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
        printf("********************************\n\n");

        switch(opcion)
        {
            case 1:
                //METODO CONTACTOS
                gestorContacto(&lstContacto);
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