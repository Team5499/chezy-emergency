#include "ManualPIDOut.h"
ManualPIDOut::ManualPIDOut()
    :
    lastOut(0)
{
}

void ManualPIDOut::PIDWrite(float output)
{
    lastOut = (double) output;
}
double ManualPIDOut::getOut()
{
    return lastOut;
}