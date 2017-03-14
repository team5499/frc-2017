/*
 * CowGyro.h
 *
 *  Created on: Jan 22, 2016
 *      Author: kchau
 */

#ifndef SRC_COWGYRO_H_
#define SRC_COWGYRO_H_

#include <thread>
#include <WPILib.h>

namespace team1538
{

  typedef enum
  {
    INVALID_DATA,
    VALID_DATA,
    SELF_TEST_DATA,
    RW_RESPONSE,
    STATUS_FLAG_ERROR
  } e_StatusFlag;

  typedef enum
  {
    PLL_FAILURE = 7,
    QUADRATURE_ERROR = 6,
    NONVOLATILE_MEMORY_FAULT = 5,
    RESET_INITIALIZE_FAILURE = 4,
    POWER_FAILURE = 3,
    CONTINUOUS_SELFTEST_FAILURE = 2,
    GENERATED_FAULTS = 1
  } e_ErrorFlag;

  class CowGyro
  {
  private:
    std::thread* m_Thread;
    SPI* m_Spi;

    std::vector <e_ErrorFlag> m_ALL_ERRORS = {
            PLL_FAILURE,
            QUADRATURE_ERROR,
            NONVOLATILE_MEMORY_FAULT,
            RESET_INITIALIZE_FAILURE,
            POWER_FAILURE,
            CONTINUOUS_SELFTEST_FAILURE,
            GENERATED_FAULTS
    };

    const int SENSOR_DATA_CMD = 0x20000000;
    const int CHK_GENERATE_FAULTS_BIT = 0x03;

    static const int32_t K_READING_RATE = 1000;
    static const int32_t K_ZEROING_SAMPLES = 5 * K_READING_RATE;
    static const int32_t K_STARTUP_SAMPLES = 2 * K_READING_RATE;

    int32_t m_RemainingStartupCycles = K_STARTUP_SAMPLES;

    double m_Angle = 0;
    double m_LastTime = 0;
    double m_VolatileRate = 0;
    double m_ZeroBias = 0;
    double m_ZeroRatesSamples[K_ZEROING_SAMPLES] = {0};

    bool m_Calibrating = false;
    bool m_HasEnoughZeroingSamples = false;
    bool m_IsZeroed = false;

    uint16_t m_CurrentIndex = 0;

  public:
    CowGyro();
    virtual ~CowGyro();
    float GetAngle();
    double GetRate();
    void ResetAngle();
    void BeginCalibration();
    void FinalizeCalibration();
  private:
    void Handle();
    int16_t DoRead(int8_t address);
    int32_t DoTransaction(int32_t command);
    std::vector <e_ErrorFlag> ExtractErrors(int32_t result);
    e_StatusFlag ExtractStatus(int32_t result);
    double ExtractAngleRate(int32_t result);
    int32_t GetReading();
    bool InitializeGyro();
    bool IsOddParity(int32_t word);
    int16_t ReadPartId();
    void Reset();
  };

} /* namespace CowLib */

#endif /* SRC_COWGYRO_H_ */
