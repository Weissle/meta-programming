#pragma once
#include "meta/class_list.h"

template <typename CL, typename T>
class ClassListHas;

template <typename CL, typename T>
class ClassListHas
{
public:
    static constexpr bool value = std::is_same_v<typename CL::THX, T> ||
                                  ClassListHas<typename CL::RST, T>::value;
};

template <typename T>
class ClassListHas<EmptyClassList, T>
{
public:
    static constexpr bool value = false;
};

template <typename CL, typename T>
inline constexpr bool ClassListHasV = ClassListHas<CL, T>::value;
