#include "switchUtils.h"

void initNxlink()
{
    socketInitializeDefault();
    nxlinkStdio();
}

void closeNxlink()
{
    socketExit();
}
