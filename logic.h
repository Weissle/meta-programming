#pragma once
// Assuming all logic code is place in here.
#include "meta/meta.h"
#include <iostream>
#include <string>

#define DEFINE_CLASS(CLASS_NAME)                                               \
    class CLASS_NAME                                                           \
    {                                                                          \
        inline static bool ran = false;                                        \
                                                                               \
    public:                                                                    \
        CLASS_NAME() = default;                                                \
        static void run()                                                      \
        {                                                                      \
            std::cout << #CLASS_NAME << " is running" << std::endl;            \
        }                                                                      \
        static void run(std::string& s)                                        \
        {                                                                      \
            s += #CLASS_NAME;                                                  \
            s += ";";                                                          \
        }                                                                      \
    }

DEFINE_CLASS(LogicA);
DEFINE_CLASS(LogicB);
DEFINE_CLASS(LogicC);
DEFINE_CLASS(LogicD);
DEFINE_CLASS(LogicE);
DEFINE_CLASS(LogicF);
