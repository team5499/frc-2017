//==================================================
// Copyright (C) 2015 Team 1538 / The Holy Cows
//==================================================

#ifndef __COW_ALPHA_NUM_H__
#define __COW_ALPHA_NUM_H__

#include <stdint.h>
#include <WPILib.h>

#define HT16K33_BLINK_CMD 0x80
#define HT16K33_BLINK_DISPLAYON 0x01
#define HT16K33_BLINK_OFF 0
#define HT16K33_BLINK_2HZ 1
#define HT16K33_BLINK_1HZ 2
#define HT16K33_BLINK_HALFHZ 3
#define HT16K33_OSCILLATOR 0x21
#define HT16K33_CMD_BRIGHTNESS 0xE0
#define HT16K33_CMD_BUFFER_SIZE 17

namespace team1538
{
  class CowAlphaNum
  {
  private:
    static uint16_t m_Table[];
    I2C m_I2C;
    uint16_t* m_Banner = nullptr;
    uint32_t m_BannerLength = 0;
    uint32_t m_BannerPosition = 0;
    uint8_t m_DisplayBuffer[HT16K33_CMD_BUFFER_SIZE] = {0};

  public:
    CowAlphaNum();
    void BlinkRate(uint8_t b);
    void SetBrightness(uint8_t b);
    void WriteAscii(uint32_t n, uint8_t c, bool d);
    void WriteRaw(uint32_t n, uint16_t d);
    void Clear();
    void Display();
    void SetBanner(std::string);
    void SetBannerPosition(uint32_t);
    void DisplayBanner();
    void OscillatorOn();
  };
}

#endif /* __COW_ALPHA_NUM_H__ */
