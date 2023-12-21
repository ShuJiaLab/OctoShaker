// following comment convention: motor#:pin#
int dir[4] = {6, 4, 11, 9}; //1:6; 2:4:; 3:11; 4:9
int pulse[4] = {5, 3, 10, 7}; //1:5; 2:3; 3:10; 4:7;
int dir4 = 11;
int pulse4 = 10;
int duration = 60; // time it takes to complete all rotations.
int revolutions = 10; // total number of revolutions for the machine 
int numDelays = 4;  // total number of times we use the delay method
int standardDelay = 0; // time for delay given parameters
int steps = 40; // amplitude
int countPulse = 0; // number of pulses occurred

int up = 1;
int rev = 5;
int ena = 8;
int amp = 15;

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
  
// the loop routine runs over and over again forever:
void loop() {
  if (up == 1) {
        up = 0;
       // rise();
        delay(5000);
       } else {
         // initial(); implement
          for (int i = 0; i< rev; i ++) {
              axial2Vertical();
          }
           // final(); implement
          digitalWrite(ena, HIGH);
          exit(0);
       }
}

int cDelay(int s) {
  return (int) ((duration * 1000) / (revolutions * 2 * s * 2));
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

void axial2Vertical() {

  for (int i = 0; i < 4; i++) {
      digitalWrite(dir[i], HIGH);
   }
   
   pulsing(motorL);

   delay(5);
   
   pulsing(motorF);

   delay(5);
      
   pulsing(motorR);

   delay(5);
      
   pulsing(motorB);

   delay(5);

   /// going down

   for (int i = 0; i < 4; i++) {
      digitalWrite(dir[i], LOW);
   }
   
   pulsing(motorL);

   delay(5);
   
   pulsing(motorF);

   delay(5);
      
   pulsing(motorR);

   delay(5);
      
   pulsing(motorB);

   delay(5);
 
}


//  Pulse the fast motor 4, vertical 2, slow 1
void pulsing(int motor_fast) {

  
  //define vertical motors for each motor_fast
  int motor_ver1 = (motor_fast + 1) %4;
  int motor_ver2 = (motor_fast + 3) %4;

  for (int i = 0; i < amp; i++){
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
    
}  
