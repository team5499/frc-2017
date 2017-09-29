#include "Angle.h"

namespace team5499
{
    Angle::Angle()
    :
    angle(0),
    last_left_distance(0),
    last_right_distance(0)
    {
    }
    void Angle::handle(double leftValue, double rightValue)
    {
        double left_dist = (leftValue-last_left_distance);
        double right_dist = (rightValue-last_right_distance);
        double diff = left_dist-right_dist;
        double angle_delta = (180*diff)/(Reference::center_wheel_dist_inches*Reference::pi);

        angle+=angle_delta;

        last_left_distance = leftValue;
        last_right_distance = rightValue;
    }
    double Angle::getAngle()
    {
        return angle;
    }
    void Angle::resetLastDistances()
    {
        last_left_distance=0;
        last_right_distance=0;
    }
    void Angle::reset()
    {
        angle=0;
        resetLastDistances();
    }
}