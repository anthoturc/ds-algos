#include "./include/graph.hpp"

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
  
}

bool
graph::contains(int node)
{

}