#pragma once
#include <WPILib.h>

//! Class to manage the PIDOutput interface with an IterativeRobot.

/*
* This class essentially serves as a "collector", collecting the value that it is passed by the PIDController.
* It stores the value so that it may be accessed by other functions such as AutonomousPeriodic.
*/
class ManualPIDOut : public PIDOutput
{
    private:
        double lastOut = 0;
    public:
        double getOut() {return lastOut;}
        void PIDWrite(float output) {lastOut = (double) output;}
        ManualPIDOut() {}
        
};

/*
* This class implements PID.
*/
class TwoEncoders : public PIDSource
{
    private:
        Encoder *l;
        Encoder *r;
    protected:
        PIDSourceType m_pidSource = PIDSourceType::kDisplacement;
    public:
        PIDSourceType GetPIDSourceType() {return m_pidSource;}
        void SetPIDSourceType(PIDSourceType pidSource) {l->SetPIDSourceType(pidSource);r->SetPIDSourceType(pidSource);}
        double PIDGet() {return (l->PIDGet()+r->PIDGet())/2.0;}
        TwoEncoders(Encoder* left, Encoder* right) {l = left; r = right;}
        
};