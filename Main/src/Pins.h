#ifndef Pins_h
#define Pins_h

#include <Arduino.h>

// Sensores de reflectancia
unsigned char SensorArrayPins[] = { A4, A3, A2, A1 };
unsigned char LeftBorderSensorPin = 6;
unsigned char RightBorderSensorPin = 7;

#define COMMAND_BUTTON_PIN  5
#define STATUS_LED_PIN 13


//Pinos do Microcontrolador
#define L_MOTOR_PWM_PIN 11
#define L_MOTOR_DIR_PIN 3
#define R_MOTOR_PWM_PIN 9
#define R_MOTOR_DIR_PIN 10
#define BUZZER_PIN 12


#endif //Pins_h
