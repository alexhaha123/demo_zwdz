//
//  ToolFunction.cpp
//  zwdz
//
//  Created by zhouzhan on 12/6/17.
//
//

#include "ToolFunction.h"
std::string ToolFunction::convertIntToString(const int& num)
{
    std::ostringstream stream;
    stream<<num;
    return stream.str();
}
