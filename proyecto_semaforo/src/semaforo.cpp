#include "semaforo.h"

// Definición de los pines del semáforo
const int PIN_ROJO = 10;
const int PIN_AMARILLO = 9;
const int PIN_VERDE = 8;

const int BOTON_M = 2;
const int BOTON_V = 6;


int t1 = 3000;
int t2 = 500;
int t3 = 500;

int velocidad = 1;

// Variable para almacenar el estado actual del semáforo
int estado_actual = ESTADO_VERDE;

// Varaiable para almacenar el estado actual del modo de operacion 
int modo = NORMAL;




Estados estadoActual = Inactivo;
int tiempoUltimoCambio = 0;





// Función para inicializar el semáforo
void inicializar_semaforo() {
  pinMode(PIN_ROJO, OUTPUT);
  pinMode(PIN_AMARILLO, OUTPUT);
  pinMode(PIN_VERDE, OUTPUT);
  
  // Inicialmente, el semáforo está en estado rojo
  digitalWrite(PIN_ROJO, HIGH);
  digitalWrite(PIN_AMARILLO, LOW);
  digitalWrite(PIN_VERDE, LOW);
}





void Espera(int valor){
  unsigned long time_now = 0;
  time_now = millis();
  while (millis() < time_now + valor){
    
  }  
}



// Función para actualizar el modo del semaforo
void actualizar_semaforo() {
  switch (estado_actual) {
    case ESTADO_VERDE:
      digitalWrite(PIN_ROJO, LOW);
      digitalWrite(PIN_AMARILLO, LOW);
      digitalWrite(PIN_VERDE, HIGH);
      Espera(t1);
      estado_actual = ESTADO_AMARILLO;
      break;
      
    case ESTADO_AMARILLO:
      digitalWrite(PIN_ROJO, LOW);
      digitalWrite(PIN_AMARILLO, HIGH);
      digitalWrite(PIN_VERDE, HIGH);
      Espera(t2);
      estado_actual = ESTADO_ROJO;
      break;
      
    case ESTADO_ROJO:
      digitalWrite(PIN_ROJO, HIGH);
      digitalWrite(PIN_AMARILLO, LOW);
      digitalWrite(PIN_VERDE, LOW);
      Espera(t3);
      if (modo == NORMAL){
        estado_actual = ESTADO_VERDE;
      }
      else {
        estado_actual = D_APAGADO;
      }
      break;

    case D_AMARILLO:
      digitalWrite(PIN_ROJO, LOW);
      digitalWrite(PIN_AMARILLO, HIGH);
      digitalWrite(PIN_VERDE, LOW);
      Espera(t2);
      estado_actual = D_APAGADO;
      break;

    case D_APAGADO:
      digitalWrite(PIN_ROJO, LOW);
      digitalWrite(PIN_AMARILLO, LOW);
      digitalWrite(PIN_VERDE, LOW);
      if (modo == DESCONECTADO){
        estado_actual = D_AMARILLO;
        Espera(t2);
      }
      else {
        estado_actual = ESTADO_ROJO;
        Espera(t3);
      }
      break;
  }
}


void actualizar_modo() {
  switch (modo) {
    case NORMAL:
      actualizar_semaforo();
      break;

    case DESCONECTADO:
      actualizar_semaforo();
      break;
      
    case ALARMA:
      actualizar_semaforo();
      break;
  }
}














