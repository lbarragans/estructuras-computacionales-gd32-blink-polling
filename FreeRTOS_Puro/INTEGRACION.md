# Integracion funcional con el MSDK oficial

Esta variante usa el FreeRTOS, port Nuclei/ECLIC, heap, tick, startup y linker
ya integrados y probados por GigaDevice en `GD32VW55x_RELEASE_V1.0.3g`.

1. Instale o extraiga el SDK en `C:\\GD32\\GD32VW55x_RELEASE_V1.0.3g`.
2. Respalde `MSDK/app/main.c` y `MSDK/app/app_cfg.h`.
3. Copie `FreeRTOS_Puro/main.c` y `FreeRTOS_Puro/app_cfg.h` a `MSDK/app/`.
   El proyecto Eclipse oficial compila esa carpeta; no descubre automaticamente
   una carpeta de aplicacion nueva ni usa el `CMakeLists.txt` docente.
4. Compile primero MBL y despues MSDK.
5. Genere `image-all.bin` con MSDK en offset `0xA000`.
6. Programe la imagen completa en `0x08000000` mediante GD32 ISP CLI/CH340.
7. Libere BOOT0, reinicie y observe PC13 y los simbolos `g_*` indicados por
   el ejercicio.

`main.c` llama `sys_os_init()` y `platform_init()`, crea las tareas/objetos
FreeRTOS y entrega el control a `sys_os_start()`. No descargue otro kernel ni mezcle un port
RISC-V generico con el ECLIC de este dispositivo.

La compilacion en el MSDK elimina la antigua dependencia pendiente de un port
externo. La validacion fisica final debe registrarse sobre la placa real.
