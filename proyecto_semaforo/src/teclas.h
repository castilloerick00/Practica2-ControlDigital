// Generamos la estructura principal del archivo header para teclas.cpp
#ifndef TECLAS_H
#define TECLAS_H

// Llamamos a la libreria de arduino
#include <Arduino.h>

// Definición de los estados del semáforo
const int ESTADO_ROJO = 0;
const int ESTADO_AMARILLO = 1;
const int ESTADO_VERDE = 2;
const int D_AMARILLO = 3;
const int D_APAGADO = 4;

// Definición de los modos del semáforo
const int NORMAL = 0;
const int DESCONECTADO = 1;
const int ALARMA = 2;

// Exportamos los tiempos 
extern int t1;
extern int t2;
extern int t3;

// Exportamos la bandera de velocidad
extern int velocidad;

// Exportamos la variable para almacenar el estado actual del semáforo
extern int estado_actual;

// Exportamos la varaiable para almacenar el estado actual del modo de operacion 
extern int modo;

// Definimos un tiempo para el ANTIRREBORTE
const unsigned long tiempoRebote = 100; // Tiempo en milisegundos

// Estados de la máquina de estados para los pulsantes
enum Estados {
  Inactivo,
  Activo,
  Antirrebote
};

// Exportamos el estado actual de los pulsantes y el tiempo del ultimo cambio 
extern Estados estadoActual;
extern int tiempoUltimoCambio;

// Inicializamos las funciones programadas en semaforo.cpp, para luego llamar en el programa principal
void pulsantes(int sw);
void condicion_antirrebote(int pul);
void condicion_anti(int pulsa);

#endif 