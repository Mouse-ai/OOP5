#include <iostream>
#include <string>

class Base
{
public:
    virtual bool isA(std::string className)
    {
        return className == "Base";
    }
    virtual std::string classname()
    {
        return "Base";
    }

    virtual ~Base() = default;
};
class Desc : public Base
{
public:
    bool isA(std::string className) override
    {
        if (className == "Desc")
            return true;

        return Base::isA(className);
    }
    std::string classname() override
    {
        return "Desc";
    }
};
class Child : public Desc
{
public:
    bool isA(std::string className) override {
        if (className == "Child")
            return true;

        return Desc::isA(className);
    }
    std::string classname() override
    {
        return "Child";
    }
    void childMethod()
    {
        std::cout << "Child::childMethod()" << std::endl;
    }
};
int main() {
    Child obj;
    Base* ptr = &obj;
    Base baseObj;
    Base* badPtr = &baseObj;
    if (ptr->isA("Child") )
    {
        Child* childPtr = static_cast<Child*>(ptr);
        childPtr->childMethod();
    }
    Child* childPtr2 = dynamic_cast<Child*>(ptr);

    if (childPtr2 != nullptr)
    {
        childPtr2->childMethod();
    }
    Child* wrongPtr2 = dynamic_cast<Child*>(badPtr);

    if (wrongPtr2 == nullptr)
    {
        std::cout << "badPtr is not Child" << std::endl;
    }
}