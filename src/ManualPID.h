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
        double getOut() const {return lastOut;}
        void PIDWrite(float output) {lastOut = (double) output;}
        ManualPIDOut() {}

};

/*
* This class implements PID.
*/
class TwoEncoders : public PIDSource
{
    private:
        // Pointers to encoders owned by other classes
        Encoder *l;
        Encoder *r;
    protected:
        PIDSourceType m_pidSource = PIDSourceType::kDisplacement;
    public:
        //! Get our source.
        PIDSourceType GetPIDSourceType() const {return m_pidSource;}
        //! Set the specified sourcetype for both of our encoders.
        void SetPIDSourceType(PIDSourceType pidSource) {l->SetPIDSourceType(pidSource); r->SetPIDSourceType(pidSource);}
        //! Reset the values for both encoders.
        void Reset() {l->Reset(); r->Reset();}
        //! Return the average of both encoder values.
        double PIDGet() {return (l->PIDGet()+r->PIDGet())/2.0;}
        //! Initialize both of our pointers to actual Encoder classes.
        TwoEncoders(Encoder* left, Encoder* right) {l = left; r = right;}

};
