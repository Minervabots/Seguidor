#include "PrestoMotorController.h"
#include "../lib/MathHelper/MathHelper.h"
#include <Arduino.h>

PrestoMotorController::PrestoMotorController()
{

}

PrestoMotorController::PrestoMotorController(int leftPin1, int leftPin2, int rightPin1, int rightPin2,
  float maxVelocity, float inCurveVelocity,
  float wheelsRadius, float wheelsDistance, WheelEncoder *pWheelEncoder) :
  DifferentialDriveController(wheelsRadius, wheelsDistance, pWheelEncoder)
{
  setPins(leftPin1, leftPin2, rightPin1, rightPin2);
  setVelocities(maxVelocity, inCurveVelocity);
}

void PrestoMotorController::setPins(int leftPin1, int leftPin2, int rightPin1, int rightPin2)
{
  pinMode(leftPin1, OUTPUT);
  pinMode(leftPin2, OUTPUT);
  pinMode(rightPin1, OUTPUT);
  pinMode(rightPin2, OUTPUT);
}

void PrestoMotorController::setVelocities(float maxVelocity, float inCurveVelocity)
{
  _maxVelocity = maxVelocity;
  _inCurveVelocity = inCurveVelocity;
}

void PrestoMotorController::move(float linearVelocity, float angularVelocity)
{
  if(inCurve)
  {
    linearVelocity = clamp(linearVelocity, 0, _inCurveVelocity);
  }
  else
  {
    linearVelocity = clamp(linearVelocity, 0, _maxVelocity);
  }
  DifferentialDriveController::move(linearVelocity, angularVelocity);
  // TODO - PWM dos motores
}