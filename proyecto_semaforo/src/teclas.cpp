// Importamos el header del programa teclas
#include "teclas.h"

// Función para actualizar el estado de los pulsantes
void pulsantes(int sw){
  switch (estadoActual) {               // Posibles estados de los pulsantes
    // Este caso corresponde al estado donde no se a presionado el pulsante
    case Inactivo:
      if (digitalRead(sw) == LOW) {     // Si se detecta el cambio de estado (PRESIONAMOS)
        estadoActual = Antirrebote;     // Actualización del estado
        tiempoUltimoCambio = millis();  // Tiempo de ejecución del programa
      }
      break;
    
    // Este caso corresponde al estado donde se mantiene presionado el pulsante
    case Activo:
      if (digitalRead(sw) == HIGH) {    // Si se detecta el cambio de estado (SOLTAMOS)
        estadoActual = Antirrebote;     // Actualización del estado
        tiempoUltimoCambio = millis();  // Tiempo de ejecución del programa
      }
      break;
    
    // Este caso corresponde al estado donde se presiona o se suelta el pulsante (ANTIRREBOTE)
    case Antirrebote:
      if (millis() - tiempoUltimoCambio >= tiempoRebote) {  // Transcurrido un tiempo determinado
        if (digitalRead(sw) == LOW) {                       // Si se presiono el pulsante 
          estadoActual = Activo;                            // Actualización del estado
        } else {                                            // Si se solto el pulsante
          estadoActual = Inactivo;                          // Actualización del estado
        }
      }
      break;
  }
}

// Función para la lectura del pulsante del cambio de MODO
void condicion_antirrebote(int pul) {
  pulsantes(pul);                         // Detectamos un pulso
  if (estadoActual == Antirrebote){  
    Serial.println(" ");
    Serial.println("Transición del pulsante 1: "); 
    while(1){                             // Esperamos que se finalice el antirrebote
      pulsantes(pul);
      if (estadoActual == Activo){    
        Serial.println("Pulsante 1 presionado");
        break;
      }
    }
    if (estadoActual == Activo){          // Si se encuentra presionado
      while(1){                           // Esperamos que se suelte el pulsante
        pulsantes(pul);
        if (estadoActual == Antirrebote){ // Si se suelta el pulsante, rompemos el bucle
        Serial.println("Transición del pulsante 1: ");
          break;
        }
      }
    }
    if (estadoActual == Antirrebote){    
      while(1){                           // Esperamos que finalice el antirrebote
        pulsantes(pul); 
        if (estadoActual == Inactivo){    // Verificamos si se solto el pulsante
          Serial.println("Pulsante 1 liberado");
          Serial.println(" ");
          break;
        }
      }

      // En el caso de haber detectado un pulso
      if (modo == NORMAL){              // Cambiamos de modo NORMAL a modo DESCONECTADO
        Serial.println("Modo actual : DESCONECTADO");
        modo = DESCONECTADO;
        estado_actual = D_AMARILLO;}
      else if (modo == DESCONECTADO){   // Cambiamos de modo DESCONECTADO a modo ALARMA
        Serial.println("Modo actual : ALARMA");
        modo = ALARMA;  
        estado_actual = ESTADO_ROJO;}
      else {                            // Cambiamos de modo ALARMA a modo NORMAL
        Serial.println("Modo actual : NORMAL");
        modo = NORMAL;
        estado_actual = ESTADO_VERDE;
      }
    }
  }
}

// Función para la lectura del pulsante del cambio de VELOCIDAD
void condicion_anti(int pulsa) {
  pulsantes(pulsa);                       // Detectamos un pulso
  if (estadoActual == Antirrebote){ 
    Serial.println(" ");
    Serial.println("Transición del pulsante 2: "); 
    while(1){                             // Esperamos que se finalice el antirrebote
      pulsantes(pulsa);
      if (estadoActual == Activo){  
        Serial.println("Pulsante 2 presionado");      
        break;
      }
    }
    if (estadoActual == Activo){          // Si se encuentra presionado
      while(1){                           // Esperamos que se suelte el pulsante
        pulsantes(pulsa);
        if (estadoActual == Antirrebote){ // Si se suelta el pulsante, rompemos el bucle
          Serial.println("Transición del pulsante 2: ");
          break;
        }
      }
    }
    if (estadoActual == Antirrebote){
      while(1){                           // Esperamos que finalice el antirrebote
        pulsantes(pulsa);
        if (estadoActual == Inactivo){    // Verificamos si se solto el pulsante
          Serial.println("Pulsante 2 liberado");
          Serial.println(" ");
          break;
        }
      }
      
      // En el caso de haber detectado un pulso
      if (velocidad == 1){          // Actualizamos la velocidad (x2)
        t1 = 1500;
        t2 = 250;
        t3 = 500;
        velocidad = 2;}
      else if (velocidad == 2){     // Actualizamos la velocidad (x0.5)
        t1 = 6000;
        t2 = 1000;
        t3 = 2000;
        velocidad = 3;}             // Actualizamos la velocidad (x1)
      else {
        t1 = 3000;
        t2 = 500;
        t3 = 1000;
        velocidad = 1;
      }
    }
  }
}