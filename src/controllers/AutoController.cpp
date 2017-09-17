#include "AutoController.h"

namespace team5499
{
    AutoController::AutoController()
    :
    step_now(0),
    time_now(0),
    routine(1)
    {
        subsystems::pid.left_encoder.SetReverseDirection(true);
        subsystems::pid.left_setpoint+=75;
        subsystems::pid.right_setpoint+=75;
    }
    void AutoController::Step()
    {
            if(step_now == 0) {
                double left_error = (subsystems::pid.left_setpoint-subsystems::pid.left_encoder.GetDistance());
                double right_error = (subsystems::pid.right_setpoint-subsystems::pid.right_encoder.GetDistance());
                if(left_error < 4 && right_error < 4)
                {
                    step_now=1;
                    time_now = Timer::GetFPGATimestamp();
                }
                double left_value_drive = (-left_error*0.0225)+((right_error-left_error)*0.002);
                double right_value_drive = (-right_error*0.0225)+((left_error-right_error)*0.002);
                if(left_value_drive < -0.4)
                    left_value_drive = -0.4;
                else if(left_value_drive > 0.4)
                    left_value_drive = 0.4;

                if(right_value_drive < -0.4)
                    right_value_drive = -0.4;
                else if(right_value_drive > 0.4)
                    right_value_drive = 0.4;
                std::cout << left_error << ":" << right_error << std::endl;
                subsystems::drivetrain.Drive(left_value_drive, right_value_drive);
            }
            else if(step_now == 1)
            {
                double left_error = (subsystems::pid.left_setpoint-subsystems::pid.left_encoder.GetDistance());
                double right_error = (subsystems::pid.right_setpoint-subsystems::pid.right_encoder.GetDistance());

                double left_value_drive = (-left_error*0.0225)+((right_error-left_error)*0.002);
                double right_value_drive = (-right_error*0.0225)+((left_error-right_error)*0.002);
                if(left_value_drive < -0.4)
                    left_value_drive = -0.4;
                else if(left_value_drive > 0.4)
                    left_value_drive = 0.4;

                if(right_value_drive < -0.4)
                    right_value_drive = -0.4;
                else if(right_value_drive > 0.4)
                    right_value_drive = 0.4;
                std::cout << left_error << ":" << right_error << std::endl;
                subsystems::drivetrain.Drive(left_value_drive, right_value_drive);
                if(Timer::GetFPGATimestamp()-time_now>1)
                {
                    step_now=2;
                    time_now = Timer::GetFPGATimestamp();
                }
            }
            else if(step_now == 2)
            {
                double left_error = (subsystems::pid.left_setpoint-subsystems::pid.left_encoder.GetDistance());
                double right_error = (subsystems::pid.right_setpoint-subsystems::pid.right_encoder.GetDistance());

                double left_value_drive = (-left_error*0.0225)+((right_error-left_error)*0.002);
                double right_value_drive = (-right_error*0.0225)+((left_error-right_error)*0.002);
                if(left_value_drive < -0.4)
                    left_value_drive = -0.4;
                else if(left_value_drive > 0.4)
                    left_value_drive = 0.4;

                if(right_value_drive < -0.4)
                    right_value_drive = -0.4;
                else if(right_value_drive > 0.4)
                    right_value_drive = 0.4;
                std::cout << left_error << ":" << right_error << std::endl;
                subsystems::drivetrain.Drive(left_value_drive, right_value_drive);
                
                subsystems::gearmech.SetArm(-0.75);
                if((Timer::GetFPGATimestamp()-time_now)>1)
                {
                    time_now=Timer::GetFPGATimestamp();
                    step_now=3;
                }
            }
            else if(step_now == 3)
            {

                subsystems::gearmech.SetArm(0);
                subsystems::drivetrain.Drive(0.2, 0.2);
                if((Timer::GetFPGATimestamp()-time_now)>0.75)
                {
                    step_now=4;
                }
            }
            else
                subsystems::drivetrain.Drive(0, 0);
    }
}