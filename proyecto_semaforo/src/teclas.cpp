#include "teclas.h"


void pulsantes(int sw){
  switch (estadoActual) {
    case Inactivo:
      if (digitalRead(sw) == LOW) {
        estadoActual = Antirrebote;
        tiempoUltimoCambio = millis();
      }
      break;
      
    case Activo:
      if (digitalRead(sw) == HIGH) {
        estadoActual = Antirrebote;
        tiempoUltimoCambio = millis();
      }
      break;
      
    case Antirrebote:
      if (millis() - tiempoUltimoCambio >= tiempoRebote) {
        if (digitalRead(sw) == LOW) {
          estadoActual = Activo;
        } else {
          estadoActual = Inactivo;
        }
      }
      break;
  }
}

void condicion_antirrebote(int pul) {
  pulsantes(pul);
  if (estadoActual == Antirrebote){
    while(1){
      pulsantes(pul);
      if (estadoActual == Activo){
        break;
      }
    }
    if (estadoActual == Activo){
      while(1){
        pulsantes(pul);
        if (estadoActual == Antirrebote){
          break;
        }
      }
    }
    if (estadoActual == Antirrebote){
      while(1){
        pulsantes(pul);
        if (estadoActual == Inactivo){
          break;
        }
      }

      if (modo == NORMAL){
        modo = DESCONECTADO;
        estado_actual = D_AMARILLO;}
      else if (modo == DESCONECTADO){
        modo = ALARMA;
        estado_actual = ESTADO_ROJO;}
      else {
        modo = NORMAL;
        estado_actual = ESTADO_VERDE;
      }
    }
  }
}


void condicion_anti(int pulsa) {
  pulsantes(pulsa);
  if (estadoActual == Antirrebote){
    while(1){
      pulsantes(pulsa);
      if (estadoActual == Activo){
        break;
      }
    }
    if (estadoActual == Activo){
      while(1){
        pulsantes(pulsa);
        if (estadoActual == Antirrebote){
          break;
        }
      }
    }
    if (estadoActual == Antirrebote){
      while(1){
        pulsantes(pulsa);
        if (estadoActual == Inactivo){
          break;
        }
      }

      // return true;

       if (velocidad == 1){
              t1 = 500;
              t2 = 3000;
              t3 = 500;
              velocidad = 2;}
            else if (velocidad == 2){
              t1 = 500;
              t2 = 500;
              t3 = 3000;
              velocidad = 3;}
            else {
              t1 = 3000;
              t2 = 500;
              t3 = 500;
              velocidad = 1;
          }
 

      }
      }
}