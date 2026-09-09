#include <stdint.h>

#include "gd32vw55x.h"
#include "systimer.h"

#define LED_GPIO_PORT       GPIOC
#define LED_GPIO_PIN        GPIO_PIN_13
#define LED_GPIO_CLOCK      RCU_GPIOC
#define BLINK_INTERVAL_MS   1000U

static uint32_t last_transition_ms = 0U;

static void led_init(void)
{
    rcu_periph_clock_enable(LED_GPIO_CLOCK);
    gpio_mode_set(LED_GPIO_PORT, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, LED_GPIO_PIN);
    gpio_output_options_set(
        LED_GPIO_PORT, GPIO_OTYPE_PP, GPIO_OSPEED_10MHZ, LED_GPIO_PIN
    );
}

int main(void)
{
    led_init();
    systimer_init_1ms();
    last_transition_ms = systimer_millis();

    while (1) {
        uint32_t now = systimer_millis();

        if ((uint32_t)(now - last_transition_ms) >= BLINK_INTERVAL_MS) {
            last_transition_ms = now;
            gpio_bit_toggle(LED_GPIO_PORT, LED_GPIO_PIN);
        }

        /* Aqui la CPU podria ejecutar otras tareas. */
    }
}
