/*
 * =====================================================================================
 *
 *       Filename:  cons.cpp
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
    testAA aa("p0", "p1");
    aa.print("init");

    auto s1 = aa["param0"];
    std::cout << std::endl << s1 << '\n';
    aa.print("operator[]");

    auto s2 = aa.param1;
    std::cout << std::endl << s2 << '\n';
    aa.print("member param1 ");

    auto s3 = aa.param0;
    std::cout << std::endl << s3 << '\n';
    aa.print("member param0 ");

    return 0;
}
