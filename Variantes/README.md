# Implementaciones alternativas del Blink

Esta carpeta NO reemplaza `Src/main.c`.

El objetivo es conservar, comparar e ir validando varias maneras de resolver el mismo problema.

## Menu

1. [01 - C + Polling](01_C_Polling/README.md)
2. [02 - C + Assembly: retardo externo](02_C_Assembly_ExternalDelay/README.md)
3. [03 - SysTimer + interrupcion](03_SysTimer_Interrupt/README.md)
4. [04 - Maquina de estados](04_StateMachine/README.md)
5. [05 - Scheduler cooperativo](05_Cooperative_Scheduler/README.md)
6. [06 - FreeRTOS](06_FreeRTOS/README.md)

## Importante

Las variantes son codigo real de estudio, por lo que sus lenguajes cuentan en GitHub.

Sin embargo, el CMake principal sigue compilando solamente `Src/main.c` hasta que integremos cada variante de forma controlada.
