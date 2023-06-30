#ifndef FUNCIONES_H
#define FUNCIONES_H

typedef struct
{
    char nombre[50];
    int edad;
    char nombreDueno[50];
    int id;
} Mascota;

typedef struct
{
    char descripcion[100];
    float precio;
} Servicio;

void agregarMascota(Mascota *mascotas, int *numMascotas);
void mostrarServicios(Servicio *servicios, int numServicios);
void facturarServicios(Mascota *mascotas, int numMascotas, Servicio *servicios, int numServicios);

#endif