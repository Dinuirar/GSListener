#include "commands.h"
#include <fstream>
#include <sstream>

void ShowHelp(std::string helpfilename) {
    std::ifstream file;
    file.open(helpfilename);
    if( !file.is_open() ) { std::cout<< "Helpfile not found. Contact the developer.\n"; return;}
    std::string line;
    while(!file.eof()) {
        std::getline(file, line);
        std::cout << line << std::endl;
    }
    file.close();
    return;
}

void configure(std::string configfilename, std::string& ip, unsigned int& port) {
    std::ifstream file;
    std::string line;
    file.open(configfilename);
    if(file.is_open()) {
        std::getline(file, line);
        std::stringstream data (line);
        data >> ip >> port;
        file.close();
    }
    else {
        std::cout << "Error. Configuration file '" << configfilename <<
                     "'not found. This fill will be created\n"
                     "Enter experiment's ip and port (e. g. 192.168.1.1 34): \n";
        std::cin >> ip >> port;
        std::ofstream output;
        output.open(configfilename);
        output << ip << " " << port << std::endl;
    }

    std::cout << "LUSTRO-GS initialization and config succeded" << std::endl
         << "target ip: " << ip << std::endl
         << "target port: " << port << std::endl;
}

//void manconfig(std::string configfilename, std::string& ip, unsigned int& port) {
//    std::ofstream output;
//    output.open(configfilename);
//    output << ip << " " << port << std::endl;

//    std::cout << "LUSTRO-GS config succeded" << std::endl
//         << "target ip: " << ip << std::endl
//         << "target port: " << port << std::endl;
//}

void SetExperimentIp(std::string ip, std::string configfilename) {
    unsigned int port;
    std::string line, tmp;
    std::ifstream in (configfilename);
    std::getline(in, line);
    std::stringstream ss (line);
    ss >> tmp >> port;
    std::ofstream out(configfilename);
    out << ip << " " << port << std::endl;
    out.close();
    return;
}

void SetExperimentPort(unsigned int port, std::string configfilename) {
    std::string ip;
    std::string line, tmp;
    std::ifstream in (configfilename);
    std::getline(in, line);
    std::stringstream ss (line);
    ss >> ip >> tmp;
    std::ofstream out(configfilename);
    out << ip << " " << port << std::endl;
    out.close();
    return;
}
