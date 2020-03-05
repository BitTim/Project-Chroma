#include "../lib/logger.hh"
#include <cstdarg>

std::ofstream Logger::logFile;
bool Logger::silent = false;

void Logger::init()
{
  std::string path = "log/log_";
  path.append(getTime("%02d-%02d-%04d_%02d-%02d-%02d", false));
  path.append(".log");

  logFile.open(path, std::ios_base::app);
}

std::string Logger::getTime(std::string format, bool timeOnly)
{
  char buf[16];
  time_t now  = time(0);
  tm *ltm = localtime(&now);

  if(timeOnly) sprintf(buf, format.c_str(), ltm->tm_hour, ltm->tm_min, ltm->tm_sec);
  else sprintf(buf, format.c_str(), ltm->tm_mday, ltm->tm_mon + 1, ltm->tm_year + 1900,
    ltm->tm_hour, ltm->tm_min, ltm->tm_sec);
  
  return buf;
}

void Logger::log(std::string tag, std::string format, ...)
{
  if(!logFile) init();

  va_list args;
  va_start (args, format);

  char buf[256];
  char buf2[192];
  std::string tmp;

  vsprintf(buf2, format.c_str(), args);
  sprintf(buf, "(%s): [%s] %s\n", getTime("%02d:%02d:%02d", true).c_str(), tag.c_str(), buf2);
  tmp = buf;

  logFile.write(tmp.c_str(), tmp.length());
  printf("%s", tmp.c_str());

  va_end(args);
}

void Logger::logSilent(std::string tag, std::string format, ...)
{
  va_list args;

  silent = true;
  log(tag, format, args);
  silent = false;
}

void Logger::terminate() { logFile.close(); }