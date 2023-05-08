#include "logic.h"
#include "meta/meta.h"

int main(int argc, char* argv[])
{
    Run<DFS<NodeList>::FinnalClassSeq> dfs;
    std::cout << "DFS Run 1:" << std::endl;
    dfs.run();
    std::cout << "DFS Run 2:" << std::endl;
    dfs.run();
    std::cout << "DFS Run 3:" << std::endl;
    dfs.run();

    Run<BFS<NodeList>::FinnalClassSeq> bfs;
    std::cout << "BFS Run 1:" << std::endl;
    bfs.run();
    std::cout << "BFS Run 2:" << std::endl;
    bfs.run();
    return 0;
}
