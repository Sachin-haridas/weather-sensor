#include "DHT.h"

#define DHTTYPE DHT11
#define DHTPIN 2

// Initialize DHT sensor
DHT dht(DHTPIN, DHTTYPE); // connecting DHT sensor with D0 pin of NodeMCU

// Rain sensor pin
const int rainSensorPin = A1;

void setup() {
  Serial.begin(9600);
  delay(10);
  dht.begin();
  pinMode(rainSensorPin, INPUT);
}

void loop() {
  // Read humidity and temperature from DHT sensor
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  // Read rain sensor status
  int rainValue = analogRead(rainSensorPin);

  // Check if readings failed
  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Determine rain status using if condition
  String rain;
  if (rainValue== HIGH) {
    rain = "No Rain";
  } else {
    rain = "Rain Detected";
  }
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print("\tHumidity: ");
  Serial.print(h);
  Serial.print("\tRain Status: ");
  Serial.println(rain);

  delay(1000);
}