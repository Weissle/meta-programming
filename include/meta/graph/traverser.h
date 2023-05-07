#pragma once
#include "../class_list.h"
#include "node.h"
#include <type_traits>

template <template <typename, typename> typename InsertF,
          typename TotalNodeList, typename RestNodeList = TotalNodeList,
          typename NextNodeList = EmptyClassList,
          typename ClassSeq_ = EmptyClassList>
class Traverser;

template <template <typename, typename> typename InsertF,
          typename TotalNodeList, typename ClassSeq_>
class Traverser<InsertF, TotalNodeList, EmptyClassList, EmptyClassList,
                ClassSeq_>
{
public:
    using FinnalClassSeq = ClassSeq_;
};

template <template <typename, typename> typename InsertF,
          typename TotalNodeList, typename RestNodeList, typename CurClassSeq_>
class Traverser<InsertF, TotalNodeList, RestNodeList, EmptyClassList,
                CurClassSeq_>
{
    using CurClassSeq = CurClassSeq_;
    using CurNode = typename RestNodeList::THX;
    using CurClass = typename CurNode::NodeClass;
    using NewRestNodeList = typename RestNodeList::RST;
    using NewClassSeq = std::conditional_t<
        ClassListHasV<CurClassSeq, CurClass>, CurClassSeq,
        typename ClassListInsertTail<CurClassSeq, CurClass>::type>;

public:
    using FinnalClassSeq =
        typename Traverser<InsertF, TotalNodeList, NewRestNodeList,
                           typename CurNode::NXT, NewClassSeq>::FinnalClassSeq;
};

template <template <typename, typename> typename InsertF,
          typename TotalNodeList, typename RestNodeList, typename NextNodeList,
          typename CurClassSeq_>
class Traverser
{
    using CurClassSeq = CurClassSeq_;
    using CurClass = typename ClassListPopHead<NextNodeList>::head;
    using NextNodeList1 = typename ClassListPopHead<NextNodeList>::type;
    using CurNode = typename GetNode<CurClass, TotalNodeList>::Node;

    static constexpr bool need_append = !ClassListHasV<CurClassSeq, CurClass>;
    using NewClassSeq = std::conditional_t<
        need_append, typename ClassListInsertTail<CurClassSeq, CurClass>::type,
        CurClassSeq>;
    using NewNextNodeList = std::conditional_t<
        need_append,
        typename InsertF<NextNodeList1, typename CurNode::NXT>::type,
        NextNodeList1>;

public:
    using FinnalClassSeq =
        typename Traverser<InsertF, TotalNodeList, RestNodeList,
                           NewNextNodeList, NewClassSeq>::FinnalClassSeq;
};

template <typename TotalNodeList>
using BFS = Traverser<ClassListMultiInsertTail, TotalNodeList, TotalNodeList,
                      EmptyClassList, EmptyClassList>;

template <typename TotalNodeList>
using DFS = Traverser<ClassListMultiInsertHead, TotalNodeList, TotalNodeList,
                      EmptyClassList, EmptyClassList>;
