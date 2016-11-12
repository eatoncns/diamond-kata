#include <gmock/gmock.h>
#include <diamond/Diamond.h>

using namespace diamond;
using testing::StrEq;

TEST(BuildDiamondShould, ReturnDiamondOfDepthOne)
{
    std::ostringstream diamond;
    diamond << "/\\" << "\n"
            <<"\\/" << "\n";
    EXPECT_THAT(buildDiamond(1), StrEq(diamond.str()));
}

TEST(BuildDiamondShould, ReturnDiamondOfDepthFive)
{
    std::ostringstream diamond;
    diamond << "    /\\    \n"
            << "   /  \\   \n"
            << "  /    \\  \n"
            << " /      \\ \n"
            << "/        \\\n"
            << "\\        /\n"
            << " \\      / \n"
            << "  \\    /  \n"
            << "   \\  /   \n"
            << "    \\/    \n";
    EXPECT_THAT(buildDiamond(5), StrEq(diamond.str()));
}

TEST(BuildDiamondShould, ReturnEmptyStringForDepthZero)
{
    EXPECT_THAT(buildDiamond(0), StrEq(""));
}