/*
 * Input.c
 *
 *  Created on: 16 abr. 2022
 *      Author: MI COMPU Weiss Mariano
 */
#include "input.h"

//Desarrollo de funciones

int utn_getNumero(char* mensaje, int* pOpcion, int minimo, int maximo, char* mensajeError)
{
	int retorno;
	int auxiliarInt;

	if(mensaje != NULL && pOpcion != NULL && minimo<maximo)
	{
		printf("%s", mensaje);
		scanf("%d", &auxiliarInt);

		*pOpcion = auxiliarInt;
	}
	else
	{
		printf("%s", mensajeError);
	}

	if(auxiliarInt<minimo || auxiliarInt>maximo)
	{
		retorno = -1;
	}
	else
	{
		retorno = 0;
	}

	return retorno;
}

float calcularResultados(float precio, float kilometros, float *pResultadoDebito, float *pResultadoCredito, float *pResultadoBitcoin, float *pPrecioPorKilometro)
{
	int retorno = 0;

	*pResultadoDebito = precio * 0.9;

	*pResultadoCredito = precio * 1.25;

	*pResultadoBitcoin = precio / 4606954.55;

	*pPrecioPorKilometro = precio / kilometros;

	return retorno;
}

float difPrecio(int precioUno, int precioDos, int *pDiferenciaDePrecio)
{
	float retorno;

	retorno = -1;

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

	return retorno;
}

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

