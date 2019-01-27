#define LED 13

#include <SoftwareSerial.h>
SoftwareSerial BT(0, 1);
const int motorPin1  = 9; // Pin  7 of L293
const int motorPin2  = 6;  // Pin  2 of L293
const int motorPin3  = 5; // Pin  7 of L293
const int motorPin4  = 3;  // Pin  2 of L293
// Using http://slides.justen.eng.br/python-e-arduino as refference

void setup() {
  pinMode(13, OUTPUT);
  // set the data rate for the SoftwareSerial port
  BT.begin(9600);
  // Send test message to other device


}

void go() {
  analogWrite(motorPin1, 0);
  analogWrite(motorPin2, 45);
  analogWrite(motorPin3, 0);
  analogWrite(motorPin4, 40);

}

void stopp() {
  analogWrite(motorPin1, 0);
  analogWrite(motorPin2, 0);
  analogWrite(motorPin3, 0);
  analogWrite(motorPin4, 0);

}

void left() {
  analogWrite(motorPin1, 0);
  analogWrite(motorPin2, 0);
  analogWrite(motorPin3, 0);
  analogWrite(motorPin4, 40);
}

void right() {
  analogWrite(motorPin1, 0);
  analogWrite(motorPin2, 40);
  analogWrite(motorPin3, 0);
  analogWrite(motorPin4, 0);

}


void two() {
  analogWrite(motorPin1, 40);
  analogWrite(motorPin2, 0);
  analogWrite(motorPin3, 40);
  analogWrite(motorPin4, 0);

}

void three() {
  analogWrite(motorPin1, 0);
  analogWrite(motorPin2, 100);
  analogWrite(motorPin3, 0);
  analogWrite(motorPin4, 100);

}


void happy() {
  analogWrite(motorPin1, 50);
  analogWrite(motorPin2, 0);
  analogWrite(motorPin3, 0);
  analogWrite(motorPin4, 50);

}

void loop() {
  
  if (BT.available()) {
    char serialListener = BT.read();
    if (serialListener == 'F') {
      go();
    }
    else if (serialListener == 'S') {
      stopp();
    }
    else if (serialListener == 'L') {
      left();
    }
    else if (serialListener == 'R') {
      right();
    }
    else if (serialListener == 'T') {
      two();
    }
    else if (serialListener == 'E') {
      three();
    }
    else if (serialListener == 'H') {
      happy();
    }

  }
}
