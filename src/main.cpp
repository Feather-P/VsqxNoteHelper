#include <iostream>
#include "vsq4.cpp"
#include "vsq4.h"
int main(int argc, char** argv)
{
    std::cout << "请输入文件地址： " << std::endl;
    VsqxNoteHelper::vsq4 workingvsqx;
    std::string Filepath;
    std::cin>>Filepath;
    workingvsqx.ReadVsqx(Filepath);
return 0;

}


void VsqxNoteHelper::vsq4::ReadVsqx(std::string filePath) {
    // 加载文件
    pugi::xml_document vsqx;
    pugi::xml_parse_result result = vsqx.load_file(filePath.c_str());
    std::cout << "加载结果: " << result.description() << std::endl;
    // 获取vsq4节点
    pugi::xml_node vsqxRoot = vsqx.child("vsq4");
    // 获取vVoiceTable节点
    pugi::xml_node voicetable = vsqxRoot.child("vVoiceTable");
    // 获取vVoice节点数量
    vsq4 vsq4;
    for (pugi::xml_node voicenode = voicetable.child("vVoice"); voicenode; voicenode = voicenode.next_sibling(
            "vVoice")) {
        vsq4::Vsq4record::VoiceTable::Voice tempvoice;
        tempvoice.bs = std::stoi(voicenode.child("bs").value());
        tempvoice.pc = std::stoi(voicenode.child("pc").value());
        tempvoice.name = voicenode.child("name").value();
        tempvoice.id = voicenode.child("id").value();
        tempvoice.parameter.bri = std::stoi(voicenode.child("vPrm").child("bri").value());
        tempvoice.parameter.bre = std::stoi(voicenode.child("vPrm").child("bre").value());
        tempvoice.parameter.cle = std::stoi(voicenode.child("vPrm").child("cle").value());
        tempvoice.parameter.gen = std::stoi(voicenode.child("vPrm").child("gen").value());
        vsq4.Vsq4record.voiceTable.voice.push_back(tempvoice);
    }
    pugi::xml_node mixernode =vsqxRoot.child("mixer");
    vsq4.Vsq4record.mixer.masterUnit.oDev=std::stoi(mixernode.child("oDev").value());
    vsq4.Vsq4record.mixer.masterUnit.returnLevel=std::stoi(mixernode.child("rLvl").value());
    vsq4.Vsq4record.mixer.masterUnit.volume=std::stoi(mixernode.child("vol").value());
    for (pugi::xml_node unitnode=mixernode.child("vsUnit");unitnode;unitnode=unitnode.next_sibling())
    {
        vsq4::Vsq4record::Mixer::Unit tempunit;
        tempunit.trackNunber=std::stoi(unitnode.child("tNo").value());
        tempunit.inputGain=std::stoi(unitnode.child("iGin").value());
        tempunit.sendLevel=std::stoi(unitnode.child("sLvl").value());
        tempunit.sendEnable=(bool)std::stoi(unitnode.child("sEnable").value());
        tempunit.mute=(bool)std::stoi(unitnode.child("m").value());
        tempunit.solo=(bool)std::stoi(unitnode.child("s").value());
        tempunit.pan=(short int)std::stoi(unitnode.child("pan").value());
        tempunit.volume=std::stoi(unitnode.child("vol").value());
        vsq4.Vsq4record.mixer.unit.push_back(tempunit);
    }
    std::cout<<"function run well"<<std::endl;

}