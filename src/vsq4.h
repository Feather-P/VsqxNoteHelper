#ifndef _VSQ4_H_
#define _VSQ4_H_

#include<pugixml.hpp>
#include<vector>
#include<array>
#include<iostream>

namespace VsqxNoteHelper{
    
    enum VsqxPitch{
        C_2 = 0,   Cs_2 = 1,   D_2 = 2,   Eb_2 = 3,   E_2 = 4,   F_2 = 5,   Fs_2 = 6,   G_2 = 7,   Gs_2 = 8,   A_2 = 9,   Bb_2 = 10,  B_2 = 11,
        C_1 = 12,  Cs_1 = 13,  D_1 = 14,  Eb_1 = 15,  E_1 = 16,  F_1 = 17,  Fs_1 = 18,  G_1 = 19,  Gs_1 = 20,  A_1 = 21,  Bb_1 = 22,  B_1 = 23,
        C0  = 24,  Cs0  = 25,  D0  = 26,  Eb0  = 27,  E0  = 28,  F0  = 29,  Fs0  = 30,  G0  = 31,  Gs0  = 32,  A0  = 33,  Bb0  = 34,  B0  = 35,
        C1  = 36,  Cs1  = 37,  D1  = 38,  Eb1  = 39,  E1  = 40,  F1  = 41,  Fs1  = 42,  G1  = 43,  Gs1  = 44,  A1  = 45,  Bb1  = 46,  B1  = 47,
        C2  = 48,  Cs2  = 49,  D2  = 50,  Eb2  = 51,  E2  = 52,  F2  = 53,  Fs2  = 54,  G2  = 55,  Gs2  = 56,  A2  = 57,  Bb2  = 58,  B2  = 59,
        C3  = 60,  Cs3  = 61,  D3  = 62,  Eb3  = 63,  E3  = 64,  F3  = 65,  Fs3  = 66,  G3  = 67,  Gs3  = 68,  A3  = 69,  Bb3  = 70,  B3  = 71,
        C4  = 72,  Cs4  = 73,  D4  = 74,  Eb4  = 75,  E4  = 76,  F4  = 77,  Fs4  = 78,  G4  = 79,  Gs4  = 80,  A4  = 81,  Bb4  = 82,  B4  = 83,
        C5  = 84,  Cs5  = 85,  D5  = 86,  Eb5  = 87,  E5  = 88,  F5  = 89,  Fs5  = 90,  G5  = 91,  Gs5  = 92,  A5  = 93,  Bb5  = 94,  B5  = 95,
        C6  = 96,  Cs6  = 97,  D6  = 98,  Eb6  = 99,  E6  = 100, F6  = 101, Fs6  = 102, G6  = 103, Gs6  = 104, A6  = 105, Bb6  = 106, B6  = 107,
        C7  = 108, Cs7  = 109, D7  = 110, Eb7  = 111, E7  = 112, F7  = 113, Fs7  = 114, G7  = 115, Gs7  = 116, A7  = 117, Bb7  = 118, B7  = 119,
        C8  = 120, Cs8  = 121, D8  = 122, Eb8  = 123, E8  = 124, F8  = 125, Fs8  = 126, G8  = 127,
    };

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
        VoiceTable voiceTable;

        class Mixer{
        public:
            class MasterUnit{//vsqx为masterUnit
            public:
                int oDev;//不清楚什么意思好像改了没用
                int returnLevel;//vsqx为rLvl
                int volume;//vsqx为vol
            };
            MasterUnit masterUnit;

            class Unit{//vsqx中为vsUnit
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

            class MonoUnit{//vsqx为monoUnit
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

            class SteroUnit{//vsqx为stUnit
            public:
                int inputGain;//vsqx为iGin
                bool mute;//vsqx为m
                bool solo;//vsqx为s
                int volume;//vsqx为vol
            };
            SteroUnit steroUnit;
        };
        Mixer mixer;

        class MasterTrack{//vsqx为masterTrack
        public:
            class TimeSig{//拍号类，同一vsqx可以有多个,vsqx为timeSig
            public:
                short int startBar;//起始小结，vsqx为m
                short int numerator;//拍子分子，vsqx为nu
                short int denominator;//拍子分母，vsqx为de
            };
            class Tempo{//BPM类，同一vsqx可以有多个，vsqx为temple
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
        class Track{//vsqx为vsTrack
        public:
            class Part{//vsqx为vsPart
            public:
                class StylePlug{//vsqx为sPlug
                public:
                    std::string id;//vsqx为id
                    std::string name;//vsqx为name
                    std::string version;//vsqx为version
                };
                class PartStyle{//vsqx为pStyle
                public:
                    int accent;//vsqx为 v id="accent"
                    int bendDep;//vsqx为 v id="bendDep"
                    int bendLen;//vsqx为 v id="bendLen"
                    int decay;//vsqx为 v id="decay"
                    int fallPort;//vsqx为 v id="fallPort"
                    int opening;//vsqx为 v id="opening"
                    int risePort;//vsqx为 v id="risePort"
                };
                class Singer{//vsqx为singer
                public:
                    int t;//vsqx为t,不知道是干什么的 默认为0,怀疑为没用的上的StartTime
                    int bs;
                    int pc;
                };
                class CC{//vsqx为cc
                public:
                    int time;//控制点时间
                    std::string id;//参数类型
                    int value;//参数的值
                };
                class Note{//vsqx为note
                public:
                    class NoteStyle{//vsqx为nStyle
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
        class MonoTrack{

        };
        MonoTrack monoTrack;
        class SteroTrack{

        };
        SteroTrack steroTrack;
        class Aux{//vsqx末尾不知道干啥用的，名字是aux
            std::string id;
            std::string content;
        };
        Aux aux;
    private:
    };
}

#endif