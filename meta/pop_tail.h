#pragma once
#include "meta/class_list.h"

template <typename CL>
class ClassListPopTail
{
    using THX = typename CL::THX;
    using RST = typename CL::RST;
    using NewRst = ClassListPopTail<RST>;

public:
    using tail = typename NewRst::tail;
    using type = ClassList<THX, typename NewRst::type>;
};

template <typename T>
class ClassListPopTail<ClassList<T>>
{
public:
    using tail = T;
    using type = EmptyClassList;
};
