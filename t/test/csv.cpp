/*
 * =====================================================================================
 *
 *       Filename:  csv.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/16/24 08:18:19
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  rgc (rgc), sessyargc.jp@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

#include "csv.h"

int main(void)
{
    int retval = 0;

    std::vector<std::string> csv_text_;

    auto r = read_csv_file("files/colrowhdr.csv", csv_text_);
    for(auto& line : csv_text_)
    {
        std::vector<std::string> r_;
        std::cout << line << '\n' << '\n';
        split(line, ',', r_);
        for(auto& col : r_)
        {
            std::cout << '\t' << col << '\n';
        }
    }
    retval = r;

    return retval;
}

