#pragma once
#include <string>

class Person
{

public:

    Person(std::string name="noName",std::string surname = "noSurname");

    std::string getName() const;
    std::string getSurname() const;
    int getMagicNumber() const;

    void setSurname(std::string);
    void setName(std::string);
    void setMagicNumber(int);


private:

    std::string name_;
    std::string surname_;
    int magicNumber_;
    };

