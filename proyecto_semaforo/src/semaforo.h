// Generamos la estructura principal del archivo header para semaforo.cpp
#ifndef SEMAFORO_H
#define SEMAFORO_H

// Llamamos el archivo teclas.h, para importar las funciones de los pulsantes
#include "teclas.h"

// Inicializamos las funciones programadas en semaforo.cpp, para luego llamar en el programa principal
void inicializar_semaforo();
void Espera(int valor);
void actualizar_semaforo();
void actualizar_modo();

#endif