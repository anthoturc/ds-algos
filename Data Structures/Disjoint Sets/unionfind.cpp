#include "./include/unionfind.hpp"

unionfind::unionfind(std::size_t n) : numComponents_(n) 
{
    rank_.resize(n+1, 1);
    parents_.resize(n+1);

    for (std::size_t i = 0; i < n+1; ++i) {
        parents_[i] = i;
    }
}

std::size_t
unionfind::find(std::size_t i)
{
    
    if (i != parents_[i]) {
        parents_[i] = find(parents_[i]);
    }

    return parents_[i];
}

void
unionfind::merge(std::size_t i, std::size_t j)
{
    auto iPar = find(i);
    auto jPar = find(j);

    if (iPar == jPar) return;

    if (rank_[iPar] > rank_[jPar]) {
        parents_[jPar] = parents_[iPar];
    } else if (rank_[iPar] < rank_[jPar]) {
        parents_[iPar] = parents_[jPar];
    } else {
        parents_[iPar] = parents_[jPar];
        rank_[jPar] += rank_[iPar];
    }
    --numComponents_;
}