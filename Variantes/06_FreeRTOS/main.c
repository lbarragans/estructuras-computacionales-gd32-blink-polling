#include "gd32vw55x.h"

#include "FreeRTOS.h"
#include "task.h"

#define LED_GPIO_PORT   GPIOC
#define LED_GPIO_PIN    GPIO_PIN_13
#define LED_GPIO_CLOCK  RCU_GPIOC

static void led_init(void)
{
    rcu_periph_clock_enable(LED_GPIO_CLOCK);
    gpio_mode_set(LED_GPIO_PORT, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, LED_GPIO_PIN);
    gpio_output_options_set(
        LED_GPIO_PORT, GPIO_OTYPE_PP, GPIO_OSPEED_10MHZ, LED_GPIO_PIN
    );
}

static void blink_task(void *argument)
{
    (void)argument;

    for (;;) {
        gpio_bit_toggle(LED_GPIO_PORT, LED_GPIO_PIN);
        vTaskDelay(pdMS_TO_TICKS(1000U));
    }
}

int main(void)
{
    led_init();

    (void)xTaskCreate(
        blink_task,
        "Blink",
        configMINIMAL_STACK_SIZE,
        NULL,
        tskIDLE_PRIORITY + 1U,
        NULL
    );

    vTaskStartScheduler();

    /*
     * Solo se alcanza si el scheduler no pudo iniciar,
     * por ejemplo por configuracion/memoria insuficiente.
     */
    for (;;) {
    }
}
