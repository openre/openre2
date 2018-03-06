/*
 * index.cpp
 *
 *  Created on: 07.11.2017
 *      Author: Dmitrii Boiarshinov
 */

#include "index.hpp"
#include "types.hpp"
// uncomment to disable assert()
// #define NDEBUG
#include <cassert>
#include <string>
#include <iostream>

namespace openre {

Index::Index(){

}

Index::~Index(){

}

/*
 * a_tail - connection tail
 * a_head - connection head (tail -> head - directed connection)
 * return - void
 * Example:
 * tail = [5, 1, 2, 3, undef] contains an id of the connection (index in to and list)
 * heads   = [10, 12,    11,    100,   2, 3    ] contains heads
 * next = [undef,  undef, undef, undef, 0, 4] conains next element in list
 * size = 5
 * connections (tail --> head):
 *      0 --> 10
 *      0 --> 2
 *      0 --> 3
 *      1 --> 12
 *      2 --> 11
 *      3 --> 100
 *      4 --> not connected
 *
 * */
void Index::add(address a_tail, address a_head){
    tail_to_heads[a_tail].insert(a_head);
}

void Index::rebuild(){
    // put all back to map
    address tail_address = 0;
    for(t_tail tail: tails){
        for(address i = 0; i < tail.heads_count; i++){
            tail_to_heads[tail_address].insert(
                heads[tail.heads_start + i].head
            );
        }
        tail_address++;
    }
    // find max tail
    address max_tail = 0;
    bool was_element = false;
    for (auto pair: tail_to_heads){
        was_element = true;
        max_tail = pair.first > max_tail ? pair.first : max_tail;
    }
    // resize index arrays according to max tail
    heads.resize(0);
    if(!was_element){
        tails.resize(0);
        return;
    }
    tails.resize(max_tail+1, {undef, 0});
    // fill arrays back
    for (address tail_address = 0; tail_address <= max_tail; tail_address++){
        tails[tail_address] = {undef, 0};
        if (!tail_to_heads.count(tail_address))
            continue;
        tails[tail_address].heads_count = tail_to_heads[tail_address].size();
        if (!tails[tail_address].heads_count){
            tail_to_heads.erase(tail_address);
            continue;
        }
        tails[tail_address].heads_start = heads.size();
        for(address head: tail_to_heads[tail_address]){
            heads.push_back({head});
        }
        tail_to_heads.erase(tail_address);
    }
}

string Index::str_dict(){
    string ret;
    ret += "{\n";
    for (auto pair: tail_to_heads){
        ret += "    " + to_string(pair.first) + ": [";
        for (auto value: pair.second){
            ret += to_string(value) + ",";
        }
        ret += "],\n";
    }
    ret += "}\n";
    return ret;
}

string Index::str(){
    string ret;
    ret += "{\n";
    address tail_address = 0;
    for (t_tail tail: tails){
        ret += "    " + to_string(tail_address) + ": [";
        for (address i = 0; i < tail.heads_count; i++){
            ret += to_string(heads[tail.heads_start + i].head) + ",";
        }
        ret += "],\n";
        tail_address++;
    }
    ret += "}\n";
    return ret;
}

const t_tail* Index::get_tails(){
    return &tails[0];
}

address Index::tails_count(){ return tails.size(); }

const t_head* Index::get_heads(){
    return &heads[0];
}

address Index::heads_count(){ return heads.size(); }

} /* namespace openre */
