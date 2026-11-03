#include <iostream>

class Base
{
public:
    void nonVirtualMethod()
    {
        std::cout << "Base::nonVirtualMethod()" << std::endl;
    }

    virtual void virtualMethod()
    {
        std::cout << "Base::virtualMethod()" << std::endl;
    }

    void method1NonVirtual()
    {
        std::cout << "Base::method1NonVirtual()" << std::endl;
        method2NonVirtual();
    }

    void method2NonVirtual()
    {
        std::cout << "Base::method2NonVirtual()" << std::endl;
    }

    void method1Virtual()
    {
        std::cout << "Base::method1Virtual()" << std::endl;
        method2Virtual();
    }

    virtual void method2Virtual()
    {
        std::cout << "Base::method2Virtual()" << std::endl;
    }
    virtual ~Base()
    {
        std::cout << "Base::~Base()" << std::endl;
    }
};


class Desc : public Base
{
public:
    void nonVirtualMethod()
    {
        std::cout << "Desc::nonVirtualMethod()" << std::endl;
    }

    void virtualMethod() override
    {
        std::cout << "Desc::virtualMethod()" << std::endl;
    }

    void method2NonVirtual()
    {
        std::cout << "Desc::method2NonVirtual()" << std::endl;
    }

    void method2Virtual() override
    {
        std::cout << "Desc::method2Virtual()" << std::endl;
    }
    ~Desc() override
    {
        std::cout << "Desc::~Desc()" << std::endl;
    }
};


int main()
{
    Desc obj;

    Base* basePtr = &obj;
    Desc* descPtr = &obj;

    std::cout << "=== Non-virtual and virtual methods ===" << std::endl;

    basePtr->nonVirtualMethod();
    descPtr->nonVirtualMethod();

    basePtr->virtualMethod();
    descPtr->virtualMethod();


    std::cout << "\n=== Method calls non-virtual method ===" << std::endl;

    obj.method1NonVirtual();


    std::cout << "\n=== Method calls virtual method ===" << std::endl;

    obj.method1Virtual();

    std::cout << "\n=== Virtual destructor ===" << std::endl;

    Base* ptr = new Desc();

    delete ptr;

    return 0;
}