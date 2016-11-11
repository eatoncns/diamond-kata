#include <gmock/gmock.h>
#include <diamond/Diamond.h>

using namespace diamond;
using testing::StrEq;

TEST(EdgesForRowShould, ReturnUnseparatedEdgesForRow1)
{
    EXPECT_THAT(edgesForRow(0), StrEq("/\\"));
}