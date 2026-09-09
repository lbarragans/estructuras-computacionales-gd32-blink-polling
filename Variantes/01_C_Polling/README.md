# 01 - Blink con C y Polling

## Lenguaje

C, con una instruccion `nop` insertada mediante Assembly inline.

## Metodo

Espera activa.

## Por que funciona

Cada instruccion consume tiempo de CPU. Al repetir miles de instrucciones antes de volver a cambiar PC13 se obtiene un retardo visible.

## Que hace la CPU durante la espera

Trabaja continuamente ejecutando el bucle de retardo.

## Ventajas

- simple;
- excelente para comenzar;
- facil de depurar;
- no necesita interrupciones.

## Desventajas

- bloquea la CPU;
- tiempo aproximado;
- dificil de escalar.

## Cuando puede fallar o cambiar

La duracion puede variar si cambia:

- `SystemCoreClock`;
- el nivel de optimizacion;
- el numero de ciclos del bucle;
- la arquitectura/compilador.

## Estado

**Base actual.** Es esencialmente la implementacion principal ya existente.
