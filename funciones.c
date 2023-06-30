#include <stdio.h>
#include "funciones.h"

#define MAX_MASCOTAS 100
#define MAX_DESCRIPCION 100

void agregarMascota(Mascota *mascotas, int *numMascotas)
{
    if (*numMascotas >= MAX_MASCOTAS)
    {
        printf("No se pueden agregar mas mascotas.\n");
        return;
    }

    Mascota nuevaMascota;
    printf("Ingrese el nombre de la mascota: ");
    scanf("%s", nuevaMascota.nombre);
    printf("Ingrese la edad de la mascota: ");
    scanf("%d", &nuevaMascota.edad);
    printf("Ingrese el nombre del dueno: ");
    scanf("%s", nuevaMascota.nombreDueno);

    nuevaMascota.id = *numMascotas + 1;

    mascotas[*numMascotas] = nuevaMascota;
    (*numMascotas)++;

    printf("Mascota agregada correctamente con ID %d.\n", nuevaMascota.id);
}

void mostrarServicios(Servicio *servicios, int numServicios)
{
    printf("Servicios disponibles:\n");
    for (int i = 0; i < numServicios; i++)
    {
        printf("%d. %s - $%.2f\n", i + 1, servicios[i].descripcion, servicios[i].precio);
    }
}

void facturarServicios(Mascota *mascotas, int numMascotas, Servicio *servicios, int numServicios)
{
    int id;
    float total = 0.0;

    printf("Ingrese el ID de la mascota: ");
    scanf("%d", &id);

    int encontrado = 0;
    for (int i = 0; i < numMascotas; i++)
    {
        if (mascotas[i].id == id)
        {
            encontrado = 1;
            printf("Mascota encontrada:\n");
            printf("Nombre: %s\n", mascotas[i].nombre);
            printf("Edad: %d\n", mascotas[i].edad);
            printf("Dueno: %s\n", mascotas[i].nombreDueno);

            printf("Seleccione los servicios que desea realizar (separados por comas): ");
            int opcion;
            scanf("%d", &opcion);

            while (opcion != 0)
            {
                if (opcion > 0 && opcion <= numServicios)
                {
                    total += servicios[opcion - 1].precio;
                }
                else
                {
                    printf("Opcion invalida. Por favor, seleccione una opcion valida.\n");
                }

                scanf("%d", &opcion);
            }

            printf("Total a pagar: $%.2f\n", total);

            printf("Gracias por elegirnos. ¡Esperamos verlos nuevamente!\n");
            break;
        }
    }

    if (!encontrado)
    {
        printf("No se encontro una mascota con ese ID.\n");
    }
}