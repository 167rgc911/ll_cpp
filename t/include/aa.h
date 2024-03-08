/*
 * =====================================================================================
 *
 *       Filename:  aa.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/08/24 21:00:08
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  rgc (rgc), sessyargc.jp@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#pragma once
#ifndef AA_H
#define AA_H

#include <map>
#include <string>

typedef std::map<std::string, std::string> aa;

class testAA
{
    aa aa_;
    std::string p0_;
    std::string p1_;
public:
    testAA(const std::string& p0, const std::string& p1)
        : p0_(p0), p1_(p1)
    {
        aa_.insert( {"p0", p0} );
        aa_.insert( {"p1", p1} );
    };
    ~testAA();
    std::string& operator[](const std::string& p0);
};

#endif
