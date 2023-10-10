#include <iostream>

class People
{
private:
    std::string name;
    unsigned int age;

public:
// Конструктор по-умолчанию
People() : name(0), age(0)
{
    std::cout << "Конструктор по умолчанию отработал" << std::endl;
}

// параметрический конструктор
People(const std::string& nameP, int ageP) : name(nameP), age(ageP) {}
{
    std::cout << "Конструктор с параметрами отработал" << std::endl;
}

// Конструктор копирования
People(const People& other) : name(other.name), age(other.age) {}

// Деструктор
~People()      
{
    std::cout << "Деструктор отработал" << std::endl;
}
}
int main()
{

}