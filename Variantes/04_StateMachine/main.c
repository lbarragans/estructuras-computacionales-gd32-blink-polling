#include <stdint.h>

#include "gd32vw55x.h"
#include "systimer.h"

#define LED_GPIO_PORT       GPIOC
#define LED_GPIO_PIN        GPIO_PIN_13
#define LED_GPIO_CLOCK      RCU_GPIOC
#define STATE_TIME_MS       1000U

typedef enum {
    STATE_LED_LOW = 0,
    STATE_LED_HIGH
} blink_state_t;

static blink_state_t state = STATE_LED_LOW;
static uint32_t state_started_ms = 0U;

static void led_init(void)
{
    rcu_periph_clock_enable(LED_GPIO_CLOCK);
    gpio_mode_set(LED_GPIO_PORT, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, LED_GPIO_PIN);
    gpio_output_options_set(
        LED_GPIO_PORT, GPIO_OTYPE_PP, GPIO_OSPEED_10MHZ, LED_GPIO_PIN
    );
    gpio_bit_reset(LED_GPIO_PORT, LED_GPIO_PIN);
}

static void blink_fsm_update(void)
{
    const uint32_t now = systimer_millis();

    if ((uint32_t)(now - state_started_ms) < STATE_TIME_MS) {
        return;
    }

    state_started_ms = now;

    switch (state) {
    case STATE_LED_LOW:
        gpio_bit_set(LED_GPIO_PORT, LED_GPIO_PIN);
        state = STATE_LED_HIGH;
        break;

    case STATE_LED_HIGH:
    default:
        gpio_bit_reset(LED_GPIO_PORT, LED_GPIO_PIN);
        state = STATE_LED_LOW;
        break;
    }
}

int main(void)
{
    led_init();
    systimer_init_1ms();
    state_started_ms = systimer_millis();

    while (1) {
        blink_fsm_update();
        /* Otras maquinas de estados pueden ejecutarse aqui. */
    }
}
