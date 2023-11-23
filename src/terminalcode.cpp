#include "teminalcode.h"
namespace VsqxNoteHelper{
    void SetTerminalUtf8(){
        system("chcp 65001");//以65001运行终端以解UTF-8
        std::cout << "Set Terminal to CodePage 65001 for UTF-8 Successfully." << std::endl;
    }
}