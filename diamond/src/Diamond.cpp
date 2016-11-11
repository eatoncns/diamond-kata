#include <diamond/Diamond.h>

namespace diamond
{
    std::string edgesForRow(unsigned int iRow)
    {
        return "/" + std::string(iRow*2, ' ') + "\\";
    }
}