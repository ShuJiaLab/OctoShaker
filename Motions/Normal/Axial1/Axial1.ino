int pulse[4] = {4, 6, 9, 11}; //1:4; 2:6; 3:9; 4:11;
int dir[4] = {3, 5, 7, 10}; //1:3; 2:5:; 3:7; 4:10   1:A, 2:B, 3:C, 4:D
int up = 1;
int amp = 80;
int rev = 5;
int ena = 8;

void setup() {
  pinMode(ena, OUTPUT);
  digitalWrite(ena, LOW);

  digitalWrite(pulse[1], LOW);
  digitalWrite(pulse[3], LOW);
  digitalWrite(dir[1], HIGH);
  digitalWrite(dir[3], LOW);

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

// motor 1,3 needs to go at different direction all the time
void loop() {

      if (up == 1) {
        up = 0;
        //rise();
        delay(5000);
       } else {
         axial();
         //digitalWrite(ena, HIGH);
         exit(0);
         
       }
}

void axial() {
   digitalWrite(dir[1], LOW);
   digitalWrite(dir[3], HIGH);
   for (int i = 0; i < amp; i++) {
          digitalWrite(pulse[1], HIGH);
          digitalWrite(pulse[3], HIGH);
          delay(5);
          digitalWrite(pulse[1], LOW);
          digitalWrite(pulse[3], LOW);
          delay(5);
      
     }
     delay (5);

   for (int j = 0; j < rev; j++) {
     
       digitalWrite(dir[1], HIGH);
       digitalWrite(dir[3], LOW);
       for (int i = 0; i < 2 * amp; i++) {
              
              
              digitalWrite(pulse[1], HIGH);
              digitalWrite(pulse[3], HIGH);
              delay(5);
              digitalWrite(pulse[1], LOW);
              digitalWrite(pulse[3], LOW);
              delay(5);
          
         }
         delay (5);
    
         digitalWrite(dir[1], LOW);
         digitalWrite(dir[3], HIGH);
         for (int i = 0; i < 2 * amp; i++) {
               
              digitalWrite(pulse[1], HIGH);
              digitalWrite(pulse[3], HIGH);
              delay(5);
              digitalWrite(pulse[1], LOW);
              digitalWrite(pulse[3], LOW);
              delay(5);
         }
         delay(5);
   }

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

}


void flat() {
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
         delay (5);
  
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
