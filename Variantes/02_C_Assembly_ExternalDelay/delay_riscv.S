.section .text
    .align  2
    .global riscv_delay_cycles
    .type   riscv_delay_cycles, @function

/*
 * void riscv_delay_cycles(uint32_t iterations);
 *
 * ABI RISC-V:
 *   a0 = primer argumento
 *
 * Retardo pedagogico. No representa una unidad de tiempo absoluta.
 */
riscv_delay_cycles:
    beqz    a0, .Ldone

.Lloop:
    addi    a0, a0, -1
    nop
    bnez    a0, .Lloop

.Ldone:
    ret

    .size riscv_delay_cycles, .-riscv_delay_cycles
