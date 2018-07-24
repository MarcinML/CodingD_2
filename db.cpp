#include "db.h"
#include "engine.h"
#include <fstream>

Database::Database(IEngine& new_engine) : engine_(new_engine)
{

}


int Database::getSize() const
{
    return engine_.getSize();
            //peopleDB.size();
}

void Database::addPerson(const Person& per)
{

    engine_.add(per, ++ID);

}


IEngine::S Database::search(const std::string & surname)
{
    return engine_.search(surname);
}


bool Database::readFromFile(std::string fileName)
{
   std::ifstream file(fileName);
    if(!file.is_open())
        return false;

   return readFromStream(file);
}

bool Database::readFromStream(std::istream& stream)
{
    while(stream)
    {
        std::string line, name, surname;
        std::getline(stream, line);
        std::stringstream tokens(line);
        tokens >>  name >> surname;
        addPerson(Person{name, surname});
    }
    return true;
}

bool Database::writeToStream(std::ostream& stream)
{
for(int i=0; i < getSize(); i++) {
    const Person& p = engine_.getPerson(i);
    stream << p.getName() << " " << p.getSurname() << std::endl;
}
return 1;
       //std::string name, surname;

}
