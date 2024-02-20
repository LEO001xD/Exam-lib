#include <leo_exam.h>
const uint8_t led1 = 2;
const uint8_t led2 = 3;
const uint8_t led3 = 4;
void setup()
{
    work3::dx100_setup(led1, led2, led3);
}
void loop()
{
    work3::dx100_loop(led1, led2, led3);
}
