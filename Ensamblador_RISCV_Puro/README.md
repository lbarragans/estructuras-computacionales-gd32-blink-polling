# Blink en Ensamblador RISC-V puro

Este apartado contiene la aplicacion completa del Blink en:

```text
main.S
```

No contiene archivos `.c`.

No llama funciones C para RCU, GPIO o retardo.

## Flujo

```text
RCU
 ↓
GPIOC
 ↓
PC13
 ↓
toggle
 ↓
retardo
 ↓
repetir
```

## Estado

Integrada en CMake mediante `APP_VARIANT=assembly`. La prueba fisica final se
ejecuta con `tools/build_variant.ps1 -Variant assembly -Flash`.
