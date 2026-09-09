# 05 - Blink con scheduler cooperativo

## Lenguaje

C.

## Metodo

Una tabla contiene tareas y periodos.

El bucle principal revisa cuales tareas deben ejecutarse.

## Por que funciona

SysTimer aporta un reloj comun. Cada tarea recuerda cuando se ejecuto por ultima vez.

En este ejemplo:

- `task_blink`: cada 1000 ms;
- `task_background`: cada 100 ms.

## Diferencia frente a FreeRTOS

No existe un kernel que interrumpa una tarea para ejecutar otra. Cada funcion debe terminar rapidamente y devolver el control al scheduler.

## Limitacion importante

Si una tarea tarda demasiado o se queda bloqueada, retrasa a todas las demas.

## Estado

**Fuente lista; pendiente de integracion y prueba.**
