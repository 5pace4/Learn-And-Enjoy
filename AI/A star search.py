from collections import deque

class Graph:
  def __init__(self, g):
    self.g = g

  def get_neighbors(self, u):
    return self.g[u]

  # heuristic
  def h(self, n):
    H = {
        'S' : 8,
        'A' : 1,
        'B' : 4,
        'C' : 3,
        'D' : 99999, # 99999 defined as infinity
        'E' : 99999,
        'G' : 0
    }
    return H[n]

  def a_star(self, u, v):
    # u -> start node & v -> stop node
    openList = set([u])
    closeList = set([])

    cost = {} # current cost of all nodes from start node
    cost[u] = 0
    parents = {}
    parents[u] = u

    while len(openList) > 0:
      n = None

      for v_ in openList:
        if n == None or cost[v_] + self.h(v_) < cost[n] + self.h(n):
          n = v_

      if n == None:
        print('Path does not exist!')
        return None


      if n == v:
        reconst_path = []
        while parents[n] != n:
          reconst_path.append(n)
          n = parents[n]

        reconst_path.append(u)
        reconst_path.reverse()

        print(f'path found: {reconst_path}')
        return reconst_path

      for (m, weight) in self.get_neighbors(n):
        if m not in openList and m not in closeList:
          openList.add(m)
          parents[m] = n
          cost[m] = cost[n] + weight

        else:
          if cost[m] > cost[n] + weight:
            cost[m] = cost[n] + weight
            parents[m] = n

            if m in closeList:
              closeList.remove(m)
              openList.add(m)


      openList.remove(n)
      closeList.add(n)

    print('path does not exist!')
    return None





# adjacency list
g = {
    'S' : [('A', 1), ('B', 5), ('C', 8)],
    'A' : [('D', 99999), ('E', 99999), ('G', 9)],
    'B' : [('G', 4)],
    'C' : [('G', 5)]
}

graph = Graph(g)
graph.a_star('S', 'G')


# Tutorial Link: https://stackabuse.com/courses/graphs-in-python-theory-and-implementation/lessons/a-star-search-algorithm/


