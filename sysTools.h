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

            enum COLORS{
                RESET,
                RED,
                BLUE,
                BOLD
            };

            std::string printAndSetColor(COLORS color = RESET, const char* text = "", bool reset = false);
            std::string setColor(COLORS color = RESET, const char* text = "", bool reset = false);
            void putError(std::string);

            void print(const char *);
            void print_line(const char *);

            std::string getColor(COLORS);

        };
#endif
    };
};

#endif // _SYS_TOOLS_H_
