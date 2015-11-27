#include "sysTools.h"

namespace Utils{
    namespace Signals{
        void sigCatcher(int sinal)
        {
            char info[30];

            if( sinal == SIGINT  ){
                sprintf(info, "%s, signal = %d", "SIGINT", (int)SIGINT );
            }
            else if( sinal == SIGTERM  ){
                sprintf(info, "%s, signal = %d","SIGTERM", (int)SIGTERM );
            }
            else{
                sprintf(info, "%s, signal = %d","UnKnOwN", (int)SIGTERM );
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

            std::string printAndSetColor(const char* color, const char* text, bool reset){
                std::cout<<color<<text;
                std::string clean = "";
                if(reset){
                    print(RESET);
                    clean += RESET;
                }

                return std::string(color)+std::string(text)+std::string(clean);
            }

            std::string setColor(const char* color, const char* text, bool reset){
                std::string clean = "";
                if(reset){
                    clean += RESET;
                }

                return std::string(color)+std::string(text)+std::string(clean);
            }

            void putError(std::string msg){
                fprintf(stderr, "%s%s:: %s", setColor(BOLD).c_str(), setColor(RED,"Error",true).c_str(), msg.c_str());
            }
        };
#endif

    };
};
