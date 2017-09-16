#pragma once

namespace team5499
{
    class DoNothingCommand : public GenericAutoCommand
    {
    public:
        void Handle() override;
        void Init() override;
        bool isFinished() override;
    };
}