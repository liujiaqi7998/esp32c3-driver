#include "header.h"

TimerHandle_t PID_timer;

Encoder AEnc(0, 1);
Encoder BEnc(12, 18);
// Encoder CEnc(19, 13);
// Encoder DEnc(8, 8);

float AInput = 0, AOutput = 0, ASetpoint = 0;
float BInput = 0, BOutput = 0, BSetpoint = 0;
float Kp = 0.5, Ki = 1.5, Kd = 0;
float OutputLimits_MAX = 177.0;
QuickPID APID(&AInput, &AOutput, &ASetpoint);
QuickPID BPID(&BInput, &BOutput, &BSetpoint);

/*********************************setup**********************************/
void setup()
{

  Serial.begin(115200);
  int_motors();


  ASetpoint = 30.0;
  APID.SetTunings(Kp, Ki, Kd);
  APID.SetOutputLimits(0, OutputLimits_MAX);
  APID.SetMode(APID.Control::automatic);

  BSetpoint = 40.0;
  BPID.SetTunings(Kp, Ki, Kd);
  BPID.SetOutputLimits(0, OutputLimits_MAX);
  BPID.SetMode(BPID.Control::automatic);

  Serial.println("Setup success");
}

/************************************loop************************************/
void loop()
{
  AInput = (double)AEnc.readAndReset();
  BInput = (double)-BEnc.readAndReset();
  APID.Compute();
  BPID.Compute();
   Serial.printf("%lf,%lf,%lf,%lf\n", AInput, BInput, AOutput, BOutput);
  // set_A_pwm(map(AOutput + 28, 0, OutputLimits_MAX, 0, Amplitude));
  set_B_pwm(map(BOutput, 0, OutputLimits_MAX, 0, Amplitude));
  delay(15);

}

