# 1. Preparación del entorno

## Requisitos

- Windows 10 u 11.
- Visual Studio Code.
- CMake 3.20 o superior.
- Ninja.
- GD32 Embedded Builder con Nuclei RISC-V GCC.
- OpenOCD con el archivo `target/gd32vw55x.cfg`.
- Biblioteca `GD32VW55x_Firmware_Library_V1.6.0`.
- Depurador CMSIS-DAP compatible, como WCH-Link.

Compruebe CMake y Ninja:

```powershell
cmake --version
ninja --version
```

## Configuración de rutas locales

Copie:

```text
tools/local_config.example.ps1
```

como:

```text
tools/local_config.ps1
```

Edite únicamente las rutas de:

```powershell
$GD32_SDK_ROOT
$NUCLEI_TOOLCHAIN_DIR
$OPENOCD_ROOT
```

En el computador utilizado durante el desarrollo, las rutas corresponden a
la biblioteca GD32, al directorio `NucleiRISCVGCC/bin` y a la raíz de
`xpack-openocd-0.11.0-3`.

`local_config.ps1` no se sube a GitHub. De esta manera cada estudiante puede
usar una instalación diferente sin modificar los archivos compartidos.

## Conexión

1. Alimente la placa por USB.
2. Conecte el WCH-Link mediante JTAG y niveles de 3,3 V.
3. Verifique tierra común entre la placa y el depurador.
4. Abra la carpeta raíz del ejercicio en VS Code.

