/*
 * Input.h
 *
 *  Created on: 16 abr. 2022
 *      Author: MI COMPU Weiss Mariano
 */

#include <stdio.h>
#include <stdlib.h>

#ifndef INPUT_H_
#define INPUT_H_

//funciones utilizadas

int utn_getNumero(char* mensaje, int* pOpcion, int minimo, int maximo, char* mensajeError);

float calcularResultados(float precio, float kilometros, float *pResultadoDebito, float *pResultadoCredito, float *pResultadoBitcoin, float *pPrecioPorKilometro);

float difPrecio(int precioUno, int precioDos, int *pDiferenciaDePrecio);

float mostrarResultados(float kilometros, float precioAerolineas, float precioLatam, float debitoAerolineas, float debitoLatam, float creditoAerolineas, float creditoLatam, float bitcoinAerolineas, float bitcoinLatam, float kilometroAerolineas, float kilometroLatam, float DiferenciaDePrecio);

#endif /* INPUT_H_ */
