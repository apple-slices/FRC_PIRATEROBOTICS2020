// Jason Cheng
#include "PIDDriver.h"

PIDDriver::PIDDriver()
{
    // Explicitly sets encoder, so hopefully it detects it
    flController.SetFeedbackDevice(flEncoder);
    frController.SetFeedbackDevice(frEncoder);
    blController.SetFeedbackDevice(blEncoder);
    brController.SetFeedbackDevice(brEncoder);

    flController.SetSmartMotionAllowedClosedLoopError(tolerance);
    frController.SetSmartMotionAllowedClosedLoopError(tolerance);
    blController.SetSmartMotionAllowedClosedLoopError(tolerance);
    brController.SetSmartMotionAllowedClosedLoopError(tolerance);

    read();
}

void PIDDriver::read()
{
    kp = frc::SmartDashboard::GetNumber("P Gain", kp);
    ki = frc::SmartDashboard::GetNumber("I Gain", ki);
    kd = frc::SmartDashboard::GetNumber("D Gain", kd);
    iz = frc::SmartDashboard::GetNumber("I Zone", iz);
    ff = frc::SmartDashboard::GetNumber("Feed Forward", ff);
    max = frc::SmartDashboard::GetNumber("Max Output", max);
    min = frc::SmartDashboard::GetNumber("Min Output", min);

    flController.SetP(kp);
    flController.SetI(ki);
    flController.SetD(kd);
    flController.SetIZone(iz);
    flController.SetFF(ff);
    flController.SetOutputRange(min, max);

    frController.SetP(kp);
    frController.SetI(ki);
    frController.SetD(kd);
    frController.SetIZone(iz);
    frController.SetFF(ff);
    frController.SetOutputRange(min, max);

    blController.SetP(kp);
    blController.SetI(ki);
    blController.SetD(kd);
    blController.SetIZone(iz);
    blController.SetFF(ff);
    blController.SetOutputRange(min, max);

    brController.SetP(kp);
    brController.SetI(ki);
    brController.SetD(kd);
    brController.SetIZone(iz);
    brController.SetFF(ff);
    brController.SetOutputRange(min, max);
}

void PIDDriver::drive(double distance)
{
    flController.SetReference(distance, rev::ControlType::kPosition);
    frController.SetReference(distance, rev::ControlType::kPosition);
    blController.SetReference(distance, rev::ControlType::kPosition);
    brController.SetReference(distance, rev::ControlType::kPosition);
}

void PIDDriver::stop()
{
    PIDDriver::drive(flEncoder.GetPosition());
}

void PIDDriver::display()
{
    frc::SmartDashboard::PutNumber("P Gain", kp);
    frc::SmartDashboard::PutNumber("I Gain", ki);
    frc::SmartDashboard::PutNumber("D Gain", kd);
    frc::SmartDashboard::PutNumber("I Zone", iz);
    frc::SmartDashboard::PutNumber("Feed Forward", ff);
    frc::SmartDashboard::PutNumber("Max Output", max);
    frc::SmartDashboard::PutNumber("Min Output", min);
}