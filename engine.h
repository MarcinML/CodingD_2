#pragma once
#include "person.h"
#include <gmock/gmock.h>
#include <vector>
#include <functional>

class IEngine
{
public:
    using S=std::vector<std::reference_wrapper<const Person>>;

    virtual int getSize() const = 0;
    virtual const Person& getPerson(int) const = 0;
    virtual void add(const Person&, int) = 0;
    virtual S search(const std::string & surname)const = 0;
    virtual ~IEngine();
};


class VectorEngine: public IEngine {
public:
   VectorEngine () =default;


    int getSize() const
    {
        return peopleDB.size();
    }

    void add(const Person& per, int ID)
    {
        peopleDB.push_back(per);
        peopleDB.back().setMagicNumber(ID);
    }
    S search(const std::string & surname) const;

    const Person& getPerson(int index) const
    {
        return peopleDB.at(index);
    }

private:
    std::vector<Person> peopleDB;

};

class MockEngine : public IEngine
{
public:
    MOCK_CONST_METHOD0(getSize, int());
    MOCK_METHOD2(add, void (const Person& , int));
    MOCK_CONST_METHOD1(search, IEngine::S (const std::string & ));
    MOCK_CONST_METHOD1(getPerson, const Person& (int));



};
