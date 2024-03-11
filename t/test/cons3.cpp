/*
 * =====================================================================================
 *
 *       Filename:  cons3.cpp
 *
 *    Description:  
 *
 *        Version:  0.1
 *        Created:  03/11/24 17:42:25
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  rgc (rgc), sessyargc.jp@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>

#include "aa.h"

int main(void)
{
    std::pair<std::string, std::string> p("p0", "p1");
    AA<std::string, std::string> aa(p);
    aa.print("init aa ");

    AA<std::string, std::string> bb("p0", "p1");
    bb.print("init bb ");

    if (bb == aa)
    {
        std::cout << "bb == aa" << '\n';
    }

    return 0;
}

