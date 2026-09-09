# Exercise 00 - Blink en GD32VW553: multiples formas de resolver el mismo problema

**Curso:** Estructuras Computacionales  
**Autora:** Laura Daniela Barragan Silva  
**Plataforma:** GD32VW553HMQ6 / GD32VW553HMQ7  
**Arquitectura:** Nuclei RISC-V RV32  
**Entorno base:** Visual Studio Code, CMake, Ninja y Nuclei RISC-V GCC

## 1. Proposito

El objetivo inicial sigue siendo verificar la cadena completa de desarrollo:

1. editar codigo;
2. compilar para RISC-V;
3. enlazar;
4. generar ELF, HEX, BIN, MAP y LST;
5. programar con OpenOCD/WCH-Link;
6. observar el LED conectado a PC13.

La implementacion que se compila **por defecto** continua siendo:

```text
Src/main.c
```

y utiliza **C + espera activa (polling)**.

A partir de esta fase, el repositorio tambien conserva otras maneras de producir el mismo Blink para estudiar que cambia dentro del procesador.

## 2. Menu de implementaciones

| # | Variante | Lenguaje / tecnologia | Que cambia | Estado |
|---:|---|---|---|---|
| 01 | C + Polling | C | CPU ocupada durante el retardo | Base actual |
| 02 | Retardo externo en RISC-V | C + Assembly | el bucle de espera pasa a una funcion `.S` | Fuente lista |
| 03 | SysTimer + interrupcion | C | tiempo generado por el temporizador del core | Basada en ejercicio verificado |
| 04 | Maquina de estados | C | elimina el flujo bloqueante | Fuente lista |
| 05 | Scheduler cooperativo | C | varias tareas periodicas sin RTOS | Fuente lista |
| 06 | FreeRTOS | C + FreeRTOS | tarea bloqueada con `vTaskDelay` y scheduler | Integracion pendiente |

Las fuentes educativas estan en [`Variantes/`](Variantes/README.md).

> Las variantes no se agregan automaticamente al `CMakeLists.txt` principal. Esto es intencional: primero se conserva intacto el Blink que ya funciona y despues se integra y valida cada metodo con commits separados.

## 3. Resultado fisico

Todas las variantes buscan el mismo efecto:

```text
GPIO PC13 -> LED cambia de estado periodicamente
```

Lo que cambia no es necesariamente lo que se ve, sino **lo que hace la CPU mientras espera**.

## 4. La pregunta principal

> ¿Que esta haciendo el procesador entre un cambio del LED y el siguiente?

### Polling

```text
CPU -> nop -> nop -> nop -> ... -> cambia LED
```

La CPU permanece ocupada.

### SysTimer / FSM

```text
CPU -> consulta tiempo -> otras tareas -> consulta tiempo -> cambia LED
```

La aplicacion no necesita ejecutar un bucle de retardo largo.

### FreeRTOS

```text
Tarea Blink -> vTaskDelay -> BLOQUEADA
Scheduler -> ejecuta otras tareas
```

## 5. Por que la version base funciona

`Src/main.c`:

1. habilita el reloj de GPIOC;
2. configura PC13 como salida;
3. cambia el estado del pin;
4. ejecuta una espera activa;
5. repite indefinidamente.

La espera funciona porque la CPU tarda tiempo real en ejecutar las instrucciones del bucle. Su precision, sin embargo, depende del reloj, del compilador y de la optimizacion.

## 6. Por que puede no ser la mejor solucion

La espera activa es apropiada para comenzar porque hace visible la secuencia de ejecucion, pero tiene limitaciones:

- ocupa la CPU;
- dificulta atender otras tareas;
- el tiempo es aproximado;
- escala mal cuando aumenta el numero de eventos.

Por eso el repositorio conserva progresivamente otras soluciones.

## 7. Estructura

```text
estructuras-computacionales-gd32-blink-polling/
├── Src/
│   └── main.c                     # implementacion que compila por defecto
├── Inc/
├── Doc/
│   ├── 1_SETUP.md
│   ├── 2_BUILD_AND_FLASH.md
│   ├── 3_CONCEPTS_AND_QUESTIONS.md
│   ├── 4_DEBUGGING.md
│   ├── 5_TROUBLESHOOTING.md
│   ├── 6_VARIANTES_DEL_EJERCICIO.md
│   └── 7_PLAN_DE_VALIDACION.md
├── Variantes/
│   ├── 01_C_Polling/
│   ├── 02_C_Assembly_ExternalDelay/
│   ├── 03_SysTimer_Interrupt/
│   ├── 04_StateMachine/
│   ├── 05_Cooperative_Scheduler/
│   └── 06_FreeRTOS/
├── tools/
├── .gitattributes
├── REGLA_GLOBAL_LENGUAJES.md
├── CMakeLists.txt
└── README.md
```

## 8. Lenguajes en GitHub

La barra de lenguajes debe reflejar los lenguajes que realmente existen en las implementaciones.

Como este repositorio contiene C y una variante con Assembly, es correcto que aparezcan:

```text
C + Assembly
```

Los porcentajes exactos los calcula GitHub y suman 100%.

PowerShell, CMake, JSON y Markdown se mantienen como herramientas/documentacion, pero no se cuentan como lenguajes de la solucion.

## 9. FreeRTOS

FreeRTOS **no es un lenguaje**. La variante esta escrita en C.

El SDK oficial GD32VW55x WiFi/BLE contiene fuentes de FreeRTOS, pero el proyecto base actual usa la Firmware Library clasica y todavia no enlaza el kernel/port de FreeRTOS.

Por eso la variante se incluye como siguiente paso de integracion y **no se afirma que compile dentro del CMake actual hasta realizar esa integracion y validarla en la placa**.

## 10. Filosofia de validacion

Nunca reemplazaremos una solucion funcional sin conservarla.

Cada nueva forma se incorporara con:

1. fuente;
2. explicacion;
3. razon de funcionamiento;
4. limitaciones;
5. prueba de compilacion;
6. prueba en placa;
7. commit separado.

Ver [`Doc/7_PLAN_DE_VALIDACION.md`](Doc/7_PLAN_DE_VALIDACION.md).
