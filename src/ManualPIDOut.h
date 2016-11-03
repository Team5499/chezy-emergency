#pragma once
#include <WPILib.h>

class ManualPIDOut : public PIDOutput
{
    private:
        double lastOut;
    public:
        double getOut();
        void PIDWrite(float output);
        ManualPIDOut();
        
};