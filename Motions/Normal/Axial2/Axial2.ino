
// Using motor 2:4 in this example 
// another axis should still be completed in this code
int dir[4] = {6, 4, 11, 9}; //1:6; 2:4:; 3:11; 4:9
int pulse[4] = {5, 3, 10, 7}; //1:5; 2:3; 3:10; 4:7;
int up = 1; // used to raise platform initially
int amp = 10;
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

// motor 2,4 needs to go at different direction all the time
void loop() {
       if (up == 1) { // in the beginning, raise platform
          //rise();
          up = 0;
          delay(5000);
        } else {
          axial2();
          //digitalWrite(ena, HIGH);
          exit(0);
        }

}

void axial2() {

        // initial, motor 2 goes down, 4 goes up
      
        digitalWrite(dir[1], LOW);
        digitalWrite(dir[3], HIGH);
        for (int i = 0; i < amp; i++) {
             digitalWrite(dir[1], LOW);
             digitalWrite(dir[3], HIGH);
                   
             digitalWrite(pulse[1], HIGH);
             digitalWrite(pulse[3], HIGH);
             delay(5);
             digitalWrite(pulse[1], LOW);
             digitalWrite(pulse[3], LOW);
             delay(5);
                
        }    

        delay(5);

        // initial, motor 1 goes down, 3 goes up [0], [2]
        
        digitalWrite(dir[0], LOW);
        digitalWrite(dir[2], HIGH);
        for (int i = 0; i < amp; i++) {
             digitalWrite(dir[0], LOW);
             digitalWrite(dir[2], HIGH);
                   
             digitalWrite(pulse[0], HIGH);
             digitalWrite(pulse[2], HIGH);
             delay(5);
             digitalWrite(pulse[0], LOW);
             digitalWrite(pulse[2], LOW);
             delay(5);
                
        }    
        
        delay(5);
        
        for (int j = 0; j < rev; j++) {
        
  //      motor 2 goes up, 4 goes down. [1], [3] --> twice amp
              digitalWrite(dir[1], HIGH);
              digitalWrite(dir[3], LOW);
              for (int i = 0; i < 2* amp; i++) {
                    
                    
                    digitalWrite(pulse[1], HIGH);
                    digitalWrite(pulse[3], HIGH);
                    delay(5);
                    digitalWrite(pulse[1], LOW);
                    digitalWrite(pulse[3], LOW);
                    delay(5);
                
               }    

               delay(5);

                // motor 1 goes up, 3 goes down [0], [2]
                digitalWrite(dir[0], HIGH);
                digitalWrite(dir[2], LOW);
               for (int i = 0; i < 2* amp; i++) {
                    
                    
                    digitalWrite(pulse[0], HIGH);
                    digitalWrite(pulse[2], HIGH);
                    delay(5);
                    digitalWrite(pulse[0], LOW);
                    digitalWrite(pulse[2], LOW);
                    delay(5);
               }

               delay(5);
               
          //      motor 2 goes down, 4 goes up
               digitalWrite(dir[1], LOW);
               digitalWrite(dir[3], HIGH);
               for (int i = 0; i < 2* amp; i++) {
                    digitalWrite(dir[1], LOW);
                    digitalWrite(dir[3], HIGH);
                     
                    digitalWrite(pulse[1], HIGH);
                    digitalWrite(pulse[3], HIGH);
                    delay(5);
                    digitalWrite(pulse[1], LOW);
                    digitalWrite(pulse[3], LOW);
                    delay(5);
               }

               delay(5);

          //  motor 1 goes down, 3 goes up [0],[2]
                 digitalWrite(dir[0], LOW);
                 digitalWrite(dir[2], HIGH);
                 for (int i = 0; i < 2* amp; i++) {
                   
                    
                   digitalWrite(pulse[0], HIGH);
                   digitalWrite(pulse[2], HIGH);
                   delay(5);
                   digitalWrite(pulse[0], LOW);
                   digitalWrite(pulse[2], LOW);
                   delay(5);
                 }

                  delay(5);
        }


              delay(10);
        
         //   end:   motor 2 goes up, 4 goes down. [1], [3]
              digitalWrite(dir[1], HIGH);
              digitalWrite(dir[3], LOW);
              for (int i = 0; i < amp; i++) {
                    
                    
                    digitalWrite(pulse[1], HIGH);
                    digitalWrite(pulse[3], HIGH);
                    delay(5);
                    digitalWrite(pulse[1], LOW);
                    digitalWrite(pulse[3], LOW);
                    delay(5);
                
               }    

          // end, motor 1 goes up, 3 goes down [0], [2]

       

        digitalWrite(dir[0], HIGH);
        digitalWrite(dir[2], LOW);
        for (int i = 0; i < amp; i++) {
                   
             digitalWrite(pulse[0], HIGH);
             digitalWrite(pulse[2], HIGH);
             delay(5);
             digitalWrite(pulse[0], LOW);
             digitalWrite(pulse[2], LOW);
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
