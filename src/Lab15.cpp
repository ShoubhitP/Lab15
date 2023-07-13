/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/Users/shoubhitsstuff/Desktop/Lab15/src/Lab15.ino"
void setup();
void loop();
void refreshDisplay();
#line 1 "/Users/shoubhitsstuff/Desktop/Lab15/src/Lab15.ino"
SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);

#include "oled-wing-adafruit.h"

OledWingAdafruit display;

void setup()
{
  display.setup();
  pinMode(D5, INPUT_PULLUP);
  Serial.begin(9600);
  while (!Serial.isConnected())
  {
  }

  Watchdog.init(WatchdogConfiguration().timeout(5s));
  Watchdog.start();

  if (System.resetReason() == RESET_REASON_WATCHDOG)
  {
    refreshDisplay();
    display.println("Watchdog reset");
    display.display();
  }
  else
  {
    refreshDisplay();
    display.println("Normal reset");
    display.display();
    }
}

void loop()
{
  display.loop();
  if (!digitalRead(D5)) // D5 is high
  {
    Watchdog.refresh();
  }
}
void refreshDisplay()
{
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
}
