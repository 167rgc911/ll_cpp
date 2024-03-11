/*
 * =====================================================================================
 *
 *       Filename:  cons2.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/08/24 21:31:25
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
    AA<std::string, std::string> aa("p0", "p1");
    aa.print("init aa ");

    AA<std::string, std::string> bb("q0", "q1");
    bb.print("init bb ");

    if (! (bb == aa))
    {
        std::cout << "bb != aa" << '\n';
    }

    return 0;
}

