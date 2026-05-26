#include "Ai.h"


Color Ai::GetUniqueColor()
{
    while (true)
    {
        Color c = {
            (unsigned char)GetRandomValue(50, 255),
            (unsigned char)GetRandomValue(50, 255),
            (unsigned char)GetRandomValue(50, 255),
            255
        };
        if (c.g > 200 && c.r < 100 && c.b < 100)
            continue;

        bool exists = false;

        for (Color u : usedColors)
        {
            if (u.r == c.r && u.g == c.g && u.b == c.b)
            {
                exists = true;
                break;
            }
        }

        if (!exists)
        {
            usedColors.push_back(c);
            return c;
        }
    }
}