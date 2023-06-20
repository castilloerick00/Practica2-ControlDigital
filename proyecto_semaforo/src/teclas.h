#ifndef TECLAS_H
#define TECLAS_H

#include <Arduino.h>

// Definición de los estados del semáforo
const int ESTADO_ROJO = 0;
const int ESTADO_AMARILLO = 1;
const int ESTADO_VERDE = 2;
const int D_AMARILLO = 3;
const int D_APAGADO = 4;

const int NORMAL = 0;
const int DESCONECTADO = 1;
const int ALARMA = 2;

extern int t1;
extern int t2;
extern int t3;

extern int velocidad;

// Variable para almacenar el estado actual del semáforo
extern int estado_actual;

// Varaiable para almacenar el estado actual del modo de operacion 
extern int modo;



// ANTIRREBORTE
const unsigned long tiempoRebote = 100; // Tiempo en milisegundos

// Estados de la máquina de estados
enum Estados {
  Inactivo,
  Activo,
  Antirrebote
};

// Variables globales
extern Estados estadoActual;
extern int tiempoUltimoCambio;


void pulsantes(int sw);
void condicion_antirrebote(int pul);
void condicion_anti(int pulsa);

#endif 