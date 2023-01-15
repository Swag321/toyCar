

long detection_range_start = 0, detection_range = 0;
int status_sensor, clap = 0, direction = HIGH;
int 
  Sensor = 8,
  frontWheel[][3] = {{0},{A0,10,11},{A1,12,13}};
  /*backWheel[][3] = {{0},{A2,7,6},{A3,5,4}};*/

void setup() { //execute once:
  pinMode(Sensor, INPUT);
  pinMode(frontWheel[1][0],OUTPUT);
  pinMode(frontWheel[1][1],OUTPUT);
  pinMode(frontWheel[1][2],OUTPUT);
  pinMode(frontWheel[2][0],OUTPUT);
  pinMode(frontWheel[2][1],OUTPUT);
  pinMode(frontWheel[2][2],OUTPUT);
 /* pinMode(backWheel[1][0], OUTPUT);
  pinMode(backWheel[1][1], OUTPUT);
  pinMode(backWheel[1][2], OUTPUT);
  pinMode(backWheel[2][0], OUTPUT);
  pinMode(backWheel[2][1], OUTPUT);
  pinMode(backWheel[2][2], OUTPUT);*/
  //Set the wheels to maximum speed:
  analogWrite(frontWheel[1][0], 255);
  analogWrite(frontWheel[2][0], 255);
/*  analogWrite(backWheel[1][0], 255);
  analogWrite(backWheel[2][0], 255);*/
  //Moves the car forward:
 /*        digitalWrite(backWheel[1][2], !direction);
         digitalWrite(backWheel[2][2], !direction);*/
         digitalWrite(frontWheel[1][2],!direction);
         digitalWrite(frontWheel[2][2],!direction);

/*         digitalWrite(backWheel[1][1],direction);
         digitalWrite(backWheel[2][1],direction);*/
         digitalWrite(frontWheel[1][1],direction);
         digitalWrite(frontWheel[2][1], direction);
  
}


void loop() {
   status_sensor = digitalRead(Sensor);
  if (status_sensor == 0) // If sound is detected...
  {
    if (clap == 0) // clap will increment through this block first time...
    {
      detection_range_start = detection_range = millis();
      clap++;
    } // To avoid noise, the second clap/snap will have to occur after 70 milliseconds...
    else if (clap > 0 && millis() - detection_range >= 70) 
    {
      detection_range = millis(); // updates the variable for another possible clap.
      clap++;
    }
  }
  if (millis() - detection_range_start >= 1000) // After 1 second, the program goes through this block.
  {
    if (clap == 2) // If clapped twice then car turns right.
    {
      turnRight();
    }
    if (clap == 3) // If 3 claps were sounded then car turns left.
    {
      turnLeft();
    }
    if (clap == 4) // The car switches velocity for 4 claps. 
    {
      moveOpposite();
    }
    clap = 0;
  }
}

void turnRight() { //Made possible by reducing speed of the right wheels.
  analogWrite(frontWheel[2][0],190);
  // analogWrite(backWheel[2][0],190);
  delay(500);
}

void turnLeft() { //Reduces speed of left 2 wheels.
  analogWrite(frontWheel[1][0],190);
  // analogWrite(backWheel[2][0],190);
  delay(500);
}

void moveOpposite() { // Changes wheels to opposite state.
    direction = !direction;
        // digitalWrite(backWheel[1][2], !direction);
        // digitalWrite(backWheel[2][2], !direction);
         digitalWrite(frontWheel[1][2],!direction);
         digitalWrite(frontWheel[2][2],!direction);

        // digitalWrite(backWheel[1][1],direction);
        // digitalWrite(backWheel[2][1],direction);
         digitalWrite(frontWheel[1][1],direction);
         digitalWrite(frontWheel[2][1], direction);
}


