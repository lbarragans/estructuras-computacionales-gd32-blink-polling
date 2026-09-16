# Exercise 00 - Blink en GD32VW553

**Curso:** Estructuras Computacionales  
**Autora:** Laura Daniela Barragan Silva  
**Plataforma:** GD32VW553HMQ6 / GD32VW553HMQ7  
**Arquitectura:** Nuclei RISC-V RV32  
**Entorno base:** Visual Studio Code, CMake, Ninja y Nuclei RISC-V GCC

## 1. Proposito

Este repositorio conserva la implementacion original funcional en:

```text
Src/main.c
```

como referencia del ejercicio.

A partir de esta revision, las unicas dos implementaciones alternativas que se
conservan son:

```text
Ensamblador_RISCV_Puro/
FreeRTOS_Puro/
```

Se eliminan las antiguas carpetas de variantes de polling alternativo,
SysTimer, maquina de estados, scheduler cooperativo y formas hibridas.

## 2. Estructura definitiva

```text
00_Blink_Polling/
├── Src/
│   └── main.c
├── Ensamblador_RISCV_Puro/
│   ├── main.S
│   ├── README.md
│   └── MAPA_REGISTROS.md
├── FreeRTOS_Puro/
│   ├── main.c
│   ├── README.md
│   └── INTEGRACION.md
├── Doc/
├── .gitattributes
├── REGLA_GLOBAL_LENGUAJES.md
├── NOTA_LINGUIST.md
├── CMakeLists.txt
└── README.md
```

## 3. Implementacion original

`Src/main.c` se conserva porque es la referencia que ya funciona y permite
comparar el resultado fisico con los dos apartados nuevos.

No se presenta como una tercera variante de estudio.

## 4. Ensamblador RISC-V puro

Este apartado contiene:

```text
Ensamblador_RISCV_Puro/main.S
```

No contiene archivos `.c`.

La aplicacion configura directamente:

```text
RCU_AHB1EN
GPIOC_CTL
GPIOC_OMODE
GPIOC_OSPD
GPIOC_PUD
GPIOC_BOP
GPIOC_TG
```

mediante instrucciones RISC-V y acceso MMIO.

No llama funciones C para:

- habilitar el reloj de GPIOC;
- configurar PC13;
- cambiar el estado del LED;
- generar el retardo.

La secuencia es:

```text
habilitar GPIOC
      ↓
configurar PC13
      ↓
dejar LED apagado
      ↓
conmutar PC13
      ↓
retardo por instrucciones
      ↓
repetir
```

## 5. FreeRTOS puro

FreeRTOS no es un lenguaje; la aplicacion se escribe en C.

En este repositorio, **FreeRTOS puro** significa que la planificacion y la
temporizacion de la aplicacion dependen de primitivas nativas de FreeRTOS.

La aplicacion usa:

```text
xTaskCreate()
vTaskStartScheduler()
xTaskDelayUntil()
```

y no usa para generar el periodo:

```text
busy-wait
delay_ms artesanal
scheduler cooperativo propio
maquina de estados
consulta manual de SysTimer
```

La estructura es:

```text
main
  ↓
inicializar GPIO
  ↓
crear BlinkTask
  ↓
arrancar scheduler
  ↓
BlinkTask
  ↓
toggle PC13
  ↓
xTaskDelayUntil
```

## 6. Diferencia entre los dos apartados

| Apartado | Que significa "puro" |
|---|---|
| Ensamblador RISC-V puro | toda la logica de aplicacion esta escrita en `main.S`, sin C |
| FreeRTOS puro | toda la planificacion y temporizacion usa primitivas nativas del RTOS |

## 7. Estado

| Implementacion | Estado |
|---|---|
| `Src/main.c` | referencia funcional |
| `Ensamblador_RISCV_Puro` | seleccionable con `APP_VARIANT=assembly`; validacion fisica requerida |
| `FreeRTOS_Puro` | aplicacion MSDK sobre FreeRTOS oficial V1.0.3g |

## 8. Lenguajes en GitHub

El codigo real del repositorio contiene:

```text
C
Ensamblador RISC-V
```

FreeRTOS se programa en C, por lo que no aparece como lenguaje independiente.

PowerShell, CMake, JSON y Markdown no deben alterar la barra de lenguajes.

## 9. Regla para los siguientes ejercicios

La misma estructura se aplicara progresivamente a los demas ejercicios:

```text
codigo original de referencia
+
Ensamblador_RISCV_Puro
+
FreeRTOS_Puro
```

No se conservaran las otras variantes educativas salvo que exista una razon
especifica para mantenerlas.

## Ejecutar las variantes

Referencia original por JTAG/OpenOCD:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\\tools\\build_variant.ps1 -Variant original -Flash
```

Assembly puro por JTAG/OpenOCD:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass -File .\\tools\\build_variant.ps1 -Variant assembly -Flash
```

FreeRTOS usa el port oficial del SDK WiFi V1.0.3g. Copie la carpeta completa
`FreeRTOS_Puro/` dentro de `MSDK/` y siga `FreeRTOS_Puro/INTEGRACION.md`.

## Guía central de ejecución

Para instalar herramientas, reconocer la placa en Windows/VS Code e integrar
Assembly y FreeRTOS paso a paso, consulte la
[guía central GD32VW553](https://github.com/lbarragans/gd32vw553-vscode-cmake-guide).
