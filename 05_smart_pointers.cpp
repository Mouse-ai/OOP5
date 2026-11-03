#include <iostream>
#include <memory>
#include <utility>

class Base
{
public:
    Base()
    {
        std::cout << "Base()" << std::endl;
    }

    ~Base()
    {
        std::cout << "~Base()" << std::endl;
    }
};
void takeOwnership(std::unique_ptr<Base> ptr)
{
    std::cout << "takeOwnership()" << std::endl;
}
std::unique_ptr<Base> createBase()
{
    std::cout << "createBase()" << std::endl;

    return std::make_unique<Base>();
}
void useShared(std::shared_ptr<Base> ptr)
{
    std::cout << "useShared count: " << ptr.use_count() << std::endl;
}
std::shared_ptr<Base> createShared() {
    std::cout << "createShared()" << std::endl;
    return std::make_shared<Base>();
}
int main()
{
    std::cout << "=== unique_ptr ===" << std::endl;

    {
        std::unique_ptr<Base> ptr = std::make_unique<Base>();

        std::cout << "Inside block" << std::endl;
    }

    std::cout << "After block" << std::endl;


    std::cout << "\n=== move unique_ptr ===" << std::endl;

    std::unique_ptr<Base> ptr1 = std::make_unique<Base>();

    std::unique_ptr<Base> ptr2 = std::move(ptr1);

    if (ptr1 == nullptr)
    {
        std::cout << "ptr1 is empty" << std::endl;
    }

    if (ptr2 != nullptr)
    {
        std::cout << "ptr2 owns Base" << std::endl;
    }


    std::cout << "\n=== unique_ptr as function parameter ===" << std::endl;

    std::unique_ptr<Base> ptr3 = std::make_unique<Base>();

    takeOwnership(std::move(ptr3));

    if (ptr3 == nullptr)
    {
        std::cout << "ptr3 is empty" << std::endl;
    }


    std::cout << "\n=== return unique_ptr ===" << std::endl;

    std::unique_ptr<Base> ptr4 = createBase();

    std::cout << "Back in main" << std::endl;


    std::cout << "\n=== shared_ptr copy ===" << std::endl;

    std::shared_ptr<Base> shared1 = std::make_shared<Base>();

    std::cout << "count: "
              << shared1.use_count() << std::endl;

    {
        std::shared_ptr<Base> shared2 = shared1;

        std::cout << "count: "
                  << shared1.use_count() << std::endl;
    }

    std::cout << "count: "
              << shared1.use_count() << std::endl;


    std::cout << "\n=== shared_ptr as function parameter ===" << std::endl;

    std::shared_ptr<Base> shared3 = std::make_shared<Base>();

    std::cout << "before function: "
              << shared3.use_count() << std::endl;

    useShared(shared3);

    std::cout << "after function: "
              << shared3.use_count() << std::endl;


    std::cout << "\n=== return shared_ptr ===" << std::endl;

    std::shared_ptr<Base> shared4 = createShared();

    std::cout << "shared4 count: "
              << shared4.use_count() << std::endl;

    std::cout << "Back in main" << std::endl;


    return 0;
}