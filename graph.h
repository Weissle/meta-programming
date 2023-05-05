#pragma once
#include "./meta/meta.h"
#include "logic.h"
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

/*
A -> E
A -> C
B -> C
B -> D
C -> D
E -> D
F -> H
G
*/

using ANext = ClassList<LogicE, LogicC>;
using BNext = ClassList<LogicC, LogicD>;
using CNext = ClassList<LogicD>;
using DNext = ClassList<>;
using ENext = ClassList<LogicD>;
using FNext = ClassList<LogicH>;
using GNext = ClassList<>;
using HNext = ClassList<>;

using NodeA = Node<LogicA, ANext>;
using NodeB = Node<LogicB, BNext>;
using NodeC = Node<LogicC, CNext>;
using NodeD = Node<LogicD, DNext>;
using NodeE = Node<LogicE, ENext>;
using NodeF = Node<LogicF, FNext>;
using NodeG = Node<LogicG, GNext>;
using NodeH = Node<LogicH, HNext>;
using NodeList =
    ClassList<NodeA, NodeB, NodeC, NodeD, NodeE, NodeF, NodeG, NodeH>;
