#ifndef SHAKER_MOTIONS_H
#define SHAKER_MOTIONS_H
#include <Arduino.h>

void rise(int pulse[], int elevation); // can be used for all motions

// Three_D_Vortex motion
void three_D_Vortex(int pulse[], int dir[], int amp, int inter_axis_delay,int inter_motor_delay);
void three_D_Vortex_initial(int pulse[], int dir[], int amp, int inter_axis_delay,int inter_motor_delay);
void three_D_Vortex_fin(int pulse[], int dir[], int amp, int inter_axis_delay,int inter_motor_delay);

// SeeSaw motion
void seeSaw(int pulse[], int dir[], int amp, int inter_axis_delay,int inter_motor_delay);
void seeSaw_initial(int pulse[], int dir[], int amp, int inter_axis_delay,int inter_motor_delay);
void seeSaw_fin(int pulse[], int dir[], int amp, int inter_axis_delay,int inter_motor_delay);

#endif
