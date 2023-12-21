// following comment convention: motor#:pin#
int dir[4] = {6, 4, 11, 9}; //1:6; 2:4:; 3:11; 4:9
int pulse[4] = {5, 3, 10, 7}; //1:5; 2:3; 3:10; 4:7;
int dir4 = 11;
int pulse4 = 10;
int ena = 8; //enables or disables all the motors !!! --> HIGH is to disable, LOW is to enable

int duration = 60; // time it takes to complete all rotations.
int revolutions = 10; // total number of revolutions for the machine 
int numDelays = 4;  // total number of times we use the delay method
int standardDelay = 0; // time for delay given parameters
int steps = 80; // delay()
int up = 1; // used to raise platform initially

void setup() {
  pinMode(ena, OUTPUT);
  pinMode(ena, HIGH);
   
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
   if (up == 1) { // in the beginning, raise platform
          rise(); // only enable when from home z position
          up = 0;
          delay(2000);
          
  } else {
    for (int rot = 0; rot < revolutions; rot++) {
          upDown();
    }
   // digitalWrite(ena, HIGH); // disable motors
    exit(0);
  }
     
} 

int cDelay() {
  return (int) ((duration * 1000) / (revolutions * 2 * steps * 2)); 
}

void upDown() {
  standardDelay = cDelay();
  // move it up
      for (int j = 0; j < 80; j++) {
        for (int i = 0; i < 4; i++) {
          digitalWrite(dir[i], HIGH);
          digitalWrite(pulse[i], HIGH);
        }
        
        
        delay(5);
        for (int i = 0; i < 4; i++) {
          digitalWrite(pulse[i], LOW);
        }
        delay(5);
      
     }    
// move it down
      for (int j = 0; j < 80; j++) {
        for (int i = 0; i < 4; i++) {
          digitalWrite(dir[i], LOW);
          digitalWrite(pulse[i], HIGH);
        }
        
        
        delay(5);
        for (int i = 0; i < 4; i++) {
          digitalWrite(pulse[i], LOW);
        }
        delay(5);
      
     }  
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
