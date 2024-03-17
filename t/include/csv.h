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

int construct_index(const std::vector<std::string>& v, const std::vector<unsigned long int>& i, std::vector<std::string>& o);

int construct_map(const std::vector<std::string>& k, const std::vector<std::string>& v, std::map<std::string, std::string>& m);

int split(const std::string& s, char delim, std::vector<std::string>& o);

int read_csv_string(const std::string& s, std::vector<std::string>& o);
int read_csv_file(const std::string& f, std::vector<std::string>& o);

#endif

