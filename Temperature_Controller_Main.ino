#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define LED_PIN 8               // Heater LED pin
#define DHTPIN 7                // DHT11 sensor data pin
#define DHTTYPE DHT11           // DHT sensor type

#define MOTOR_PIN_ENA 9         // Enable pin for motor driver (PWM pin)
#define MOTOR_PIN_IN1 10        // Input pin 1 for motor driver
#define MOTOR_PIN_IN2 11        // Input pin 2 for motor driver

#define TEMPERATURE_THRESHOLD_LOW 27
#define TEMPERATURE_THRESHOLD_MED 29
#define TEMPERATURE_THRESHOLD_HIGH 32

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);  // Adjust the I2C address if needed

void setup() {
  Serial.begin(9600);
  dht.begin();

  Wire.begin();
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Temperature:");

  // Pin modes
  pinMode(LED_PIN, OUTPUT);
  pinMode(MOTOR_PIN_ENA, OUTPUT);
  pinMode(MOTOR_PIN_IN1, OUTPUT);
  pinMode(MOTOR_PIN_IN2, OUTPUT);
}

void loop() {
  delay(2000); // Delay between readings

  float temperature = dht.readTemperature(); // Read temperature in Celsius

  if (isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" °C");

  lcd.setCursor(0, 1);
  lcd.print("                "); // Clear previous text

  // Adjust fan speed and LED
  if (temperature > TEMPERATURE_THRESHOLD_HIGH) {
    // High speed
    digitalWrite(LED_PIN, LOW);
    analogWrite(MOTOR_PIN_ENA, 255);
    digitalWrite(MOTOR_PIN_IN1, HIGH);
    digitalWrite(MOTOR_PIN_IN2, LOW);
    lcd.setCursor(0, 1);
    lcd.print("Fan Speed: HIGH");
  }
  else if (temperature > TEMPERATURE_THRESHOLD_MED && temperature <= TEMPERATURE_THRESHOLD_HIGH) {
    // Medium speed
    digitalWrite(LED_PIN, LOW);
    analogWrite(MOTOR_PIN_ENA, 180);
    digitalWrite(MOTOR_PIN_IN1, HIGH);
    digitalWrite(MOTOR_PIN_IN2, LOW);
    lcd.setCursor(0, 1);
    lcd.print("Fan Speed: MED");
  }
  else if (temperature > TEMPERATURE_THRESHOLD_LOW && temperature <= TEMPERATURE_THRESHOLD_MED) {
    // Low speed
    digitalWrite(LED_PIN, LOW);
    analogWrite(MOTOR_PIN_ENA, 100);
    digitalWrite(MOTOR_PIN_IN1, HIGH);
    digitalWrite(MOTOR_PIN_IN2, LOW);
    lcd.setCursor(0, 1);
    lcd.print("Fan Speed: LOW");
  }
  else {
    // Heater ON, fan OFF
    digitalWrite(LED_PIN, HIGH);
    analogWrite(MOTOR_PIN_ENA, 0);
    lcd.setCursor(0, 1);
    lcd.print("Heater ON");
  }

  // Display temperature on LCD
  lcd.setCursor(12, 0);
  lcd.print(temperature);
  lcd.print("C");
}
