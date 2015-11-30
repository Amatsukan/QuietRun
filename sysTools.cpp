#include "sysTools.h"

#include <cstdio>

namespace Utils{
    namespace Exec{
        FILE* command(std::string comm){
            FILE * output;

            if(!(output = (popen(comm.c_str(), "r")))){
                perror("Error:");
                exit(1);
            }

            if( output != NULL){
                perror("Error: UnKnOwN ErRoR!!! 42");
                pclose(output);
            }

            return output;
        }
    };

    namespace Signals{
        void sigCatcher(int sinal)
        {
            char info[30];

            if( sinal == SIGINT  ){
                sprintf(info, "%s, signal = %d", "SIGINT", (int)SIGINT);
            }
            else if( sinal == SIGTERM  ){
                sprintf(info, "%s, signal = %d", "SIGTERM", (int)SIGTERM);
            }
            else{
                sprintf(info, "%s, signal = %d","UnKnOwN", (int)sinal);
            }
#ifdef ENABLE_VERBOSE
            IO::Output::print_line(info);
#endif
        }

        void setSignals()
        {
            for (int s=1; s<35; s++){
                signal(s, sigCatcher);
            }
        }
    };

    namespace IO{

        namespace Input{

            std::string getCommand(int argv, char* *args){
                std::string returns = "";
                for (int i = 1; i < argv; ++i)
                {
                    returns+=args[i];
                    returns+=" ";
                }

                return returns+'&';
            }

        };

#ifdef ENABLE_VERBOSE
        namespace Output{

            std::string printAndSetColor(COLORS color, const char* text, bool reset){
                print(getColor(color).c_str());
                print(text);
                std::string clean = "";
                if(reset){
                    print(getColor(RESET).c_str());
                    clean += getColor(RESET).c_str();
                }

                return std::string(getColor(color).c_str())+std::string(text)+std::string(clean);
            }

            std::string setColor(COLORS color, const char* text, bool reset){
                std::string clean = "";
                if(reset){
                    clean += getColor(RESET).c_str();
                }

                return std::string(getColor(color))+std::string(text)+std::string(clean);
            }

            void putError(std::string msg){
                fprintf(stderr, "%s%s:: %s", setColor(BOLD).c_str(), setColor(RED,"Error",true).c_str(), msg.c_str());
            }

            void print_stdout(FILE * out){
                char buff[512];

                while(fgets(buff, sizeof(buff), out)!=NULL){
                    Utils::IO::Output::print(buff);
                }

                //delete(buff);
            }

            void print(const char * s){
                std::cout<<s;
            }
            void print_line(const char * s){
                std::cout<<s<<std::endl;
            }

            void supress_stderr(){
                freopen("/dev/null", "w", stderr);
            }

            // void emit_stderr(){
            //     if(buffer != NULL){

            //     }
            // }

            std::string getColor(COLORS c){
                switch(c){
                    case RESET:
                        return "\033[0m";
                    case RED:
                        return "\033[31m"; /* Red */
                    case BLUE:
                        return "\033[34m"; /* Blue */
                    case BOLD:
                        return "\033[1m";   /* Bold */
                }
            }
        };
#endif

    };
};
