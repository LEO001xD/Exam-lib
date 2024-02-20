#include <leo_exam.h>
const uint8_t potentio_work5 = 2;
LiquidCrystal lcd(12, 13, 16, 17, 18, 19);
void setup()
{
    work5::dx100_setup(potentio_work5, LiquidCrystal lcd);
}
void loop()
{
    work5::dx100_loop(potentio_work5, LiquidCrystal lcd);
}
