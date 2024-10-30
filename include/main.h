
#ifndef __MAIN_H__
#define __MAIN_H__

#include<Arduino.h>

#define A13 13  // ADC input
#define ECO 5
#define CITY 4
#define PRO 2
const byte RidingModes[] = {ECO, CITY, PRO};  // All modes
const uint8_t currentOutDiv[] = {0, 8, 15, 23, 31, 38, 46, 54, 62, 69, 85, 92, 100, 108, 112, 119, 192};
// Current output for each riding mode
const uint16_t currentOutEcoMode[] = {250, 220, 200, 170, 150, 110, 90, 80, 80, 70, 20, 10, 5, 5, 2, 1, 1};
const uint16_t currentOutCityMode[] = {565, 524, 498, 464, 430, 396, 362, 311, 250, 150, 33, 30, 25, 20, 25, 20, 3};
const uint16_t currentOutProMode[] = {800, 800, 760, 690, 620, 576, 542, 507, 442, 376, 300, 300, 300, 300, 300, 300, 3};
const uint8_t speedLimit = 200;
const double  coef = 0.048841;  //this coeficient is used when we directly use the ADC values
uint8_t numCurrentOutDiv = sizeof(currentOutDiv);
double currentOut = 0;
uint8_t ridingMode = 0;   // This can be set as default mode



#endif