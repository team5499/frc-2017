#pragma once

#include "GenericCommand.h"

namespace team5499
{
    class GearmechCommand : public GenericCommand
    {
    public:
        enum Direction {UP, DOWN, NONE};
    private:
        Direction m_direction;
    public:
        GearmechCommand(double timeout, Direction direction)
        :
        GenericCommand(timeout),
        m_direction(direction)
        {
        }
        void start() override
        {
            GenericCommand::start();
        }
        void handle()
        {
            switch(m_direction)
            {
                case UP:
                    subsystems::gearmech.SetArm(0.5);
                    break;
                case DOWN:
                    subsystems::gearmech.SetArm(-0.4);
                    break;
                case NONE:
                    subsystems::gearmech.SetArm(0);
                    break;
                default:
                    break;
            }
        }
        bool isFinished() override
        {
            GenericCommand::isFinished();
        }
        void reset() override
        {
        }
    };
}