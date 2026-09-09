# Politica de GitHub Linguist

Este repositorio contiene varias maneras reales de resolver el mismo ejercicio de Blink.

Por esa razon, al agregar una variante con RISC-V Assembly, GitHub puede mostrar una combinacion como:

```text
C          xx.x %
Assembly   yy.y %
```

Eso es correcto: ambos lenguajes participan en las implementaciones guardadas.

No se ocultara C para forzar `Assembly 100%` ni se ocultara Assembly para forzar `C 100%`.

Los scripts PowerShell existentes pueden seguir utilizandose localmente, pero `.gitattributes` evita que aparezcan como lenguaje del ejercicio.
