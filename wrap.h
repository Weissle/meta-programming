#pragma once
#include "logic.h"
#include "meta.h"
#include <type_traits>

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
        typename GetNode<WantedClass, typename NodeList::RES>::Node>;
};

template <typename Seq>
class Run
{
public:
    void run()
    {
        Run<typename Seq::RST> r;
        r.run();
        using T = typename Seq::THX;
        T::run();
    }
};

template <>
class Run<EmptyClassList>
{
public:
    void run() {}
};

template <typename TotalNodeList, typename RestNodeList = TotalNodeList,
          typename NextNodeList = EmptyClassList,
          typename ClassSeq_ = EmptyClassList>
class DFS;

template <typename TotalNodeList, typename ClassSeq_>
class DFS<TotalNodeList, EmptyClassList, EmptyClassList, ClassSeq_>
{
public:
    using FinnalClassSeq = ClassSeq_;
};

template <typename TotalNodeList, typename RestNodeList, typename NextNodeList,
          typename CurClassSeq_>
class DFS
{
    using CurClassSeq = CurClassSeq_;
    using CurNode = typename RestNodeList::THX;
    using CurClass = typename CurNode::NodeClass;
    using NewRestNodeList = typename RestNodeList::RST;

public:
    using FinnalClassSeq = std::conditional_t<
        InClassList_v<CurClassSeq, CurClass>, CurClassSeq,
        std::conditional_t<
            std::is_same_v<CurClassSeq_, EmptyClassList>,
            typename DFS<TotalNodeList, NewRestNodeList,
                         ClassList<CurClass>>::FinnalClassSeq,
            typename DFS<TotalNodeList, NewRestNodeList,
                         ClassList<CurClass, CurClassSeq>>::FinnalClassSeq>>;
    void run()
    {
        Run<FinnalClassSeq> r;
        r.run();
    }
};
