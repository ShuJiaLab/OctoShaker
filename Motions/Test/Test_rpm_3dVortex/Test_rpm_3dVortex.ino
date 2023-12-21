//bread board direction look --> + - + - orientaiton
//[ena+] [pul+] [dir+] [V+] [V-]
//Current code for expriment
// following comment convention: motor#:pin#
//int pulse[4] = {5, 3, 10, 7}; //1:5; 2:3; 3:10; 4:7;
//int dir[4] = {6, 4, 11, 9}; //1:6; 2:4:; 3:11; 4:9   1:A, 2:B, 3:C, 4:D

int pulse[4] = {4, 6, 9, 11}; //1:4; 2:6; 3:9; 4:11;
int dir[4] = {3, 5, 7, 10}; //1:3; 2:5:; 3:7; 4:10   1:A, 2:B, 3:C, 4:D

int duration = 60; // time it takes to complete all rotations.
int revolutions = 5; // total number of revolutions for the machine 
int numDelays = 4;  // total number of times we use the delay method
int standardDelay = 0; // time for delay given parameters
int steps = 20; // amplitude
int up = 1;
int rev = 100;
int ena = 8;
int exiting = 0;

// control for speed and frequency
int amp = 5; // Organoids originnal: 5
int inter_axis_delay = 200; //Organoids originnal: 200 um --> delayMicroseconds()
int inter_motor_delay = 900; // Organoids originnal: 900 um  --> delayMicroseconds()
int iter_time = (8 * inter_axis_delay + 2 * inter_motor_delay * amp * 8)/ 1000; //ms per iteration
int run_time = 1 * 60 * 1000; // 1 min * 60 seconds * 1000 s/ms
int iterations = floor(run_time/iter_time);
unsigned long startTime;
unsigned long time_iteration; 
// CONFIRMED: 73~74 ms per iteration


void setup() {
  Serial.begin(9600);
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

  for (int iter = 0; iter < iterations; iter++) {
     startTime = millis();
     axial23();
     time_iteration = millis() - startTime;
     Serial.println(time_iteration);
  }
  
}

// the loop routine runs over and over again forever:
// for expriment for certain time, the loop is modified to run infinitely
void loop() {  
  
}

int cDelay() {
  return (int) ((duration * 1000) / (revolutions * 2 * steps * 2));
}

