#include <stdint.h>

#include "app_cfg.h"
#include "gd32vw55x_platform.h"
#include "wrapper_os.h"

#include "gd32vw55x.h"
#include "FreeRTOS.h"
#include "task.h"

#define LED_GPIO_PORT   GPIOC
#define LED_GPIO_PIN    GPIO_PIN_13
#define LED_GPIO_CLOCK  RCU_GPIOC

#define BLINK_PERIOD_MS 1000U

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

    gpio_bit_set(LED_GPIO_PORT, LED_GPIO_PIN);
}

static void blink_task(void *argument)
{
    (void)argument;

    TickType_t last_wake_time = xTaskGetTickCount();
    const TickType_t period = pdMS_TO_TICKS(BLINK_PERIOD_MS);

    for (;;) {
        gpio_bit_toggle(LED_GPIO_PORT, LED_GPIO_PIN);
        xTaskDelayUntil(&last_wake_time, period);
    }
}

int main(void)
{
    sys_os_init();
    platform_init();
    led_init();

    BaseType_t created = xTaskCreate(
        blink_task,
        "Blink",
        configMINIMAL_STACK_SIZE,
        NULL,
        tskIDLE_PRIORITY + 1U,
        NULL
    );

    if (created != pdPASS) {
        for (;;) {
        }
    }

    sys_os_start();

    for (;;) {
    }
}
