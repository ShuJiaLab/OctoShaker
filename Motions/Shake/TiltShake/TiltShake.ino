// following comment convention: motor#:pin#
int dir[4] = {6, 4, 11, 9}; //1:6; 2:4:; 3:11; 4:9
int pulse[4] = {5, 3, 10, 7}; //1:5; 2:3; 3:10; 4:7;
int dir4 = 11;
int pulse4 = 10;
int duration = 60; // time it takes to complete all rotations.
int revolutions = 10; // total number of revolutions for the machine 
int numDelays = 4;  // total number of times we use the delay method
int standardDelay = 0; // time for delay given parameters
int steps = 5; // amplitude
int countPulse = 0; // number of pulses occurred

int up = 1;
int rev = 10;
int ena = 8;
int amp = 15;

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
         rise();
         tilt();
        delay(5000);
       } else {
         
         for (int i = 0; i< rev; i++) { //!!! i = 1 or 0 testing only, change to 'rev'
            tiltShake();
         }
         digitalWrite(ena, HIGH);
         exit(0);
         
  }
}

void tiltShake() {
  
  for (int i = 0; i < amp; i++) {
    for (int motor = 0; motor < 4; motor++) {
      digitalWrite(dir[motor], HIGH);
      
      digitalWrite(pulse[motor], HIGH);
    }
    delay(10);
    for (int motor = 0; motor < 4; motor++) {
      digitalWrite(pulse[motor], LOW);
    }
    delay(10);
  }



  for (int i = 0; i < amp; i++) {
    for (int motor = 0; motor < 4; motor++) {
      digitalWrite(dir[motor], LOW);
      
      digitalWrite(pulse[motor], HIGH);
    }
    delay(10);
    for (int motor = 0; motor < 4; motor++) {
      digitalWrite(pulse[motor], LOW);
    }
    delay(10);
  }

 
}

void tilt() {
  for (int i = 0; i < 40; i++) {
    digitalWrite(dir[0], HIGH);
    digitalWrite(dir[2], LOW);
    
    digitalWrite(pulse[0], HIGH);
    digitalWrite(pulse[2], HIGH);
    
    delay(10);
    
    digitalWrite(pulse[0], LOW);
    digitalWrite(pulse[2], LOW);
    
    delay(10);
  }
  
}



void rise() { // raise platform by 60 pulse * 1.8 degrees 
  for (int j = 0; j < 80; j++) {
      for (int i = 0; i < 4; i++) {
         digitalWrite(pulse[i], HIGH); // pulse level 3.3V wave
         delay(2);
         digitalWrite(pulse[i], LOW);
         delay(2);  
     }
  }
  
}
