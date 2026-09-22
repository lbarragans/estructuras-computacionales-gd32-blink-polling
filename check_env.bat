@echo off
setlocal EnableExtensions
title Verificacion GD32VW553 - Ejercicio 00
echo ============================================================
echo  EJERCICIO 00 - VERIFICACION DEL ENTORNO
echo ============================================================
echo.
set "ERRORS=0"
call :check cmake "CMake"
call :check ninja "Ninja"
call :check git "Git"
call :check riscv-nuclei-elf-gcc "Nuclei RISC-V GCC"
call :check riscv-nuclei-elf-gdb "Nuclei RISC-V GDB"
call :check openocd "OpenOCD"
call :file "C:\gd32_tools\GD32VW55x_Firmware_Library_V1.6.0\Firmware\GD32VW55x_standard_peripheral\system_gd32vw55x.c" "SDK bare-metal"
call :file "C:\gd32_tools\openocd\scripts\target\gd32vw55x.cfg" "Target OpenOCD"
echo.
if "%ERRORS%"=="0" (
  echo [OK] Entorno listo. Abra esta carpeta en VS Code.
) else (
  echo [ERROR] Hay %ERRORS% problema(s). Revise C:\gd32_tools y PATH.
)
echo.
pause
exit /b %ERRORS%

:check
where %~1 >nul 2>&1
if errorlevel 1 (
  echo [FALTA] %~2: %~1 no esta en PATH
  set /a ERRORS+=1
) else (
  for /f "delims=" %%I in ('where %~1') do (
    echo [OK] %~2: %%I
    %~1 --version
    echo.
    goto :check_done
  )
)
:check_done
exit /b 0

:file
if exist "%~1" (
  echo [OK] %~2: %~1
) else (
  echo [FALTA] %~2: %~1
  set /a ERRORS+=1
)
exit /b 0
