


// following comment convention: motor#:pin#
int dir[4] = {6, 4, 11, 9}; //1:6; 2:4:; 3:11; 4:9
int pulse[4] = {5, 3, 10, 7}; //1:5; 2:3; 3:10; 4:7;


// number of steps each arm tilt to the side 
// Each step is a combination of pulses allow the arms to tilt for a certain pulses/distance
// to increase frequency, change this number 'amp'
// note by changing frequency to faster, the tilting angle is less, for now!!!!!!!


// number of pulses for each step
// total amplitude to each side equals 
int amp = 20;

// amplitude and Rotations
int up = 1;
int rev = 5;
int ena = 8;

// motor selection, change 'motor_start' to select the axis
int motor_start = 0; //pulse[0] // motor that will move first and down
int motor2 = (motor_start + 2) % 4; // pair with motor_start

int motorA = (motor_start + 1) % 4; // vertical arms
int motorB = (motor2 + 1) % 4;

void setup() {
  pinMode(ena, OUTPUT);
  digitalWrite(ena, LOW);

  
  for (int i=0; i<4; i++)
  {
    pinMode(dir[i], OUTPUT);
    digitalWrite(dir[i], HIGH);
  }
   for (int i=0; i<4; i++)
  {
    pinMode(pulse[i], OUTPUT);
    digitalWrite(pulse[i],LOW);
  }

}

void loop() {
  if (up == 1) {
        up = 0;
       // rise();
        delay(2000);
       } else if (up == 0) {
         for (int i = 0; i< 2; i++) { //!!! i = 1 or 0 testing only, change to 'rev'
           axial1Shaking();
         }
      // digitalWrite(ena, HIGH);
       exit(0);
         
  }

}


void axial1Shaking() {

     shake_left(); // motor 1 dip first at beginning
     delay(10);
     shake_right();
     delay(10);
     shake_right();
     delay(10);
     shake_left();
     delay(10);

  
}

//motor is the arm that would dip first in beginning of code
// input of 0-3. Pair 1-3, 0-2
void shake_left() {
  for (int j = 0; j < amp; j++) {
      for (int i = 0; i < 4; i++){
       digitalWrite(dir[i], LOW);
      }
      
        pulsing(motor_start); // when going down, motor_start is going faster --> tilt this side
      
    
      
    
      for (int i = 0; i < 4; i++){
       digitalWrite(dir[i], HIGH);
      }
    
      
        pulsing(motor2); // when going up, motor2 is going faster --> tilt toward motor_start
      
  }
}

//same motor as previous method
void shake_right() {
   for (int j = 0; j < amp; j++) {
    for (int i = 0; i < 4; i++){
     digitalWrite(dir[i], LOW);
    }
  
      pulsing(motor2); // when going down, motor2 is going faster --> tilt this side
      
  
    for (int i = 0; i < 4; i++){
     digitalWrite(dir[i], HIGH);
    }
  
      pulsing(motor_start); // when going down, motor_start is going faster --> tilt toward motor2
   }
}

//  Pulse the fast motor 4, vertical 2, slow 1
// motor 1, 3 for vertical; motor 2, 4 for tilting
void pulsing(int motor_fast) {
 
      // All motor 
      for (int i = 0; i < 4; i++) {
         digitalWrite(pulse[i], HIGH);
       
      }
  
      delay(5); 
      for (int i = 0; i < 4; i++) {
         digitalWrite(pulse[i], LOW);
          
      }
      delay(5);
      
     // Fast and vertical motor
     for (int i = 0; i < 2; i++) {
         delay(5);
         digitalWrite(pulse[motor_fast], HIGH);
         digitalWrite(pulse[motorA], HIGH);
         digitalWrite(pulse[motorB], HIGH);
         delay(5);
         digitalWrite(pulse[motor_fast], LOW);
         digitalWrite(pulse[motorA], LOW);
         digitalWrite(pulse[motorB], LOW);
         delay(5);
     }
     
     // Fast motor
     digitalWrite(pulse[motor_fast], HIGH);
     delay(5);
     digitalWrite(pulse[motor_fast], LOW);
     delay(5);
     
  
}  


void rise() { // raise platform by 60 pulse * 1.8 degrees 
  for (int j = 0; j < 100; j++) {
      for (int i = 0; i < 4; i++) {
         digitalWrite(pulse[i], HIGH); // pulse level 3.3V wave
         delay(2);
         digitalWrite(pulse[i], LOW);
         delay(2);  
     }
  }
  
}
