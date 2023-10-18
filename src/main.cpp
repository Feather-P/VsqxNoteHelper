#include <iostream>
#include "vsq4.cpp"
#include "vsq4.h"

int main(int argc, char** argv)
{
    std::cout << "There will be something soon o((>w< ))o" << std::endl;
   VsqxNoteHelper::Vsq4 vsqx;
   VsqxNoteHelper::Vsq4::VoiceTable::Voice i;
    vsqx.voicetable.voice.push_back(i);
   vsqx.voicetable.voice[0].pc=10;
   std::cout<<vsqx.voicetable.voice[0].pc<<std::endl;
    return 0;
}