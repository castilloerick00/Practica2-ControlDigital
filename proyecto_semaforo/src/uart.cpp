/* ************************* Universidad de Cuenca *************************

  Asignatura:   --> Control Digital

  Integrantes:  --> Erick Castillo
                --> Sebastián Chalco 

************************************************************************* */ 
// Importamos el header del programa principal
#include "uart.h"

// Definición de los pines del semáforo (ROJO, AMARILLO, VERDE)
const int PIN_ROJO = 10;
const int PIN_AMARILLO = 9;
const int PIN_VERDE = 8;

// Definición de los pines para los pulsantes (MODO --> 2 ; VELOCIDAD --> 6)
const int BOTON_M = 2;
const int BOTON_V = 6;

// Función setup de Arduino (se ejecuta una vez al iniciar)
void setup() {
  // Inicializamos las variables como entrada o salida
  Serial.begin(9600);
  pinMode(BOTON_M, INPUT);  
  pinMode(BOTON_V, INPUT);
  inicializar_semaforo(); 
}

// Función loop de Arduino (se ejecuta en un ciclo infinito)
void loop() {
  actualizar_modo();                // Función para actualizar el modo de operación del semáforo
  condicion_antirrebote(BOTON_M);   // Función para lectura del pulsante de cambio de modo
  condicion_anti(BOTON_V);          // Función para lectura del pulsante de cambio de velocidad
}