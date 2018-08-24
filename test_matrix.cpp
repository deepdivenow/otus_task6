//
// Created by dro on 24.08.18.
//

#include <string>
#include "gtest/gtest.h"
#include "Matrix.h"

using namespace std;

TEST (Matrix, SetValue){
    Matrix<int,-1> m;
    m[1][2]=5;
    EXPECT_EQ(m[1][2],5);
    EXPECT_EQ(m.size(),1);
}
TEST (Matrix, GetDefaultValue){
    Matrix<int,-2> m;
    EXPECT_EQ(m[1][2],-2);
    EXPECT_EQ(m.size(),0);
}
TEST (Matrix, SetDefaultValue){
    Matrix<int,-3> m;
    m[1][2]=5;
    EXPECT_EQ(m[1][2],5);
    m[1][2]=-3;
    EXPECT_EQ(m[1][2],-3);
    EXPECT_EQ(m.size(),0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}