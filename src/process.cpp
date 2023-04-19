#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

#include "process.h"

using std::string;
using std::to_string;
using std::vector;

// TODO: Return this process's ID
int Process::Pid() { return pid_; }

// Return this process's CPU utilization
float Process::CpuUtilization () { 
    long active_time = LinuxParser::ActiveJiffies(pid_);
    long uptime = LinuxParser::UpTime();
    long elapsed_time = uptime - (LinuxParser::UpTime(pid_) / sysconf(_SC_CLK_TCK));
    cpu_utilization_ = static_cast<float>(active_time) / static_cast<float>(elapsed_time);
    return cpu_utilization_;
 }

// Return the command that generated this process
string Process::Command() { return LinuxParser::Command(pid_); }

// Return this process's memory utilization
string Process::Ram() { return LinuxParser::Ram(pid_); }

// Return the user (name) that generated this process
string Process::User() { return LinuxParser::User(pid_); }

// Return the age of this process (in seconds)
long int Process::UpTime() { return LinuxParser::UpTime(pid_); }

// TODO: Overload the "less than" comparison operator for Process objects
// REMOVE: [[maybe_unused]] once you define the function
bool Process::operator<(Process const& a) const { 
    return cpu_utilization_ < a.cpu_utilization_;
 }