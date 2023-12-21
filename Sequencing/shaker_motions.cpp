#include "shaker_motions.h"
//int pulse[4] = {4, 6, 9, 11}; //1:4; 2:6; 3:9; 4:11;
//int dir[4] = {3, 5, 7, 10}; //1:3; 2:5:; 3:7; 4:10   1:A, 2:B, 3:C, 4:D
//
//// control for speed and frequency
//int amp = 5; // Organoids originnal: 5
//int inter_axis_delay = 200; //Organoids originnal: 200 um --> delayMicroseconds()
//int inter_motor_delay = 900; // Organoids originnal: 900 um  --> delayMicroseconds()
//// CONFIRMED: 73~74 ms per iteration
//

void rise(int pulse[], int elevation){// raise platform by 100 pulse * 1.8 degrees 
  for (int j = 0; j < elevation; j++) {
      for (int i = 0; i < 4; i++) {
         digitalWrite(pulse[i], HIGH); // pulse level 3.3V wave
         delay(5);
         digitalWrite(pulse[i], LOW);
         delay(5);  
     }
  }
}

void three_D_Vortex(int pulse[], int dir[], int amp, int inter_axis_delay,int inter_motor_delay){
 
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

void three_D_Vortex_initial(int pulse[], int dir[], int amp, int inter_axis_delay,int inter_motor_delay){
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

void three_D_Vortex_fin(int pulse[], int dir[], int amp, int inter_axis_delay,int inter_motor_delay){
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

void seeSaw(int pulse[], int dir[], int amp, int inter_axis_delay,int inter_motor_delay) {     
       digitalWrite(dir[1], HIGH);
       digitalWrite(dir[3], LOW);
       for (int i = 0; i < 2 * amp; i++) {
              
              
              digitalWrite(pulse[1], HIGH);
              digitalWrite(pulse[3], HIGH);
              delayMicroseconds(inter_motor_delay);
              digitalWrite(pulse[1], LOW);
              digitalWrite(pulse[3], LOW);
              delayMicroseconds(inter_motor_delay);
          
         }
         delayMicroseconds(inter_axis_delay);
    
         digitalWrite(dir[1], LOW);
         digitalWrite(dir[3], HIGH);
         for (int i = 0; i < 2 * amp; i++) {
           
              digitalWrite(pulse[1], HIGH);
              digitalWrite(pulse[3], HIGH);
              delayMicroseconds(inter_motor_delay);
              digitalWrite(pulse[1], LOW);
              digitalWrite(pulse[3], LOW);
              delayMicroseconds(inter_motor_delay);
         }
         delayMicroseconds(inter_axis_delay);
 }

void seeSaw_initial(int pulse[], int dir[], int amp, int inter_axis_delay,int inter_motor_delay) {
  //initial tilting adjustment
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
  }

void seeSaw_fin(int pulse[], int dir[], int amp, int inter_axis_delay,int inter_motor_delay) {
  //final tilting to flat position
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

  
