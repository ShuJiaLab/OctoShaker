
// following comment convention: motor#:pin#
int dir[4] = {6, 4, 11, 9}; //1:6; 2:4:; 3:11; 4:9
int pulse[4] = {5, 3, 10, 7}; //1:5; 2:3; 3:10; 4:7;

// number of pulses for each step
// total amplitude to each side equals amp * 2 * steps = 60
int amp = 10;

// amplitude and Rotations
int up = 1;
int rev = 3;
int ena = 8;

// remember to set motor_left as the real left motor
int motor_left = 0; //pulse[0] // 
int motor_right = (motor_left + 2) % 4; // pair with motor_start

int motor_forw = (motor_left + 1) % 4; // forward respect to left motor
int motor_back = (motor_right + 1) % 4; // backward respect to left motor

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
        initial();
        delay(10);
        for (int i = 0; i< rev; i++) { //!!! i = 1 or 0 testing only, change to 'rev'
           axial3Shaking();
         }
       fin();
       digitalWrite(ena, HIGH);
       exit(0);
         
  }

}


void axial3Shaking() {

  

     shake_LF(); // dip down left and forward

     delay(10);

     shake_RF(); // dip down right and forward

     delay(10);

     shake_RB(); // dip down right and backward

     delay(10);

     shake_LB(); // dip down left and backward

     delay(10);
  
}


void shake_LF() {
   for (int j = 0; j < amp; j++) {
        for (int i = 0; i < 4; i++){
         digitalWrite(dir[i], LOW);
        }
        
        pulsing(motor_left, motor_forw); // tilt left and forward
      
       
        for (int i = 0; i < 4; i++){
         digitalWrite(dir[i], HIGH);
        }
      
         pulsing(motor_right, motor_back); // tilt left and forward
   }
  
}


void shake_RF() {
   for (int j = 0; j < amp; j++) {
        for (int i = 0; i < 4; i++){
         digitalWrite(dir[i], LOW);
        }
      
      
          pulsing(motor_right, motor_forw); // tilt right and forward
      
        for (int i = 0; i < 4; i++){
         digitalWrite(dir[i], HIGH);
        }
      
          pulsing(motor_left, motor_back); // tilt right and forward
   }
}


void shake_LB() {
   for (int j = 0; j < amp; j++) {
      for (int i = 0; i < 4; i++){
       digitalWrite(dir[i], LOW);
      }
    
    
        pulsing(motor_left, motor_back); // tilt left and backward
    
    
      for (int i = 0; i < 4; i++){
       digitalWrite(dir[i], HIGH);
      }
    
        pulsing(motor_right, motor_forw); // tilt left and backward
   }
}

void shake_RB() {
   for (int j = 0; j < amp; j++) {
      for (int i = 0; i < 4; i++){
       digitalWrite(dir[i], LOW);
      }
      
        pulsing(motor_right, motor_back); // tilt right and backward 
      
    
      for (int i = 0; i < 4; i++){
       digitalWrite(dir[i], HIGH); 
      }
    
        pulsing(motor_left, motor_forw); // tilt right and backward
   }

}



//  Pulse the fast motors 4, slow motors 1
void pulsing(int motor_fast1, int motor_fast2) {
     
      for (int i = 0; i < 4; i++) {
         digitalWrite(pulse[i], HIGH);
      }
  
      delay(5); 
      
      for (int i = 0; i < 4; i++) {
         digitalWrite(pulse[i], LOW);
          
      }
      delay(5);
      
     
     // Fast motors
     for (int z = 0; z < 3; z++) {
         digitalWrite(pulse[motor_fast1], HIGH);
         digitalWrite(pulse[motor_fast2], HIGH);
         delay(5);
         digitalWrite(pulse[motor_fast1], LOW);
         digitalWrite(pulse[motor_fast2], LOW);
         delay(5);
     }
}  

void initial() {
      for (int j = 0; j < amp / 2; j++) {
          for (int i = 0; i < 4; i++){
           digitalWrite(dir[i], LOW);
          }
        
        
            pulsing(motor_left, motor_back); // tilt left and backward
        
        
          for (int i = 0; i < 4; i++){
           digitalWrite(dir[i], HIGH);
          }
        
            pulsing(motor_right, motor_forw); // tilt left and backward
       }

     for (int j = 0; j < amp / 2; j++) {
        for (int i = 0; i < 4; i++){
         digitalWrite(dir[i], LOW);
        }
        
          pulsing(motor_right, motor_back); // tilt right and backward 
        
      
        for (int i = 0; i < 4; i++){
         digitalWrite(dir[i], HIGH); 
        }
      
          pulsing(motor_left, motor_forw); // tilt right and backward
    }
  
}

void fin() {
   for (int j = 0; j < amp / 2; j++) {
        for (int i = 0; i < 4; i++){
         digitalWrite(dir[i], LOW);
        }
        
        pulsing(motor_left, motor_forw); // tilt left and forward
      
       
        for (int i = 0; i < 4; i++){
         digitalWrite(dir[i], HIGH);
        }
      
         pulsing(motor_right, motor_back); // tilt left and forward
   }

    for (int j = 0; j < amp / 2; j++) {
          for (int i = 0; i < 4; i++){
           digitalWrite(dir[i], LOW);
          }
        
        
            pulsing(motor_right, motor_forw); // tilt right and forward
        
          for (int i = 0; i < 4; i++){
           digitalWrite(dir[i], HIGH);
          }
        
            pulsing(motor_left, motor_back); // tilt right and forward
     }

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
