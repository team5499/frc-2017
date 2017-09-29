#include "Encoders.h"

namespace team5499
{
    Encoders::Encoders()
    :
    left_encoder(Reference::left_encoder_port1, Reference::left_encoder_port2, true),
    right_encoder(Reference::right_encoder_port1, Reference::right_encoder_port2)
    {
        left_encoder.SetDistancePerPulse(Reference::distance_per_pulse);
        right_encoder.SetDistancePerPulse(Reference::distance_per_pulse);
    }
    double Encoders::getLeftDistance()
    {
        return left_encoder.GetDistance();
    }
    double Encoders::getRightDistance()
    {
        return right_encoder.GetDistance();
    }
    void Encoders::reset()
    {
        left_encoder.Reset();
        right_encoder.Reset();
    }
}