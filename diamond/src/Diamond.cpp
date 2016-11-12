#include <diamond/Diamond.h>
#include <assert.h>

namespace diamond
{
    std::string edgesForRow(unsigned int iRow)
    {
        return "/" + std::string(iRow*2, ' ') + "\\";
    }

    std::string padEdgesToWidth(unsigned int iWidth, const std::string& iEdges)
    {
        const int remainingSpace = iWidth - iEdges.length();
        assert(remainingSpace%2 == 0);
        if (remainingSpace <= 0)
        {
            return iEdges;
        }
        const int paddingNum = remainingSpace / 2;
        return std::string(paddingNum, ' ') + iEdges + std::string(paddingNum, ' ');
    }

    std::string buildUpperDiamond(unsigned int)
    {
        return "/\\\n";
    }
}