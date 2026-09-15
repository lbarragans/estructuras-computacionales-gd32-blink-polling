# Integracion pendiente

Para compilar esta implementacion deben integrarse al proyecto:

```text
FreeRTOS kernel
port RISC-V
FreeRTOSConfig.h
heap_x.c
tick
context switch
includes del kernel
fuentes del kernel en CMake
```

Solo se marcara validada cuando compile, enlace, arranque el scheduler y el LED
funcione en la placa sin usar espera activa para temporizacion.
