#include <diamond/Diamond.h>
#include <assert.h>
#include <sstream>
#include <algorithm>

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


    std::string buildUpperDiamond(unsigned int iDepth)
    {
        std::ostringstream upperDiamond;
        const unsigned int rowWidth = iDepth*2;
        for (unsigned int row = 0; row < iDepth; ++row)
        {
            upperDiamond << padEdgesToWidth(rowWidth, edgesForRow(row))
                         << "\n";
        }
        return upperDiamond.str();
    }


    void split(const std::string& iString, const char iDelimeter, std::vector<std::string>& oElems)
    {
        std::stringstream ss;
        ss.str(iString);
        std::string elem;
        while (std::getline(ss, elem, iDelimeter)) {
            oElems.push_back(elem);
        }
    }


    std::string mirrorDiamondHalf(const std::string& iDiamondHalf)
    {
        std::ostringstream mirrorDiamond;
        std::vector<std::string> rows;
        split(iDiamondHalf, '\n', rows);
        for (auto row = rows.rbegin(); row != rows.rend(); ++row)
        {
            std::reverse(row->begin(), row->end());
            mirrorDiamond << *row << "\n";
        }
        return mirrorDiamond.str();
    }
}