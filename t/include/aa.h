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
#include <iostream>

typedef std::map<std::string, std::string> aa;

class testAA
{
    aa aa_;
public:
    const std::string& param0;
    const std::string& param1;

    testAA(const std::string& p0, const std::string& p1)
        :
            param0(p0),
            param1(p1)
    {
        aa_.insert( {"param0", p0} );
        aa_.insert( {"param1", p1} );
    };

    const std::string& operator[](const std::string& p)
    {
        return aa_.at(p);
        /* if (! aa_.empty()) */
        /* { */
        /*     auto s = aa_.find(p); */
        /*     if (s != aa_.end()) */
        /*     { */
        /*         return s->second; */
        /*     } */
        /* } */
        /* return {}; */
    };

    void print(const std::string comment)
    {
        std::cout << comment << "{";
            for (const auto &pair : aa_)
                std::cout << "{" << pair.first << ": " << pair.second << "}";
            std::cout << "}\n";
    };
};

#endif
