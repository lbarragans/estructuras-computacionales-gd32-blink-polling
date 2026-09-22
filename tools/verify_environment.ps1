[CmdletBinding()]
param()

$ErrorActionPreference = "Stop"
$ConfigFile = Join-Path $PSScriptRoot "local_config.ps1"

if (-not (Test-Path $ConfigFile)) {
    throw "Falta tools/local_config.ps1. Copie el archivo de ejemplo."
}

. $ConfigFile

$Checks = @(
    @{ Name = "CMake en PATH"; Path = (Get-Command cmake -ErrorAction SilentlyContinue).Source },
    @{ Name = "Ninja en PATH"; Path = (Get-Command ninja -ErrorAction SilentlyContinue).Source },
    @{ Name = "Git en PATH"; Path = (Get-Command git -ErrorAction SilentlyContinue).Source },
    @{ Name = "GCC RISC-V en PATH"; Path = (Get-Command riscv-nuclei-elf-gcc -ErrorAction SilentlyContinue).Source },
    @{ Name = "GDB RISC-V en PATH"; Path = (Get-Command riscv-nuclei-elf-gdb -ErrorAction SilentlyContinue).Source },
    @{ Name = "OpenOCD en PATH"; Path = (Get-Command openocd -ErrorAction SilentlyContinue).Source },
    @{ Name = "GCC configurado"; Path = (Join-Path $NUCLEI_TOOLCHAIN_DIR "riscv-nuclei-elf-gcc.exe") },
    @{ Name = "GDB configurado"; Path = (Join-Path $NUCLEI_TOOLCHAIN_DIR "riscv-nuclei-elf-gdb.exe") },
    @{ Name = "OpenOCD configurado"; Path = (Join-Path $OPENOCD_ROOT "bin/openocd.exe") },
    @{ Name = "Scripts OpenOCD"; Path = (Join-Path $OPENOCD_ROOT "scripts") },
    @{ Name = "Target GD32VW55x"; Path = (Join-Path $OPENOCD_ROOT "scripts/target/gd32vw55x.cfg") },
    @{ Name = "SDK bare-metal"; Path = (Join-Path $GD32_SDK_ROOT "Firmware/GD32VW55x_standard_peripheral/system_gd32vw55x.c") },
    @{ Name = "Linker"; Path = (Join-Path $GD32_SDK_ROOT "Firmware/RISCV/env_Eclipse/GD32VW553xM.lds") }
)

$Failed = $false
foreach ($Check in $Checks) {
    $Exists = -not [string]::IsNullOrWhiteSpace($Check.Path) -and
        (Test-Path $Check.Path)
    if ($Exists) {
        Write-Host ("[OK] {0}: {1}" -f $Check.Name, $Check.Path) -ForegroundColor Green
    } else {
        Write-Host ("[FALTA] {0}: {1}" -f $Check.Name, $Check.Path) -ForegroundColor Red
        $Failed = $true
    }
}

if ($Failed) {
    throw "El entorno no esta completo. Corrija el primer elemento [FALTA]."
}

Write-Host "Entorno listo para Blink Polling." -ForegroundColor Green
