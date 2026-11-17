#include "servomotor.h"

servomotor::servomotor(gpio_num_t servo_pin)
{
    this->servo_pin = servo_pin;
    #ifdef ESP32DEV
      gpio_pad_select_gpio((gpio_num_t)servo_pin);
    #elif ESP32C3DEV
        gpio_pad_select_gpio((gpio_num_t)servo_pin);
    #elif ESP32S2DEV
        gpio_pad_select_gpio((gpio_num_t)servo_pin);
    #elif ESP32DEVC6
        esp_rom_gpio_pad_select_gpio((gpio_num_t)servo_pin);
    #elif ESP32DEVC5
        esp_rom_gpio_pad_select_gpio((gpio_num_t)servo_pin);
    #endif
    gpio_set_direction(servo_pin, GPIO_MODE_OUTPUT);
    return;
}

void servomotor::controlMotor(void*arg)
{
	while(1) {
        this->setPosition(this->pos);
    }
}

void servomotor::setPosition(unsigned int pos)
{
  // programação feita com lógica inversa, pois usei um transistor bc337 para aumentar a tensão de 3,3 para 5v
      gpio_set_level(servo_pin,1);
      #ifdef ESP32DEV
        ets_delay_us((uint32_t)pos);
        #elif ESP32C3DEV
            ets_delay_us((uint32_t)pos);
        #elif ESP32S2DEV
            ets_delay_us((uint32_t)pos);
        #elif ESP32DEVC6
            esp_rom_delay_us((uint32_t)pos);
        #elif ESP32DEVC5
            esp_rom_delay_us((uint32_t)pos);
        #endif

      gpio_set_level(servo_pin,0);

      #ifdef ESP32DEV
      ets_delay_us((uint32_t)10000-pos);
    #elif ESP32C3DEV
        ets_delay_us((uint32_t)10000-pos);
    #elif ESP32S2DEV
        ets_delay_us((uint32_t)10000-pos);
    #elif ESP32DEVC6
        esp_rom_delay_us((uint32_t)10000-pos);
    #elif ESP32DEVC5
        esp_rom_delay_us((uint32_t)10000-pos);
    #endif
}
