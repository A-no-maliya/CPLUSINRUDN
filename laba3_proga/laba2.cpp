#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Company {
private:
    string name;
    string owner;
    
public:

    Company() : name(""), owner("") {}

    Company(string name, string owner): 
        name(name), owner(owner) {}

    void printInfocompany(ostream& os) {  // исп ostream, чтобы иметь возможность перенаправлять вывод в файл или в др поток
        os << "Company Name: " << name << endl;
        os << "Company owner: " << owner << endl; 
    }

    string getName() {
        return name;
    }

    void setName(string name) {
        this->name = name;
    }

    void setowner(string owner) {
        this->owner = owner;
    }

    
};

class Employee : public Company {
private:
    string name;
    int age;
    

public:
    Employee(string company_name, string owner,
        string name, int age) : Company(company_name, owner)
    {
        this->name = name;
        this->age = age;
    }

    void printInfoemplo(ostream& os) {
        os << "Name: " << name << endl;
        os << "Age: " << age << endl;
    }

    string getName() {
        return name;
    }

    void setName(string name) {
        this->name = name;
    }

    void setAge(int age) {
        this->age = age;
    }

    Employee() :
        name{ "Петя Петров"}, age{ 30 }
    {
        cout << "defolt emploees' info" << endl;
    }
};

class Vehicle : public Employee {
private:
    string manufacturer;
    int year;
    string registration_number;
    
public:
    Vehicle(string manufacturer, int year, string registration_number,
        string company_name, string owner,
        string emplo_name, int age) : Employee(company_name, owner, 
            emplo_name, age)

    {
        this->registration_number = registration_number;
        this->manufacturer = manufacturer;
        this->year = year;
    }


    Vehicle(std::string manufacturer) : manufacturer(manufacturer), year(0) {
    }

    Vehicle(int year) : manufacturer(""), year(year) {
    }


    void printInfovehicle(ostream& os) {
        os << "Manufacturer: " << manufacturer << endl;
        os << "Year: " << year << endl;
        os << "Registration Number: " << registration_number << endl;
    }

    void setManufacturer(string manufacturer) {
        this->manufacturer = manufacturer;
    }

    void setYear(int year) {
        this->year = year;
    }

    void setRegnumber(string registration_number) {
        this->registration_number = registration_number;
    }

    Vehicle() :
        registration_number{ "O777OO" }, year{ 1965 }
    {
        cout << "DEFOLT INFO" << std::endl;
    }
};

// Класс Car наследуется от класса Vehicle
class Car : public Vehicle {
private:
    string transmission; // Тип трансмиссии
    int seats; // Количество сидений
    string has_passengers; // Имеет ли пассажиров
    string has_speeding_tickets; // Имеет ли штрафы за превышение скорости
   

public:

    // Конструктор с параметрами
    Car(string transmission, int seats, string has_passengers, string has_speeding_tickets,
        string manufacturer, int year, string registration_number,
        string company_name, string owner,
        string emplo_name, int age) : Vehicle(manufacturer, year, registration_number,
            company_name, owner,
            emplo_name, age)

    {
        this->transmission = transmission;
        this->seats = seats;
        this->has_passengers = has_passengers;
        this->has_speeding_tickets = has_speeding_tickets;
    }

    
    Car() :
        transmission{ "Avto" }, seats{5}, has_passengers{true}, has_speeding_tickets{true}
    {
        cout << "DEFOLT INFO" << endl;
    }

    // Печать информации о машине
    void getInfocar(ostream& os) {
        os << "transmission: " << transmission << endl;
        os << "seats: " << seats << endl;
        os << "has_passengers: " << has_passengers << endl;
        os << "has_speeding_tickets: " << has_speeding_tickets << endl;
    }

    // Перевозка пассажиров
    void drive_passengers() {
        this->has_passengers = true;
    }

    // Превышение скорости
    void speeding() {
        this->has_speeding_tickets = true;
    }
};

class Truck : public Vehicle {
private:

    double mass;
    double load_capacity;
    double current_load;

public:

    Truck(double mass, double load_capacity, double current_load, 
        string company_name, string owner,
        string manufacturer, int year, string registration_number,
        string emplo_name, int age) : Vehicle(manufacturer, year, registration_number,
            company_name, owner,
            emplo_name, age)

    {
        this->mass = mass;
        this->load_capacity = load_capacity;
        this->current_load = current_load;
    }

    void load_capacity_smth() {

    }

    void current_load() {

    }

    void getInfotrack(ostream& os) {
        os << "mass: " << mass << endl;
        os << "load_capacity: " << load_capacity << endl;
        os << "current_load: " << current_load << endl;
    }

    Truck() : mass(9245), load_capacity(1002), current_load(302)
    {
        std::cout << "DEFOLT INFO" << endl;
    }

};

int main() {
    return 0;
}


/*написала некоторые доп контрукторы 
несколькими вариантами, удалять не буду

на классе КАР(ыч) я решила прокомментировать */