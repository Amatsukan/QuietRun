#include "sysTools.h"

int main(int argv, char* *args) {
    FILE *in;
    char buff[512];

    if(argv > 1){

        std::string comm = Utils::IO::Input::getCommand(argv,args);

#ifdef ENABLE_VERBOSE
        Utils::IO::Output::printAndSetColor(Utils::IO::Output::BOLD);
        Utils::IO::Output::printAndSetColor(Utils::IO::Output::RED,"Command ~>", true);
        Utils::IO::Output::print_line(comm);
#endif

        if(!(in = (popen(comm.c_str(), "r")))){
           perror("Error:");
           return EXIT_FAILURE;
        }


#ifdef ENABLE_STDOUT
            while(fgets(buff, sizeof(buff), in)!=NULL){
                Utils::IO::Output::print(buff);
            }
#endif
        if( in != NULL)
            pclose(in);
        return EXIT_SUCCESS;
    }

#ifdef ENABLE_VERBOSE
    Utils::IO::Output::putError("Falta de argumentos seu burro!!");
#endif

    return EXIT_FAILURE;
}
