#include"vsq4.h"
#include"pugixml.hpp"
#include<iostream>

namespace VsqxNoteHelper{

short int VsqxPitch(std::string vsqxPitch){
    if (vsqxPitch == "C-2") return 0;
    else if (vsqxPitch == "C#-2") return 1;
    else if (vsqxPitch == "D-2") return 2;
    else if (vsqxPitch == "Eb-2") return 3;
    else if (vsqxPitch == "E-2") return 4;
    else if (vsqxPitch == "F-2") return 5;
    else if (vsqxPitch == "F#-2") return 6;
    else if (vsqxPitch == "G-2") return 7;
    else if (vsqxPitch == "G#-2") return 8;
    else if (vsqxPitch == "A-2") return 9;
    else if (vsqxPitch == "Bb-2") return 10;
    else if (vsqxPitch == "B-2") return 11;
    else if (vsqxPitch == "C-1") return 12;
    else if (vsqxPitch == "C#-1") return 13;
    else if (vsqxPitch == "D-1") return 14;
    else if (vsqxPitch == "Eb-1") return 15;
    else if (vsqxPitch == "E-1") return 16;
    else if (vsqxPitch == "F-1") return 17;
    else if (vsqxPitch == "F#-1") return 18;
    else if (vsqxPitch == "G-1") return 19;
    else if (vsqxPitch == "G#-1") return 20;
    else if (vsqxPitch == "A-1") return 21;
    else if (vsqxPitch == "Bb-1") return 22;
    else if (vsqxPitch == "B-1") return 23;
    else if (vsqxPitch == "C0") return 24;
    else if (vsqxPitch == "C#0") return 25;
    else if (vsqxPitch == "D0") return 26;
    else if (vsqxPitch == "Eb0") return 27;
    else if (vsqxPitch == "E0") return 28;
    else if (vsqxPitch == "F0") return 29;
    else if (vsqxPitch == "F#0") return 30;
    else if (vsqxPitch == "G0") return 31;
    else if (vsqxPitch == "G#0") return 32;
    else if (vsqxPitch == "A0") return 33;
    else if (vsqxPitch == "Bb0") return 34;
    else if (vsqxPitch == "B0") return 35;
}

    const std::array<std::string, 128> VsqxPitchName = {
        "C-2", "C#-2", "D-2", "Eb-2", "E-2", "F-2", "F#-2", "G-2", "G#-2", "A-2", "Bb-2", "B-2",
        "C-1", "C#-1", "D-1", "Eb-1", "E-1", "F-1", "F#-1", "G-1", "G#-1", "A-1", "Bb-1", "B-1",
        "C0",  "C#0",  "D0",  "Eb0",  "E0",  "F0",  "F#0",  "G0",  "G#0",  "A0",  "Bb0",  "B0",
        "C1",  "C#1",  "D1",  "Eb1",  "E1",  "F1",  "F#1",  "G1",  "G#1",  "A1",  "Bb1",  "B1",
        "C2",  "C#2",  "D2",  "Eb2",  "E2",  "F2",  "F#2",  "G2",  "G#2",  "A2",  "Bb2",  "B2",
        "C3",  "C#3",  "D3",  "Eb3",  "E3",  "F3",  "F#3",  "G3",  "G#3",  "A3",  "Bb3",  "B3",
        "C4",  "C#4",  "D4",  "Eb4",  "E4",  "F4",  "F#4",  "G4",  "G#4",  "A4",  "Bb4",  "B4",
        "C5",  "C#5",  "D5",  "Eb5",  "E5",  "F5",  "F#5",  "G5",  "G#5",  "A5",  "Bb5",  "B5",
        "C6",  "C#6",  "D6",  "Eb6",  "E6",  "F6",  "F#6",  "G6",  "G#6",  "A6",  "Bb6",  "B6",
        "C7",  "C#7",  "D7",  "Eb7",  "E7",  "F7",  "F#7",  "G7",  "G#7",  "A7",  "Bb7",  "B7",
        "C8",  "C#8",  "D8",  "Eb8",  "E8",  "F8",  "F#8",  "G8",
    };
}

void VsqxNoteHelper::Vsq4::GetFileToRam(std::string filePath) {
    // 加载文件
    pugi::xml_document vsqx;
    pugi::xml_parse_result result = vsqx.load_file(filePath.c_str());
    std::cout << "加载结果: " << result.description() << std::endl;
    // 获取vsq4节点
    pugi::xml_node vsqxRoot = vsqx.child("vsq4");
    // 获取vVoiceTable节点
    pugi::xml_node voicetable = vsqxRoot.child("vVoiceTable");
    // 获取vVoice节点数量
    int num2 = 0;
    for (pugi::xml_node voicenode = voicetable.child("vVoice");
         voicenode;
         voicenode = voicenode.next_sibling("vVoice")
            ) {
        num2 = num2 + 1;
    }
    // 遍历vVoice节点

    // 获取mixer节点
    pugi::xml_node mixernode = vsqxRoot.child("mixer");
    // 获取masterUnit节点
    pugi::xml_node matserunitnode = mixernode.child("masterUnit");
    // 获取oDev节点
//Vsq4::Mixer::MasterUnit::oDev = std::stoi(matserunitnode.child("oDev").value());
    // 获取returnLevel节点
//Vsq4::Mixer::MasterUnit::returnLevel = std::stoi(matserunitnode.child("rLvl").value());
    // 获取volume节点
//Vsq4::Mixer::MasterUnit::volume = std::stoi(matserunitnode.child("vol").value());
    // 获取vsUnit节点数量
    int num3;
    for (pugi::xml_node vsUnitnode = mixernode.child("vsUnit");
         vsUnitnode;
         vsUnitnode = vsUnitnode.next_sibling("vVoice")
            ) {
        num3 = num3 + 1;
    }
    // 遍历vsUnit节点

}
