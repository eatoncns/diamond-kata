#include "StringUtils.h"
#include <sstream>

namespace diamond
{
    void split(const std::string& iString, const char iDelimeter, std::vector<std::string>& oElems)
    {
        std::stringstream ss;
        ss.str(iString);
        std::string elem;
        while (std::getline(ss, elem, iDelimeter)) {
            oElems.push_back(elem);
        }
    }
}