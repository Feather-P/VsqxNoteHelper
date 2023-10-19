#include"vsq4.h"
#include"pugixml.hpp"
#include<iostream>

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
    for (pugi::xml_node voicenode = voicetable.child("vVoice");
         voicenode;
         voicenode = voicenode.next_sibling("vVoice")
            ) {
        // 获取pc和name节点
        std::string i = voicenode.child("pc").value();
        VoiceTable::Voice::pcandname[i] = voicenode.child("name").value();
        // 获取id节点
        std::string id = voicenode.child("id").value();
        // 创建参数数组
        VoiceTable::Voice::Parameter prm[num2];
        // 获取vPrm节点
        pugi::xml_node vprmnode = voicenode.child("vPrm");
        // 获取参数数量
        int num = 0;
        // 获取参数
        prm[num].bre = std::stoi(vprmnode.child("bre").value());
        prm[num].bri = std::stoi(vprmnode.child("bri").value());
        prm[num].cle = std::stoi(vprmnode.child("cle").value());
        prm[num].gen = std::stoi(vprmnode.child("gen").value());
        prm[num].ope = std::stoi(vprmnode.child("ope").value());
        num++;
    }

    // 获取mixer节点
    pugi::xml_node mixernode = vsqxRoot.child("mixer");
    // 获取masterUnit节点
    pugi::xml_node matserunitnode = mixernode.child("masterUnit");
    // 获取oDev节点
    Vsq4::Mixer::MasterUnit::oDev = std::stoi(matserunitnode.child("oDev").value());
    // 获取returnLevel节点
    Vsq4::Mixer::MasterUnit::returnLevel = std::stoi(matserunitnode.child("rLvl").value());
    // 获取volume节点
    Vsq4::Mixer::MasterUnit::volume = std::stoi(matserunitnode.child("vol").value());
    // 获取vsUnit节点数量
    int num3;
    for (pugi::xml_node vsUnitnode = mixernode.child("vsUnit");
         vsUnitnode;
         vsUnitnode = vsUnitnode.next_sibling("vVoice")
            ) {
        num3 = num3 + 1;
    }
    // 遍历vsUnit节点
    for (pugi::xml_node vsUnitnode = mixernode.child("vsUnit");
         vsUnitnode;
         vsUnitnode = vsUnitnode.next_sibling("vVoice")
            ) {
        // 创建vsunit数组
        Vsq4::Mixer::Unit vsunit[num3];
        // 获取tNo节点
        int num4=0;
        vsunit[num4].trackNunber=std::stoi(vsUnitnode.child("tNo").value());
        // 获取iGin节点
        vsunit[num4].inputGain=std::stoi(vsUnitnode.child("iGin").value());
        // 获取sLvl节点
        vsunit[num4].sendLevel=std::stoi(vsUnitnode.child("sLvl").value());
        // 获取sEnable节点
        vsunit[num4].sendEnable=(bool)std::stoi(vsUnitnode.child("sEnable").value());
        // 获取m节点
        vsunit[num4].mute=(bool)std::stoi(vsUnitnode.child("m").value());
        // 获取s节点
        vsunit[num4].solo=(bool)std::stoi(vsUnitnode.child("s").value());
        // 获取pan节点
        vsunit[num4].pan=(short int)std::stoi(vsUnitnode.child("pan").value());
        // 获取vol节点
        vsunit[num4].volume=std::stoi(vsUnitnode.child("vol").value());
        num4++;
    }
}
