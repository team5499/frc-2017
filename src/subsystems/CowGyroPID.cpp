#include "CowGyroPID.h"

namespace team5499
{
    CowGyroPID::CowGyroPID()
    :
    mxp_gyro()
    {
    }
    void CowGyroPID::init()
    {
        mxp_gyro.BeginCalibration();
    }
    void CowGyroPID::goLive()
    {
        mxp_gyro.FinalizeCalibration();
    }
    void CowGyroPID::step()
    {

    }
}