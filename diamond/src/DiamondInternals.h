#ifndef DIAMOND_CUTTER_DIAMONDINTERNALS_H
#define DIAMOND_CUTTER_DIAMONDINTERNALS_H

#include <string>

namespace diamond
{
    std::string edgesForRow(unsigned int iRow);

    std::string padEdgesToWidth(unsigned int iWidth, const std::string& iEdges);

    std::string buildUpperDiamond(unsigned int iDepth);

    std::string mirrorDiamondHalf(const std::string& iDiamondHalf);
}

#endif //DIAMOND_CUTTER_DIAMONDINTERNALS_H
