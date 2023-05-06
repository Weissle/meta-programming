#pragma once
#include "meta/class_list.h"

template <typename CL, typename T>
class ClassListInsertHead
{
public:
    using type = ClassList<T, CL>;
};
