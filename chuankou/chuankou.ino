#include <SoftwareSerial.h>

SoftwareSerial mySerial(0, 1); // RX, TX

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
   Serial.println(80, HEX);// "4E"
  Serial.println(06, HEX);// "4E"
  Serial.println(03, HEX);// "4E"
  Serial.println(77, HEX);// "4E"
  //Serial.println("Goodnight moon!");

  // set the data rate for the SoftwareSerial port
 
 // mySerial.println("Hello, world?");


}

void loop() { // run over and over
 setup();

}
