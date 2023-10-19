#include"vsq4.h"
#include"pugixml.hpp"
#include<iostream>

void VsqxNoteHelper::Vsq4::ReadVsqx(std::string filePath) {
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
