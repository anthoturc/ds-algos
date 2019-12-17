/*
 *  Implementation of a union find for elements
 *  labeled [1...n]
 *  
 *  With path compression and find by rank
 */

#pragma once

#include <cstddef>
#include <vector>

#ifndef _UNION_FIND_
#define _UNION_FIND_

class unionfind
{
public:
    unionfind(std::size_t n);

    void merge(std::size_t i, std::size_t j);
    std::size_t find(std::size_t i);

private:
    std::vector<std::size_t> parents_;
    std::vector<std::size_t> rank_;
    std::size_t numComponents_;
};

#endif /* _UNION_FIND_ */