// following comment convention: motor#:pin#

int dir[4] = {6, 4, 11, 9}; //1:6; 2:4:; 3:11; 4:9
int pulse[4] = {5, 3, 10, 7}; //1:5; 2:3; 3:10; 4:7;
int dir4 = 11;
int pulse4 = 10;
int revolutions = 10; // total number of revolutions for the machine 
int numDelays = 4;  // total number of times we use the delay method
int standardDelay = 0; // time for delay given parameters
int amp = 20; // pulse per each tilting rotation, amplitude/ rotation = amp * 6 = 60 
// to increase frequency, change this number 'amp'
// note by changing frequency to faster, the tilting angle is less, for now!!!!!!!

int steps = 2; // number of rotations, total amplitude per up/down = amp * 6 * 2 = 120
int countPulse = 0; // number of pulses occurred
int up = 1;
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

void loop() {
  if (up == 1) {
        up = 0;
       // rise();
       initial();
        delay(5000);
       } else {
         for (int i = 0; i< 10; i++) {
           axial3Vertical();
         }
         fin();
         digitalWrite(ena, HIGH);
         exit(0);
         
  }

}


// starting from z-plane go up/down amplitude of 120
///////////////////// Now at amplitude of 0, 0, 0, 0

void axial3Vertical() { 
   
   for (int i = 0; i< 4; i++) { // set direction up
  
      digitalWrite(dir[i], HIGH);
   }
   
   // tilt
      axial3pulsing(0, 3); //2-3 down, 1-4 up 
      delay(10);
      axial3pulsing(0, 1); //3-4 down, 1-2 up
      delay(10);
      axial3pulsing(1, 2); // 2-3 up
      delay(10);
      axial3pulsing(2, 3); // 3-4 up
      delay(10);



///////////////////// Now at amplitude of 60, 60, 60, 60


   for (int i = 0; i< 4; i++) { // set direction down
  
      digitalWrite(dir[i], LOW);
   }
   

   // tilt

      axial3pulsing(0, 3); //2-3 up, 1-4 down 
      delay(10);
      axial3pulsing(0, 1); //3-4 up, 1-2 down
      delay(10);
      axial3pulsing(1, 2); // 2-3 down
      delay(10);
      axial3pulsing(2, 3); // 3-4 down
      delay(10);


///////////////////// Now at amplitude of 0, 0, 0, 0
   
}

// take fast motors as parameter
//  Pulse the fast motors 3, and slow motors once
// for each tilting rotation, the amp is inputed
void axial3pulsing(int motor_fast1, int motor_fast2) {
 
   for (int j = 0; j < amp; j++) {
    
      for (int i = 0; i < 4; i++) {
         digitalWrite(pulse[i], HIGH);
       
      }
  
      delay(5); 
      for (int i = 0; i < 4; i++) {
         digitalWrite(pulse[i], LOW);
          
      }
     delay(5);
  
     // as if it took 10ms for fast motor to go twice distance than (slower motor with 10ms)
     // same as twice the speed
     for (int z = 0; z < 2; z++) {
       digitalWrite(pulse[motor_fast1], HIGH);
       digitalWrite(pulse[motor_fast2], HIGH);
       delay(5);
       digitalWrite(pulse[motor_fast1], LOW);
       digitalWrite(pulse[motor_fast2], LOW);
       delay(5);
     }
     
  }
}  

// prepare for tilting such that we are tilting above and below z plane

void initial() {
    delay(2000);
    // axis 2-3 up, 1-4 down
    for (int i = 0; i < amp / 2; i++) {

           digitalWrite(pulse[1], HIGH);
           digitalWrite(pulse[2], HIGH);
           
           delay(10);
           
           digitalWrite(pulse[1], LOW);
           digitalWrite(pulse[2], LOW);
       
           delay(10);
    }

    delay(2000);

    // axis 3-4 up, 1-2 down
    for (int i = 0; i < amp/2; i++) {
      
           digitalWrite(pulse[2], HIGH);
           digitalWrite(pulse[3], HIGH);
           
           delay(10);
           
           digitalWrite(pulse[2], LOW);
           digitalWrite(pulse[3], LOW);
       
           delay(10);
                
     }

    delay(2000);
}


void fin() {
    
    delay(2000);
    // axis 1-4 up
    for (int i = 0; i < amp / 2; i++) {
           digitalWrite(dir[0],HIGH);
           digitalWrite(dir[3],HIGH);

           digitalWrite(pulse[0], HIGH);
           digitalWrite(pulse[3], HIGH);
           
           delay(10);
           
           digitalWrite(pulse[0], LOW);
           digitalWrite(pulse[3], LOW);
       
           delay(10);
    }

    delay(2000);

    // axis 1-2 up
    for (int i = 0; i < amp/2; i++) {
           digitalWrite(dir[0],HIGH);
           digitalWrite(dir[1],HIGH);
      
           digitalWrite(pulse[0], HIGH);
           digitalWrite(pulse[1], HIGH);
           
           delay(10);
           
           digitalWrite(pulse[0], LOW);
           digitalWrite(pulse[1], LOW);
       
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
