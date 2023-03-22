#define cimg_use_png
#include "CImg.h"
using namespace cimg_library;

int main(int argc, char **argv) {

    // File Input
    const CImg<> bg("../imgs/pizza.png"); // RGB image
    const CImg<> fg1("../imgs/cheese.png"); // RGBA image.
    const CImg<> fg2("../imgs/pepperoni.png"); // RGBA image.

    // Cheese Separation
    const CImg<> fg_rgb1 = fg1.get_shared_channels(0,2); // Only RGB part of the foreground.
    const CImg<> fg_a1 = fg1.get_shared_channel(3); // Only Alpha part of the foreground.

    // Pepperoni Separation
    const CImg<> fg_rgb2 = fg2.get_shared_channels(0,2); // Only RGB part of the foreground.
    const CImg<> fg_a2 = fg2.get_shared_channel(3); // Only Alpha part of the foreground.

    // Create Obj
    CImg<> result(bg);

    // Layer
    result.draw_image(30,30,fg_rgb1,fg_a1,1,255);
    result.draw_image(150,30,fg_rgb2,fg_a2,1,255);

    // Display
    (result).display();
}