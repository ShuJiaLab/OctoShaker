// following comment convention: motor#:pin#
int dir[4] = {6, 4, 11, 9}; //1:6; 2:4:; 3:11; 4:9
int pulse[4] = {5, 3, 10, 7}; //1:5; 2:3; 3:10; 4:7;
int dir4 = 11;
int pulse4 = 10;
int revolutions = 10; // total number of revolutions for the machine 
int numDelays = 4;  // total number of times we use the delay method
int standardDelay = 0; // time for delay given parameters
int amp = 5; // pulse per each tilting rotation, amplitude/ rotation = amp * (6 + 8) = 140 
// to increase frequency, change this number 'amp'
// note by changing frequency to faster, the tilting angle is less, for now!!!!!!!

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
        delay(2000);
        rise();
       //initial();
        delay(3000);
       } else {
         for (int i = 0; i< rev; i++) { //!!! i = 1 or 0 testing only, change to 'rev'
           //axial23Vertical();
         }
        // fin();
        // digitalWrite(ena, HIGH);
         exit(0);
         
  }

}


// starting from z-plane go up/down amplitude of 120
///////////////////// Now at amplitude of 0, 0, 0, 0

void axial23Vertical() { 
   
   for (int i = 0; i< 4; i++) { // set direction up
  
      digitalWrite(dir[i], HIGH);
   }
   
   // tilt
      axial3pulsing(0, 3); //1-4 up
      delay(5);
      axial1pulsing(0, 1, 3); // 3 slow, 1 fast, 2,4 vertical
      delay(5);
      axial3pulsing(0, 1); //1-2 up
      delay(5);
      axial1pulsing(1, 0, 2); // 4 slow, 2 fast, 1,3 vertical
      delay(5);
      axial3pulsing(1, 2); //2-3 up
      delay(5);
      axial1pulsing(2, 1, 3); // 3 fast, 1 slow, 2,4 vertical
      delay(5);
      axial3pulsing(2, 3); //3-4 up
      delay(5);
      axial1pulsing(3, 0, 2);
      delay(5);




///////////////////// Now at amplitude of 


   for (int i = 0; i< 4; i++) { // set direction down
  
      digitalWrite(dir[i], LOW);
   }
   
   // tilt
      axial3pulsing(0, 3); //1-4 up
      delay(5);
      axial1pulsing(0, 1, 3); // 3 slow, 1 fast, 2,4 vertical
      delay(5);
      axial3pulsing(0, 1); //1-2 up
      delay(5);
      axial1pulsing(1, 0, 2); // 4 slow, 2 fast, 1,3 vertical
      delay(5);
      axial3pulsing(1, 2); //2-3 up
      delay(5);
      axial1pulsing(2, 1, 3); // 3 fast, 1 slow, 2,4 vertical
      delay(5);
      axial3pulsing(2, 3); //3-4 up
      delay(5);
      axial1pulsing(3, 0, 2);
      delay(5);
       

///////////////////// Now at amplitude of 0, 0, 0, 0
   
}


//  Pulse the fast motor 4, vertical 2, slow 1
// motor 1, 3 for vertical; motor 2, 4 for tilting

void axial1pulsing(int motor_fast, int motor_ver1, int motor_ver2) {
 
  for (int j = 0; j < amp; j++) {

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
     for (int i = 0; i < 1; i++) {
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

     digitalWrite(pulse[motor_fast], HIGH);
     delay(5);
     digitalWrite(pulse[motor_fast], LOW);
     delay(5);

  }
}  

// take fast motors as parameter
//  Pulse the fast motors 4, and slow motors once --> adjusted 3 to 4 to 
        // match the axial1pulsing relative speed vs. Axial3Vertical.ino
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
     for (int z = 0; z < 3; z++) {
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
  
     delay(1500);
    // axis 2-3 up, 1-4 down -- axial3
    for (int i = 0; i < amp / 2; i++) {

           digitalWrite(pulse[1], HIGH);
           digitalWrite(pulse[2], HIGH);
           
           delay(10);
           
           digitalWrite(pulse[1], LOW);
           digitalWrite(pulse[2], LOW);
       
           delay(10);
    }

    delay(1500);

    // axis 3-4 up, 1-2 down -- axial3
    for (int i = 0; i < amp/2; i++) {
      
           digitalWrite(pulse[2], HIGH);
           digitalWrite(pulse[3], HIGH);
           
           delay(10);
           
           digitalWrite(pulse[2], LOW);
           digitalWrite(pulse[3], LOW);
       
           delay(10);
                
     }

    delay(1500);

    // axis 3 up [2] (1 down) -- axial2
  for (int i = 0; i < amp / 2; i++) {
          for (int j = 0; j < 4; j ++) {
            digitalWrite(pulse[2], HIGH);
           
          }

          delay(10);

          for (int k = 0; k < 4; k ++) {
            digitalWrite(pulse[2], LOW);
           
          }

          delay(10);

                
   }

      delay(1500);

      // axial 4 up [3] (2 down) -- axial2
      for (int i = 0; i < amp / 2; i++) {
          for (int j = 0; j < 4; j ++) {
            digitalWrite(pulse[3], HIGH);
          
          }

          delay(10);

          for (int k = 0; k < 4; k ++) {
            digitalWrite(pulse[3], LOW);
           
          }

          delay(10);          
   }

      delay(1500);
}


void fin() {
  
   for (int d = 0; d < 4; d++) {
      digitalWrite(dir[d], HIGH);
    }
  
     delay(1500);
     
    //  1-4 up -- axial3
    for (int i = 0; i < amp / 2; i++) {

           digitalWrite(pulse[0], HIGH);
           digitalWrite(pulse[3], HIGH);
           
           delay(10);
           
           digitalWrite(pulse[0], LOW);
           digitalWrite(pulse[3], LOW);
       
           delay(10);
    }

    delay(1500);

    // 1-2 up -- axial3
    for (int i = 0; i < amp/2; i++) {
      
           digitalWrite(pulse[0], HIGH);
           digitalWrite(pulse[1], HIGH);
           
           delay(10);
           
           digitalWrite(pulse[0], LOW);
           digitalWrite(pulse[1], LOW);
       
           delay(10);
                
     }

    delay(1500);

    // axis 1 up [0] (3 down) -- axial2
  for (int i = 0; i < amp / 2; i++) {
         
            digitalWrite(pulse[0], HIGH);
           
          

          delay(10);

    
            digitalWrite(pulse[0], LOW);
           
          

          delay(10);

                
   }

      delay(1500);

      // axial 2 up [1] (4 down) -- axial2
      for (int i = 0; i < amp / 2; i++) {
            digitalWrite(pulse[1], HIGH);
          
          }

          delay(10);

            digitalWrite(pulse[1], LOW);
           

          delay(10);          

      delay(1500);
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
