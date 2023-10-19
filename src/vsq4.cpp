#include"vsq4.h"
#include"pugixml.hpp"
#include<iostream>

void VsqxNoteHelper::Vsq4::GetFileToRam(std::string filePath) {
    pugi::xml_document vsqx;
    pugi::xml_parse_result result = vsqx.load_file(filePath.c_str());
    std::cout << "加载结果: " << result.description() << std::endl;
    pugi::xml_node vsqxRoot = vsqx.child("vsq4");
    pugi::xml_node voicetable = vsqxRoot.child("vVoiceTable");
    int num2 = 0;
    for (pugi::xml_node voicenode = voicetable.child("vVoice");
         voicenode;
         voicenode = voicenode.next_sibling("vVoice")
            ) {
        num2 = num2 + 1;
    }
    for (pugi::xml_node voicenode = voicetable.child("vVoice");
         voicenode;
         voicenode = voicenode.next_sibling("vVoice")
            ) {
        std::string i = voicenode.child("pc").value();
        VoiceTable::Voice::pcandname[i] = voicenode.child("name").value();
        std::string id = voicenode.child("id").value();
        VoiceTable::Voice::Parameter prm[num2];
        pugi::xml_node vprmnode = voicenode.child("vPrm");
        int num = 0;
        prm[num].bre = std::stoi(vprmnode.child("bre").value());
        prm[num].bri = std::stoi(vprmnode.child("bri").value());
        prm[num].cle = std::stoi(vprmnode.child("cle").value());
        prm[num].gen = std::stoi(vprmnode.child("gen").value());
        prm[num].ope = std::stoi(vprmnode.child("ope").value());
        num++;
    }

    pugi::xml_node mixernode = vsqxRoot.child("mixer");
    pugi::xml_node matserunitnode = mixernode.child("masterUnit");
    Vsq4::Mixer::MasterUnit::oDev = std::stoi(matserunitnode.child("oDev").value());
    Vsq4::Mixer::MasterUnit::returnLevel = std::stoi(matserunitnode.child("rLvl").value());
    Vsq4::Mixer::MasterUnit::volume = std::stoi(matserunitnode.child("vol").value());
    int num3;
    for (pugi::xml_node vsUnitnode = mixernode.child("vsUnit");
         vsUnitnode;
         vsUnitnode = vsUnitnode.next_sibling("vVoice")
            ) {
        num3 = num3 + 1;
    }
    for (pugi::xml_node vsUnitnode = mixernode.child("vsUnit");
         vsUnitnode;
         vsUnitnode = vsUnitnode.next_sibling("vVoice")
            ) {
        Vsq4::Mixer::Unit vsunit[num3];
        int num4=0;
        vsunit[num4].trackNunber=std::stoi(vsUnitnode.child("tNo").value());
        vsunit[num4].inputGain=std::stoi(vsUnitnode.child("iGin").value());
        vsunit[num4].sendLevel=std::stoi(vsUnitnode.child("sLvl").value());
        vsunit[num4].sendEnable=(bool)std::stoi(vsUnitnode.child("sEnable").value());
        vsunit[num4].mute=(bool)std::stoi(vsUnitnode.child("m").value());
        vsunit[num4].solo=(bool)std::stoi(vsUnitnode.child("s").value());
        vsunit[num4].pan=(short int)std::stoi(vsUnitnode.child("pan").value());
        vsunit[num4].volume=std::stoi(vsUnitnode.child("vol").value());
        num4++;
    }
}
