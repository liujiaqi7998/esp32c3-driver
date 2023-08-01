#ifndef __MOTORS_H
#define __MOTORS_H

#include <Arduino.h>

// 4路电机驱动线
#define AIN1R 2  // 控制电机1的方向
#define AIN2R 3  // 控制电机1的方向
#define BIN1R 4 // 控制电机2的方向
#define BIN2R 5  // 控制电机2的方向
#define CIN1R 11  // 控制电机3的方向
#define CIN2R 7 // 控制电机3的方向
#define DIN1R 6  // 控制电机4的方向
#define DIN2R 10  // 控制电机4的方向

#define freq 10000    // PWM波形频率10KHZ
#define resolution 9  // 使用PWM占空比的分辨率，占空比最大可写2^10-1=1023
#define Amplitude 800 // PWM限幅

void int_motors();
void set_A_pwm(int speed);
void set_B_pwm(int speed);
void set_C_pwm(int speed);
void set_D_pwm(int speed);
#endif // !__MOTORS_H
