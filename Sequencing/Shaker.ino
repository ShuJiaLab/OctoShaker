//bread board direction look --> + - + - orientaiton
//[ena+] [pul+] [dir+] [V+] [V-]
//Current code for expriment
// following comment convention: motor#:pin#
//int pulse[4] = {5, 3, 10, 7}; //1:5; 2:3; 3:10; 4:7;
//int dir[4] = {6, 4, 11, 9}; //1:6; 2:4:; 3:11; 4:9   1:A, 2:B, 3:C, 4:D
#include "shaker_motions.h"

int pulse[4] = {4, 6, 9, 11}; //1:4; 2:6; 3:9; 4:11;
int dir[4] = {3, 5, 7, 10}; //1:3; 2:5:; 3:7; 4:10   1:A, 2:B, 3:C, 4:D
int ena = 8;
int up = 1;
int elevation = 60; //number of steps motor take when first raise platform

//https://www.digikey.com/en/maker/tutorials/2022/how-to-avoid-using-the-delay-function-in-arduino-sketches
//Might need to remove delay in future

//// control for speed and frequency
int amp = 5; // Organoids originnal: 5
int inter_axis_delay = 5000; //Organoids originnal: 200 um --> delayMicroseconds() //"seen" as motion smoothness
int inter_motor_delay = 5000; // Organoids originnal: 900 um  --> delayMicroseconds() //"seen" as arm speed

//// shaking for minutes -- use this code block
//int run_time = 1 * 60 * 1000; // # min (CHANGE this number to needed) * 60 seconds * 10^6 s/ms //Shaking duration
//int rest_time = 1 * 60 * 1000; 

//// shaking for seconds -- use this code block
int run_time = 1 * 1000; //  # seconds (CHANGE this number to needed) * 10^6 s/ms //Shaking duration
int rest_time = 4 * 1000; 

// shaking for miliseconds -- use this code block
//int run_time = 1000; // # miliseconds (CHANGE this number to needed) //Shaking duration
//int rest_time = 1000; 

int iter_time;
int iterations;
//int iter_time = (8 * inter_axis_delay + 2 * inter_motor_delay * amp * 8)/ 1000; //ms per iteration
//int iterations = floor(run_time/iter_time); //the number of iterations performed within allotted time

// For rmp testing
unsigned long startTime;
unsigned long time_iteration; 
// CONFIRMED: 73~74 ms per iteration

void setup() { //Commented block used for rpm test, with empty loop
  
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

//  for (int iter = 0; iter < iterations; iter++) {
//     startTime = millis();
//     #testingFunctionName;
//     time_iteration = millis() - startTime;
//     Serial.println(time_iteration);
//  }

}

// the loop routine runs over and over again forever:
// for rpm testing, leave loop empty

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(ena, LOW);
  if (up == 1) { // put this in SETUP???
       up = 0;
       // rise and readying for start
       delay(1000);
       rise(pulse, elevation);
       delay(1000);
  }

  
//  /////// Testing Section - comment out other unwanted codes before using
//  delay(5000);
//  digitalWrite(ena, HIGH);
//  delay(5000);
//  //////

  // Resting/Break block, allows motors to rest to shake at periodic intervals, reduce heat
  

//  // 3D Vortex Motion Block
  iter_time = (8 * inter_axis_delay + 2 * inter_motor_delay * amp * 8)/ 1000; //ms per iteration
  iterations = floor(run_time/iter_time); //the number of iterations performed within allotted time
//  three_D_Vortex_initial(pulse, dir, amp, inter_axis_delay,inter_motor_delay);
  for (int iter = 0; iter < iterations; iter++) {
     startTime = millis();
     three_D_Vortex(pulse, dir, amp, inter_axis_delay,inter_motor_delay);
     time_iteration = millis() - startTime;
     Serial.println(time_iteration);
  }
//  three_D_Vortex_fin(pulse, dir, amp, inter_axis_delay,inter_motor_delay);
  //// disable and exit code
//  digitalWrite(ena, HIGH);
////  exit(0); // Use exit(0) carefully. It will permenantly stops the code, will require re-upload!


//// seeSaw motion block
//  iter_time = (2 * inter_axis_delay + 2 * inter_motor_delay * 2 * amp * 2)/ 1000; //ms per iteration
//  iterations = floor(run_time/iter_time); //the number of iterations performed within allotted time
//  seeSaw_initial(pulse, dir, amp, inter_axis_delay,inter_motor_delay);
//  for (int iter = 0; iter < iterations; iter++) {
//    seeSaw(pulse, dir, amp, inter_axis_delay,inter_motor_delay);
//  }
//  seeSaw_fin(pulse, dir, amp, inter_axis_delay,inter_motor_delay);
//  //// disable and exit code 
//  digitalWrite(ena, HIGH);
//  exit(0); // Use exit(0) carefully. It will permenantly stops the code, will require re-upload!


//// Use for periodical Shaking
//  delay(rest_time);
}
