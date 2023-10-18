#ifndef _VSQ4_H_
#define _VSQ4_H_

#include<pugixml.hpp>
#include<vector>
#include<array>
#include<iostream>

namespace VsqxNoteHelper {
    class Vsq4 {
    public:
        class VoiceTable {//vVoiceTable
        public:
            class Voice {//vVoice
            public:
                class Parameter {//vsqx为Prm
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

        class Mixer {
        public:
            class MasterUnit {//vsqx为masterUnit
            public:
                int oDev;//不清楚什么意思好像改了没用
                int returnlevel;//vsqx为rLvl
                int volume;//vsqx为vol
            };

            MasterUnit masterunit;

            class Unit {//vsqx中为vsUnit
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

            class MonoUnit {//vsqx为monoUnit
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

            class SteroUnit {//vsqx为stUnit
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

    class Track {
    public:
        int tNo;//不知道是啥
        std::string name;//歌姬名字;
        std::string comment;//注释
        class Part{
        public:
            int t;//应该是起始时间
            unsigned int playtime;//不知道
            class Pstyle{
                int accent;//参数1
                int bendDep;//参数2
                int bendLen;//参数3
                int decay;//参数4
                int Fallport;//参数5
                int opening;//也许是开口度？
                int risePort;//参数6
            };
            class singer{
                int pc;//歌姬的值
                int bs;//也许是每秒拍数？ beats per second=bs?
                int t;//应该是起始时间
            };
        };
    };
}

#endif