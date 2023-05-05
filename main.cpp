#include "logic.h"
#include "wrap.h"

int main(int argc, char* argv[])
{
    DFS<NodeList, NodeList, EmptyClassList> dfs;
    dfs.run();
    // auto node = graph.get_node<LogicE, typename G::NodeList>();
    // decltype(node)::NodeClass::run();
    // graph.dfs();
    return 0;
}
