# Blink con FreeRTOS puro

FreeRTOS no es un lenguaje; esta aplicacion esta escrita en C.

"Puro" significa que toda la temporizacion y planificacion de la aplicacion usa
primitivas nativas de FreeRTOS.

## Usa

```text
xTaskCreate()
sys_os_init()
sys_os_start()
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

Aplicacion MSDK completa: usa el kernel y el port oficial incluidos en
`GD32VW55x_RELEASE_V1.0.3g`. Consulte `INTEGRACION.md`.
