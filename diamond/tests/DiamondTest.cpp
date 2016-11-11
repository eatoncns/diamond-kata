#include <gmock/gmock.h>
#include <diamond/Diamond.h>

using namespace diamond;
using testing::StrEq;

TEST(EdgesForRowShould, ReturnEdgesSeparatedByTwiceTheRowNumberSpaces)
{
    std::map<unsigned int, std::string> expectedResults =
            {{0, "/\\"},
             {1, "/  \\"},
             {6, "/            \\"}};

    for (auto inOutPair : expectedResults)
    {
        EXPECT_THAT(edgesForRow(inOutPair.first), StrEq(inOutPair.second));
    }
}