# Blink con FreeRTOS puro

FreeRTOS no es un lenguaje; esta aplicacion esta escrita en C.

"Puro" significa que toda la temporizacion y planificacion de la aplicacion usa
primitivas nativas de FreeRTOS.

## Usa

```text
xTaskCreate()
vTaskStartScheduler()
xTaskDelayUntil()
```

## No usa

```text
busy-wait
delay_ms artesanal
scheduler cooperativo propio
FSM para producir el periodo
consulta manual de SysTimer
```

## Estado

Fuente lista. La integracion del kernel, port RISC-V, heap y configuracion sigue
pendiente.
