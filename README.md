# Practica2-ControlDigital
## Integrantes: 
#### Erick Castillo 
#### Sebastian Chalco
## Implementacion:
#### Mediante el modelo de Máquina de Estados Finitos (MEF) se implementó el antirrebote de teclas y la lógica de funcionamiento de un semáforo.
## Archivos de programa:
### uart.cpp
##### En este archivo se define los pines a utilizar para los leds y pulsantes, además se ejecuta el void setup y el void loop, es decir es el programa principal del cual se irán llamando a los demas archivos según los requerimientos. 
### uart.h
##### En este archivo se define el header del archivo uart.cpp donde importamos las funciones implementadas para el correcto funcionamiento del antirrebote y modo de operación del semáforo.
### semaforo.cpp
##### En este archivo se implementaron las funciones para la actualización del estado y modo de operación del semáforo, además se inicializaron algunas variables necesarias para el funcionamiento.  
### semaforo.h
##### En este archivo se define el header del archivo semaforo.cpp donde importamos las funciones implementadas para los pulsantes e inicializamos las funciones programadas en semaforo.cpp para que puedan ser llamadas en el programa principal.
### teclas.cpp
##### En este archivo se implemenetaron las funciones para actualizar el estado de los pulsantes y para la lectura del cambio de estado de los pulsantes tanto para el modo de funcionamiento y velocidad del semáforo.
### tecla.h
##### En este archivo se define el header del archivo teclas.cpp donde importamos la libreria de arduino que se llamara en todos los archivos de manera recursiva, además exportamos e inicializamos algunas variables necesarias.
## NOTA:
#### Los archivos descritos en la secciones anterior (Archivos de programa) se encuentran localizados en la carpeta "proyecto_semaforo/src".
