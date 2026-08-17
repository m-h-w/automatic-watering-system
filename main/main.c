#include <stdio.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

static void process_1_task(void *arg)
{
    while (1) {
        printf("Hello World from process 1\n");
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

static void process_2_task(void *arg)
{
    while (1) {
        printf("Hello World from process 2\n");
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

void app_main(void)
{
    xTaskCreate(process_1_task, "process_1", 2048, NULL, 5, NULL);
    xTaskCreate(process_2_task, "process_2", 2048, NULL, 5, NULL);
}
