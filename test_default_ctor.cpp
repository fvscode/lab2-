// John Sipahioglu
// Kent State University - Computer Science 2 - Lab 2
// test_default_ctor.cpp

#include "time.hpp"
#include <cassert>

int main() {
    std::cout << "Begin unit test for: Time::Time()\n";

    {
        Time t1;
        TimePart ref = {0,0,0};
        assert(t1.time() == ref);
    }

    std::cout << "Done testing Time::Time()\n";
    return 0;
}