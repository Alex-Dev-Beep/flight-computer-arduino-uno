#pragma once

#include <Arduino.h> 
#include <Wire.h>

void oled_data_block(uint8_t* data, uint8_t size);
void oled_cmd(uint8_t cmd);
void oled_data(uint8_t data);
void oled_setCursor(uint8_t col, uint8_t page);
void oled_char(char c);
void oled_printLine(uint8_t page, const char* text);
void oled_init();
void oled_clearLine(uint8_t page);

extern const uint8_t font6x8_ascii[128][6] PROGMEM;
