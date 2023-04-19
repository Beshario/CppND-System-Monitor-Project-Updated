#include <string>

#include "format.h"

using std::string;

// INPUT: Long int measuring seconds
string Format::ElapsedTime(long seconds) { 
    long hours = seconds / 3600;
    long minutes = (seconds % 3600) / 60;
    long secs = (seconds % 3600) % 60;
    return std::to_string(hours) + ":" + std::to_string(minutes) + ":" + std::to_string(secs);
 }