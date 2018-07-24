#include "gtest/gtest.h"
#include <gmock/gmock.h>
#include "person.h"

TEST(personShould, classPersonShouldGetAnInstance)
{
    Person p;
    p.setName("Roman");

    EXPECT_EQ(p.getName(), "Roman");
}

TEST(personShould, afterAddingAllInfoSuccessfullyRetrieveIt)
{
    Person p1;

    p1.setName("A");
    p1.setSurname("B");
    p1.setMagicNumber(1);
    EXPECT_EQ(p1.getName(), "A");
    EXPECT_EQ(p1.getSurname(), "B");
    EXPECT_EQ(p1.getMagicNumber(), 1);
}

