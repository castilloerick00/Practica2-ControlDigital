// Importamos el header del programa semáforo
#include "semaforo.h"

// Definición de los pines del semáforo (ROJO, AMARILLO, VERDE)
const int PIN_ROJO = 10;
const int PIN_AMARILLO = 9;
const int PIN_VERDE = 8;

// Definición de los pines para los pulsantes (MODO --> 2 ; VELOCIDAD --> 6)
const int BOTON_M = 2;
const int BOTON_V = 6;

// Definición de los tiempos de estado del semáforo
int t1 = 3000;
int t2 = 500;
int t3 = 1000;

// Bandera para controlar el cambio de la velocidad
int velocidad = 1;

// Variable para almacenar el estado actual del semáforo
int estado_actual = ESTADO_VERDE;

// Variable para almacenar el estado actual del modo de operacion 
int modo = NORMAL;

// Inicialización del estado actual de los pulsantes y el tiempo del ultimo cambio 
Estados estadoActual = Inactivo;
int tiempoUltimoCambio = 0;

// Función para inicializar el semáforo
void inicializar_semaforo() {
  // Definimos los pines de los leds como salida 
  pinMode(PIN_ROJO, OUTPUT);
  pinMode(PIN_AMARILLO, OUTPUT);
  pinMode(PIN_VERDE, OUTPUT);
  // Inicialmente, el semáforo está en estado rojo
  digitalWrite(PIN_ROJO, HIGH);
  digitalWrite(PIN_AMARILLO, LOW);
  digitalWrite(PIN_VERDE, LOW);
}

// Función de espera entre cada estado del semáforo
void Espera(int valor){
  unsigned long time_now = 0;
  time_now = millis();                  // Lectura del tiempo actual de ejecución del programa
  while (millis() < time_now + valor){  // Esperamos que transcurra un tiempo de espera definido
  }  
}

// Función para actualizar el estado del semáforo
void actualizar_semaforo() {
  switch (estado_actual) {              // Posibles estados del semáforo
    // Este caso corresponde al encendido del led VERDE, con t = 3 [s]
    case ESTADO_VERDE:                  
      digitalWrite(PIN_ROJO, LOW);
      digitalWrite(PIN_AMARILLO, LOW);
      digitalWrite(PIN_VERDE, HIGH);
      Espera(t1);
      estado_actual = ESTADO_AMARILLO;  // Actualización del estado (Modo NORMAL)
      break;
    
    // Este caso corresponde al encendido del led VERDE y AMARILLO, con t = 0.5 [s]
    case ESTADO_AMARILLO:
      digitalWrite(PIN_ROJO, LOW);
      digitalWrite(PIN_AMARILLO, HIGH);
      digitalWrite(PIN_VERDE, HIGH);
      Espera(t2);
      estado_actual = ESTADO_ROJO;    // Actualización del estado (Modo NORMAL)
      break;
    
    // Este caso corresponde al encendido del led ROJO, con t = 1 [s]
    case ESTADO_ROJO:
      digitalWrite(PIN_ROJO, HIGH);
      digitalWrite(PIN_AMARILLO, LOW);
      digitalWrite(PIN_VERDE, LOW);
      Espera(t3);
      if (modo == NORMAL){
        estado_actual = ESTADO_VERDE; // Actualización del estado (Modo NORMAL)
      }
      else {
        estado_actual = D_APAGADO;    // Actualización del estado (Modo ALARMA)
      }
      break;

    // Este caso corresponde al encendido del led AMARILLO, con t = 0.5 [s]
    case D_AMARILLO:
      digitalWrite(PIN_ROJO, LOW);
      digitalWrite(PIN_AMARILLO, HIGH);
      digitalWrite(PIN_VERDE, LOW);
      Espera(t2);
      estado_actual = D_APAGADO;      // Actualización del estado (Modo DESCONECTADO)
      break;

    // Este caso corresponde al apagado de los leds
    case D_APAGADO:
      digitalWrite(PIN_ROJO, LOW);
      digitalWrite(PIN_AMARILLO, LOW);
      digitalWrite(PIN_VERDE, LOW);
      if (modo == DESCONECTADO){
        estado_actual = D_AMARILLO;   // Actualización del estado (Modo DESCONECTADO)
        Espera(t2);
      }
      else {
        estado_actual = ESTADO_ROJO;  // Actualización del estado (Modo ALARMA)
        Espera(t3);
      }
      break;
  }
}

// Función para actualizar el modo del semáforo
void actualizar_modo() {
  switch (modo) {              // Posibles modos del semáforo
    // Este caso corresponde al modo de operación NORMAL
    case NORMAL:
      actualizar_semaforo();  // Actualizamos el modo del semáforo 
      break;
    // Este caso corresponde al modo de operación DESCONECTADO
    case DESCONECTADO:
      actualizar_semaforo();  // Actualizamos el modo del semáforo
      break;
    // Este caso corresponde al modo de operación ALARMA
    case ALARMA:
      actualizar_semaforo();  // Actualizamos el modo del semáforo
      break;
  }
}