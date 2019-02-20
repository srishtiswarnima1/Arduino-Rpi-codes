#include <Wire.h>
#define add 0x04
char c;
int flag;

const int ledPin = 13; // onboard LED

static_assert(LOW == 0, "Expecting LOW to be 0");

void setup() {
  Wire.begin(add);                // join i2c bus with address #8
  Wire.onReceive(receiveEvent); // register event
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW); // turn it off
  Wire.onRequest(sendData);
  Serial.begin(9600);
  
}

void loop() {
  delay(100);
}

// function that executes whenever data is received from master
void receiveEvent(int bytes) {
  while (Wire.available()) { // loop through all but the last
    c = Wire.read(); // receive byte as a character
    Serial.print(c);
    //digitalWrite(ledPin, c);
    if(c==1)
    {
    digitalWrite(ledPin,HIGH);
    flag = 1;
    }
    else 
    if(c==0)
    {
    digitalWrite(ledPin, LOW);
    flag = 0;
    }
  }
}
//when data is requested from the slave 
void sendData(){
  Wire.write(flag);
  }
