// John Sipahioglu
// Kent State University - Computer Science 2 - Lab 2
// test_tp_equals.cpp

#include "time.hpp"
#include <cassert>

int main() {
    std::cout << "Begin unit test for: TimePart::operator==\n";

    {
        TimePart tp1 = {0,0,0};
        TimePart tp2 = {0,0,0};
        std::cout << "Testing " << tp1 << " == " << tp2 << std::endl;
        assert(tp1 == tp2);
        std::cout << "Pass\n";
    }
    
    {
        TimePart tp1 = {1,46,35};
        TimePart tp2 = {1,46,35};
        std::cout << "Testing " << tp1 << " == " << tp2 << std::endl;
        assert(tp1 == tp2);
        std::cout << "Pass\n";
    }

    {
        TimePart tp1 = {5,24,34};
        TimePart tp2 = {5,24,33};
        std::cout << "Testing " << tp1 << " != " << tp2 << std::endl;
        assert(!(tp1 == tp2));
        std::cout << "Pass\n";
    }
    std::cout << "Done testing TimePart::operator==\n";
    return 0;
}