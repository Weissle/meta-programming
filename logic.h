#pragma once
#include <iostream>

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
    }

DEFINE_CLASS(LogicA);
DEFINE_CLASS(LogicB);
DEFINE_CLASS(LogicC);
DEFINE_CLASS(LogicD);
DEFINE_CLASS(LogicE);
DEFINE_CLASS(LogicF);
