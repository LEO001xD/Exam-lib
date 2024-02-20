#include <leo_exam.h>
const uint8_t ldr = 2;
const uint8_t leds[] = {2, 0, 4};
void setup()
{
    work2::dx100_setup(ldr, leds, 3);
}
void loop()
{
    work2::dx100_loop(ldr, leds, 3);
}