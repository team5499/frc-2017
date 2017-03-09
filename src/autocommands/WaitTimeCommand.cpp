#include "WaitTimeCommand.h"

WaitTimeCommand::WaitTimeCommand(Reference* ref, Hardware* hardware, int t)
    :
    start(std::chrono::system_clock::now()),
    wait_time(t)
{
    r=ref;
    h=hardware;
}

void WaitTimeCommand::init()
{
    start = std::chrono::system_clock::now();
}

void WaitTimeCommand::step()
{
}

bool WaitTimeCommand::finished()
{
    std::chrono::time_point<std::chrono::system_clock> end = std::chrono::system_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()>=wait_time;
}