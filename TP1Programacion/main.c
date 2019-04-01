#include <stdio.h>
#include <stdlib.h>
#include "biblioteca.h"


int main()
{

    float numeroA;
    float numeroB;
    int opcion;
    char seguir = 's';
    float numeroSuma;
    float numeroResta;
    float numeroMulti;
    float numeroDivision;
    int numeroFactorialA;
    int numeroFactorialB;

    do
    {
        opcion = pedirOpcionMenu(" 1. Ingresar 1er operando (A=x) \n 2. Ingresar 2do operando (B=y) \n 3. Calcular todas las operaciones \n 4. Informar resultados \n 5. Salir \n Elija una opcion: ");



        switch(opcion)
        {
        case 1:

            printf("\nIngrese el operando A: ");
            scanf("%f",&numeroA);
            break;


        case 2:

            printf("\nIngrese el operando B: ");
            scanf("%f",&numeroB);
            break;

        case 3:


            /** SUMA */

            numeroSuma = hacerSuma (numeroA, numeroB) ;

            /** RESTA */

            numeroResta = hacerResta (numeroA, numeroB) ;

            /** MULTIPLICACION */

            numeroMulti = hacerMultiplicacion(numeroA, numeroB) ;

            /** DIVISION */

            if (numeroB > 0)
            {

                numeroDivision = hacerDivision(numeroA, numeroB);

            }

            /** NUMERO FACTORIAL DE CADA OPERANDO */


            numeroFactorialA = hacerFactorial (numeroA);
            numeroFactorialB = hacerFactorial (numeroB);


            printf (" Las cuentas ya se calcularon!  :) \n ");

            /** Se realizan las cuentas sin mostrarlas al usuario */

            break;

        case 4:

            /** Se muestran los resultados al usuario */

            printf (" a) El resultado de %.1f + %.1f es: %.2f \n", numeroA, numeroB, numeroSuma);
            printf (" a) El resultado de %.1f - %.1f es: %.2f \n", numeroA, numeroB, numeroResta);
            printf (" a) El resultado de %.1f * %.1f es: %.2f \n", numeroA, numeroB, numeroMulti);

            /** Division si el operandoB es 0 */

            if (numeroB == 0)
            {
                printf (" d) No se puede dividir si el operandoB es 0 \n");
            }
            else
            {
                printf (" a) El resultado de %.1f / %.1f es: %.2f \n", numeroA, numeroB, numeroDivision);

            }

                printf(" e) El factorial de A es: %.1d y el factorial de B es: %.1d \n ", numeroFactorialA, numeroFactorialB);

            break;

        /** Boton para salir del Menu */

        case 5:
            seguir = 'n';
            break;


        /** Accion que se realiza si no se pone un numero de los indicados */

        default:
            printf ("Opcion incorrecta \n");
            break;
        }

        /** Comandos para que el MENU no se reinicie y queden datos guardados */

        system("pause");
        system ("cls");

        }

    while(seguir == 's');



    return 0;
}



