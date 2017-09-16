#include "PIDHandle.h"

namespace team5499
{
    PIDHandle::PIDHandle()
    :
    setPointLeft(0.0),
    setPointRight(0.0),
    left_side(Reference::left_encoder_port1, Reference::left_encoder_port2),
    right_side(Reference::right_encoder_port1, Reference::right_encoder_port2),
    drive_left(),
    drive_right()
    left_side_controller(Reference::kP, Reference::kI, Reference::kD, left_side, drive_left)
    {
        //left_side.SetDistancePerPulse(0.0490625); //4 * pi / 256 = <wheel circumference> / <pulses per rotation>
        //right_side.SetDistancePerPulse(0.0490625); //4 * pi / 256 = <wheel circumference> / <pulses per rotation>
    }
    
    void PIDHandle::resetEncoders()
    {
        left_side.Reset();
        right_side.Reset();
    }
    /*
    void PIDHandle::enable()
    {
        left_side.Reset();
        right_side.Reset();
        left_side_controller.Enable();
        right_side_controller.Enable();
    }
    double PIDHandle::getSetPoint()
    {
        return setPoint;
    }
    void PIDHandle::setLeftSetPoint(double set)
    {
        setPointLeft = set;
        left_side_controller.SetSetpoint(setPointLeft);
    }
    void PIDHandle::setRightSetPoint(double set)
    {
        setPointRight = set;
        right_side_controller.SetSetpoint(setPointRight);
    }
    void PIDHandle::step()
    {
        double left_value = drive_left.getOut();
        double right_value = drive_right.getOut();

        subsystems::drivetrain.Drive(left_value, right_value);
    }
    */
    int PIDHandle::getRawLeftValue()
    {
        return left_side.Get();
    }
    int PIDHandle::getRawRightValue()
    {
        return right_side.Get();
    }
}