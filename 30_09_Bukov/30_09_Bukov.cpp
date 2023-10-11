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
        std::cout << "Конструктор People по умолчанию отработал" << ", по адресу " << this << std::endl;
    }

    // параметрический конструктор
    People(const std::string& nameP, int ageP) : name(nameP), age(ageP)
    {
        std::cout << "Конструктор People с параметрами отработал" << ", по адресу " << this << std::endl;
    }

    // Конструктор копирования
    People(const People& other) : name(other.name), age(other.age) 
    {
        std::cout << "Конструктор копирования People  отработал" << ", по адресу " << this << std::endl;
    }

    // Деструктор
    ~People()      
    {
        std::cout << "Деструктор People отработал" << ", по адресу " << this << std::endl;
    }

    // геттеры
    std::string getName() const { return name; }
    int getAge() const { return age; }

    // вывод информации о человеке
    void print() const 
    {
        std::cout << "Имя: " << name <<", Возраст: " << age << std::endl; 
    }

};

class Apartment
{
private:
    unsigned int number;
    People* residents;
    unsigned int numResidents;

public:
    // Конструктор по умолчанию
    Apartment() : number(), residents(nullptr), numResidents(0)
    {
 std::cout << "Конструктор Apartment по умолчанию отработал" << ", по адресу " << this << std::endl;
    }

    //Конструктор с параметрами
    Apartment(int numberP) : number(numberP), residents(nullptr), numResidents(0)
    {
        std::cout << "Конструктор Apartment с параметрами отработал" << ", по адресу " << this << std::endl;
    }

    // Конструктор копирования
    Apartment(const Apartment& other) : number(other.number), numResidents(other.numResidents) {
        residents = new People[numResidents];
        for (int i = 0; i < numResidents; ++i) 
        {
            residents[i] = other.residents[i];
        }
        std::cout << "Конструктор копирования Apartment  отработал" << ", по адресу " << this << std::endl;
    }

        // Деструктор
    ~Apartment() 
    {
        delete[] residents;
        std::cout << "Деструктор Apartment отработал" << ", по адресу " << this << std::endl;
    }
    

    // Добавление жильцов
    void addResident(const People& people)
    {
        People* newPeople = new People[numResidents + 1];
        for (int i = 0; i < numResidents; i++)
        {
            newPeople[i] = residents[i];
        }
        newPeople[numResidents] = people;
        delete[] residents;
        residents = newPeople;
        numResidents++;
    }

    // вывести информацию о жильцах
    void printResidents() const{
        std::cout << "Квартира " << number << " Жилец:" << std::endl;
        for (int i = 0; i < numResidents; i++)
        {
            residents[i].print();
        }
    }
};


class House
{
private:
    Apartment* apartments;
    unsigned int nunApartments;

public:
    // конструктор по-умолчанию
    

    // конструктоh c параметрами
    House(const House& other) : nunApartments(other.nunApartments)
    {
        apartments = new Apartment[other.nunApartments];
        for (int i = 0; i < nunApartments; i++)
        {
            apartments[i] = Apartment(i + 1);
        }
        

    }
}

int main()
{

}