#pragma once
#include "./class_list.h"

template <typename CL>
struct ClassListPopHead
{
public:
    using head = typename CL::THX;
    using type = typename CL::RST;
};

template <typename CL>
struct ClassListPopTail
{
    using tail = typename ClassListPopTail<typename CL::RST>::tail;
    using type = ClassList<typename CL::THX, typename ClassListPopTail<typename CL::RST>::type>;
};

template <typename T>
struct ClassListPopTail<ClassList<T>>
{
    using tail = T;
    using type = EmptyClassList;
};
