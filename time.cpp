// John Sipahioglu
// Kent State University - Computer Science 2 - Lab 2
// time.cpp
// write the implementation of class Time here

#include "time.hpp"


bool TimePart::operator==(const TimePart &rhs) {
    return hour == rhs.hour && minute == rhs.minute && second == rhs.second;
}

std::ostream& operator<<(std::ostream &out, const TimePart &tp) {
    out << std::setfill('0') << std::setw(2) << tp.hour << ":";
    out << std::setfill('0') << std::setw(2) << tp.minute << ":";
    out << std::setfill('0') << std::setw(2) << tp.second;
    return out;
}

Time::Time() {
    _time.hour = 0;
    _time.minute = 0;
    _time.second = 0;
}
time::time(int hour){
    if (hour < 0){
        _time.hour=0;
    } else {
        _time.hour = hour % 24;
    }
    _time.minute= 0;
    _time.second = 0;
}
Time::Time(int hour, int minute) {
    if (minute < 0) minute = 0;

    int total_minutes = minute; // what if i delete total.minutes
    _time.hour = (hour + total_minutes / 60) % 24;
    _time.minute = total_minutes % 60;
    _time.second = 0;
}
Time::Time(int hour, int minute, int second) {
    if (second < 0) second = 0;

    int total_seconds = second + minute * 60 + hour * 3600;
    total_seconds %= 86400;

    _time.hour = total_seconds / 3600;
    total_seconds %= 3600;
    _time.minute = total_seconds / 60;
    _time.second = total_seconds % 60;
}
bool Time::operator==(const Time& rhs) {
    return _time == rhs._time;
}
void Time::increment() {
    add(1);
}
void Time::decrement() {
    add(-1);
}
void Time::add(int seconds) {
    int total_seconds = _time.hour * 3600 + _time.minute * 60 + _time.second + seconds;

    while (total_seconds < 0) {
        total_seconds += 86400;
    }

    total_seconds %= 86400;

    _time.hour = total_seconds / 3600;
    total_seconds %= 3600;
    _time.minute = total_seconds / 60;
    _time.second = total_seconds % 60;
}
int Time::diff(Time sub) {
    int this_seconds = _time.hour * 3600 + _time.minute * 60 + _time.second;
    int sub_seconds = sub._time.hour * 3600 + sub._time.minute * 60 + sub._time.second;
    return this_seconds - sub_seconds;
}