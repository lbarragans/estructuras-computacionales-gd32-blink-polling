#include <stdint.h>

#include "gd32vw55x.h"

#define LED_GPIO_PORT       GPIOC
#define LED_GPIO_PIN        GPIO_PIN_13
#define LED_GPIO_CLOCK      RCU_GPIOC
#define BLINK_INTERVAL_MS   1000U

/*
 * Retardo aproximado mediante espera activa.
 *
 * Esta función mantiene ocupada la CPU ejecutando instrucciones nop. Su
 * duración depende del reloj del procesador y de la optimización del
 * compilador. Se conserva intencionalmente para estudiar sus limitaciones
 * antes de introducir SysTimer e interrupciones.
 */
static void busy_wait_delay_us(uint32_t microseconds)
{
    volatile uint32_t cycles;

    while (microseconds-- > 0U) {
        cycles = 16U;
        while (cycles-- > 0U) {
            __asm volatile ("nop");
        }
    }
}

static void busy_wait_delay_ms(uint32_t milliseconds)
{
    while (milliseconds-- > 0U) {
        busy_wait_delay_us(1000U);
    }
}

static void led_init(void)
{
    rcu_periph_clock_enable(LED_GPIO_CLOCK);

    gpio_mode_set(
        LED_GPIO_PORT,
        GPIO_MODE_OUTPUT,
        GPIO_PUPD_NONE,
        LED_GPIO_PIN
    );

    gpio_output_options_set(
        LED_GPIO_PORT,
        GPIO_OTYPE_PP,
        GPIO_OSPEED_10MHZ,
        LED_GPIO_PIN
    );
}

int main(void)
{
    led_init();

    while (1) {
        gpio_bit_toggle(LED_GPIO_PORT, LED_GPIO_PIN);
        busy_wait_delay_ms(BLINK_INTERVAL_MS);
    }
}

