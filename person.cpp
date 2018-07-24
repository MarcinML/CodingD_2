#include "person.h"





Person::Person(std::string name, std::string surname)
    : name_(name), surname_(surname)
{
}



void Person::setName(std::string name)
{
    name_ = name;
}

std::string Person::getName() const
{
    return name_;
}

void Person::setSurname(std::string surname)
{
    surname_ = surname;
}

std::string Person::getSurname() const
{
    return surname_;
}

void Person::setMagicNumber(int id)
{
    magicNumber_ = id;
}

int Person::getMagicNumber() const
{
    return magicNumber_;
}
