#ifndef DIAMOND_CUTTER_STRINGUTILS_H
#define DIAMOND_CUTTER_STRINGUTILS_H

#include <string>
#include <vector>

namespace diamond
{
    void split(const std::string& iString, const char iDelimeter, std::vector<std::string>& oElems);
}

#endif //DIAMOND_CUTTER_STRINGUTILS_H
