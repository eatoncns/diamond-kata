#include <diamond/Diamond.h>
#include "DiamondInternals.h"


namespace diamond
{
    std::string buildDiamond(const unsigned int iDepth)
    {
        std::string upperHalf = buildUpperDiamond(iDepth);
        std::string lowerHalf = mirrorDiamondHalf(upperHalf);
        return upperHalf + lowerHalf;
    }
}