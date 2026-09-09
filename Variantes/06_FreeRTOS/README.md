# 06 - Blink con FreeRTOS

## Lenguaje / tecnologia

- Lenguaje: C.
- Tecnologia: FreeRTOS.

FreeRTOS no es un lenguaje.

## Metodo

El Blink vive dentro de una tarea:

```c
vTaskDelay(pdMS_TO_TICKS(1000U));
```

## Por que funciona

Cuando la tarea llama `vTaskDelay`, deja de estar lista para ejecutar durante el numero de ticks indicado.

El scheduler puede usar ese tiempo para ejecutar otras tareas.

## Diferencia fundamental frente a polling

`busy_wait_delay()`:

```text
la CPU ejecuta el retardo
```

`vTaskDelay()`:

```text
la tarea Blink se bloquea
el scheduler puede seleccionar otra tarea
```

## Por que TODAVIA no se marca como compilable en este proyecto

El `CMakeLists.txt` actual usa la Firmware Library clasica y no incluye:

- fuentes del kernel FreeRTOS;
- port RISC-V;
- `FreeRTOSConfig.h`;
- configuracion del tick;
- reglas de enlace necesarias.

El SDK oficial GD32VW55x WiFi/BLE si contiene un arbol `MSDK/rtos/FreeRTOS`, por lo que la integracion es viable, pero debe hacerse y validarse conscientemente.

## Estado

**Integracion pendiente.**

No debe afirmarse que esta variante funciona en la placa hasta que compilemos, carguemos y probemos el scheduler.
