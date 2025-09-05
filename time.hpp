// John Sipahioglu
// Kent State University - Computer Science 2 - Lab 2
// time.hpp

#ifndef TIME_H
#define TIME_H
#include <iostream>
#include <iomanip>

struct TimePart {
    int hour;
    int minute;
    int second;
    // compares this and rhs for equality
    bool operator==(const TimePart &rhs);
    // overloaded insertion operator to allow output of TimePart
    friend std::ostream& operator<<(std::ostream &out, const TimePart &tp); 
};

class Time {
public:
    // initializes time to 00:00:00
    Time();
    // initializes time to hour:00:00
    Time(int hour);
    // initializes time to hour:minute:00
    Time(int hour, int minute);
    // initializes time hour:minute:second
    Time(int hour, int minute, int second);
    // returns the current value of _time
    TimePart time() const { return _time; }
    // returns the current value of hour
    int hour() const { return _time.hour; }
    // returns the current value of minute
    int minute() const { return _time.minute; }
    // returns the current value of second
    int second() const { return _time.second; }
    // compares this and rhs for equality
    bool operator==(const Time& rhs);
    // increments the time by 1 second
    void increment();
    // decrements the time by 1 second
    void decrement();
    // adds the value of second to time
    void add(int seconds);
    // returns the difference (in seconds) between the *this and sub
    int diff(Time sub);
private:
    TimePart _time;
};

#endif