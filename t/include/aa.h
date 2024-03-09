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

template <typename T>
class testAA
{
    typedef std::map<std::string, T> aa;

    aa aa_;
    const std::string& param0_;
    const std::string& param1_;
public:
    testAA(const T& p0, const T& p1)
        :
            param0_(p0),
            param1_(p1)
    {
        aa_.insert( {"param0", p0} );
        aa_.insert( {"param1", p1} );
    };

    const T& operator[](const std::string& p)
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


    bool operator==(const testAA& other) const
    {
        return aa_ == other.aa_;
    }

    /* getters */
    const T& param0() const { return param0_; };
    const T& param1() const { return param1_; };

    void print(const std::string comment)
    {
        std::cout << comment << "{";
            for (const auto &pair : aa_)
                std::cout << "{" << pair.first << ": " << pair.second << "}";
            std::cout << "}\n";
    };
};

#endif
