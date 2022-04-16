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
/**
 *
 * @param mensaje Es el mensaje que va a visualizar el usuario por consola
 * @param pOpcion Es el puntero que va a ser utilizado segun necesidades en los diferenes usos de la funcion
 * @param minimo Define el minimo dentro del rango de opciones validas
 * @param maximo Define el maximo dentro del rango de opciones validas
 * @param mensajeError Es el mensaje a mostrar en caso de que los parametros sean inconsistentes
 * @return Lo utilizamos para corroborar que el usuario haya ingresado un valor valido, de lo contrario informamos del error.
 */
int utn_getNumero(char* mensaje, int* pOpcion, int minimo, int maximo, char* mensajeError);

/**
 *
 * @param precio Indica el precio ingresado
 * @param kilometros Indica los kilometros ingresados
 * @param pResultadoDebito Devuelve como puntero el valor a abonar con tarjeta de debito
 * @param pResultadoCredito Devuelve como puntero el valor a abonar con tarjeta de credito
 * @param pResultadoBitcoin Devuelve como puntero el valor a abonar en bitcoin
 * @param pPrecioPorKilometro Devuelve como puntero el valor unitario por kilometro
 * @return
 */
float calcularResultados(float precio, float kilometros, float *pResultadoDebito, float *pResultadoCredito, float *pResultadoBitcoin, float *pPrecioPorKilometro);

/**
 *
 * @param precioUno Toma el valor de precio de una de las empresas de vuelos
 * @param precioDos Toma el valor de precio de una de las empresas de vuelos
 * @param pDiferenciaDePrecio Devuelve como puntero la diferencia de precio entre las mismas
 * @return
 */
float difPrecio(int precioUno, int precioDos, int *pDiferenciaDePrecio);

/**
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
float mostrarResultados(float kilometros, float precioAerolineas, float precioLatam, float debitoAerolineas, float debitoLatam, float creditoAerolineas, float creditoLatam, float bitcoinAerolineas, float bitcoinLatam, float kilometroAerolineas, float kilometroLatam, float DiferenciaDePrecio);

#endif /* INPUT_H_ */
