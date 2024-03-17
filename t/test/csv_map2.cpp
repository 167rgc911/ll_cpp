/*
 * =====================================================================================
 *
 *       Filename:  csv_map2.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/17/24 06:02:44
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

    std::vector<std::pair<std::map<std::string, std::string>, std::map<std::string, std::string>>> vpm_;

    std::vector<std::string> csv_text_;

    auto r = read_csv_file("files/colrowhdr.csv", csv_text_);
    retval = r;
    std::vector<std::string> k_;
    split(csv_text_.front(), ',', k_);

    const std::vector<unsigned long int> ndx {0, 1};

    std::vector<std::string> ik_;
    /* ik_.push_back(k_.at(0)); */
    retval = construct_index(k_, ndx, ik_);

    for(unsigned long int i = 1; i < csv_text_.size(); ++i)
    {
        std::vector<std::string> v_;
        split(csv_text_.at(i), ',', v_);

        std::vector<std::string> iv_;
        /* iv_.push_back(v_.at(0)); */
        retval = construct_index(v_, ndx, iv_);

        std::map<std::string, std::string> i_;
        retval = construct_map(ik_, iv_, i_);

        std::map<std::string, std::string> m_;
        retval = construct_map(k_, v_, m_);

        /* std::for_each(i_.begin(), i_.end(), */
        /*         [](const std::pair<std::string, std::string>& p_) */
        /*             { std::cout << "index \t" << p_.first << '\t' << p_.second << '\n'; }); */
        /* std::for_each(m_.begin(), m_.end(), */
        /*         [](const std::pair<std::string, std::string>& p_) */
        /*             { std::cout << "row \t" << p_.first << '\t' << p_.second << '\n'; }); */

        vpm_.emplace_back(std::make_pair(i_, m_));
    }

    std::for_each(vpm_.begin(), vpm_.end(),
            [](const std::pair<std::map<std::string, std::string>, std::map<std::string, std::string>>& p_)
                {
                    std::map<std::string, std::string> f_ = p_.first;
                    std::map<std::string, std::string> s_ = p_.second;
                    std::cout << "index \t";
                    std::for_each(f_.begin(), f_.end(),
                            [](const std::pair<std::string, std::string>& pf_)
                                { std::cout << " " << pf_.first << ": " << pf_.second; });
                    std::cout << " row \t";
                    std::for_each(s_.begin(), s_.end(),
                            [](const std::pair<std::string, std::string>& ps_)
                                { std::cout << " " << ps_.first << ": " << ps_.second; });
                    std::cout << '\n';
                });

    return retval;
}

