#ifndef _SYS_TOOLS_H_
#define _SYS_TOOLS_H_

#include <unistd.h>
#include <signal.h>

#include <string>
#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>

namespace Utils{
    namespace Signals{

        void sigCatcher(int sinal);
        void setSignals();
    }

    namespace IO{
        namespace Input{
            std::string getCommand(int argv, char* *args);
        };
#ifdef ENABLE_VERBOSE
        namespace Output{

            const char * RESET= "\033[0m";
            const char * RED  = "\033[31m"; /* Red */
            const char * BLUE = "\033[34m"; /* Blue */
            const char * BOLD = "\033[1m";   /* Bold */

            std::string printAndSetColor(const char* color = RESET, const char* text = "", bool reset = false);
            std::string setColor(const char* color = RESET, const char* text = "", bool reset = false);
            void putError(std::string);

            void print(std::string s){
                std::cout<<s;
            }
            void print_line(std::string s){
                std::cout<<s<<std::endl;
            }
        };
#endif
    };
};

#endif // _SYS_TOOLS_H_
