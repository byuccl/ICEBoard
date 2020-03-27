#include "iceBoard.h"

void puzzle4()
{

    // this is under construction

        while (1)
    {
        uint32_t color = pack_color(50, 139, 168);

        for (int i = 0; i < 4; i++)
            leds.setPixelColor(1, color);
        leds.show();
    }
}