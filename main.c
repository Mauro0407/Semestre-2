#include <stdio.h>
#include "funciones.h"

#define MAX_MASCOTAS 100
#define MAX_SERVICIOS 3

int main()
{
    Mascota mascotas[MAX_MASCOTAS];
    int numMascotas = 0;

    Servicio servicios[MAX_SERVICIOS] = {
        {"Corte de cabello", 20.0},
        {"Lavado", 15.0},
        {"Corte de unas", 10.0}};

    int opcion;

    do
    {
        printf("\n---Veterinaria Udla---\n");
        printf("1. Agregar mascota\n");
        printf("2. Mostrar servicios\n");
        printf("3. Facturar servicios\n");
        printf("0. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            agregarMascota(mascotas, &numMascotas);
            break;
        case 2:
            mostrarServicios(servicios, MAX_SERVICIOS);
            break;
        case 3:
            facturarServicios(mascotas, numMascotas, servicios, MAX_SERVICIOS);
            break;
        case 0:
            printf("Saliendo del programa.\n");
            break;
        default:
            printf("Opcion no valida. Por favor, seleccione una opcion valida.\n");
            break;
        }
    } while (opcion != 0);

    return 0;
}