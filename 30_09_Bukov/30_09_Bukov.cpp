#include <iostream>
#include <string>

class People
{
private:
    std::string name;
    unsigned int age;

public:
    // Конструктор по-умолчанию
    People();

    // параметрический конструктор
    People(const std::string& nameP, int ageP);

    // Конструктор копирования
    People(const People& other);

    // Деструктор
    ~People();

    // геттеры
    std::string getName() const { return name; }
    int getAge() const { return age; }

    // вывод информации о человеке
    void print() const;

};

// Конструктор по-умолчанию
People::People() : name(""), age(0)
{
    std::cout << "Конструктор People по умолчанию отработал" << ", по адресу " << this << std::endl;
}

// параметрический конструктор
People::People(const std::string& nameP, int ageP) : name(nameP), age(ageP)
{
    std::cout << "Конструктор People с параметрами отработал" << ", по адресу " << this << std::endl;
}

// Конструктор копирования
People::People(const People& other) : name(other.name), age(other.age)
{
    std::cout << "Конструктор копирования People  отработал" << ", по адресу " << this << std::endl;
}

// Деструктор
People::~People()
{
    std::cout << "Деструктор People отработал" << ", по адресу " << this << std::endl;
}

void People::print() const
{
    std::cout << "Имя: " << getName() << ", Возраст: " << getAge() << std::endl;
}



class Apartment
{
private:
    unsigned int number;
    People* residents;
    int numResidents;

public:
    // Конструктор по умолчанию
    Apartment();

    //Конструктор с параметрами
    Apartment(int numberP);

    // Конструктор копирования
    Apartment(const Apartment& other);

    // Деструктор
    ~Apartment();
    

    // Добавление жильцов
    void addResident(const People& people);

    // вывести информацию о жильцах
    void printResidents() const;
};

// Конструктор по умолчанию
Apartment::Apartment() : number(), residents(nullptr), numResidents(0)
{
    std::cout << "Конструктор Apartment по умолчанию отработал" << ", по адресу " << this << std::endl;
}

//Конструктор с параметрами
Apartment::Apartment(int numberP) : number(numberP), residents(nullptr), numResidents(0)
{
    std::cout << "Конструктор Apartment с параметрами отработал" << ", по адресу " << this << std::endl;
}
    
// Конструктор копирования
Apartment::Apartment(const Apartment& other) : number(other.number), numResidents(other.numResidents)
{
    residents = new People[numResidents];
    for (int i = 0; i < numResidents; ++i)
    {
        residents[i] = other.residents[i];
    }
    std::cout << "Конструктор копирования Apartment  отработал" << ", по адресу " << this << std::endl;
}

// Деструктор
Apartment::~Apartment()
{
    delete[] residents;
    std::cout << "Деструктор Apartment отработал" << ", по адресу " << this << std::endl;
}

// вывести информацию о жильцах
void Apartment::printResidents() const
{
    std::cout << "Квартира " << number << " Жилец:" << std::endl;
    for (int i = 0; i < numResidents; i++)
    {
        residents[i].print();
    }
}

// Добавление жильцов
void Apartment::addResident(const People& people)
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



class House
{
private:
    Apartment* apartments;
    int numApartments;

public:
    // конструктор по-умолчанию
    House();
    

    // конструктоh c параметрами
    House(int numApartmentsP);

    // Конструктор копирования
    House(const House& other);

    // деструктор
    ~House();


    // Добавление жильца в квартиру
    void addResidentsApartments(int numApartments, const People& people);

    // Вывести информацию о квартирах и их жильцах
    void displayHouse() const;
        
    
};

// конструктор по-умолчанию
House::House() : apartments(nullptr), numApartments(0)
{
    std::cout << "Конструктор House по умолчанию отработал" << ", по адресу " << this << std::endl;
}

// конструктоh c параметрами
House::House(int numApartmentsP) : numApartments(numApartmentsP)
{
    apartments = new Apartment[numApartments];
    for (int i = 0; i < numApartments; ++i)
    {
        apartments[i] = Apartment(i + 1);
    }
    std::cout << "Конструктор House c параметрами отработал" << ", по адресу " << this << std::endl;
}

// Конструктор копирования
House::House(const House& other) : numApartments(other.numApartments)
{
    apartments = new Apartment[numApartments];
    for (int i = 0; i < numApartments; i++)
    {
        apartments[i] = other.apartments[i];
    }
    std::cout << "Конструктор копирования House  отработал" << ", по адресу " << this << std::endl;
}

// деструктор
House::~House()
{
    delete[] apartments;
    std::cout << "Деструктор House отработал" << ", по адресу " << this << std::endl;
}

// Вывести информацию о квартирах и их жильцах
void House::displayHouse() const
{
    std::cout << "House: " << std::endl;
    for (int i = 0; i < numApartments; i++)
    {
        apartments[i].printResidents();
    }
}

// Добавление жильца в квартиру
void House::addResidentsApartments(int numApartments, const People& people)
{
    if (numApartments >= 1 && numApartments <= numApartments)

    {
        apartments[numApartments - 1].addResident(people);
    }
    else
    {
        std::cout << "Неверный номер квартиры." << std::endl;
    }
}



int main()
{
    setlocale(LC_ALL, "rus");
    House myhouse(3); // создание дома с 3 квартирами

    // добавыление жильцов в квартиры
    myhouse.addResidentsApartments(1, People("Иван", 33)); 
    myhouse.addResidentsApartments(1, People("Екатерина", 25)); 
    myhouse.addResidentsApartments(2, People("Александр", 45)); 
    myhouse.addResidentsApartments(3, People("Сергей", 79)); 
    myhouse.addResidentsApartments(3, People("Эдуард", 82)); 


    //вывод информацйии о доме
    myhouse.displayHouse();
}