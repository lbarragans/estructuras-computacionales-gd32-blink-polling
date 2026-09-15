# Apartados definitivos del ejercicio

Las antiguas variantes comparativas se retiran.

El ejercicio conserva solamente dos caminos de implementacion alternativos.

## 1. Ensamblador RISC-V puro

```text
Ensamblador_RISCV_Puro/main.S
```

Caracteristicas:

- no contiene codigo C;
- acceso directo a MMIO;
- configuracion directa de RCU y GPIOC;
- retardo implementado con instrucciones y registros;
- control completo de PC13 desde ensamblador RISC-V.

## 2. FreeRTOS puro

```text
FreeRTOS_Puro/main.c
```

Caracteristicas:

- usa tareas FreeRTOS;
- usa el scheduler del RTOS;
- usa `xTaskDelayUntil()` para el periodo;
- no usa espera activa para temporizacion;
- no usa scheduler cooperativo propio;
- no usa FSM para producir el Blink.

## Referencia

`Src/main.c` se conserva unicamente como implementacion original funcional para
comparacion y validacion.
