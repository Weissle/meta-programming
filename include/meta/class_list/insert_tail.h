#pragma once
#include "meta/class_list.h"

template <typename CL, typename T>
class ClassListInsertTail;

template <typename CL, typename T>
class ClassListInsertTail
{

    using THX = typename CL::THX;
    using RST = typename CL::RST;

public:
    using type = ClassList<THX, typename ClassListInsertTail<RST, T>::type>;
};

template <typename T>
class ClassListInsertTail<EmptyClassList, T>
{
public:
    using type = ClassList<T>;
};
