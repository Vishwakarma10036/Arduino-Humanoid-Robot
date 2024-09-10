#include <IRremote.h>
#include <Servo.h>
IRrecv irrecv(6);
decode_results results;
unsigned long last;
int state = 0;
int state1 = 0;
Servo servo1, servo2, servo3, servo4, servo5, servo6, servo7;
Servo servo8, servo9, servo10, servo11, servo12, servo13;
void bosh() {
  for (int i = 40; i <= 150; i++) {
    servo4.write(i);
    delay(20);
  }
  for (int i = 150; i >= 40; i--) {
    servo4.write(i);
    delay(20);
  }
  servo4.write(90);
  delay(500); 
}
void tren() {
  for (int i = 0,  w = 180; i <= 180, w >= 0; i++, w--) {
    servo1.write(i);
    servo7.write(w);
    servo4.write(i);
    delay(5);
  }
  delay(1000);
  for (int i = 180, w = 0; i >= 0, w <= 180 ; i--, w++) {
    servo1.write(i);
    servo7.write(w);
    servo4.write(i);
    delay(5);
  }
  servo4.write(90);
  delay(1000);
  for (int i = 180, w = 0; i >= 0, w <= 180 ; i--, w++) {
    servo2.write(i);
    servo6.write(w);
    delay(5);
  }
  delay(1000);
  for (int i = 0,  w = 180; i <= 180, w >= 0; i++, w--) {
    servo2.write(i);
    servo6.write(w);
    delay(5);
  }
  delay(1000);
  for (int i = 90,  w = 90; i <= 180, w >= 0; i++, w--) {
    servo3.write(i);
    servo5.write(w);
    delay(5);
  }
  delay(1000);
  for (int i = 180, w = 0; i >= 90, w <= 90 ; i--, w++) {
    servo2.write(i);
    servo6.write(w);
    delay(5);
  }
  delay(1000);
  for (int i = 90,  w = 90; i <= 180, w >= 0; i++, w--) {
    servo2.write(i);
    servo6.write(w);
    delay(5);
  }
  delay(1000);
  for (int i = 180, w = 0; i >= 90, w <= 90 ; i--, w++) {
    servo3.write(i);
    servo5.write(w);
    delay(5);
  }
  delay(1000);
}

void yurish() {
  if (millis() - last > 500 && state == 0) {
    servo3.write(60);
    servo5.write(60);
    servo8.write(85);
    servo9.write(70);
    servo10.write(20);
    servo11.write(60);
    servo12.write(70);
    servo13.write(55);
    last = millis();
    state = 1;
  }
  if (millis() - last > 500 && state == 1) {
    servo3.write(90);
    servo5.write(90);
    servo8.write(95);
    servo9.write(70);
    servo10.write(60);
    servo11.write(60);
    servo12.write(90);
    servo13.write(65);
    last = millis();
    state = 2;
  }
  if (millis() - last > 500 && state == 2) {
    servo3.write(120);
    servo5.write(120);
    servo8.write(95);
    servo9.write(95);
    servo10.write(60);
    servo11.write(110);
    servo12.write(90);
    servo13.write(65);
    last = millis();
    state = 3;
  }
  if (millis() - last > 500 && state == 3) {
    servo3.write(90);
    servo5.write(90);
    servo8.write(85);
    servo9.write(70);
    servo10.write(60);
    servo11.write(60);
    servo12.write(90);
    servo13.write(55);
    last = millis();
    state = 0;
  }
}
void roslan() {
  servo1.write(20);
  servo2.write(180);
  servo3.write(90);
  servo4.write(90);
  servo5.write(90);
  servo6.write(0);
  servo7.write(160);
  servo8.write(90);
  servo9.write(70);
  servo10.write(60);
  servo11.write(60);
  servo12.write(90);
  servo13.write(50);
}
void prisidani() {
  if (millis() - last > 500 && state1 == 0) {
    servo3.write(90);
    servo5.write(90);
    servo8.write(90);
    servo9.write(70);
    servo10.write(60);
    servo11.write(60);
    servo12.write(90);
    servo13.write(60);
    last = millis();
    state1 = 1;
  }
  if (millis() - last > 500 && state1 == 1) {
    servo3.write(90);
    servo5.write(90);
    servo8.write(90);
    servo9.write(120);
    servo10.write(20);
    servo11.write(100);
    servo12.write(40);
    servo13.write(60);
    last = millis();
    state1 = 0;
  }
}
void setup() {
  irrecv.enableIRIn();
  Serial.begin(9600);
  pinMode(6, INPUT);

  servo1.attach(A0);
  servo2.attach(A1);
  servo3.attach(A2);
  servo4.attach(A3);
  servo5.attach(A4);
  servo6.attach(A5);
  servo7.attach(A6);
  servo8.attach(A7);
  servo9.attach(A8);
  servo10.attach(A9);
  servo11.attach(2);
  servo12.attach(4);
  servo13.attach(5);

  servo1.write(20);
  servo2.write(180);
  servo3.write(90);
  servo4.write(90);
  servo5.write(90);
  servo6.write(0);
  servo7.write(160);
  servo8.write(90);
  servo9.write(70);
  servo10.write(60);
  servo11.write(60);
  servo12.write(90);
  servo13.write(50);
}

void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value);
    if (results.value == 16718055) {
      yurish();
    } else if (results.value == 16730805) {
      prisidani();
    } else if (results.value == 12535991) {
      bosh();
    } else if (results.value == 12574751) {
      tren();
    } else {
      roslan();
    }







    irrecv.resume();
  }
}
