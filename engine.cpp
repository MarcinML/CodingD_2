#include "engine.h"

IEngine::~IEngine() = default;



IEngine::S VectorEngine::search(const std::string & surname ) const
{

    S matchSurnames;
    for(const auto & x : peopleDB)
    {
        if(x.getSurname()==surname)
            matchSurnames.push_back(x);
    }

    return matchSurnames;
}
