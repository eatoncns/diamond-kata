#include <diamond/Diamond.h>

namespace diamond
{
    std::string edgesForRow(unsigned int iRow)
    {
        return "/" + std::string(iRow*2, ' ') + "\\";
    }

    std::string padEdgesToWidth(unsigned int iWidth, const std::string& iEdges)
    {
        const int remainingSpace = iWidth - iEdges.length();
        const int paddingNum = remainingSpace / 2;
        return std::string(paddingNum, ' ') + "/\\" + std::string(paddingNum, ' ');
    }
}