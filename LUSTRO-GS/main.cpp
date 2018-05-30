#include "commands.h"
#include "communications.h"

#include <QCoreApplication>
#include <sstream>
#include <iostream>

using namespace std;
int main() {
    string configfilename = "config.cfg"; // configuration file to store experiment's initial ip and port

    string input_str, command = "configure";
    string ip;
    unsigned char speed1, speed2;
    unsigned int port;
    unsigned char arg1, arg2;
    unsigned short arg_nth;

    unsigned long int timeout; // time to wait for the transmission from the gondola

    configure(configfilename, ip, port);

    // initialize communication - handshake with gondola

    stringstream input;
    do {
        input.clear();
        getline(cin, input_str);
        input.str(input_str);
        input >> command;

        if (command == "set-speed") {
            input >> arg1 >> arg2;
            if ( (arg1 == 1 || arg1 == 2) && (arg2 > 0 && arg2 < 256) ) {
                // call for SetSpeed(arg1, arg2);
                if (arg1 == 1) speed1 = arg2;
                else if (arg2 == 2) speed2 = arg2;
            }
            else if ( !(arg1 == 1 || arg1 == 2) ) cout << "First argument must be 1 or 2! Enter 'help' for more info\n";
            else if (0) cout << "Second argument must be from 0-255!\n";
        }
        else if (command == "mknlog") {
            //
        }
        else if (command == "send-nth") {
            input >> arg1 >> arg_nth;
            //
        }
        else if (command == "stopm") {
            //
        }
        else if (command == "get-uc-temp") {
            //
        }
        else if (command == "get-htp") {
            //
        }
        else if (command == "get-photo") {
            //
        }
        else if (command == "get-speed") {
            //
        }
        else if (command == "get-speed-fast") {
            cout << "speed motor1: " << speed1 << endl
                 << "speed motor2: " << speed2 << endl;
        }
        else if(command == "set-ip") {
            input >> ip;
            SetExperimentIp(ip, configfilename);
        }
        else if (command == "set-port") {
            input >> port;
            SetExperimentPort(port, configfilename);
        }
        else if (command == "set-address") {
            input >> ip >> port;
            SetExperimentIp(ip, configfilename);
            SetExperimentPort(port, configfilename);
        }
        else if (command == "show-address") {
            cout << "ip: " << ip << endl
                 << "port: " << port << endl;
        }
        else if (command == "help") { ShowHelp("help.info"); }
        else if (command == "configure") {  }
        else {
            cout << "Unknown command. Please type 'help' for the list of available commands \nor 'exit' to close the program." << endl;
        }
    }
    while(input.str() != "exit");
    return 0;
}
