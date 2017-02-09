/*
 Name:		Arduino_IRSmartCar.ino
 Created:	2/9/2017 3:13:54 PM
 Author:	snackk
*/

#include <IRremote.h>
#include <SmartCarLib.h>

SmartCar smartcar(10, 11, 6, 12, 13, 5);

int RECV_PIN = 9;
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
	Serial.begin(9600);
	irrecv.enableIRIn(); // Start the receiver
}

void loop() {

	if (irrecv.decode(&results)) {
		Serial.println(results.value, HEX);
		switch (results.value) {
		case 0xFD8877:
			smartcar.handleCar("F");
			break;
		case 0xFD9867:
			smartcar.handleCar("B");
			break;
		case 0xFD28D7:
			smartcar.handleCar("L");
			break;
		case 0xFD6897:
			smartcar.handleCar("R");
			break;
		}
		irrecv.resume(); // Receive the next value
	}
}
