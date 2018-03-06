/*
 * layer.h
 *
 *  Created on: 07.11.2017
 *      Author: Dmitrii Boiarshinov
 */

#pragma once
#include <vector>
#include "types.hpp"
#include <unordered_map>
#include <unordered_set>

using namespace std;

namespace openre {

// tail.heads_start -> [heads] length is tail.heads_count
typedef struct {
    address heads_start;
    address heads_count;
} t_tail;

typedef struct {
    address head;
} t_head;

typedef unordered_map<
    address,
    unordered_set<address>
> dict;

class Index {
private:
    dict tail_to_heads;
    // heads_start_address[tail_address] points to element in heads
    vector<t_tail> tails;
    vector<t_head> heads;
public:
    Index();
    ~Index();
    void add(address a_tail, address a_head);
    // refresh index arrays from tail_to_heads
    void rebuild();
    string str_dict();
    string str();
    const t_tail* get_tails();
    address tails_count();
    const t_head* get_heads();
    address heads_count();

};

} /* namespace openre */

