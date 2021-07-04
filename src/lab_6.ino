#include "oled-wing-adafruit.h"

SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);

OledWingAdafruit display;
// setup() runs once, when the device is first turned on.
void setup() {
  // Put initialization like pinMode and begin functions here.
  display.setup();
	display.clearDisplay();
	display.display();
}

// loop() runs over and over again, as quickly as it can execute.
void loop() {
  display.loop();
  //The formula to get the temperature in celsius from the TMP36
  uint64_t reading = analogRead(A5);
  double voltage = (reading * 3.3) / 4095.0;
  double temperature = (voltage - 0.5) * 100;
  double fahrenheit = temperature * 1.8 + 32;
  // to display the temperature
  if (display.pressedA()) {
    display.clearDisplay();
		display.setTextSize(1);
		display.setTextColor(WHITE);
		display.setCursor(0,0);
    display.println("celsius:");
		display.println(temperature);
    display.println("fahrenheit:");
		display.println(fahrenheit);
		display.display();
  }
  // The core of your code will likely live here.

}