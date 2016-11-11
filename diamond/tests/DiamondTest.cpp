#include <gmock/gmock.h>
#include <diamond/Diamond.h>

using namespace diamond;
using testing::StrEq;

TEST(EdgesForRowShould, ReturnEmptyStringForRow0)
{
    EXPECT_THAT(edgesForRow(0), StrEq(""));
}