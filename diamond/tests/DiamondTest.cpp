#include <gmock/gmock.h>
#include <diamond/Diamond.h>

using namespace diamond;
using testing::StrEq;

TEST(EdgesForRowShould, ReturnEdgesSeparatedByTwiceTheRowNumberSpaces)
{
    EXPECT_THAT(edgesForRow(0), StrEq("/\\"));
    EXPECT_THAT(edgesForRow(1), StrEq("/  \\"));
    EXPECT_THAT(edgesForRow(6), StrEq("/            \\"));
}