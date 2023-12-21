


// following comment convention: motor#:pin#
int dir[4] = {6, 4, 11, 9}; //1:6; 2:4:; 3:11; 4:9
int pulse[4] = {5, 3, 10, 7}; //1:5; 2:3; 3:10; 4:7;


// number of steps each arm tilt to the side 
// Each step is a combination of pulses allow the arms to tilt for a certain pulses/distance
// to increase frequency, change this number 'amp'
// note by changing frequency to faster, the tilting angle is less, for now!!!!!!!
int steps = 6;

// number of pulses for each step
// total amplitude to each side equals amp * 2 * steps = 60
int amp = 5;

// amplitude and Rotations
int up = 1;
int rev = 3;
int ena = 8;

// motor selection, change 'motorL' to select the axis
int motorL = 0; //pulse[0] // motor that will move first and down
int motorR = (motorL + 2) % 4; // pair with motorL
//motors left and right

//motors front and back
int motorF = (motorL + 1) % 4; 
int motorB = (motorR + 1) % 4;

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
        //rise();
        delay(2000);
        
       } else if (up == 0) {
        //initial(); Needs to be implemented
        delay(5);
        for (int i = 0; i< rev; i++) { //!!! i = 1 or 0 testing only, change to 'rev'
           axial2Shaking();
         }
      // fin(); Needs to be implemented
       digitalWrite(ena, HIGH);
       exit(0);
         
  }

}


void axial2Shaking() {

     shake_left(); // motor 1 dip first at beginning

     delay(5);

     shake_right();

     delay(5);

     shake_front(); // motor 2 dip first at beginning

     delay(5);

     shake_back();

     delay(5);

     shake_right(); // motor 3 dip first at beginning

     delay(5);
     
     shake_left();

     delay(5);

     shake_back(); // motor 4 dip first at beginning

     delay(5);
     
     shake_front();

     delay(5);
 
}

//motor is the arm that would dip first in beginning of code
// input of 0-3. Pair 1-3, 0-2
void shake_left() {

  for (int i = 0; i < amp; i++){
      for (int i = 0; i < 4; i++){
       digitalWrite(dir[i], LOW);
      }
    
      
        pulsing(motorL); // when going down, motorL is going faster --> tilt this side
      
    
      
    
      for (int i = 0; i < 4; i++){
       digitalWrite(dir[i], HIGH);
      }
    
        pulsing(motorR); // when going up, motorR is going faster --> tilt toward motorL
      
   }
}

//same motor as previous method
void shake_right() {
       for (int i = 0; i < amp; i++){
            for (int i = 0; i < 4; i++){
             digitalWrite(dir[i], LOW);
            }
          
              pulsing(motorR); // when going down, motorR is going faster --> tilt this side
            
          
            for (int i = 0; i < 4; i++){
             digitalWrite(dir[i], HIGH);
            }
          
              pulsing(motorL); // when going down, motorL is going faster --> tilt toward motorR
            
       }
}

void shake_front() {
     for (int i = 0; i < amp; i++){
        for (int i = 0; i < 4; i++){
         digitalWrite(dir[i], LOW);
        }
      
        
         pulsing(motorF); // when going down, motorL is going faster --> tilt this side
      
      
        for (int i = 0; i < 4; i++){
         digitalWrite(dir[i], HIGH);
        }
      
      
         pulsing(motorB); // when going up, motorR is going faster --> tilt toward motorL
     }
}

void shake_back() {
   for (int i = 0; i < amp; i++){
      for (int i = 0; i < 4; i++){
       digitalWrite(dir[i], LOW);
      }
      
        pulsing(motorB); // when going down, motorL is going faster --> tilt this side
      
    
      
    
      for (int i = 0; i < 4; i++){
       digitalWrite(dir[i], HIGH);
      }
    
        pulsing(motorF); // when going up, motorR is going faster --> tilt toward motorL
    }
}

//  Pulse the fast motor 4, vertical 2, slow 1
// motor 1, 3 for vertical; motor 2, 4 for tilting
void pulsing(int motor_fast) {

  //define vertical motors for each motor_fast
  int motor_ver1 = (motor_fast + 1) %4;
  int motor_ver2 = (motor_fast + 3) %4;
  
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
         digitalWrite(pulse[motor_ver1], HIGH);
         digitalWrite(pulse[motor_ver2], HIGH);
         delay(5);
         digitalWrite(pulse[motor_fast], LOW);
         digitalWrite(pulse[motor_ver1], LOW);
         digitalWrite(pulse[motor_ver2], LOW);
         delay(5);
     }
     
     // Fast motor
     digitalWrite(pulse[motor_fast], HIGH);
     delay(5);
     digitalWrite(pulse[motor_fast], LOW);
     delay(5);
    
}  


void rise() { // raise platform by 60 pulse * 1.8 degrees 
  for (int j = 0; j < 200; j++) {
      for (int i = 0; i < 4; i++) {
         digitalWrite(pulse[i], HIGH); // pulse level 3.3V wave
         delay(2);
         digitalWrite(pulse[i], LOW);
         delay(2);  
     }
  }
  
}
