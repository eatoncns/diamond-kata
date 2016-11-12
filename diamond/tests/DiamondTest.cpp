#include <gmock/gmock.h>
#include <diamond/Diamond.h>

using namespace diamond;
using testing::StrEq;
using testing::ElementsAre;

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