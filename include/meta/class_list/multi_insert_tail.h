#pragma once
#include "./class_list.h"
#include "./insert_tail.h"

template <typename To, typename From>
class ClassListMultiInsertTail;

template <typename To, typename From>
class ClassListMultiInsertTail
{
    using THX = typename From::THX;
    using RST = typename From::RST;
    using T1 = typename ClassListInsertTail<To, THX>::type;

public:
    using type = typename ClassListMultiInsertTail<T1, RST>::type;
};

template <typename To>
class ClassListMultiInsertTail<To, EmptyClassList>
{
public:
    using type = To;
};
