#include "CustomFunctions.h"

void CustomFunctions::setColor(int textColor, int bgColor) {
    std::cout << "\033[" << textColor << ";" << bgColor << "m";
}