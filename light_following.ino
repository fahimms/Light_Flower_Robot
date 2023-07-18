int RMotor_1 = 2;

int RMotor_2 = 3;

int LMotor_1 = 4;

int LMotor_2 = 5;

int RPwm = 10;

int LPwm = 11;

int gSpeed = 70;        // MAX 255
int turn_speed = 80;    // MAX 255
  

void setup() {

  pinMode(RMotor_1, OUTPUT);

  pinMode(RMotor_2, OUTPUT);

  pinMode(LMotor_1, OUTPUT);

  pinMode(LMotor_2, OUTPUT);

  pinMode(RPwm, OUTPUT);

  pinMode(LPwm, OUTPUT);

  analogWrite(RPwm, gSpeed);

  analogWrite(LPwm, gSpeed);

} 

void loop() {

  int ldrright = digitalRead(7);

  int ldrleft = digitalRead(8);

  if (ldrright == 0 && ldrleft == 0) {

    move_forward();

  }

  if (ldrright == 0 && ldrleft == 1) {

    turn_right();

  }

  if (ldrright == 1 && ldrleft == 0) {

    turn_left();

  }

  if (ldrright == 1 && ldrleft == 1) {

    move_stop();

  }

  delay(100);

}

void move_forward() {

  digitalWrite(RMotor_1, HIGH);

  digitalWrite(RMotor_2, LOW);

  digitalWrite(LMotor_1, LOW);

  digitalWrite(LMotor_2, HIGH);

  analogWrite (RPwm, gSpeed);
  analogWrite (LPwm, gSpeed);
}


void turn_right() {

  digitalWrite(RMotor_1, LOW);

  digitalWrite(RMotor_2, LOW);

  digitalWrite(LMotor_1, LOW);

  digitalWrite(LMotor_2, HIGH);

  analogWrite (RPwm, gSpeed);
  analogWrite (LPwm, turn_speed);
}

void turn_left() {

  digitalWrite(RMotor_1, HIGH);

  digitalWrite(RMotor_2, LOW);

  digitalWrite(LMotor_1, LOW);

  digitalWrite(LMotor_2, LOW);
  
  analogWrite (RPwm, turn_speed);
  analogWrite (LPwm, gSpeed);
}

void move_stop() {

  digitalWrite(RMotor_1, LOW);

  digitalWrite(RMotor_2, LOW);

  digitalWrite(LMotor_1, LOW);

  digitalWrite(LMotor_2, LOW);

  analogWrite (RPwm, 0);
  analogWrite (LPwm, 0);
}