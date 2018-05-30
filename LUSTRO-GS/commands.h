#ifndef COMMANDS_H
#define COMMANDS_H

#include <iostream>

void ShowHelp(std::string helpfilename);
void SetExperimentIp(std::string ip, std::string configfilename);
void SetExperimentPort(unsigned int, std::string configfilename);
void configure(std::string configfile, std::string& ip, unsigned int& port);
//void manconfig(std::string configfile, std::string& ip, unsigned int& port);

#endif // COMMANDS_H
