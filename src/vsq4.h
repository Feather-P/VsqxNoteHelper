#ifndef _VSQ4_H_
#define _VSQ4_H_

#include<pugixml.hpp>
#include<vector>
#include<array>
#include<iostream>

namespace VsqxNoteHelper{
    class Vsq4{
    public:
        class VoiceTable{//vVoiceTable
        public:
            class Voice{//vVoice
            public:
                class Parameter{//vsqx为Prm
                public:
                    int bre;
                    int bri;
                    int cle;
                    int gen;
                    int ope;
                };
            int bs;
            int pc;//意ProgramContorl 需要和track部分配合获取歌手信息
            std::string id;
            std::string name;
            Parameter parameter;
            };
        std::vector<Voice> voice;
        };
        VoiceTable voicetable;

        class Mixer{
        public:
            class MasterUnit{//vsqx为masterUnit
            public:
                int oDev;//不清楚什么意思好像改了没用
                int returnlevel;//vsqx为rLvl
                int volume;//vsqx为vol
            };
            MasterUnit masterunit;

            class Unit{//vsqx中为vsUnit
                int tracknunber;//vsqx为tNO
                int inputgain;//vsqx为iGin
                int sendlevel;//vsqx为sLvl
                bool sendenable;//vsqx为sEnable
                bool mute;//vsqx为m
                bool solo;//vsqx为s
                short int pan;
                int volume;//vsqx为vol
            };
            std::vector<Unit> unit;

            class MonoUnit{//vsqx为monoUnit
            public:
                int inputgain;//vsqx为iGin
                int sendlevel;//vsqx为sLvl
                bool sendenable;//vsqx为sEnable
                bool mute;//vsqx为m
                bool solo;//vsqx为s
                short int pan;
                int volume;//vsqx为vol
            };
            MonoUnit monounit;

            class SteroUnit{//vsqx为stUnit
            public:
                int inputgain;//vsqx为iGin
                bool mute;//vsqx为m
                bool solo;//vsqx为s
                int volume;//vsqx为vol
            };
            SteroUnit sterounit;
        };
        Mixer mixer;
    private:
    };
}

#endif