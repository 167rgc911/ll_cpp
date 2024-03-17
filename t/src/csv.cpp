/*
 * =====================================================================================
 *
 *       Filename:  csv.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/16/24 08:06:29
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  rgc (rgc), sessyargc.jp@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#include <map>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>
#include <algorithm>

#define _STRINGIFY(x) #x
#define STRINGIFY(x) _STRINGIFY(x)

int construct_index(
            const std::vector<std::string>& v,
            const std::vector<unsigned long int>& i,
            std::vector<std::string>& o
        )
{
    int retval = 0;

    for(auto& i_ : i)
    {
        o.push_back(v.at(i_));
    }

    return retval;
}

int construct_map(
            const std::vector<std::string>& k,
            const std::vector<std::string>& v,
            std::map<std::string, std::string>& m
        )
{
    int retval = 0;

    std::vector<std::pair<std::string, std::string>> vp;
    vp.reserve(k.size());
    std::transform(k.begin(), k.end(), v.begin(), std::back_inserter(vp),
            [](std::string k, std::string v)
                { return std::make_pair(k, v); });

    for (auto& p : vp)
    {
        /* m_[p_.first] = p_.second; */
        m.insert(p);
    }

    return retval;
}

int split(
            const std::string& s,
            const char delim,
            std::vector<std::string>& o
        )
{
    int retval = 0;
    std::istringstream ss_(s);
    for(std::string l; std::getline(ss_, l, delim);)
    {
        o.push_back(l);
    }
    /* std::cout << o.size() << '\n'; */
    return retval;
}

int read_csv_string(
            const std::string& s,
            std::vector<std::string>& o
        )
{
    int retval = 0;
    retval = split(s, '\n', o);
    return retval;
}

int read_csv_file(
            const std::string& f,
            std::vector<std::string>& o
        )
{
    int retval = 0;

    /* std::string root_ = STRINGIFY(SOURCE_ROOT); */
    std::string root_ = SOURCE_ROOT; // cmake-3.28.3
    std::string fn_ = root_ + "/" + f;
    /* std::cout << '\t' << fn_ << '\n'; */

    std::ifstream ifs_{fn_, std::ios::ate};
    if (ifs_.is_open())
    {
        auto sz_= ifs_.tellg();
        ifs_.seekg(0, std::ios::beg);
        /* std::cout << '\t' << sz_ << '\n'; */

        std::string s_(sz_, '\0');
        ifs_.read(&s_[0], sz_);

        retval = read_csv_string(s_, o);

        /* for(std::string l; std::getline(ifs_, l);) */
        /* { */
        /*     o.push_back(l); */
        /* } */
    }
    else
    {
        std::cout << " XXX ifs_.is_open()" << fn_ << '\n';
        retval = -1;
    }

    return retval;
}

