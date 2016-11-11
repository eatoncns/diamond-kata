#ifndef CMAKE_PROJECT_DIAMOND_H
#define CMAKE_PROJECT_DIAMOND_H

#include <string>

namespace diamond
{
    std::string edgesForRow(unsigned int iRow);

    std::string padEdgesToWidth(unsigned int iWidth, const std::string& iEdges);
}

#endif //CMAKE_PROJECT_DIAMOND_H
