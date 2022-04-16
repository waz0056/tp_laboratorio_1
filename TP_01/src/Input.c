/*
 * Input.c
 *
 *  Created on: 16 abr. 2022
 *      Author: MI COMPU Weiss Mariano
 */
#include "input.h"

//Desarrollo de funciones
/** Funcion utn_getNumero
 *
 * @param mensaje Es el mensaje que va a visualizar el usuario por consola y le indica la informacion solicitada
 * @param pOpcion Es el puntero que va a ser utilizado segun necesidades en los diferenes usos de la funcion, en caso de que existan errores en argumentos, tambien lo usamos para cerrar el programa
 * @param minimo Define el minimo dentro del rango de opciones validas
 * @param maximo Define el maximo dentro del rango de opciones validas
 * @param mensajeError Es el mensaje a mostrar en caso de que los parametros sean inconsistentes
 * @return Lo utilizamos para corroborar que el usuario haya ingresado un valor valido, de lo contrario informamos del error
 */
int utn_getNumero(char* mensaje, int* pOpcion, int minimo, int maximo, char* mensajeError)
{
	int retorno;
	int auxiliarInt;

	if(mensaje != NULL && pOpcion != NULL && minimo<maximo && mensajeError != NULL)
	{
		printf("%s", mensaje);
		scanf("%d", &auxiliarInt);

		*pOpcion = auxiliarInt;

		if(auxiliarInt<minimo || auxiliarInt>maximo)
		{
			retorno = -1;
		}
		else
		{
			retorno = 0;
		}
	}
	else
	{
		printf("%s", mensajeError);

		*pOpcion = 6;
	}

	return retorno;
}

/** Funcion calcularResultados
 *
 * @param precio Indica el precio ingresado
 * @param kilometros Indica los kilometros ingresados
 * @param pResultadoDebito Devuelve como puntero el valor a abonar con tarjeta de debito
 * @param pResultadoCredito Devuelve como puntero el valor a abonar con tarjeta de credito
 * @param pResultadoBitcoin Devuelve como puntero el valor a abonar en bitcoin
 * @param pPrecioPorKilometro Devuelve como puntero el valor unitario por kilometro
 * @return Usamos el valor de retorno para comprobar el correcto funcionamiento de la funcion
 */
float calcularResultados(float precio, float kilometros, float *pResultadoDebito, float *pResultadoCredito, float *pResultadoBitcoin, float *pPrecioPorKilometro)
{
	int retorno;

	retorno = -1;

	if(pResultadoDebito != NULL && pResultadoCredito != NULL && pResultadoBitcoin != NULL && pPrecioPorKilometro != NULL)
	{
		*pResultadoDebito = precio * 0.9;

		*pResultadoCredito = precio * 1.25;

		*pResultadoBitcoin = precio / 4606954.55;

		*pPrecioPorKilometro = precio / kilometros;

		retorno = 0;
	}

	return retorno;
}

/** Funcion difPrecio
 *
 * @param precioUno Toma el valor de precio de una de las empresas de vuelos
 * @param precioDos Toma el valor de precio de una de las empresas de vuelos
 * @param pDiferenciaDePrecio Devuelve como puntero la diferencia de precio entre las mismas
 * @return Se usa el valor de return para corroborar el correcto funcionamiento de la funcion propiamente dicha
 */
float difPrecio(int precioUno, int precioDos, int *pDiferenciaDePrecio)
{
	float retorno;

	retorno = -1;

	if(pDiferenciaDePrecio != NULL)
	{
		if(precioUno > precioDos)
		{
			*pDiferenciaDePrecio = precioUno - precioDos;

			retorno = 0;
		}
		else
		{
			*pDiferenciaDePrecio = precioDos - precioUno;

			retorno = 0;
		}
	}


	return retorno;
}

/** Funcion mostrarResultados
 * Esta funcion toma todos los valores obtenidos por ingreso del usuario y tambien calculados por el programa y los imprime por consola
 *
 * @param kilometros Son los kilometros ingresados por el usuario
 * @param precioAerolineas Es el precio de Aerolineas ingresado por el usuario
 * @param precioLatam Es el precio de Latam ingresado por el usuario
 * @param debitoAerolineas Es el valor viajando en Aerolineas abonando con debito
 * @param debitoLatam Es el valor viajando en Latam abonando con debito
 * @param creditoAerolineas Es el valor viajando en Aerolineas abonando con credito
 * @param creditoLatam Es el valor viajando en Latam abonando con credito
 * @param bitcoinAerolineas Es el valor viajando en Aerolineas abonando con bitcoin
 * @param bitcoinLatam Es el valor viajando en Latam abonando con bitcoin
 * @param kilometroAerolineas Es el precio unitario por kilometro en Aerolineas
 * @param kilometroLatam Es el precio unitario por kilometro en Latam
 * @param DiferenciaDePrecio Es la diferencia de precio entre ambas empresas de vuelos
 * @return
 */
float mostrarResultados(float kilometros, float precioAerolineas, float precioLatam, float debitoAerolineas, float debitoLatam, float creditoAerolineas, float creditoLatam, float bitcoinAerolineas, float bitcoinLatam, float kilometroAerolineas, float kilometroLatam, float DiferenciaDePrecio)
{
	float retorno = 0;

	printf("KMs Ingresados: %.2f\n\n", kilometros);
	printf("Precio Aerolineas: %.0f\n", precioAerolineas);
	printf("a)Precio con tarjeta de debito: %.2f\n", debitoAerolineas);
	printf("b)Precio con tarjeta de credito: %.2f\n", creditoAerolineas);
	printf("c)Precio pagando con Bitcoin: %.2f\n",bitcoinAerolineas);
	printf("d)Precio unitario: %.2f\n\n",kilometroAerolineas);
	printf("Precio Latam: %.0f\n", precioLatam);
	printf("a)Precio con tarjeta de debito: %.2f\n", debitoLatam);
	printf("b)Precio con tarjeta de credito: %.2f\n", creditoLatam);
	printf("c)Precio pagando con Bitcoin: %.2f\n",bitcoinLatam);
	printf("d)Precio unitario: %.2f\n\n",kilometroLatam);
	printf("e)La diferencia de precio es: %.2f\n",DiferenciaDePrecio);

	return retorno;
}

