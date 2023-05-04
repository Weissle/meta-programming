#pragma once
#include <type_traits>

template <typename... NC>
class ClassList;

template <typename T, typename CL>
class ClassListInsertHead;

template <typename T, typename CL>
class ClassListInsertTail;

template <typename T, typename CL>
class ClassListPopHead;

template <typename T, typename CL>
class ClassListPopTail;

template <typename T, typename CL>
class InClassList;

template <>
class ClassList<>
{
    using THX = void;
    using RST = void;
};
using EmptyClassList = ClassList<>;

template <typename THX_, typename... NC>
class ClassList<THX_, NC...>
{
public:
    using THX = THX_;
    using RST = ClassList<NC...>;
};

template <typename T, typename CL>
class ClassListInsertTail
{
    using THX = typename CL::THX;
    using RST = typename CL::RST;

public:
    using type = ClassList<THX, typename ClassListInsertTail<T, RST>::type>;
};

template <typename T>
class ClassListInsertTail<T, EmptyClassList>
{
public:
    using type = ClassList<T>;
};

template <typename THX_, typename... NC>
class ClassList<THX_, ClassList<NC...>>
{
public:
    using THX = THX_;
    using RST = ClassList<NC...>;
};

template <typename T, typename CL>
class ClassListAppend
{
public:
    using type = ClassList<T, CL>;
};

template <typename CL, typename T>
class InClassList
{
public:
    static constexpr bool value = std::is_same_v<typename CL::THX, T> ||
                                  InClassList<typename CL::RST, T>::value;
};

template <typename T>
class InClassList<EmptyClassList, T>
{
public:
    static constexpr bool value = false;
};

template <typename CL, typename T>
inline constexpr bool InClassList_v = InClassList<CL, T>::value;
