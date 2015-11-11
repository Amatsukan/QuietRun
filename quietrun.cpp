#include <string>
#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <stdlib.h>

#define RESET       "\033[0m"
#define RED         "\033[31m"  /* Red */
#define BOLD        "\033[1m"   /* Bold */

std::string printAndSetColor(const char* color = RESET, const char* text = "", bool reset = false){
    std::cout<<color<<text;
    std::string clean = "";
    if(reset){
        std::cout<<RESET;
        clean += RESET;
    }

    return std::string(color)+std::string(text)+std::string(clean);
}

std::string setColor(const char* color = RESET, const char* text = "", bool reset = false){
    std::string clean = "";
    if(reset){
        clean += RESET;
    }

    return std::string(color)+std::string(text)+std::string(clean);
}

std::string getCommand(int argv, char* *args){
    std::string returns = "";
    for (int i = 1; i < argv; ++i)
    {
        returns+=args[i];
        returns+=" ";
    }

    return returns;
}

int main(int argv, char* *args) {
    FILE *in;
    char buff[512];

    if(argv > 1){

        std::string comm = getCommand(argv,args);

        printAndSetColor(BOLD);
        printAndSetColor(RED,"Command ~>", true);
        std::cout<<comm<<std::endl;
        if(!(in = popen(comm.c_str(), "r"))){
            perror("Error:");
            return EXIT_FAILURE;
        }
        while(fgets(buff, sizeof(buff), in)!=NULL){
            std::cout << buff;
        }
        pclose(in);
        return EXIT_SUCCESS;
    }
    fprintf(stderr, "%s%s:: Falta de argumentos seu burro!!", setColor(BOLD).c_str(), setColor(RED,"Error",true).c_str());
    return EXIT_FAILURE;
}
