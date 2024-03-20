/*
 * =====================================================================================
 *
 *       Filename:  csv.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  03/16/24 08:20:56
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  rgc (rgc), sessyargc.jp@gmail.com
 *   Organization:  
 *
 * =====================================================================================
 */

#pragma once

#ifndef CSV_H
#define CSV_H

#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

#define _STRINGIFY(x) #x
#define STRINGIFY(x) _STRINGIFY(x)

template <typename M, typename P>
void print_pair(
            const M& m
        )
{
    std::for_each(m.begin(), m.end(),
            [](const P& p)
                { std::cout << " " << p.first << ": " << p.second; });
}

std::shared_ptr<std::vector<std::string>> construct_index(
            const std::shared_ptr<std::vector<std::string>>& v,
            const std::vector<unsigned long int>& i,
            int& retval
        );

std::shared_ptr<std::map<std::string, std::string>> construct_map(
            const std::shared_ptr<std::vector<std::string>>& k,
            const std::shared_ptr<std::vector<std::string>>& v,
            int& retval
        );

std::shared_ptr<std::vector<std::string>> split(
            const std::string& s,
            const char delim,
            int& retval
        );

std::shared_ptr<std::vector<std::string>> read_csv_string(
            const std::string& s,
            int& retval
        );

std::shared_ptr<std::vector<std::string>> read_csv_file(
            const std::string& f,
            int& retval
        );

#endif

