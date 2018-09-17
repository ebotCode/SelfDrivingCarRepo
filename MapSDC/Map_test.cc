

#include "../MapSDC/Map.h"
#include "gtest/gtest.h"
#include <fstream>

namespace {

class LandmarkMapTest : public testing::Test {
protected:

virtual void SetUp(){
  testFileName_ = "TestData/landmarks1.txt";
  std::fstream inputfile2;
  inputfile2.open(testFileName_);
  map2_.ReadLandmarkFromFile(inputfile2);

}
std::string testFileName_;
Map::LandmarkMap map1_;
Map::LandmarkMap map2_;
Map::LandmarkMap map3_;

};



// Tests the Default Constructor Initialization
TEST_F(LandmarkMapTest, ConstructorInitialisation) {


  EXPECT_EQ(0,map1_.pLandmarks.size());

}

TEST_F(LandmarkMapTest, ReadingLandmarkFromFile){
  EXPECT_EQ(4, map2_.pLandmarks.size());

  // Test that when no file is open, it returns false. 
  std::fstream inputfile; 
  EXPECT_EQ(Flag::FILE_NOT_OPEN,map3_.ReadLandmarkFromFile(inputfile));

  // Test that when a filse is open, it returns true; 
  std::fstream inputfile2;
  inputfile2.open(testFileName_);
  ASSERT_TRUE(inputfile2.is_open());
  EXPECT_EQ(Flag::READ_FILE_SUCCESSFUL,map3_.ReadLandmarkFromFile(inputfile2));

}

}