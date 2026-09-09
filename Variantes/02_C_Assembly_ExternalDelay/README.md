# 02 - Blink con C + Assembly RISC-V

## Lenguajes

- C: inicializacion de GPIO y flujo principal.
- Assembly RISC-V: bucle de retardo.

## Manera de hacerlo

C llama a:

```c
riscv_delay_cycles(...)
```

La ABI RISC-V coloca el primer argumento en el registro `a0`. La funcion `.S` decrementa `a0` hasta cero y retorna con `ret`.

## Por que funciona

El retardo aparece porque el procesador ejecuta repetidamente instrucciones `addi`, `nop` y `bnez`.

## Que ensena

- interfaz C/Assembly;
- ABI RISC-V;
- registros de argumentos;
- llamada y retorno de funciones;
- diferencia entre lenguaje de alto y bajo nivel.

## Limitaciones

Sigue siendo una espera activa. Mover el bucle a Assembly NO soluciona el bloqueo.

El valor `8000000U` es deliberadamente pedagogico y debe calibrarse en la placa; no debe interpretarse como milisegundos exactos.

## Estado

**Fuente lista.** Todavia no se agrega al `CMakeLists.txt` principal para no alterar el Blink funcional antes de validarlo.
