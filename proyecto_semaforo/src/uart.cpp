#include "uart.h"

// Definición de los pines del semáforo
const int PIN_ROJO = 10;
const int PIN_AMARILLO = 9;
const int PIN_VERDE = 8;

const int BOTON_M = 2;
const int BOTON_V = 6;


// Función setup de Arduino (se ejecuta una vez al iniciar)
void setup() {
  pinMode(BOTON_M, INPUT);
  pinMode(BOTON_V, INPUT);
  inicializar_semaforo();
}


// Función loop de Arduino (se ejecuta en un ciclo infinito)
void loop() {
  actualizar_modo();
  condicion_antirrebote(BOTON_M);
  // if (condicion_anti(BOTON_V)==true){
  condicion_anti(BOTON_V);
  //     } 
}
