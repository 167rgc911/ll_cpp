/*
 * =====================================================================================
 *
 *       Filename:  csv_map.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/16/24 10:00:19
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
#include <map>
#include <algorithm>

#include "csv.h"

int main(void)
{
    int retval = 0;

    std::vector<std::string> csv_text_;

    auto r = read_csv_file("files/formap.csv", csv_text_);
    retval = r;
    std::vector<std::string> k_;
    std::vector<std::string> v_;

    split(csv_text_.front(), ',', k_);
    split(csv_text_.back(), ',', v_);

    std::vector<std::pair<std::string, std::string>> vp_;
    vp_.reserve(k_.size());
    std::transform(k_.begin(), k_.end(), v_.begin(), std::back_inserter(vp_),
            [](std::string k, std::string v)
                { return std::make_pair(k, v); });

    std::map<std::string, std::string> m_;
    for (auto& p_ : vp_)
    {
        /* m_[p_.first] = p_.second; */
        m_.insert(p_);
    }

    /* for (const auto& p_ : m_) */
    /* { */
    /*     std::cout << '\t' << p_.first << '\t' << p_.second << '\n'; */
    /* } */

    std::for_each(m_.begin(), m_.end(),
            [](const std::pair<std::string, std::string>& p_)
                { std::cout << '\t' << p_.first << '\t' << p_.second << '\n'; });

    return retval;
}

