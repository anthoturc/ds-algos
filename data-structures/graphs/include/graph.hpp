#pragma once

#ifndef _GRAPH_HPP_
#define _GRAPH_HPP_

#include <unordered_map>
#include <vector>

struct edge
{
  int dst;
  int w;
};

class graph
{
public:
  graph();

  void insert(int node);
  void insert(int node, int neighbor);
  void insert(int node, int neighbor, int weight);
  
  void remove(int node);
  void remove(int node, int neighbor);
  bool contains(int node);

private:
  int size;
  std::unordered_map<int, std::vector<edge * >> vertices_;
};

#endif /* _GRAPH_HPP_ */