#include "gtest/gtest.h"
#include <gmock/gmock.h>
#include "db.h"
#include "person.h"

struct databaseShould : public testing::Test
{

    VectorEngine VEngine;
    Database d{VEngine};
    //int d(int);
};

TEST_F(databaseShould, classDatabaseShouldGetAnInstance)
{
   // Database d;


    EXPECT_EQ(d.getSize(), 0);
}

TEST_F(databaseShould, classDatabaseShouldReturnNumberOfInstance)
{
//    Database d;
    Person p {"Wacek","Nowak"};
    Person p1 = p;//{"Wacek","Nowak"};
    //Person p2 {"Wacek","Nowak"};


    d.addPerson(p);
    d.addPerson(p1);

    EXPECT_EQ(d.getSize(), 2);
}

TEST_F(databaseShould, whenPushTwoPersonsGetIdShouldReturn2)
{
    using namespace ::testing;


    MockEngine me;
    Database d(me);
    Person p {"Wacek","Nowak"};
    Person p1 {"Wacek","Nowak"};

    EXPECT_CALL(me,add(_,1));
    EXPECT_CALL(me,add(_,2));
    EXPECT_CALL(me,getSize()).Times(2).WillOnce(Return(1234)).WillOnce(Return(12));

    d.addPerson(p);
    d.addPerson(p1);
 //   EXPECT_EQ(p1.getMagicNumber(),2);
   // EXPECT_EQ(p.getMagicNumber(),1);

    EXPECT_EQ(d.getSize(), 1234);
    EXPECT_EQ(d.getSize(), 12);
}




TEST_F(databaseShould, classDatabaseShouldSearchPerson)
{
   Person p {"Wacek","Nowak"};
    d.addPerson(p);
    auto result = d.search("Nowak");

    EXPECT_EQ(result.size(),1);
    //EXPECT_EQ(result.front().get().getName(),"Wacek");
    EXPECT_EQ(static_cast<const Person&>(result.front()).getName(),"Wacek");
}

TEST_F(databaseShould, classDatabaseShouldReadFromStream)
{
    std::string data = "Wacek Nowak\n Jan Kowalski\n Janina Janinowska";
    std::stringstream dataStream(data);
    EXPECT_TRUE(d.readFromStream(dataStream));

    auto result = d.search("Nowak");
    EXPECT_EQ(result.size(), 1);
    result = d.search("Janinowska");
    EXPECT_EQ(result.size(), 1);
}

TEST_F(databaseShould, classDatabaseShoduldSearchPerson)
{
   Person p {"Wacek","Nowak"};
    d.addPerson(p);
  //  auto result = d.search("Nowak");
    std::stringstream output;
    d.writeToStream(output);

    EXPECT_EQ(output.str(),"sdf");
    //EXPECT_EQ(result.front().get().getName(),"Wacek");
   // EXPECT_EQ(static_cast<const Person&>(result.front()).getName(),"Wacek");
}

