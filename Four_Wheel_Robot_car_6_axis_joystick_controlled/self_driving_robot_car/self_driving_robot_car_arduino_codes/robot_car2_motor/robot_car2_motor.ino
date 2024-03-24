// Adafruit Motor shield library
// copyright Adafruit Industries LLC, 2009
// this code is public domain, enjoy!

#include <AFMotor.h>
#include<Servo.h>


AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

Servo myservo;

int speed_level = 0;

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  myservo.attach(10);
  // turn on motor
  set_speed();

  // light and buzzer starts

  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);


  // light and buzzer ends



}

void loop() {



  // receiving command from python starts here

  if (Serial.available() > 0) {
    String ctrCmd = Serial.readStringUntil('\n');

    if (ctrCmd == "forward") {
      all_forward();
    }

    if (ctrCmd == "backward") {
      all_reverse();
    }


    if (ctrCmd == "stop") {
      all_stop();
    }


    if (ctrCmd == "horn") {
      horn();
    }


    if (ctrCmd == "front_light_on") {
      front_light_on();
    }


    if (ctrCmd == "front_light_off") {
      front_light_off();
    }

    if (ctrCmd == "back_light_on") {
      back_light_on();
    }


    if (ctrCmd == "back_light_off") {
      back_light_off();
    }


    if (ctrCmd == "speed_70") {
      speed_70();
    }


    if (ctrCmd == "speed_110") {
      speed_110();
    }

    if (ctrCmd == "speed_150") {
      speed_150();
    }

    if (ctrCmd == "speed_200") {
      speed_200();
    }



     if (ctrCmd == "turn_left_forward") {
      turn_left_forward();
    }

     if (ctrCmd == "turn_right_forward") {
      turn_right_forward();
    }


        if (ctrCmd == "speed_0") {
        speed_0();
    }



  }

  // receiving command from python ends here





}


void all_forward() {
  myservo.write(90);
  motor1.run(BACKWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(FORWARD);
}

void all_reverse() {
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(BACKWARD);
}

void all_stop() {
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}


void turn_left_forward() {
  myservo.write(180);
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
}


void turn_right_forward() {
  myservo.write(0);
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);
}


void front_light_on() {
  analogWrite(A0, 255);
}

void front_light_off() {
  analogWrite(A0, 0);
}

void back_light_on() {
  analogWrite(A1, 255);
}

void back_light_off() {
  analogWrite(A1, 0);
}


void horn() {
  analogWrite(A2, 255);
  delay(100);
  analogWrite(A2, 0);
  delay(100);
  analogWrite(A2, 255);
  delay(100);
  analogWrite(A2, 0);
  delay(100);
  analogWrite(A2, 255);
  delay(100);

  analogWrite(A2, 0);
}


void set_speed() {
  motor1.setSpeed(speed_level);
  motor2.setSpeed(speed_level);
  motor3.setSpeed(speed_level);
  motor4.setSpeed(speed_level);
}


void speed_0() {
  speed_level = 0;
  set_speed();
}

void speed_70() {
  speed_level = 70;
  set_speed();
}

void speed_110() {
  speed_level = 110;
  set_speed();
}

void speed_150() {
  speed_level = 150;
  set_speed();
}

void speed_200() {
  speed_level = 200;
  set_speed();
}
