#pragma once
#include "./class_list.h"


template <typename CL, typename T>
struct ClassListHas;

template <typename CL, typename T>
struct ClassListHas
{
    static constexpr bool value = std::is_same_v<typename CL::THX, T> ||
                                  ClassListHas<typename CL::RST, T>::value;
};

template <typename T>
struct ClassListHas<EmptyClassList, T>
{
    static constexpr bool value = false;
};

template <typename CL, typename T>
inline constexpr bool ClassListHasV = ClassListHas<CL, T>::value;
