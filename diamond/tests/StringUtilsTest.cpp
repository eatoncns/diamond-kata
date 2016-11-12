#include <gmock/gmock.h>
#include <StringUtils.h>

using namespace diamond;
using testing::ElementsAre;

TEST(SplitShould, AddInputStringToElemsWhenDelimeterNotPresent)
{
    std::vector<std::string> elems;
    split("Hello World!", '\n', elems);
    EXPECT_THAT(elems, ElementsAre("Hello World!"));
}

TEST(SplitShould, PopulateElemsWithSubstringsSeparatedByDelimiter)
{
    std::vector<std::string> elems;
    split("Oh no.\nNot again!\n", '\n', elems);
    EXPECT_THAT(elems, ElementsAre("Oh no.", "Not again!"));
}