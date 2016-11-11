#include <diamond/Diamond.h>

namespace diamond
{
    std::string edgesForRow(unsigned int iRow)
    {
        return "/" + std::string(iRow*2, ' ') + "\\";
    }

    std::string centreWithWidth(unsigned int, const std::string& iOriginal)
    {
        return "abc";
    }
}