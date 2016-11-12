#include <gmock/gmock.h>
#include <diamond/Diamond.h>

using namespace diamond;
using testing::StrEq;

TEST(DiamondCutterShould, ReturnDiamondOfDepthOne)
{
    std::ostringstream diamond;
    diamond << "/\\" << "\n"
            <<"\\/" << "\n";
    EXPECT_THAT(diamondCutter(1), StrEq(diamond.str()));
}

TEST(DiamondCutterShould, ReturnDiamondOfDepthFive)
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
    EXPECT_THAT(diamondCutter(5), StrEq(diamond.str()));
}

TEST(DiamondCutterShould, ReturnEmptyStringForDepthZero)
{
    EXPECT_THAT(diamondCutter(0), StrEq(""));
}