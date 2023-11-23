#include <iostream>
#include "vsq4.h"
#include "teminalcode.h"


int main(int argc, char** argv){
    VsqxNoteHelper::SetTerminalUtf8();
    std::cout << "请输入文件地址： " << std::endl;
    VsqxNoteHelper::Vsq4 Workvsqx;
    std::string Filepath;
    std::cin>>Filepath;
    Workvsqx.ReadVsqx(Filepath);
return 0;
}