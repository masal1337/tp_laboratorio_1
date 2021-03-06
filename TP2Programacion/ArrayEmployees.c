#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"


eEmpleado pedirEmpleado()
{
    eEmpleado empleadoParaRetornar;

    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(empleadoParaRetornar.name);

    printf("Ingrese apellido: ");
    fflush(stdin);
    gets(empleadoParaRetornar.lastName);

    printf("Ingrese salario: ");
    scanf("%f", &empleadoParaRetornar.salary);

    printf("Ingrese sector: ");
    scanf("%d", &empleadoParaRetornar.sector);

    empleadoParaRetornar.isEmpty = OCUPADO;

    return empleadoParaRetornar;
}


void mostrarEmpleado(eEmpleado unEmpleado)
{

    printf("%15d- %15s- %10s- %10.2f- %10d-%5d\n", unEmpleado.id, unEmpleado.name, unEmpleado.lastName, unEmpleado.salary, unEmpleado.sector, unEmpleado.isEmpty);

}





void printEmployees(eEmpleado listado[], int cant)
{
    int i;
    for(i=0; i<cant; i++)
    {
        if(listado[i].isEmpty==OCUPADO)
        {

            mostrarEmpleado(listado[i]);
        }


    }
}


void initEmployees(eEmpleado listado[], int cant)
{
    int i;
    for(i=0; i<cant; i++)
    {
        listado[i].id= LIBRE;
        listado[i].isEmpty= LIBRE;
        listado[i].salary= 0;
        listado[i].sector= 0;
        strcpy(listado[i].name, "");
        strcpy(listado[i].lastName, "");

    }
}


int addEmployees(eEmpleado listado[], int tam)
{
    int idGenerico;
    int indice;
    indice= dameLugarLibre(listado, tam);

    if(indice != -1)
    {
        idGenerico = generarId(listado,tam);
        listado[indice].id = idGenerico;
        listado[indice]= pedirEmpleado();
    }
    return indice;
}

int generarId(eEmpleado listado[],int limite)
{
    int retorno = 0;
    int i;
    if(limite > 0 && listado != NULL)
    {
        for(i=0; i<limite; i++)
        {
            if(listado[i].isEmpty == OCUPADO)
            {
                if(listado[i].id>retorno)
                {
                    retorno=listado[i].id;

                }

            }
        }
    }

    return retorno++;
}



int dameLugarLibre(eEmpleado listado[], int tam)
{
    int i;
    int index = -1;

    for(i=0; i<tam; i++)
    {
        if(listado[i].isEmpty==LIBRE)
        {
            index = i;
            break;
        }
    }
    return index;
}





int removeEmployee(eEmpleado lista[], int tam)
{


    int i;
    int codigo;
    int loEncontro = 0;

    for (i=0; i<tam; i++)
    {

        if (lista[i].isEmpty==OCUPADO)
        {
            printf("\nSu ID: %d \t-----\t name: %s  ", lista[i].id, lista[i].name);
        }

    }

    printf("\n\n-------------------------------\n");
    printf("\n\nIngrese el ID: ");
    fflush(stdin);
    scanf("%d", &codigo);

    for(i=0; i<tam; i++)
    {
        if(lista[i].id == codigo)
        {
            lista[i].isEmpty = LIBRE;
            loEncontro = 1;
            break;
        }

    }

    if(loEncontro==0)
    {
        printf("\nCodigo inexistente!!\n");
    }

return 0;
}

int editarEmpleado(eEmpleado lista[], int tam)
{
    int i;
    int codigo;
    int loEncontro = 0;
    int menu;

    for (i=0; i<tam; i++)
    {

        if (lista[i].isEmpty==OCUPADO)
        {
            printf("\nSu ID: %d \t-----\t name: %s  \n\n", lista[i].id, lista[i].name);
        }

    }

    printf("Ingrese el ID: ");
    fflush(stdin);
    scanf("%d", &codigo);

    for(i=0; i<tam; i++)
    {
        if(lista[i].id == codigo)
        {
            loEncontro = 1;
            menu = menuOp("Que dato desea cambiar?\n1.NOMBRE\n2.APELLIDO\n3.SALARIO\n4.SECTOR\n\n0.SALIR\n\n -Elegi una opcion: ");

                switch(menu)
                    {
                            case 1:
                            printf("\nIngrese el nuevo nombre: ");
                            fflush(stdin);
                            gets(lista[i].name);
                        break;
                            case 2:
                            printf("\nIngrese el nuevo lastName: ");
                            fflush(stdin);
                            gets(lista[i].lastName);
                        case 3:
                            printf("\nIngrese el nuevo salary: ");
                            fflush(stdin);
                            scanf("%f", &lista[i].salary);
                            break;
                        case 4:
                            printf("\nIngrese el nuevo sector: ");
                            fflush(stdin);
                            scanf("%d", &lista[i].sector);
                            break;

                        case 0:

                            break;

                        default:
                            printf("\nIngrese una opcion valida.\n");
                            break;

                        }
                }

            }
        if(loEncontro==0)
    {
        printf("\nCodigo inexistente!!\n");
    }

    return 0;
}

void sortEmployees (eEmpleado list[], int tam)
{

    eEmpleado empleadoAux;
    int order = 1;

    int i;
    int j;
    if(order == 1)
    {

        for(i=0; i<tam-1; i++)
        {
            for(j=i+1; j<tam; j++)
            {
                if(stricmp(list[i].lastName,list[j].lastName) > 0)
                {
                    ///SWAP
                    empleadoAux = list[i];
                    list[i] = list[j];
                    list[j] = empleadoAux;
                }

                else if (stricmp(list[i].lastName,list[j].lastName) == 0 )
                {

                    if(list[i].sector > list[j].sector)
                    {

                        empleadoAux = list[i];
                        list[i] = list[j];
                        list[j] = empleadoAux;
                    }
                }
            }
        }
    }
}


float sueldo(eEmpleado listado[], int tam)
{
    int i;
    int contador = 0;
    float acumulador = 0;
    float promedio;
    int mayorsalaryMin = 0;

    for(i=0; i<tam; i++)
    {
        if(listado[i].isEmpty==OCUPADO)
        {
            if (listado[i].salary > 15000)
            {

                mayorsalaryMin ++;

            }
            acumulador = acumulador + listado[i].salary;
            contador++;

        }

        promedio = acumulador / contador;

    }

    printf("\n\t- La suma de todos los sueldos es de: \t%.2f \n\t- El promedio de todos los sueldos es: \t%.2f", acumulador, promedio);
    printf("\n\t- La cantidad de empleados que superan el salary minimo es de: %.2d", mayorsalaryMin);
    return 0;
}

int menuOp(char mensaje[])
{
    int opcion;
    printf("%s", mensaje);
    scanf("%d", &opcion);

    return opcion;
}



