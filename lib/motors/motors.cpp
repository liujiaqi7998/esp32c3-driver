#include "motors.h"

void int_motors()
{
    pinMode(AIN1R, OUTPUT);
    pinMode(AIN2R, OUTPUT);
    pinMode(BIN1R, OUTPUT);
    pinMode(BIN2R, OUTPUT);
    pinMode(CIN1R, OUTPUT);
    pinMode(CIN2R, OUTPUT);
    pinMode(DIN1R, OUTPUT);
    pinMode(DIN2R, OUTPUT);
    digitalWrite(AIN1R, 0);
    digitalWrite(AIN2R, 0);
    digitalWrite(BIN1R, 0);
    digitalWrite(BIN2R, 0);
    digitalWrite(CIN1R, 0);
    digitalWrite(CIN2R, 0);
    digitalWrite(DIN1R, 0);
    digitalWrite(DIN2R, 0);
    ledcSetup(0, freq, resolution); // PWM通道开启设置
    ledcSetup(1, freq, resolution); // PWM通道开启设置
    ledcSetup(2, freq, resolution); // PWM通道开启设置
    ledcSetup(3, freq, resolution); // PWM通道开启设置
}

void set_A_pwm(int speed)
{
    // 先绑定一下gpio和pwm通道
    if (speed >= 0)
    {
        ledcAttachPin(AIN1R, 0); 
        ledcDetachPin(AIN2R);
        digitalWrite(AIN2R, 0);
    }
    else
    {
        ledcAttachPin(AIN2R, 0); 
        ledcDetachPin(AIN1R);
        digitalWrite(AIN1R, 0);
    }

    int abs_speed = abs(speed);
    // 功能：限制PWM赋值
    if (abs_speed > Amplitude)
        abs_speed = Amplitude;
    ledcWrite(0, abs_speed / 2); 
}

void set_B_pwm(int speed)
{
    // 先绑定一下gpio和pwm通道
    if (speed >= 0)
    {
        ledcAttachPin(BIN1R, 1);
        ledcDetachPin(BIN2R);
        digitalWrite(BIN2R, 0);
    }
    else
    {
        ledcAttachPin(BIN2R, 1);
        ledcDetachPin(BIN1R);
        digitalWrite(BIN1R, 0);
    }

    int abs_speed = abs(speed);
    // 功能：限制PWM赋值
    if (abs_speed > Amplitude)
        abs_speed = Amplitude;
    ledcWrite(1, abs_speed / 2); 
}

void set_C_pwm(int speed)
{
    // 先绑定一下gpio和pwm通道
    if (speed >= 0)
    {
        ledcAttachPin(CIN1R, 2); 
        ledcDetachPin(CIN2R);
        digitalWrite(CIN2R, 0);
    }
    else
    {
        ledcAttachPin(CIN2R, 2); 
        ledcDetachPin(CIN1R);
        digitalWrite(CIN1R, 0);
    }

    int abs_speed = abs(speed);
    // 功能：限制PWM赋值
    if (abs_speed > Amplitude)
        abs_speed = Amplitude;
    ledcWrite(2, abs_speed / 2); 
}

void set_D_pwm(int speed)
{
    // 先绑定一下gpio和pwm通道
    if (speed >= 0)
    {
        ledcAttachPin(DIN1R, 3); 
        ledcDetachPin(DIN2R);
        digitalWrite(DIN2R, 0);
    }
    else
    {
        ledcAttachPin(DIN2R, 3); 
        ledcDetachPin(DIN1R);
        digitalWrite(DIN1R, 0);
    }

    int abs_speed = abs(speed);
    // 功能：限制PWM赋值
    if (abs_speed > Amplitude)
        abs_speed = Amplitude;
    ledcWrite(3, abs_speed / 2); 
}