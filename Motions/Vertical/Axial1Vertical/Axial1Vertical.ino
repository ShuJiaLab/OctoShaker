// following comment convention: motor#:pin#
int dir[4] = {6, 4, 11, 9}; //1:6; 2:4:; 3:11; 4:9
int pulse[4] = {5, 3, 10, 7}; //1:5; 2:3; 3:10; 4:7;
int duration = 60; // time it takes to complete all rotations.
int revolutions = 10; // total number of revolutions for the machine 
int numDelays = 4;  // total number of times we use the delay method
int standardDelay = 0; // time for delay given parameters
int steps = 48; // amplitude --> must be multiple of 3!!!!!!!!!
int countPulse = 0; // number of pulses occurred

int up = 1;
int amp = 40;
int rev = 5;
int ena = 8;

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
        //rise();
        delay(5000);
       } else {
         for (int i = 0; i< rev; i++) {
           axial1Vertical();
         }
         digitalWrite(ena, HIGH);
         exit(0);
         
       }
}

int cDelay(int s) {
  return (int) ((duration * 1000) / (revolutions * 2 * s * 2));
}

void axial1Vertical() {
  // move it up
  
    countPulse = 1;
    for (int j = 0; j < steps; j++) {
      delay(2);
        for (int i = 0; i < 4; i++) {
          digitalWrite(dir[i], HIGH);
          if (i == 1 && (countPulse % 3 == 2)) {
            digitalWrite(pulse[i], HIGH);
          }
          else if ((i == 0 || i== 2) && (countPulse % 3 == 0 || countPulse % 3 == 2)) {
            digitalWrite(pulse[i], HIGH); // why not hard code this to run both level motor
          }
          else if (i==3){
            digitalWrite(pulse[i], HIGH);
          }
        }
        
        
        delay(5);
        for (int i = 0; i < 4; i++) {
          digitalWrite(pulse[i], LOW);
        }
        delay(5);
        countPulse++;
    }

  
    countPulse = 1;
    for (int j = 0; j < 2*steps; j++) {
        delay(2);
        for (int i = 0; i < 4; i++) {
          digitalWrite(dir[i], HIGH);
          if (i == 3 && (countPulse % 3 == 2)) {
            digitalWrite(pulse[i], HIGH);
          }
          else if ((i == 0 || i== 2) && (countPulse % 3 == 0 || countPulse % 3 == 2)) {
            digitalWrite(pulse[i], HIGH);
          }
          else if (i==1){
            digitalWrite(pulse[i], HIGH);
          }
        }
        
        
        delay(5);
        for (int i = 0; i < 4; i++) {
          digitalWrite(pulse[i], LOW);
        }
        delay(5);
        countPulse++;
    }


    countPulse = 1;
    for (int j = 0; j < steps; j++) {
        delay(2);
        for (int i = 0; i < 4; i++) {
          digitalWrite(dir[i], HIGH);
          if (i == 1 && (countPulse % 3 == 2)) {
            digitalWrite(pulse[i], HIGH);
          }
          else if ((i == 0 || i== 2) && (countPulse % 3 == 0 || countPulse % 3 == 2)) {
            digitalWrite(pulse[i], HIGH);
          }
          else if (i==3){
            digitalWrite(pulse[i], HIGH);
          }
        }
        
        
        delay(5);
        for (int i = 0; i < 4; i++) {
          digitalWrite(pulse[i], LOW);
        }
        delay(5);
        countPulse++;
    }


// move down
    countPulse = 1;
    for (int j = 0; j < steps; j++) {
        delay(2);
        for (int i = 0; i < 4; i++) {
          digitalWrite(dir[i], LOW);
          if (i == 3 && (countPulse % 3 == 2)) {
            digitalWrite(pulse[i], HIGH);
          }
          else if ((i == 0 || i== 2) && (countPulse % 3 == 0 || countPulse % 3 == 2)) {
            digitalWrite(pulse[i], HIGH);
          }
          else if (i==1){
            digitalWrite(pulse[i], HIGH);
          }
        }
        
        
        delay(5);
        for (int i = 0; i < 4; i++) {
          digitalWrite(pulse[i], LOW);
        }
        delay(5);
        countPulse++;
    }


    countPulse = 1;
    for (int j = 0; j < 2*steps; j++) {
        delay(2);
        for (int i = 0; i < 4; i++) {
          digitalWrite(dir[i], LOW);
          if (i == 1 && (countPulse % 3 == 2)) {
            digitalWrite(pulse[i], HIGH);
          }
          else if ((i == 0 || i== 2) && (countPulse % 3 == 0 || countPulse % 3 == 2)) {
            digitalWrite(pulse[i], HIGH);
          }
          else if (i==3){
            digitalWrite(pulse[i], HIGH);
          }
        }
        
        
        delay(5);
        for (int i = 0; i < 4; i++) {
          digitalWrite(pulse[i], LOW);
        }
        delay(5);
        countPulse++;
    }

    countPulse = 1;
    for (int j = 0; j < steps; j++) {
        delay(2);
        for (int i = 0; i < 4; i++) {
          digitalWrite(dir[i], LOW);
          if (i == 3 && (countPulse % 3 == 2)) {
            digitalWrite(pulse[i], HIGH);
          }
          else if ((i == 0 || i== 2) && (countPulse % 3 == 0 || countPulse % 3 == 2)) {
            digitalWrite(pulse[i], HIGH);
          }
          else if (i==1){
            digitalWrite(pulse[i], HIGH);
          }
        }
        
        
        delay(5);
        for (int i = 0; i < 4; i++) {
          digitalWrite(pulse[i], LOW);
        }
        delay(5);
        countPulse++;
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
