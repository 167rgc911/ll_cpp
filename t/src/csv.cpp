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
#include <memory>

std::shared_ptr<std::vector<std::string>> construct_index(
            const std::shared_ptr<std::vector<std::string>>& v,
            const std::vector<unsigned long int>& i,
            int& retval
        )
{
    retval = 0;

    std::shared_ptr<std::vector<std::string>> ov =
        std::make_shared<std::vector<std::string>>();

    for(auto& i_ : i)
    {
        ov->push_back(v->at(i_));
    }

    return ov;
}

std::shared_ptr<std::map<std::string, std::string>> construct_map(
            const std::shared_ptr<std::vector<std::string>>& c,
            int& retval
        )
{
    retval = 0;

    return nullptr;
}

std::shared_ptr<std::map<std::string, std::string>> construct_map(
            const std::shared_ptr<std::vector<std::string>>& k,
            const std::shared_ptr<std::vector<std::string>>& v,
            int& retval
        )
{
    retval = 0;

    std::shared_ptr<std::map<std::string, std::string>> om =
        std::make_shared<std::map<std::string, std::string>>();

    std::vector<std::pair<std::string, std::string>> vp;
    vp.reserve(k->size());
    std::transform(k->begin(), k->end(), v->begin(), std::back_inserter(vp),
            [](std::string k, std::string v)
                { return std::make_pair(k, v); });

    for (auto& p : vp)
    {
        /* m_[p_.first] = p_.second; */
        om->insert(p);
    }

    return om;
}

std::shared_ptr<std::vector<std::string>> split(
            const std::string& s,
            const char delim,
            int& retval
        )
{
    retval = 0;

    std::shared_ptr<std::vector<std::string>> ov =
        std::make_shared<std::vector<std::string>>();

    std::istringstream ss_(s);
    for(std::string l; std::getline(ss_, l, delim);)
    {
        ov->push_back(l);
    }
    /* std::cout << o.size() << '\n'; */

    return ov;
}

std::shared_ptr<std::vector<std::string>> read_csv_string(
            const std::string& s,
            int& retval
        )
{
    retval = 0;

    return split(s, '\n', retval);
}

std::shared_ptr<std::vector<std::string>> read_csv_file(
            const std::string& f,
            int& retval
        )
{
    retval = 0;

    /* std::string root_ = STRINGIFY(SOURCE_ROOT); */
    std::string root_ = SOURCE_ROOT; // cmake-3.28.3
    std::string fn_ = root_ + "/" + f;
    /* std::cout << '\t' << fn_ << '\n'; */

    std::shared_ptr<std::vector<std::string>> ov;

    std::ifstream ifs_{fn_, std::ios::ate};
    if (ifs_.is_open())
    {
        auto sz_= ifs_.tellg();
        ifs_.seekg(0, std::ios::beg);
        /* std::cout << '\t' << sz_ << '\n'; */

        std::string s_(sz_, '\0');
        ifs_.read(&s_[0], sz_);

        ov = read_csv_string(s_, retval);
    }
    else
    {
        std::cout << " XXX ifs_.is_open()" << fn_ << '\n';
        retval = 1;
    }

    ifs_.close();

    return ov;
}

