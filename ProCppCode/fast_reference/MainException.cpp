#include <stdexcept>
#include <iostream>

void throwIf(bool inShouldThrow) throw (std::runtime_error)
{
    if (inShouldThrow) {
        throw std::runtime_error("Here's my exception.");
    }
}

int main(int argc, char** argv)
{
    try{
        throwIf(false);
        throwIf(true);
    } catch (const std::runtime_error& e) {
        std::cerr << "Caught exception:" << e.what() << std::endl;
    }
}