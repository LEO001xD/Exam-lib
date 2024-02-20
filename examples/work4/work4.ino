#include <leo_exam.h>
const uint8_t servo_work4 = 34;
void setup()
{
    work4::dx100_setup(servo_work4);
}
void loop()
{
    work4::dx100_loop(servo_work4);
}
