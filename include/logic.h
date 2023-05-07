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

using ANext = ClassList<LogicC, LogicD>;
using BNext = ClassList<LogicA>;
using CNext = ClassList<LogicE, LogicF, LogicG>;
using DNext = ClassList<LogicH>;
using ENext = ClassList<LogicG>;
using FNext = ClassList<>;
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

template <typename CL>
class Run
{
public:
    static void run()
    {
        using T = typename CL::THX;
        T::run();
        Run<typename CL::RST> r;
        r.run();
    }
    static void run(std::string& s)
    {
        using T = typename CL::THX;
        T::run(s);
        Run<typename CL::RST> r;
        r.run(s);
    }
};

template <>
class Run<EmptyClassList>
{
public:
    static void run() {}
    static void run(std::string& s) {}
};
