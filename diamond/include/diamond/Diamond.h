#ifndef CMAKE_PROJECT_DIAMOND_H
#define CMAKE_PROJECT_DIAMOND_H

#include <string>
#include <vector>

namespace diamond
{
    std::string edgesForRow(unsigned int iRow);

    std::string padEdgesToWidth(unsigned int iWidth, const std::string& iEdges);

    std::string buildUpperDiamond(unsigned int iDepth);

    std::string mirrorDiamondHalf(const std::string& iDiamondHalf);

    void split(const std::string& iString, const char iDelimeter, std::vector<std::string>& oElems);
}

#endif //CMAKE_PROJECT_DIAMOND_H
