#pragma once

#include <ctime>
#include <fstream>
#include <string>

class Logger
{
private:
  static std::ofstream logFile;
  static bool silent;
  
public:
  static void init();

  static std::string getTime(std::string format, bool timeOnly = false);
  static void log(std::string tag, std::string format, ...);
  static void logSilent(std::string tag, std::string format, ...);

  static void terminate();
};