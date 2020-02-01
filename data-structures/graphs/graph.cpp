#include "./include/graph.hpp"
#include <algorithm>

graph::graph() : size(0) {}

void
graph::insert(int node)
{
  if (vertices_.find(node) != vertices_.end()) return;

  vertices_[node] = std::vector<edge *>();
}

void 
graph::insert(int node, int neighbor)
{
  insert(node, neighbor, 0);
}

void
graph::insert(int node, int neighbor, int weight)
{
  edge *e;
  
  insert(node);
  for (auto edge : vertices_[node]) {
    if (edge->dst == neighbor) return;
  }

  e = new edge;
  e->dst = neighbor;
  e->w = weight;

  vertices_[node].push_back(e);
}

void
graph::remove(int node)
{
  auto it = vertices_.find(node);
  if (it != vertices_.end()) {
    vertices_.erase(it);
  }
}

void
graph::remove(int node, int neighbor)
{
  if (vertices_.find(node) == vertices_.end()) return;

  vertices_[node].erase(
    std::remove_if(vertices_[node].begin(), vertices_[node].end(), [&neighbor](edge& e1) {
      return e1.dst == neighbor;
    })
  );
}

/* Too lazy to implement a BFS/DFS :b */
bool
graph::contains(int node)
{
  if (vertices_.find(node) != vertices_.end()) return true;
  for (auto v : vertices_) {
    for (auto e : v.second) {
      if (e->dst == node) return true;
    }
  }

  return false;
}