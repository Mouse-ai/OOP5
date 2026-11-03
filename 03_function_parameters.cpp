#include <iostream>

class Base
{
public:
    Base()
    {
        std::cout << "Base()" << std::endl;
    }

    Base(Base* obj)
    {
        std::cout << "Base(Base*)" << std::endl;
    }

    Base(Base& obj)
    {
        std::cout << "Base(Base&)" << std::endl;
    }
    virtual void showClass()
    {
        std::cout << "Base::showClass()" << std::endl;
    }

    virtual ~Base()
    {
        std::cout << "~Base()" << std::endl;
    }
};
class Desc : public Base
{
public:
    Desc()
    {
        std::cout << "Desc()" << std::endl;
    }

    Desc(Desc* obj)
    {
        std::cout << "Desc(Desc*)" << std::endl;
    }

    Desc(Desc& obj)
    {
        std::cout << "Desc(Desc&)" << std::endl;
    }
    void showClass() override
    {
        std::cout << "Desc::showClass()" << std::endl;
    }

    ~Desc() override
    {
        std::cout << "~Desc()" << std::endl;
    }
};

void func1(Base obj)
{
    std::cout << "func1(Base obj)" << std::endl;
    obj.showClass();

    Desc* desc = dynamic_cast<Desc*>(&obj);

    if (desc != nullptr)
    {
        std::cout << "func1: object is Desc" << std::endl;
    }
    else
    {
        std::cout << "func1: object is NOT Desc" << std::endl;
    }
}

void func2(Base* obj)
{
    std::cout << "func2(Base* obj)" << std::endl;
    obj->showClass();

    Desc* desc = dynamic_cast<Desc*>(obj);

    if (desc != nullptr)
    {
        std::cout << "func2: object is Desc" << std::endl;
    }
    else
    {
        std::cout << "func2: object is NOT Desc" << std::endl;
    }
}

void func3(Base& obj)
{
    std::cout << "func3(Base& obj)" << std::endl;
    obj.showClass();

    Desc* desc = dynamic_cast<Desc*>(&obj);

    if (desc != nullptr)
    {
        std::cout << "func3: object is Desc" << std::endl;
    }
    else
    {
        std::cout << "func3: object is NOT Desc" << std::endl;
    }
}
int main()
{
    Base obj;

    std::cout << "\n=== func1 ===" << std::endl;
    func1(obj);

    std::cout << "\n=== func2 ===" << std::endl;
    func2(&obj);

    std::cout << "\n=== func3 ===" << std::endl;
    func3(obj);

    Desc descObj;

    std::cout << "\n=== Desc to func1 ===" << std::endl;
    func1(descObj);

    std::cout << "\n=== Desc to func2 ===" << std::endl;
    func2(&descObj);

    std::cout << "\n=== Desc to func3 ===" << std::endl;
    func3(descObj);

    return 0;
}