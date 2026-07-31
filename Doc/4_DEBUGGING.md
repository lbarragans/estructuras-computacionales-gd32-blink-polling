# 4. Depuración desde Visual Studio Code

## Configuración

Instale las extensiones recomendadas por `.vscode/extensions.json`. Este
proyecto utiliza **Cortex-Debug**, no una configuración genérica `cppdbg`.

Después de editar `tools/local_config.ps1`, ejecute:

```powershell
powershell -NoProfile -ExecutionPolicy Bypass `
  -File .\tools\create_debug_config.ps1
```

El script genera `.vscode/launch.json` con las rutas locales de Nuclei GDB y
OpenOCD. Ese archivo está ignorado por Git.

## Breakpoints sugeridos

En `Src/main.c`, coloque un breakpoint sobre la instrucción que cambia PC13:

```c
gpio_bit_toggle(LED_GPIO_PORT, LED_GPIO_PIN);
```

Presione `F5` para iniciar **Debug GD32VW553 - Cortex Debug**. El depurador
compila, programa la placa y se detiene primero en `main`. Use `F5` para llegar
al breakpoint y `F10` para ejecutar el cambio del LED.

También puede detenerse dentro de la función de espera activa. Allí se observa
que la CPU permanece ocupada ejecutando el bucle de retardo: no puede realizar
otra tarea útil durante esos tres segundos.

## Concepto importante

Cuando el procesador está detenido por un breakpoint, el programa completo
queda pausado. El LED conserva su último estado hasta usar `F10`, `F5` o
finalizar la sesión.

Use el botón rojo **Stop** para terminar y después ejecute **Build + Flash
GD32** para comprobar el parpadeo normal sin GDB.