void axial23() {
//  standardDelay = cDelay();

  // for (int z = 0; z < rev; z++) { commented out for time testing
    //axial3
   for (int i = 0; i < amp; i++) {
           digitalWrite(dir[0], HIGH); // 1 and 2 up
           digitalWrite(dir[1], HIGH);
           digitalWrite(dir[2], LOW);
           digitalWrite(dir[3], LOW);

          for (int j = 0; j < 4; j ++) {
            digitalWrite(pulse[j], HIGH);
           
          }

          delayMicroseconds(inter_motor_delay);

          for (int k = 0; k < 4; k ++) {
            digitalWrite(pulse[k], LOW);
           
          }

          delayMicroseconds(inter_motor_delay);      
     }

     delayMicroseconds(inter_axis_delay);

   //axil2
   //motor 2 goes up, 4 goes down. [1], [3]
              for (int i = 0; i < amp; i++) {
                    digitalWrite(dir[1], HIGH);
                    digitalWrite(dir[3], LOW);
                    
                    digitalWrite(pulse[1], HIGH);
                    digitalWrite(pulse[3], HIGH);
                    delayMicroseconds(inter_motor_delay);
                    digitalWrite(pulse[1], LOW);
                    digitalWrite(pulse[3], LOW);
                    delayMicroseconds(inter_motor_delay);
                
               }  
    delayMicroseconds(inter_axis_delay);
   
     
   //axial3  
   for (int i = 0; i < amp; i++) {
           digitalWrite(dir[0], LOW);
           digitalWrite(dir[1], HIGH);// 2,3 up
           digitalWrite(dir[2], HIGH);
           digitalWrite(dir[3], LOW);

          for (int j = 0; j < 4; j ++) {
            digitalWrite(pulse[j], HIGH);
           
          }

          delayMicroseconds(inter_motor_delay);

          for (int k = 0; k < 4; k ++) {
            digitalWrite(pulse[k], LOW);
           
          }

          delayMicroseconds(inter_motor_delay);      
     }
     delayMicroseconds(inter_axis_delay);
     
     //axial2
       // motor 1 goes down, 3 goes up [0], [2]
               for (int i = 0; i < amp; i++) {
                    digitalWrite(dir[0], LOW);
                    digitalWrite(dir[2], HIGH);
                    
                    digitalWrite(pulse[0], HIGH);
                    digitalWrite(pulse[2], HIGH);
                    delayMicroseconds(inter_motor_delay);
                    digitalWrite(pulse[0], LOW);
                    digitalWrite(pulse[2], LOW);
                    delayMicroseconds(inter_motor_delay);
               }

     delayMicroseconds(inter_axis_delay);


      // axial 3
     for (int i = 0; i < amp; i++) {
           digitalWrite(dir[0], LOW);
           digitalWrite(dir[1], LOW);
           digitalWrite(dir[2], HIGH);
           digitalWrite(dir[3], HIGH);

          for (int j = 0; j < 4; j ++) {
            digitalWrite(pulse[j], HIGH);
           
          }

          delayMicroseconds(inter_motor_delay);

          for (int k = 0; k < 4; k ++) {
            digitalWrite(pulse[k], LOW);
           
          }

          delayMicroseconds(inter_motor_delay);     
     }
      delayMicroseconds(inter_axis_delay);
    
    //axial 2
    //      motor 2 goes down, 4 goes up
               for (int i = 0; i < amp; i++) {
                    digitalWrite(dir[1], LOW);
                    digitalWrite(dir[3], HIGH);
                     
                    digitalWrite(pulse[1], HIGH);
                    digitalWrite(pulse[3], HIGH);
                    delayMicroseconds(inter_motor_delay);
                    digitalWrite(pulse[1], LOW);
                    digitalWrite(pulse[3], LOW);
                    delayMicroseconds(inter_motor_delay);
               }
      delayMicroseconds(inter_axis_delay);




    //axial3
     for (int i = 0; i < amp; i++) {
           digitalWrite(dir[0], HIGH);
           digitalWrite(dir[1], LOW);
           digitalWrite(dir[2], LOW);
           digitalWrite(dir[3], HIGH);

          for (int j = 0; j < 4; j ++) {
            digitalWrite(pulse[j], HIGH);
           
          }

          delayMicroseconds(inter_motor_delay);

          for (int k = 0; k < 4; k ++) {
            digitalWrite(pulse[k], LOW);
           
          }    
          delayMicroseconds(inter_motor_delay);    
     }
     delayMicroseconds(inter_axis_delay);

    //axial 2 
    //  motor 1 goes up, 3 goes down [0],[2]
          
             for (int i = 0; i < amp; i++) {
               digitalWrite(dir[0], HIGH);
               digitalWrite(dir[2], LOW);
                   
               digitalWrite(pulse[0], HIGH);
               digitalWrite(pulse[2], HIGH);
               delayMicroseconds(inter_motor_delay);
               digitalWrite(pulse[0], LOW);
               digitalWrite(pulse[2], LOW);
               delayMicroseconds(inter_motor_delay);
             }
    delayMicroseconds(inter_axis_delay);
   //} commented out for time testing

}


void rise() { // raise platform by 100 pulse * 1.8 degrees 
  for (int j = 0; j < 100; j++) {
      for (int i = 0; i < 4; i++) {
         digitalWrite(pulse[i], HIGH); // pulse level 3.3V wave
         delay(5);
         digitalWrite(pulse[i], LOW);
         delay(5);  
     }
  }
  
}

void homing() {
    for (int j = 0; j < 4; j ++) {
            digitalWrite(pulse[j], LOW);
           
     }

     for (int j = 0; j < 95; j++) {
      for (int i = 0; i < 4; i++) {
         digitalWrite(pulse[i], HIGH); // pulse level 3.3V wave
         delay(5);
         digitalWrite(pulse[i], LOW);
         delay(5);  
     }
     
  }
}

