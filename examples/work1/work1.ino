#include <leo_exam.h>
const uint8_t leds[] = {21, 19, 18, 5, 17};
void setup()
{
    work1::dx100_setup(leds, 5);
}
void loop()
{
    work1::dx100_loop(leds, 5);
}
