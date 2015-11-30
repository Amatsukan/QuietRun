#include "sysTools.h"

int main(int argv, char* *args) {

    Utils::IO::Output::supress_stderr();

    if(argv > 1){

        std::string comm = Utils::IO::Input::getCommand(argv,args);

#ifdef ENABLE_VERBOSE
        Utils::IO::Output::printAndSetColor(Utils::IO::Output::BOLD);
        Utils::IO::Output::printAndSetColor(Utils::IO::Output::RED,"Command ~>", true);
        Utils::IO::Output::print_line(comm.c_str());
#endif

        FILE * Output = Utils::Exec::command(comm);


#ifdef ENABLE_STDOUT
        Utils::IO::Output::print_stdout(Output);
#endif
    }
#ifdef ENABLE_VERBOSE
    else
        Utils::IO::Output::putError("Falta de argumentos seu burro!!");
#endif

    return EXIT_FAILURE;
}
