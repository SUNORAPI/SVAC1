#include <Joystick.h>
#include <Encoder.h>


Joystick_ Joystick(JOYSTICK_DEFAULT_REPORT_ID,JOYSTICK_TYPE_GAMEPAD, 7, 0, true, true, false, false, false, false, false, false, false, false, false);
const int Abtn = 4;
const int Bbtn = 5;
const int Cbtn = 6;
const int Dbtn = 7;
const int Lbtn = 8;
const int Rbtn = 9;
const int Sbtn = 10;
const int Aled = 20;
const int Bled = 19;
const int Cled = 18;
const int Dled = 15;
const int Lled = 14;
const int Rled = 16;
const int Sled = 21;
Encoder LeftEncoder(2, 3);
Encoder RightEncoder(0, 1);
void setup(){
  pinMode(Abtn, INPUT_PULLUP);
  pinMode(Bbtn, INPUT_PULLUP);
  pinMode(Cbtn, INPUT_PULLUP);
  pinMode(Dbtn, INPUT_PULLUP);
  pinMode(Lbtn, INPUT_PULLUP);
  pinMode(Rbtn, INPUT_PULLUP);
  pinMode(Sbtn, INPUT_PULLUP);
  pinMode(Aled, OUTPUT);
  pinMode(Bled, OUTPUT);
  pinMode(Cled, OUTPUT);
  pinMode(Dled, OUTPUT);
  pinMode(Lled, OUTPUT);
  pinMode(Rled, OUTPUT);
  pinMode(Sled, OUTPUT);
  Joystick.begin();
  Joystick.setButton(1, 0);
  Joystick.setButton(2, 0);
  Joystick.setButton(3, 0);
  Joystick.setButton(4, 0);
  Joystick.setButton(5, 0);
  Joystick.setButton(6, 0);
  Joystick.setButton(0, 0);
  Joystick.setXAxisRange(0,1023);
  Joystick.setYAxisRange(0,1023);
} 
long LeftPos = 0;
long RightPos = 0;
int deltaLeft = 0;
int deltaRight = 0;
int XAxisValue = 0;
int YAxisValue = 0;
void loop(){
  long newLeft, newRight;
  newLeft = LeftEncoder.read();
  newRight = RightEncoder.read();
  if (newLeft != LeftPos || newRight != RightPos) {

    deltaLeft = (int)(newLeft - LeftPos);
    deltaRight = (int)(newRight - RightPos);

    if (deltaLeft != 0) {
      XAxisValue += deltaLeft;
    }
    if(deltaRight != 0) {
      YAxisValue += deltaRight;
    }

    LeftPos = newLeft;
    RightPos = newRight;

    if (XAxisValue < 0){
      XAxisValue += 1024;
    }
    else if (XAxisValue > 1023) {
      XAxisValue -= 1024;
    }

    if (YAxisValue < 0){
      YAxisValue += 1024;
    }
    else if (YAxisValue > 1023) {
      YAxisValue -= 1024;
    }

    Joystick.setXAxis(XAxisValue);
    Joystick.setYAxis(YAxisValue);
  }

  if (digitalRead(Abtn) == LOW) {
    Joystick.pressButton(1);
    digitalWrite(Aled, HIGH);
  }
  else {
    Joystick.releaseButton(1);
    digitalWrite(Aled, LOW);
  }

  if (digitalRead(Bbtn) == LOW) {
    Joystick.pressButton(2);
    digitalWrite(Bled, HIGH);
  }
  else {
    Joystick.releaseButton(2);
    digitalWrite(Bled, LOW);
  }

  if (digitalRead(Cbtn) == LOW) {
    Joystick.pressButton(3);
    digitalWrite(Cled, HIGH);
  }
  else {
    Joystick.releaseButton(3);
    digitalWrite(Cled, LOW);
  }

  if (digitalRead(Dbtn) == LOW) {
    Joystick.pressButton(4);
    digitalWrite(Dled, HIGH);
  }
  else {
    Joystick.releaseButton(4);
    digitalWrite(Dled, LOW);
  }

  if (digitalRead(Lbtn) == LOW) {
    Joystick.pressButton(5);
    digitalWrite(Lled, HIGH);
  }
  else {
    Joystick.releaseButton(5);
    digitalWrite(Lled, LOW);
  }

  if (digitalRead(Rbtn) == LOW) {
    Joystick.pressButton(6);
    digitalWrite(Rled, HIGH);
  }
  else {
    Joystick.releaseButton(6);
    digitalWrite(Rled, LOW);
  }

  if (digitalRead(Sbtn) == LOW) {
    Joystick.pressButton(0);
    digitalWrite(Sled, HIGH);
  }
  else {
    Joystick.releaseButton(0);
    digitalWrite(Sled, LOW);
  }
}