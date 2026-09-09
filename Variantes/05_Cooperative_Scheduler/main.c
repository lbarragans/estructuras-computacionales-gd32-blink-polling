#include <stddef.h>
#include <stdint.h>

#include "gd32vw55x.h"
#include "systimer.h"

#define LED_GPIO_PORT   GPIOC
#define LED_GPIO_PIN    GPIO_PIN_13
#define LED_GPIO_CLOCK  RCU_GPIOC

typedef void (*task_fn_t)(void);

typedef struct {
    task_fn_t fn;
    uint32_t period_ms;
    uint32_t last_run_ms;
} task_t;

static volatile uint32_t background_counter = 0U;

static void led_init(void)
{
    rcu_periph_clock_enable(LED_GPIO_CLOCK);
    gpio_mode_set(LED_GPIO_PORT, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, LED_GPIO_PIN);
    gpio_output_options_set(
        LED_GPIO_PORT, GPIO_OTYPE_PP, GPIO_OSPEED_10MHZ, LED_GPIO_PIN
    );
}

static void task_blink(void)
{
    gpio_bit_toggle(LED_GPIO_PORT, LED_GPIO_PIN);
}

static void task_background(void)
{
    background_counter++;
}

static task_t tasks[] = {
    { task_blink,      1000U, 0U },
    { task_background,  100U, 0U }
};

int main(void)
{
    size_t i;

    led_init();
    systimer_init_1ms();

    for (i = 0U; i < (sizeof(tasks) / sizeof(tasks[0])); ++i) {
        tasks[i].last_run_ms = systimer_millis();
    }

    while (1) {
        const uint32_t now = systimer_millis();

        for (i = 0U; i < (sizeof(tasks) / sizeof(tasks[0])); ++i) {
            if ((uint32_t)(now - tasks[i].last_run_ms) >= tasks[i].period_ms) {
                tasks[i].last_run_ms = now;
                tasks[i].fn();
            }
        }
    }
}
