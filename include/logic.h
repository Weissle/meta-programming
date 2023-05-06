#pragma once
// Assuming all logic code is place in here.
#include "./meta/meta.h"
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
DEFINE_CLASS(LogicG);
DEFINE_CLASS(LogicH);

/*
A -> E
A -> C
B -> C
B -> D
C -> D
E -> D
F -> H
G
*/

using ANext = ClassList<LogicE, LogicC>;
using BNext = ClassList<LogicC, LogicD>;
using CNext = ClassList<LogicD>;
using DNext = ClassList<>;
using ENext = ClassList<LogicD>;
using FNext = ClassList<LogicH>;
using GNext = ClassList<>;
using HNext = ClassList<>;

using NodeA = Node<LogicA, ANext>;
using NodeB = Node<LogicB, BNext>;
using NodeC = Node<LogicC, CNext>;
using NodeD = Node<LogicD, DNext>;
using NodeE = Node<LogicE, ENext>;
using NodeF = Node<LogicF, FNext>;
using NodeG = Node<LogicG, GNext>;
using NodeH = Node<LogicH, HNext>;
using NodeList =
    ClassList<NodeA, NodeB, NodeC, NodeD, NodeE, NodeF, NodeG, NodeH>;
