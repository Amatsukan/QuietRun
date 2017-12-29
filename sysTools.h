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
    namespace Exec{
        FILE* command(std::string);
    }

    namespace Signals{

        void sigCatcher(int sinal);
        void setSignals();
    }

    namespace IO{
        namespace Input{
            std::string getCommand(int argv, char* *args);
        };
        namespace Output{
#ifdef ENABLE_VERBOSE

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

            void print_stdout(FILE *);

            void emit_stderr();

            std::string getColor(COLORS);

#endif
            void supress_stderr();
        };
    };
};

#endif // _SYS_TOOLS_H_
