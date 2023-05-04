#include "logic.h"
#include "wrap.h"

int main(int argc, char* argv[])
{
    /*
    A -> E
    A -> C
    B -> C
    B -> D
    C -> D
    E -> D
    F
    */

    using ANext = ClassList<LogicE, LogicC>;
    using BNext = ClassList<LogicC, LogicD>;
    using CNext = ClassList<LogicD>;
    using DNext = ClassList<>;
    using ENext = ClassList<LogicD>;
    using FNext = ClassList<>;

    using NodeA = Node<LogicA, ANext>;
    using NodeB = Node<LogicB, BNext>;
    using NodeC = Node<LogicC, CNext>;
    using NodeD = Node<LogicD, DNext>;
    using NodeE = Node<LogicE, ENext>;
    using NodeF = Node<LogicF, FNext>;
    using NodeList = ClassList<NodeA, NodeB, NodeC, NodeD, NodeE, NodeF>;
    DFS<NodeList, NodeList, EmptyClassList> dfs;
    dfs.run();
    // auto node = graph.get_node<LogicE, typename G::NodeList>();
    // decltype(node)::NodeClass::run();
    // graph.dfs();
    return 0;
}
