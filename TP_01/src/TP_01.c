/*
 ============================================================================
 Name        : TP_01.c
 Author      : Weiss Mariano
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include "input.h"

int main(void)
{
	setbuf(stdout, NULL);

	//Declaracio de variables:

	int opcion;
	int retornoOpcion;
	int x; //Kilometros
	int z; //Precio Latam
	int y; //Precio Aerolineas
	float debitoLatam;
	float debitoAerolineas;
	float creditoLatam;
	float creditoAerolineas;
	float bitcoinLatam;
	float bitcoinAerolineas;
	float kilometroLatam;
	float kilometroAerolineas;
	int diferenciaPrecio;
	int flagOpcionTres;
	int flagOpcionUno;
	int flagOpcionDos;

	flagOpcionTres = 0; //Flag para validar que se cargaron datos en la opcion tres
	flagOpcionUno = 0; //Flag para validar que se cargaron datos en la opcion uno
	flagOpcionDos = 0; //Flag para validar que se cargaron datos en la opcion dos


	//Bucle do-while mientras el usuario no salga con la opcion 6

	do
	{
		retornoOpcion = utn_getNumero("\nSeleccione una de las siguientes opciones:\n1)Ingresar kilometros\n2)Ingresar Precio de Vuelos\n3)Calcular todos los costos\n4)Informar Resultados\n5)Carga forzada de datos\n6)Salir\n", &opcion, 1, 6, "ERROR, funcion mal parametrizada");
		if (retornoOpcion == 0)
		{

			switch (opcion)
			{
				case 1: //Solicitud de kilometros con validacion de rango
					retornoOpcion = utn_getNumero("Ingresar kilometros:", &x, 500, 30000, "ERROR, funcion mal parametrizada");
					while(retornoOpcion == -1)
					{
						retornoOpcion = utn_getNumero("\nERROR, ingresar kilometros:", &x, 500, 30000, "ERROR, funcion mal parametrizada");
					}
					flagOpcionUno = 1;
					break;
				case 2: //Solicitud de precios de vuelos con validacion de rango
					printf("\nIngresar precio vuelos: \n");
					retornoOpcion = utn_getNumero("\n-Precio vuelo Aerolineas:", &y, 1000, 300000, "ERROR, funcion mal parametrizada");
					while(retornoOpcion == -1)
					{
						retornoOpcion = utn_getNumero("\nERROR, ingresar precio vuelo Aerolineas:", &y, 1000, 300000, "ERROR, funcion mal parametrizada");
					}
					retornoOpcion = utn_getNumero("\n-Precio vuelo Latam:", &z, 1000, 300000, "ERROR, funcion mal parametrizada");
					while(retornoOpcion == -1)
					{
						retornoOpcion = utn_getNumero("\nERROR, ingresar precio vuelo Latam:", &z, 1000, 300000, "ERROR, funcion mal parametrizada");
					}
					flagOpcionDos = 1;
					break;
				case 3: //Calculo de precios con valores ingresados
					if(flagOpcionUno == 0 || flagOpcionDos == 0)
					{
						printf("Error, aun no hay suficientes valores ingresados\n");
					}
					else
					{
					retornoOpcion = calcularResultados(z, x, &debitoLatam, &creditoLatam, &bitcoinLatam, &kilometroLatam);

					if (retornoOpcion == -1)
					{
						printf("Error");

						opcion = 6;
					}

					retornoOpcion = calcularResultados(y, x, &debitoAerolineas, &creditoAerolineas, &bitcoinAerolineas, &kilometroAerolineas);

					retornoOpcion = difPrecio(z, y, &diferenciaPrecio);

					if (retornoOpcion == -1)
					{
						printf("Error");

						opcion = 6;
					}

					flagOpcionTres = 1;

					printf("Costos calculados\n");
					}

					break;
				case 4: //Salida de datos por consola con valores calculados
					if(flagOpcionUno == 0 || flagOpcionDos == 0)
					{
						printf("Error, aun no hay suficientes valores ingresados\n");
					}
					else
					{
						if(flagOpcionTres == 0)
						{
							printf("Error, aun no se han calculado los costos\n");
						}
						else
						{
							retornoOpcion = mostrarResultados(x, y, z, debitoAerolineas, debitoLatam, creditoAerolineas, creditoLatam, bitcoinAerolineas, bitcoinLatam, kilometroAerolineas, kilometroLatam, diferenciaPrecio);

							if (retornoOpcion == -1)
							{
								printf("Error");

								opcion = 6;
							}
						}
					}
					break;
				case 5: //Carga forzada de datos y posterior calculo y salida por consola
					x = 7090;

					y = 162965;

					z = 159339;

					retornoOpcion = calcularResultados(z, x, &debitoLatam, &creditoLatam, &bitcoinLatam, &kilometroLatam);

					retornoOpcion = calcularResultados(y, x, &debitoAerolineas, &creditoAerolineas, &bitcoinAerolineas, &kilometroAerolineas);

					retornoOpcion = difPrecio(z, y, &diferenciaPrecio);

					if (retornoOpcion == -1)
					{
						printf("Error");

						opcion = 6;
					}

					retornoOpcion = mostrarResultados(x, y, z, debitoAerolineas, debitoLatam, creditoAerolineas, creditoLatam, bitcoinAerolineas, bitcoinLatam, kilometroAerolineas, kilometroLatam, diferenciaPrecio);

					if (retornoOpcion == -1)
					{
						printf("Error");

						opcion = 6;
					}

					break;
				case 6: //Salida del bucle y finalizacion del programa
					break;

			}

		}
		else
		{
			printf("\nIngrese una opcion valida:\n\n");
		}


	}while(opcion != 6);

	return EXIT_SUCCESS;
}
