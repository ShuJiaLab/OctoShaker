// following comment convention: motor#:pin#
int dir[4] = {6, 4, 11, 9}; //1:6; 2:4:; 3:11; 4:9
int pulse[4] = {5, 3, 10, 7}; //1:5; 2:3; 3:10; 4:7;

int duration = 60; // time it takes to complete all rotations.
int revolutions = 10; // total number of revolutions for the machine 
int numDelays = 4;  // total number of times we use the delay method
int standardDelay = 0; // time for delay given parameters
int steps = 20; // amplitude
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
         axial3();
         //digitalWrite(ena, HIGH);
         exit(0);  
    }
     
}    

int cDelay() {
  return (int) ((duration * 1000) / (revolutions * 2 * steps * 2));
}

//Normal Tilting motion
void axial3() {
  standardDelay = cDelay();

   initial();

   for(int z = 0; z < rev; z++) {
    
   // axis 0-1 up, 2-3 down
   for (int i = 0; i < 40; i++) {
           digitalWrite(dir[0], HIGH);
           digitalWrite(dir[1], HIGH);
           digitalWrite(dir[2], LOW);
           digitalWrite(dir[3], LOW);

          for (int j = 0; j < 4; j ++) {
            digitalWrite(pulse[j], HIGH);
           
          }

          delay(10);

          for (int k = 0; k < 4; k ++) {
            digitalWrite(pulse[k], LOW);
           
          }

          delay (10);
    }

    delay(500);

     // axis 0-3 down, 1-2 up
    for (int i = 0; i < 40; i++) {
           digitalWrite(dir[0], LOW);
           digitalWrite(dir[1], HIGH);
           digitalWrite(dir[2], HIGH);
           digitalWrite(dir[3], LOW);

          for (int j = 0; j < 4; j ++) {
            digitalWrite(pulse[j], HIGH);
           
          }

          delay(10);

          for (int k = 0; k < 4; k ++) {
            digitalWrite(pulse[k], LOW);
           
          }

          delay(10);      
     }

     delay(500);

    // axis 0-1 down, 2-3 up.
    for (int i = 0; i < 40; i++) {
           digitalWrite(dir[0], LOW);
           digitalWrite(dir[1], LOW);
           digitalWrite(dir[2], HIGH);
           digitalWrite(dir[3], HIGH);

          for (int j = 0; j < 4; j ++) {
            digitalWrite(pulse[j], HIGH);
           
          }

          delay(10);

          for (int k = 0; k < 4; k ++) {
            digitalWrite(pulse[k], LOW);
           
          }

          delay(10);    
     }

     delay(500);


    // axis 0-3 up, 1-2 down. 
      for (int i = 0; i < 40; i++) {
           digitalWrite(dir[0], HIGH);
           digitalWrite(dir[1], LOW);
           digitalWrite(dir[2], LOW);
           digitalWrite(dir[3], HIGH);

          for (int j = 0; j < 4; j ++) {
            digitalWrite(pulse[j], HIGH);
           
          }

          delay(10);

          for (int k = 0; k < 4; k ++) {
            digitalWrite(pulse[k], LOW);
           
          }

          delay(10);

                
     }

      delay(500);
   }

   fin();
                
}
 

void rise() { // raise platform by 60 pulse * 1.8 degrees 
  for (int j = 0; j < 150; j++) {
      for (int i = 0; i < 4; i++) {
         digitalWrite(pulse[i], HIGH); // pulse level 3.3V wave
         delay(2);
         digitalWrite(pulse[i], LOW);
         delay(2);  
     }
  }
  
}


//Tilt the two individual axis in reverse direction for half of the amplitube of normal tilting
    //motion.
    //Reverse direction is defined as the opposite of the initial tilting direction of both axis
    //during normal tilting motion.
    //This insures the tilting motion is going above and below the z-plane we started with. 
void initial() {

    // axis 0-1 down, 2-3 up
    for (int i = 0; i < 20; i++) {
           digitalWrite(dir[0], LOW);
           digitalWrite(dir[1], LOW);
           digitalWrite(dir[2], HIGH);
           digitalWrite(dir[3], HIGH);

          for (int j = 0; j < 4; j ++) {
            digitalWrite(pulse[j], HIGH);
           
          }

          delay(10);

          for (int k = 0; k < 4; k ++) {
            digitalWrite(pulse[k], LOW);
           
          }

          delay (10);
    }

    delay(1000);

    // axis 0-3 up, 1-2 down
    for (int i = 0; i < 20; i++) {
           digitalWrite(dir[0], HIGH);
           digitalWrite(dir[1], LOW);
           digitalWrite(dir[2], LOW);
           digitalWrite(dir[3], HIGH);

          for (int j = 0; j < 4; j ++) {
            digitalWrite(pulse[j], HIGH);
           
          }

          delay(10);

          for (int k = 0; k < 4; k ++) {
            digitalWrite(pulse[k], LOW);
           
          }

          delay(10);

                
     }
    delay(1000);
}



//final movement to complete cycle:
void fin() {

    // axis 0-1 down, 2-3 up
    for (int i = 0; i < 20; i++) {
           digitalWrite(dir[0], HIGH);
           digitalWrite(dir[1], HIGH);
           digitalWrite(dir[2], LOW);
           digitalWrite(dir[3], LOW);

          for (int j = 0; j < 4; j ++) {
            digitalWrite(pulse[j], HIGH);
           
          }

          delay(10);

          for (int k = 0; k < 4; k ++) {
            digitalWrite(pulse[k], LOW);
           
          }

          delay (10);
    }

    delay(1000);

    // axis 0-3 up, 1-2 down
    for (int i = 0; i < 20; i++) {
           digitalWrite(dir[0], LOW);
           digitalWrite(dir[1], HIGH);
           digitalWrite(dir[2], HIGH);
           digitalWrite(dir[3], LOW);

          for (int j = 0; j < 4; j ++) {
            digitalWrite(pulse[j], HIGH);
           
          }

          delay(10);

          for (int k = 0; k < 4; k ++) {
            digitalWrite(pulse[k], LOW);
           
          }

          delay(10);

                
     }

      delay(1000);
}


     

    
       
