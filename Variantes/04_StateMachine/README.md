# 04 - Blink como maquina de estados

## Lenguaje

C.

## Metodo

El LED se modela con dos estados:

```text
LOW -> HIGH -> LOW -> ...
```

Cada transicion ocurre cuando ha pasado el tiempo configurado.

## Por que funciona

La variable `state` conserva memoria del comportamiento actual. SysTimer aporta el tiempo y la funcion `blink_fsm_update()` decide si corresponde cambiar de estado.

## Que ensena

- estado;
- transicion;
- evento temporal;
- programacion no bloqueante;
- separacion entre comportamiento y temporizacion.

## Cuando no conviene

Para un Blink trivial es mas codigo que polling. Su valor aparece cuando el sistema tiene muchos comportamientos simultaneos.

## Estado

**Fuente lista; pendiente de integracion y prueba en este repositorio.**
