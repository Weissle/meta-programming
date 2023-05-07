#include "logic.h"
#include "meta/meta.h"

int main(int argc, char* argv[])
{
    std::cout << "DFS Result:" << std::endl;
    Run<DFS<NodeList>::FinnalClassSeq> dfs;
    dfs.run();

    std::cout << "BFS Result:" << std::endl;
    Run<BFS<NodeList>::FinnalClassSeq> bfs;
    bfs.run();
    return 0;
}
