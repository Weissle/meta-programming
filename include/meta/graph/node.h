#pragma once
#include "../class_list.h"
#include <type_traits>
// define the class graph in here.

template <typename NodeClass_, typename NXT_>
class Node
{
public:
    using NodeClass = NodeClass_;
    using NXT = NXT_;
};

template <typename WantedClass, typename NodeList>
class GetNode;

template <typename WantedClass>
class GetNode<WantedClass, EmptyClassList>
{
public:
    using Node = void;
};

template <typename WantedClass, typename NodeList>
class GetNode
{
    using CurNode = typename NodeList::THX;
    using CurClass = typename CurNode::NodeClass;
    using CurNext = typename CurNode::NXT;

public:
    static constexpr bool is_wanted = std::is_same_v<CurClass, WantedClass>;
    using Node = std::conditional_t<
        is_wanted, CurNode,
        typename GetNode<WantedClass, typename NodeList::RST>::Node>;
};
