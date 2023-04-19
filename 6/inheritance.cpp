#include <iostream>

class Devise
{
public:
    Devise()
    {
        std::cout << "Devise constructor was called" << std::endl;
    }
    ~Devise()
    {
        std::cout << "Devise destructor was called" << std::endl;
    }
    void turn_on()
    {
        std::cout << "Devise is on" << std::endl;
    }
};

class Monitor: virtual public Devise
{
public:
    Monitor()
    {
        std::cout << "Monitor constructor was called" << std::endl;
    }
    ~Monitor()
    {
        std::cout << "Monitor destructor was called" << std::endl;
    }
    // void turn_on()
    // {
    //     std::cout << "Monitor is on" << std::endl;
    // }
};

class Computer: virtual public Devise
{
public:
    Computer()
    {
        std::cout << "Computer constructor was called" << std::endl;
    }
    ~Computer()
    {
        std::cout << "Computer destructor was called" << std::endl;
    }
    // void turn_on()
    // {
    //     std::cout << "Computer is on" << std::endl;
    // }
};

class Laptop: public Computer, public Monitor
{
public:
    Laptop()
    {
        std::cout << "Laptop constructor was called" << std::endl;
    }
    ~Laptop()
    {
        std::cout << "Laptop destructor was called" << std::endl;
    }
    // void turn_on()
    // {
    //     std::cout << "Laptop is on" << std::endl;
    // }
};

int main()
{
    Laptop laptop_instance;
    laptop_instance.turn_on();

    return 0;
}
