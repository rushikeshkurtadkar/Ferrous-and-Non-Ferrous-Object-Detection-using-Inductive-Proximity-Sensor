#include <Arduino.h>
#line 1 "C:\\Users\\rushi\\OneDrive\\Documents\\Arduino\\Final Arduino Ver\\Huh\\Huh.ino"
// Define pins for L298N Motor Driver
#define ENABLE_A 2
#define IN1 3
#define IN2 4
#define IN3 5
#define IN4 6
#define ENABLE_B 7

// Define pin for Inductive Proximity Sensor
#define SENSOR_PIN 8

#line 12 "C:\\Users\\rushi\\OneDrive\\Documents\\Arduino\\Final Arduino Ver\\Huh\\Huh.ino"
void setup();
#line 35 "C:\\Users\\rushi\\OneDrive\\Documents\\Arduino\\Final Arduino Ver\\Huh\\Huh.ino"
void loop();
#line 12 "C:\\Users\\rushi\\OneDrive\\Documents\\Arduino\\Final Arduino Ver\\Huh\\Huh.ino"
void setup() {
    // Set motor control pins as output
    pinMode(ENABLE_A, OUTPUT);
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    pinMode(ENABLE_B, OUTPUT);
    
    // Set sensor pin as input
    pinMode(SENSOR_PIN, INPUT);
    
    // Start motors in default rotation
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    
    // Enable motors at full speed
    analogWrite(ENABLE_A, 255);
    analogWrite(ENABLE_B, 255);
}

void loop() {
    // Read sensor state
    int sensorState = digitalRead(SENSOR_PIN);
    
    if (sensorState == HIGH) { 
        // If metal object detected, reverse Motor 2 direction
        digitalWrite(IN3, HIGH);
        digitalWrite(IN4, LOW);
    } else {
        // If no metal detected, keep Motor 2 in default direction
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
    }
    
    delay(100); // Small delay to stabilize sensor reading
}