void initial() {
     for (int d = 0; d < 4; d++) {
      digitalWrite(dir[d], HIGH);
    }
   
     delayMicroseconds(inter_axis_delay);
    // axis 3-4 up, 1-2 down -- axial3
    for (int i = 0; i < amp / 2; i++) {

           digitalWrite(pulse[2], HIGH);
           digitalWrite(pulse[3], HIGH);
           
           delayMicroseconds(inter_motor_delay);
           
           digitalWrite(pulse[2], LOW);
           digitalWrite(pulse[3], LOW);
       
           delayMicroseconds(inter_motor_delay);
    }

    delayMicroseconds(inter_axis_delay);

    // axis 2-3 down, 1-4 up -- axial3
    for (int i = 0; i < amp/2; i++) {
      
           digitalWrite(pulse[0], HIGH);
           digitalWrite(pulse[3], HIGH);
           
           delayMicroseconds(inter_motor_delay);
           
           digitalWrite(pulse[0], LOW);
           digitalWrite(pulse[3], LOW);
       
           delayMicroseconds(inter_motor_delay);
                
     }

    delayMicroseconds(inter_axis_delay);

    // axis 1 up [2] (3 down) -- axial2
  for (int i = 0; i < amp / 2; i++) {
            digitalWrite(pulse[0], HIGH);
 

          delayMicroseconds(inter_motor_delay);

            digitalWrite(pulse[0], LOW);


          delayMicroseconds(inter_motor_delay);

                
   }

      delayMicroseconds(inter_axis_delay);

      // axial 4 up [3] (2 down) -- axial2
      for (int i = 0; i < amp / 2; i++) {

            digitalWrite(pulse[3], HIGH);
 

          delayMicroseconds(inter_motor_delay);


            digitalWrite(pulse[3], LOW);
      
          delayMicroseconds(inter_motor_delay);          
   }

      delayMicroseconds(inter_axis_delay);
}

void fin() {

   for (int d = 0; d < 4; d++) {
      digitalWrite(dir[d], LOW);
   }

  delayMicroseconds(inter_axis_delay);
    // axis 3-4 up, 1-2 down -- axial3
    for (int i = 0; i < amp / 2; i++) {

           digitalWrite(pulse[2], HIGH);
           digitalWrite(pulse[3], HIGH);
           
           delayMicroseconds(inter_motor_delay);
           
           digitalWrite(pulse[2], LOW);
           digitalWrite(pulse[3], LOW);
       
           delayMicroseconds(inter_motor_delay);
    }

    delayMicroseconds(inter_axis_delay);

    // axis 2-3 down, 1-4 up -- axial3
    for (int i = 0; i < amp/2; i++) {
      
           digitalWrite(pulse[0], HIGH);
           digitalWrite(pulse[3], HIGH);
           
           delayMicroseconds(inter_motor_delay);
           
           digitalWrite(pulse[0], LOW);
           digitalWrite(pulse[3], LOW);
       
           delayMicroseconds(inter_motor_delay);
                
     }

    delayMicroseconds(inter_axis_delay);

    // axis 1 up [2] (3 down) -- axial2
  for (int i = 0; i < amp / 2; i++) {
            digitalWrite(pulse[0], HIGH);
 

          delayMicroseconds(inter_motor_delay);

            digitalWrite(pulse[0], LOW);


          delayMicroseconds(inter_motor_delay);

                
   }

      delayMicroseconds(inter_axis_delay);

      // axial 4 up [3] (2 down) -- axial2
      for (int i = 0; i < amp / 2; i++) {

            digitalWrite(pulse[3], HIGH);
 

          delayMicroseconds(inter_motor_delay);


            digitalWrite(pulse[3], LOW);
      
          delayMicroseconds(inter_motor_delay);          
   }

      delayMicroseconds(inter_axis_delay);
}
  
