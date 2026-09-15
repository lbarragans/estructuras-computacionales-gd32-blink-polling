# 7. Plan de validacion

## Referencia original

Primero comprobar que `Src/main.c` continua compilando y produciendo el Blink
esperado.

## Ensamblador RISC-V puro

Validar:

1. integracion de `Ensamblador_RISCV_Puro/main.S`;
2. compilacion sin `main.c` de aplicacion;
3. habilitacion del reloj GPIOC;
4. PC13 en modo salida;
5. push-pull;
6. velocidad configurada;
7. ausencia de pull-up/pull-down;
8. estado inicial del LED;
9. toggle mediante registro MMIO;
10. retardo implementado solamente en ensamblador;
11. prueba fisica en placa.

## FreeRTOS puro

Validar:

1. kernel FreeRTOS;
2. port RISC-V;
3. `FreeRTOSConfig.h`;
4. heap;
5. tick del kernel;
6. creacion de `BlinkTask`;
7. arranque de `vTaskStartScheduler()`;
8. periodo mediante `xTaskDelayUntil()`;
9. ausencia de busy-wait como temporizador;
10. prueba fisica en placa.

## Estados

- referencia funcional;
- fuente lista;
- integracion pendiente;
- validada por compilacion;
- validada en placa.
