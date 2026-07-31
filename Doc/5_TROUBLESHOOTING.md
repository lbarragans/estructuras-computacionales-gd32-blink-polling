# 5. Solución de problemas

| Mensaje o síntoma | Acción recomendada |
|---|---|
| `riscv-nuclei-elf-gcc was not found` | Corrija `NUCLEI_TOOLCHAIN_DIR`; debe terminar en `NucleiRISCVGCC/bin` |
| Scripts deshabilitados | Use `powershell -NoProfile -ExecutionPolicy Bypass -File ...` |
| `ninja: no work to do` | Es normal: no hay fuentes modificados |
| Error `Parameter 'arch'` | Use Cortex-Debug y genere `launch.json` con el script incluido |
| `monitor command not supported` | No use la configuración genérica `cppdbg` |
| OpenOCD no encuentra el ELF | Ejecute primero `Build GD32 Debug` |
| No aparece el WCH-Link | Revise USB, alimentación, tierra común y conexión JTAG a 3,3 V |

Si se cambia el compilador o el SDK, elimine `build` y configure nuevamente:

```powershell
Remove-Item -Recurse -Force .\build
powershell -NoProfile -ExecutionPolicy Bypass `
  -File .\tools\configure.ps1 -BuildType Debug
```
