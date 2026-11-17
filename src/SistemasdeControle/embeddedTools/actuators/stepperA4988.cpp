#include "stepperA4988.h"

stepperA4988::stepperA4988(gpio_num_t step_pin, gpio_num_t direction_pin)
{
    this->step_pin = step_pin;
    this->direction_pin = direction_pin;

    #ifdef ESP32DEV
      esp_rom_gpio_pad_select_gpio((gpio_num_t)step_pin);
    #elif ESP32C3DEV
        esp_rom_gpio_pad_select_gpio((gpio_num_t)step_pin);
    #elif ESP32S2DEV
        esp_rom_gpio_pad_select_gpio((gpio_num_t)step_pin);
    #elif ESP32DEVC6
        esp_rom_gpio_pad_select_gpio((gpio_num_t)step_pin);
    #elif ESP32DEVC5
        esp_rom_gpio_pad_select_gpio((gpio_num_t)step_pin);
    #endif
    gpio_set_direction(step_pin, GPIO_MODE_OUTPUT);

    #ifdef ESP32DEV
      esp_rom_gpio_pad_select_gpio((gpio_num_t)direction_pin);
    #elif ESP32C3DEV
        esp_rom_gpio_pad_select_gpio((gpio_num_t)direction_pin);
    #elif ESP32S2DEV
        esp_rom_gpio_pad_select_gpio((gpio_num_t)direction_pin);
    #elif ESP32DEVC6
        esp_rom_gpio_pad_select_gpio((gpio_num_t)direction_pin);
    #elif ESP32DEVC5
        esp_rom_gpio_pad_select_gpio((gpio_num_t)direction_pin);
    #endif
    gpio_set_direction(direction_pin, GPIO_MODE_OUTPUT);

    this->direction = 0;
    gpio_set_level(this->direction_pin,this->direction);
    return;
}

void stepperA4988::newStep(bool direction)
{
      if(direction != this->direction){
        this->direction = direction;
        gpio_set_level(this->direction_pin,this->direction);
      }
      vTaskDelay(15 / portTICK_PERIOD_MS);
      gpio_set_level(this->step_pin,0);
      vTaskDelay(15 / portTICK_PERIOD_MS);
      gpio_set_level(this->step_pin,1);
}
