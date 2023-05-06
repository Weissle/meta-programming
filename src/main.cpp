#include "logic.h"
#include "meta/meta.h"

int main(int argc, char* argv[])
{
    DFS<NodeList> dfs;
    dfs.run();
    BFS<NodeList> bfs;
    bfs.run();
    return 0;
}
