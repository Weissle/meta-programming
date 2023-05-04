#include <iostream>
// 定义一个空类模板作为递归终止条件
template <typename... T>
class ClassList
{
};

// 定义一个非空类模板，可以接收任意数量的模板参数
template <typename T, typename... Rest>
class ClassList<T, Rest...>
{
public:
    // 遍历每个类的方法
    void iterate()
    {
        std::cout << typeid(T).name() << std::endl; // 输出当前类的类型信息
        // 递归调用遍历方法，继续遍历后面的类
        ClassList<Rest...>().iterate();
    }
};

// 特化一个版本，避免ClassList<ClassList<...>>的情况
template <typename T>
class ClassList<T>
{
public:
    void iterate() { std::cout << typeid(T).name() << std::endl; }
};

// 定义一些类
class A
{
};
class B
{
};
class C
{
};
int main(int argc, char* argv[])
{
    // 定义一个ClassList对象
    ClassList<A, B, ClassList<C, A>> myList;

    // 遍历所有类
    myList.iterate();

    return 0;
}
