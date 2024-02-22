#include <leo_exam.h>
const uint8_t potentio_work5 = 2;

LiquidCrystal lcd(12, 13, 16, 17, 18, 19);//Vss=gnd VDD=3.3v 12=RS 13=E D4=16 D5=17 D6=18 D7=19
void setup()
{
    work5::dx100_setup(potentio_work5, lcd);
}
void loop()
{
    work5::dx100_loop(potentio_work5, lcd);
}
