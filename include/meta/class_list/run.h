#pragma once
#include "./class_list.h"
#include <string>

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
