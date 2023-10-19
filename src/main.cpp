#include <iostream>
#include "vsq4.cpp"

int main(int argc, char** argv)
{
    std::cout << "There will be something soon o((>w< ))o" << std::endl;
//There is some test code....
   VsqxNoteHelper::Vsq4 vsqx;
   VsqxNoteHelper::Vsq4::VoiceTable::Voice i;
    vsqx.voiceTable.voice.push_back(i);
   vsqx.voiceTable.voice[0].pc=10;
   std::cout<<vsqx.voiceTable.voice[0].pc<<std::endl;
return 0;
}
