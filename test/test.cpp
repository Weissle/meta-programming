#include "logic.h"
#include "meta/meta.h"
#include <assert.h>
#include <iostream>

int main(int argc, char* argv[])
{
    std::string s;

    // test1
    s.clear();
    using CL1 = ClassList<LogicA, LogicB, LogicC, LogicD, LogicE>;
    Run<CL1>::run(s);
    // std::cout << s << std::endl;
    assert(s == "LogicA;LogicB;LogicC;LogicD;LogicE;");

    // test2
    s.clear();
    using CL2 = typename ClassListInsertTail<CL1, LogicF>::type;
    Run<CL2>::run(s);
    // std::cout << s << std::endl;
    assert(s == "LogicA;LogicB;LogicC;LogicD;LogicE;LogicF;");

    // test3
    s.clear();
    using CL3W = ClassListPopTail<CL1>;
    static_assert(std::is_same_v<LogicE, typename CL3W::tail>);
    Run<CL3W::type>::run(s);
    assert(s == "LogicA;LogicB;LogicC;LogicD;");

    // test4
    s.clear();
    using CL4W = ClassListPopHead<CL1>;
    static_assert(std::is_same_v<LogicA, typename CL4W::head>);
    Run<CL4W::type>::run(s);
    assert(s == "LogicB;LogicC;LogicD;LogicE;");

    // test4
    s.clear();
    using CL5 = ClassListInsertHead<CL4W::type, LogicF>::type;
    Run<CL5>::run(s);
    assert(s == "LogicF;LogicB;LogicC;LogicD;LogicE;");

    // test5
    static_assert(ClassListHasV<CL1, LogicB>);
    static_assert(!ClassListHasV<CL1, LogicF>);

    // test6
    using CL6_1 = ClassList<LogicA, LogicB, LogicF>;
    using CL6_2 = ClassList<LogicD, LogicF, LogicC>;
    using CL6 = ClassListMultiInsertTail<CL6_1, CL6_2>::type;
    s.clear();
    Run<CL6_1>::run(s);
    assert(s == "LogicA;LogicB;LogicF;");
    s.clear();
    Run<CL6_2>::run(s);
    assert(s == "LogicD;LogicF;LogicC;");
    s.clear();
    Run<CL6>::run(s);
    assert(s == "LogicA;LogicB;LogicF;LogicD;LogicF;LogicC;");

    // test7
    using CL7_1 = ClassList<LogicA, LogicB, LogicF>;
    using CL7_2 = ClassList<LogicD, LogicF, LogicC>;
    using CL7 = ClassListMultiInsertHead<CL7_1, CL7_2>::type;
    s.clear();
    Run<CL7_1>::run(s);
    assert(s == "LogicA;LogicB;LogicF;");
    s.clear();
    Run<CL7_2>::run(s);
    assert(s == "LogicD;LogicF;LogicC;");
    s.clear();
    Run<CL7>::run(s);
    assert(s == "LogicD;LogicF;LogicC;LogicA;LogicB;LogicF;");

    // test8
    s.clear();
    Run<BFS<NodeList>::FinnalClassSeq> r1;
    r1.run(s);
    assert(s == "LogicA;LogicC;LogicD;LogicE;LogicF;LogicG;LogicH;LogicB;");

    // test9
    s.clear();
    Run<DFS<NodeList>::FinnalClassSeq> r2;
    r2.run(s);
    assert(s == "LogicA;LogicC;LogicE;LogicG;LogicF;LogicD;LogicH;LogicB;");

    std::cout << "All tests is passed.\n";
    return 0;
}
