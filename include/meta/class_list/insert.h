#pragma once
#include "./class_list.h"

template <typename To, typename From>
struct ClassListInsertTail;

template <typename ...NC, typename T>
struct ClassListInsertTail<ClassList<NC...>,T>
{
    using type = ClassList<NC...,T>;
};


template <typename... NC1, typename... NC2>
struct ClassListInsertTail<ClassList<NC1...>, ClassList<NC2...>>
{
    using type = ClassList<NC1..., NC2...>;
};

template <typename CL, typename T>
struct ClassListInsertHead;

template <typename ...NC, typename T>
struct ClassListInsertHead<ClassList<NC...>,T>
{
    using type = ClassList<T,NC...>;
};

template <typename... NC1, typename... NC2>
struct ClassListInsertHead<ClassList<NC1...>, ClassList<NC2...>>
{
    using type = ClassList<NC2..., NC1...>;
};
