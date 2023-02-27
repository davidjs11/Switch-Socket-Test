#include "switchUtils.h"

void initNxlink()
{
    socketInitializeDefault();
    nxlinkStdio();
}

void closeNxLink()
{
    socketExit();
}
