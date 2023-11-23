#ifndef _VSQ4_H_
#define _VSQ4_H_
#include "pugixml.hpp"
#include<vector>
#include<array>
#include<iostream>

namespace VsqxNoteHelper {
    class Vsq4 {
    public:

        class Vsq4Record {
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
                    int pc;
                    std::string id;
                    std::string name;
                    Parameter parameter;
                };

                std::vector<Voice> voice;
            };

            VoiceTable voiceTable;

            class Mixer {
            public:
                class MasterUnit {//vsqx为masterUnit
                public:
                    int oDev;//不清楚什么意思好像改了没用
                    int returnLevel;//vsqx为rLvl
                    int volume;//vsqx为vol
                };

                MasterUnit masterUnit;

                class Unit {//vsqx中为vsUnit
                public:
                    int trackNunber;//vsqx为tNO
                    int inputGain;//vsqx为iGin
                    int sendLevel;//vsqx为sLvl
                    bool sendEnable;//vsqx为sEnable
                    bool mute;//vsqx为m
                    bool solo;//vsqx为s
                    short int pan;
                    int volume;//vsqx为vol
                };

                std::vector<Unit> unit;

                class MonoUnit {//vsqx为monoUnit
                public:
                    int inputGain;//vsqx为iGin
                    int sendLevel;//vsqx为sLvl
                    bool sendEnable;//vsqx为sEnable
                    bool mute;//vsqx为m
                    bool solo;//vsqx为s
                    short int pan;
                    int volume;//vsqx为vol
                };

                MonoUnit monoUnit;

                class SteroUnit {//vsqx为stUnit
                public:
                    int inputGain;//vsqx为iGin
                    bool mute;//vsqx为m
                    bool solo;//vsqx为s
                    int volume;//vsqx为vol
                };

                SteroUnit steroUnit;
            };

            Mixer mixer;

            class MasterTrack {//vsqx为masterTrack
            public:
                class TimeSig {//拍号类，同一vsqx可以有多个,vsqx为timeSig
                public:
                    short int startBar;//起始小结，vsqx为m
                    short int numerator;//拍子分子，vsqx为nu
                    short int denominator;//拍子分母，vsqx为de
                };

                class Tempo {//BPM类，同一vsqx可以有多个，vsqx为temple
                public:
                    int startTime;//vsqx为t
                    int bpm;//为bpm的100倍,vsqx为v
                };

                std::string name;//vsqx为seqName
                std::string comment;//vsqx为comment,意为注释
                short int resolution;//vsqx为resolution,意为分辨率，默认为480
                short int preMeasure;//vsqx为preMeasure,意为预备小节数
                std::vector<TimeSig> timeSig;//vsqx为timeSig
                std::vector<Tempo> tempo;//vsqx为temple
            };

            MasterTrack masterTrack;

            class Track {//vsqx为vsTrack
            public:
                class Part {//vsqx为vsPart
                public:
                    class StylePlug {//vsqx为sPlug
                    public:
                        std::string id;//vsqx为id
                        std::string name;//vsqx为name
                        std::string version;//vsqx为version
                    };

                    class PartStyle {//vsqx为pStyle
                    public:
                        int accent;//vsqx为 v id="accent"
                        int bendDep;//vsqx为 v id="bendDep"
                        int bendLen;//vsqx为 v id="bendLen"
                        int decay;//vsqx为 v id="decay"
                        int fallPort;//vsqx为 v id="fallPort"
                        int opening;//vsqx为 v id="opening"
                        int risePort;//vsqx为 v id="risePort"
                    };

                    class Singer {//vsqx为singer
                    public:
                        int t;//vsqx为t,不知道是干什么的 默认为0,怀疑为没用的上的StartTime
                        int bs;
                        int pc;
                    };

                    class CC {//vsqx为cc
                    public:
                        int time;//控制点时间
                        std::string id;//参数类型
                        int value;//参数的值
                    };

                    class Note {//vsqx为note
                    public:
                        class NoteStyle {//vsqx为nStyle
                        public:
                            int accent;//vsqx为 v id="accent"
                            int bendDep;//vsqx为 v id="bendDep"
                            int bendLen;//vsqx为 v id="bendLen"
                            int decay;//vsqx为 v id="decay"
                            int fallPort;//vsqx为 v id="fallPort"
                            int opening;//vsqx为 v id="opening"
                            int risePort;//vsqx为 v id="risePort"
                            int vibLen;//vsqx为 v id="vibLen"
                            int vibType;//vsqx为 v id="vibType"
                        };

                        int startTime;//vsqx为t
                        int duration;//vsqx为dur
                        short int pitch;//vsqx为n，需要音高→对应数值
                        short int vel;//vel参数，vsqx中为v
                        std::string lyric;//词，vsqx中为y
                        bool phonemeLock;//锁定音素，vsqx中为p的属性
                        std::string phoneme;//Xsampa音素，vsqx中为p
                        NoteStyle noteStyle;//vsqx中为nstyle

                    };

                    int startTime;//vsqx为t
                    int playTime;//vsqx为playTime
                    std::string name;//vsqx为seqName
                    std::string comment;//vsqx为comment,意为注释
                    std::vector<StylePlug> stylePlug;//vsqx为sPlug，可能有多个
                    PartStyle partStyle;//vsqx为pStyle
                    Singer singer;//vsqx为singer
                    std::vector<CC> cc;
                    std::vector<Note> note;
                    short int plane;//vsqx为plane 不知道干啥子的
                };//End of class Part

                int trackNumber;//vsqx为tNO
                std::string name;//vsqx为name
                std::string comment;//vsqx为comment
                std::vector<Part> part;//vsqx为vsPart
            };//End of class Track
            std::vector<Track> track;//vsqx为vsTrack
            class MonoTrack {

            };

            MonoTrack monoTrack;

            class SteroTrack {

            };

            SteroTrack steroTrack;

            class Aux {//vsqx末尾不知道干啥用的，名字是aux
            public:
                std::string id;
                std::string content;
            };

            Aux aux;
        };
        Vsq4Record vsq4Record; 

        void ReadVsqx(std::string filePath);
    };
}

#endif