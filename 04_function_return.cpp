#include <iostream>

class Base
{
public:
    Base()
    {
        std::cout << "Base()" << std::endl;
    }

    Base(Base& obj)
    {
        std::cout << "Base(Base&)" << std::endl;
    }

    virtual ~Base()
    {
        std::cout << "~Base()" << std::endl;
    }
};
Base func1()
{
    std::cout << "func1()" << std::endl;

    Base obj;

    return obj;
}
Base* func2()
{
    std::cout << "func2()" << std::endl;

    Base obj;

    return &obj;
}
Base& func3()
{
    std::cout << "func3()" << std::endl;

    Base obj;

    return obj;
}
Base func4()
{
    std::cout << "func4()" << std::endl;

    Base* obj = new Base();

    Base result = *obj;

    delete obj;

    return result;
}
Base* func5()
{
    std::cout << "func5()" << std::endl;

    Base* obj = new Base();

    return obj;
}
Base& func6()
{
    Base* obj = new Base();
    return *obj;
}
int main()
{
    std::cout << "=== func1 ===" << std::endl;

    Base result = func1();


    std::cout << "\n=== func2 ===" << std::endl;

    Base* result2 = func2();


    std::cout << "\n=== func3 ===" << std::endl;

    Base& result3 = func3();

    std::cout << "\n=== func4 ===" << std::endl;

    Base result4 = func4();
    std::cout << "\n=== func5 ===" << std::endl;

    Base* result5 = func5();

    delete result5;

    std::cout << "\n=== func6 ===" << std::endl;

    Base& result6 = func6();

    delete &result6;

    return 0;
}