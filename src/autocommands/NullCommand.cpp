#include "NullCommand.h"

NullCommand::NullCommand(Reference* ref, Hardware* hardware)
{
    r=ref;
    h=hardware;
}

void NullCommand::init()
{
}

void NullCommand::step()
{
}

bool NullCommand::finished()
{
    return true;
}