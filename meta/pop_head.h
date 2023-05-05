#pragma once
#include "meta/class_list.h"

template <typename CL>
class ClassListPopHead
{
public:
    using head = typename CL::THX;
    using type = typename CL::RST;
};
