#include "Climber.h"

namespace team5499 {

    Climber::Climber()
    :
    climber1(Reference::climber1_port),
    climber2(Reference::climber2_port)
    {
        
    }

    void Climber::climb(double num) {
        climber1.Set(num);
        climber2.Set(num);
    }

    void Climber::stop() {
        climb(0);
    }
}