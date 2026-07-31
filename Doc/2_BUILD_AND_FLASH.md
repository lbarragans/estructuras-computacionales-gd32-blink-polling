# 2. Compilación y programación

## Desde VS Code

Abra **Terminal > Run Task** y ejecute:

```text
Build + Flash GD32
```

La secuencia realiza:

1. configuración de CMake;
2. compilación con Ninja;
3. generación de los formatos de salida;
4. conexión mediante CMSIS-DAP/JTAG;
5. programación, verificación y reinicio.

## Desde PowerShell

Configure:

```powershell
powershell -ExecutionPolicy Bypass `
  -File .\tools\configure.ps1 `
  -BuildType Debug
```

Compile:

```powershell
cmake --build --preset build-debug
```

Programe:

```powershell
powershell -ExecutionPolicy Bypass `
  -File .\tools\flash.ps1 `
  -BuildType Debug
```

## Resultados

Los archivos se generan exclusivamente en:

```text
build/debug/
├── GD32VW55x.elf
├── GD32VW55x.bin
├── GD32VW55x.hex
├── GD32VW55x.map
└── GD32VW55x.lst
```

Estos resultados no se almacenan en GitHub.

## Limpieza

```powershell
cmake --build --preset build-debug --target clean
```

Si se cambia el compilador o la ruta del SDK, elimine únicamente `build` y
configure nuevamente.

