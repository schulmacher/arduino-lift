// Include the AccelStepper Library
#include <AccelStepper.h>
#include "UltraSoundMean.h"
#include "Signals.h"
#include "Lift.h"
// #include "Fork.h"

#include <ArduinoBLE.h>

BLEService btService("180A"); // create service: "Device Information"
// create direction control characteristic and allow remote device to read and write
BLEByteCharacteristic btCharacteristics("2A57", BLERead | BLEWrite); // 2A57 is "Digital Output"

Signals liftSignals;
UltraSoundMean usDistanceInstance(5, 6);
Lift lift(&usDistanceInstance);
// Fork fork(&usDistanceInstance);

void setup() {
	Serial.begin(9600);
  while (!Serial);

  // begin initialization
  if (!BLE.begin()) {
    Serial.println("starting Bluetooth® Low Energy module failed!");
    while (1) { // blink the built-in LED fast to indicate an issue
      digitalWrite(LED_BUILTIN, HIGH);
      delay(100);
      digitalWrite(LED_BUILTIN, LOW);
      delay(100);
    }
  }
  BLE.setLocalName("UnoR4 Lift2");
  BLE.setAdvertisedService(btService);
  // add the characteristics to the service
  btService.addCharacteristic(btCharacteristics);
  // add the service
  BLE.addService(btService);
  btCharacteristics.writeValue(0);
  // start advertising
  BLE.advertise();

  Serial.println("Bluetooth® device active, waiting for connections...");
}

void loop() {
   BLEDevice controller = BLE.central();

  // if a central is connected to peripheral:
  if (controller) {
    Serial.print("Connected to controller: ");
    // print the controller's MAC address:
    Serial.println(controller.address());
    digitalWrite(LED_BUILTIN, HIGH);  // turn on the LED to indicate the connection

    // while the controller is still connected to peripheral:
    while (controller.connected()) {

      if (btCharacteristics.written()) {
        Serial.print(F("Value: "));
        Serial.println(btCharacteristics.value());

        switch (btCharacteristics.value()) {
          case 01:
            Serial.println("UP");
            lift.up(40);

            usDistanceInstance.measure();
            Serial.print("Distance: ");  
            Serial.println(usDistanceInstance.getDistance());

            break;
          case 02:
            Serial.println("DOWH");
            lift.down(40);

            usDistanceInstance.measure();
            Serial.print("Distance: ");  
            Serial.println(usDistanceInstance.getDistance());

            break;
          case 03:
            Serial.println("FLOOR 1");
            lift.floor1();
            break;
          case 04:
            Serial.println("FLOOR 2");
            lift.floor2();
            break;
          default:  // 0 or invalid control
            Serial.println("STOP");
            break;
        }
      }
    }

    // when the central disconnects, print it out:
    Serial.print(F("Disconnected from controller: "));
    Serial.println(controller.address());
    digitalWrite(LED_BUILTIN, LOW);         // when the central disconnects, turn off the LED

  }

  Serial.println("Waiting for connection");
  delay(2000);
  // fork.forward(1000);
	// delay(100);
}