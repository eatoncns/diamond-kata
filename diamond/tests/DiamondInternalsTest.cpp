#include <gmock/gmock.h>
#include <DiamondInternals.h>

using namespace diamond;
using testing::StrEq;

TEST(EdgesForRowShould, ReturnEdgeCharactersSeparatedByTwiceTheRowNumberSpaces)
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


TEST(PadEdgesToWidthShould, ReturnUnmodifiedEdgesWhenWidthAlreadyEqualToInput)
{
    EXPECT_THAT(padEdgesToWidth(2, "/\\"), StrEq("/\\"));
}

TEST(PadEdgesToWidthShould, ReturnUnmodifiedEdgesWhenWidthAlreadyMoreThanInput)
{
    EXPECT_THAT(padEdgesToWidth(2, "/  \\"), StrEq("/  \\"));
}

TEST(PadEdgesToWidthShould, PadTopLevelEdgesWithEqualSpacingOnEachSide)
{
    EXPECT_THAT(padEdgesToWidth(4, "/\\"), StrEq(" /\\ "));
}

TEST(PadEdgesToWidthShould, PadLevelOneEdgesWithEqualSpacingOnEachSide)
{
    EXPECT_THAT(padEdgesToWidth(8, "/  \\"), StrEq("  /  \\  "));
}


TEST(BuildUpperDiamondShould, BuildDepthOneUpperDiamond)
{
    EXPECT_THAT(buildUpperDiamond(1), StrEq("/\\\n"));
}

TEST(BuildUpperDiamondShould, BuildDepthTwoUpperDiamond)
{
    std::ostringstream expectedDiamond;
    expectedDiamond << " /\\ \n"
                    << "/  \\\n";
    EXPECT_THAT(buildUpperDiamond(2), StrEq(expectedDiamond.str()));
}

TEST(BuildUpperDiamondShould, BuildDepthFiveUpperDiamond)
{
    std::ostringstream expectedDiamond;
    expectedDiamond << "    /\\    \n"
                    << "   /  \\   \n"
                    << "  /    \\  \n"
                    << " /      \\ \n"
                    << "/        \\\n";
    EXPECT_THAT(buildUpperDiamond(5), StrEq(expectedDiamond.str()));
}


TEST(MirrorDiamondHalfShould, MirrorDepthOneDiamondHalf)
{
    EXPECT_THAT(mirrorDiamondHalf("/\\\n"), StrEq("\\/\n"));
}

TEST(MirrorDiamondHalfShould, MirrorDepthFiveDiamondHalf)
{
    std::ostringstream inputDiamondHalf;
    inputDiamondHalf << "    /\\    \n"
                     << "   /  \\   \n"
                     << "  /    \\  \n"
                     << " /      \\ \n"
                     << "/        \\\n";
    std::ostringstream outputDiamondHalf;
    outputDiamondHalf << "\\        /\n"
                      << " \\      / \n"
                      << "  \\    /  \n"
                      << "   \\  /   \n"
                      << "    \\/    \n";
    EXPECT_THAT(mirrorDiamondHalf(inputDiamondHalf.str()), StrEq(outputDiamondHalf.str()));
}