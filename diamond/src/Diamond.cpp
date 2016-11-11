#include <diamond/Diamond.h>

namespace diamond
{
    std::string edgesForRow(unsigned int iRow)
    {
        if (iRow == 0)
        {
            return "";
        }
        return "/\\";
    }
}