#include "processor.h"

// Return the aggregate CPU utilization
float Processor::Utilization() {
  std::string line, key;
  std::ifstream filestream(LinuxParser::kProcDirectory+LinuxParser::kStatFilename);
  if (filestream.is_open()) { 
    while (std::getline(filestream, line)) {
      std::replace(line.begin(), line.begin()+4, ' ', '_');
      std::istringstream linestream(line);
      while (linestream >> key) {
        if (key == "cpu_") {
          linestream >> user_ >> nice_ >> system_ >> idle_ >> iowait_ >> irq_ >> softirq_ >> steal_ >> guest_ >> guest_nice_;
        }
      }
    }
 }
  const float idle = idle_ + iowait_;
  const float nonIdle = user_ + nice_ + system_ + irq_ + softirq_ + steal_;
  const float total = idle + nonIdle;
  const float totald = total - prevTotal;
  const float idled = idle - prevIdle;
  prevTotal = total;
  prevIdle = idle;
   return (totald - idled)/totald;
}