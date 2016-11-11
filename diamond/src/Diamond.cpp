#include <diamond/Diamond.h>

namespace diamond
{
    std::string edgesForRow(unsigned int iRow)
    {
        return "/" + std::string(iRow*2, ' ') + "\\";
    }

    std::string padEdgesToWidth(unsigned int, const std::string& iEdges)
    {
        return "/\\";
    }
}