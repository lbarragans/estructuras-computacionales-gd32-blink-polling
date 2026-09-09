# 03 - Blink con SysTimer e interrupcion

## Lenguaje

C.

## Metodo

Un temporizador del core genera una interrupcion periodica y mantiene un contador de milisegundos.

## Por que funciona

El hardware SysTimer compara su contador con un valor programado. Al cumplirse la condicion genera `CLIC_INT_TMR`; el handler incrementa `system_milliseconds`.

El `main` ya no necesita consumir millones de instrucciones para "fabricar" un segundo.

## Ventaja principal

La nocion de tiempo deja de depender de un bucle de espera activa.

## Riesgos / posibles fallos

- configuracion incorrecta del SysTimer;
- handler no enlazado con el vector esperado;
- interrupciones deshabilitadas;
- frecuencia de `SystemCoreClock` incorrecta.

## Estado

**Basada en el repositorio SysTimer ya trabajado.** Debe integrarse y compilarse aqui antes de marcarla como validada en este repositorio.
