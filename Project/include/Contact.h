#ifndef CONTACT_H
#define CONTACT_H

#include "Vector2D.h"
#include <SDL2/SDL.h>

namespace diva
{/* Den här klassen tillhör Spelmotorn.
    Contact används för att skicka kollion information mellan kolliderade objekt.

*/

    struct Contact
    {
        SDL_Rect intersectRect;
        Vector2D getCenterPoints()
        {
            float xCenter = intersectRect.x + (intersectRect.w / 2.0f);
            float yCenter = intersectRect.y + (intersectRect.h / 2.0f);
            return Vector2D(xCenter, yCenter);
        }
    };
}
#endif
