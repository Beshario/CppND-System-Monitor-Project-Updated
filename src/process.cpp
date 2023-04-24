#include <unistd.h>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>

#include "process.h"

using std::string;
using std::to_string;
using std::vector;

Process::Process(int pid) : pid_(pid) {
    Process::CpuUtilization(pid);
};
// TODO: Return this process's ID
int Process::Pid() { return pid_; }

// Return this process's CPU utilization
// this function is called by the system every second
float Process::CpuUtilization() {
  return cpu_utilization_;
}

void Process::CpuUtilization(int pid) {
  prev_cpu_utilization_ = cpu_utilization_;

  long int process_active_time = LinuxParser::ActiveJiffies(pid) / sysconf(_SC_CLK_TCK);
  long int process_run_time = LinuxParser::UpTime(pid);
  // std::cout << "process_active_time: " << process_active_time << std::endl << " . process run time . " << process_run_time<< std::endl;
  cpu_utilization_ = (float) process_active_time /process_run_time - prev_cpu_utilization_;
}

// Return the command that generated this process
string Process::Command() { return LinuxParser::Command(pid_); }

// Return this process's memory utilization
string Process::Ram() { return LinuxParser::Ram(pid_); }

// Return the user (name) that generated this process
string Process::User() { return LinuxParser::User(pid_); }

// Return the age of this process (in seconds)
long int Process::UpTime() { return LinuxParser::UpTime(pid_); }

// Overload the "less than" comparison operator for Process objects based on utilization
bool Process::operator<(Process const& a) const { 
    return cpu_utilization_ > a.cpu_utilization_;
 }