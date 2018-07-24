#pragma once
#include <vector>
#include "person.h"
#include "engine.h"

class Database
{
public:
    Database(IEngine&);
    int getSize() const;
    void addPerson(const Person& per);
    IEngine::S search(const std::string & surname);
    bool readFromFile(std::string);
    bool readFromStream(std::istream&);
    bool writeToStream(std::ostream& stream);


private:
    //std::vector<Person> peopleDB;
    IEngine & engine_;
  //  VectorEngine engine_;
    int ID{0};
};

