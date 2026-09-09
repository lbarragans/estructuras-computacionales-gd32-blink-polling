# 7. Plan de validacion de las variantes

## Regla

Una fuente no se declarara "validada" solamente porque se vea correcta.

Para cada variante realizaremos:

1. revision de codigo;
2. integracion con CMake;
3. `cmake --build`;
4. revision de warnings;
5. carga en GD32VW553;
6. observacion del LED;
7. depuracion si aplica;
8. commit independiente.

## Orden recomendado

### Fase A - documentacion y Linguist
Agregar menu, reglas de lenguajes y carpeta `Variantes`.

### Fase B - C + Assembly externo
Integrar `delay_riscv.S` y comprobar llamadas C -> Assembly.

### Fase C - SysTimer
Integrar la variante ya conocida del ejercicio SysTimer.

### Fase D - maquina de estados
Validar comportamiento no bloqueante.

### Fase E - scheduler cooperativo
Validar dos tareas periodicas.

### Fase F - FreeRTOS
Integrar kernel + port + `FreeRTOSConfig.h`, compilar y validar `vTaskDelay`.

## Estados usados en la documentacion

- **Base actual**: ya es la implementacion principal.
- **Basada en ejercicio verificado**: codigo utilizado en otro repositorio funcional, aun no seleccionado por este CMake.
- **Fuente lista**: codigo educativo preparado, pendiente de integracion/compilacion en este repositorio.
- **Integracion pendiente**: requiere dependencias adicionales antes de compilar.
- **Validada en placa**: solo se usara despues de una prueba fisica satisfactoria.
