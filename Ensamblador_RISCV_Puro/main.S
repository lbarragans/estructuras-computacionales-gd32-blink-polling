.section .text
    .align 2

    .equ RCU_AHB1EN,         0x40023830

    .equ GPIOC_CTL,          0x40020800
    .equ GPIOC_OMODE,        0x40020804
    .equ GPIOC_OSPD,         0x40020808
    .equ GPIOC_PUD,          0x4002080C
    .equ GPIOC_BOP,          0x40020818
    .equ GPIOC_TG,           0x4002082C

    .equ GPIOC_CLOCK_BIT,    0x00000004
    .equ PC13_BIT,           0x00002000
    .equ PC13_FIELD_MASK,    0x0C000000
    .equ PC13_OUTPUT_MODE,   0x04000000
    .equ PC13_SPEED_10MHZ,   0x04000000

    .global main
    .type main, @function

main:
    /* Habilitar reloj de GPIOC. */
    li      t0, RCU_AHB1EN
    lw      t1, 0(t0)
    ori     t1, t1, GPIOC_CLOCK_BIT
    sw      t1, 0(t0)
    fence   iorw, iorw

    /* PC13 como salida. */
    li      t0, GPIOC_CTL
    lw      t1, 0(t0)
    li      t2, PC13_FIELD_MASK
    not     t2, t2
    and     t1, t1, t2
    li      t2, PC13_OUTPUT_MODE
    or      t1, t1, t2
    sw      t1, 0(t0)

    /* Push-pull. */
    li      t0, GPIOC_OMODE
    lw      t1, 0(t0)
    li      t2, PC13_BIT
    not     t2, t2
    and     t1, t1, t2
    sw      t1, 0(t0)

    /* 10 MHz. */
    li      t0, GPIOC_OSPD
    lw      t1, 0(t0)
    li      t2, PC13_FIELD_MASK
    not     t2, t2
    and     t1, t1, t2
    li      t2, PC13_SPEED_10MHZ
    or      t1, t1, t2
    sw      t1, 0(t0)

    /* Sin pull-up ni pull-down. */
    li      t0, GPIOC_PUD
    lw      t1, 0(t0)
    li      t2, PC13_FIELD_MASK
    not     t2, t2
    and     t1, t1, t2
    sw      t1, 0(t0)

    /* LED inicialmente apagado. */
    li      t0, GPIOC_BOP
    li      t1, PC13_BIT
    sw      t1, 0(t0)
    fence   iorw, iorw

.Lblink:
    li      t0, GPIOC_TG
    li      t1, PC13_BIT
    sw      t1, 0(t0)

    call    delay_aprox_1s
    j       .Lblink

    .size main, .-main

    .align 2
    .type delay_aprox_1s, @function

delay_aprox_1s:
    li      t0, 1000

.Lms:
    li      t1, 1000

.Lus:
    li      t2, 16

.Linner:
    nop
    addi    t2, t2, -1
    bnez    t2, .Linner

    addi    t1, t1, -1
    bnez    t1, .Lus

    addi    t0, t0, -1
    bnez    t0, .Lms

    ret

    .size delay_aprox_1s, .-delay_aprox_1s
