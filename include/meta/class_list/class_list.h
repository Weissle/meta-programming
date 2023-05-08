#pragma once
#include <type_traits>

template <typename... NC>
class ClassList;

template <>
class ClassList<>
{
public:
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

template <typename THX_, typename... NC>
class ClassList<THX_, ClassList<NC...>>
{
public:
    using THX = THX_;
    using RST = ClassList<NC...>;
};

//
// template <typename... NC, typename T>
// class ClassList<ClassList<NC...>, T>
// {
//     static_assert(std::is_same_v<T, void>);
// };
