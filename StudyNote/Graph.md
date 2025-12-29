# Study Note: Graph

## Description

Graph: A collection of **vertices (nodes)** connected by **edges** that model relationships between entities. Edges can be **undirected** (two-way) or **directed** (one-way), and graphs may contain **cycles** (unlike trees). Graphs are commonly used to represent real-world networks such as social connections, transportation routes, and hyperlinks on the web.  

## Graph in Discrete Mathematics

In **discrete mathematics**, a graph is defined formally as an ordered pair:

- **Undirected graph**: \(G = (V, E)\)  
    - \(V\): a **non-empty finite set** of vertices  
    - \(E \subseteq \{\{u,v\} \mid u,v \in V,\ u \neq v\}\): a set of **unordered pairs** (edges)

- **Directed graph (digraph)**: \(G = (V, E)\)  
    - \(E \subseteq V \times V\): a set of **ordered pairs** \((u,v)\) (arcs)

### Key terms
- **Adjacent vertices**: \(u\) and \(v\) are adjacent if \(\{u,v\} \in E\) (undirected) or \((u,v) \in E\) (directed)
- **Degree** (undirected): \($\deg$(v)\) = number of edges incident to \(v\)  
    **In-degree / Out-degree** (directed): \($\deg$^{-}(v)\), \($\deg^{+}(v)\)
- **Walk / Trail / Path**:
    - **Walk**: sequence of vertices where consecutive vertices are connected by edges
    - **Trail**: walk with no repeated edges
    - **Path**: walk with no repeated vertices
- **Cycle**: a path that starts and ends at the same vertex (length \($\ge$ 1\))
- **Simple graph**: no loops and no multiple edges  
    **Multigraph**: may contain multiple edges between the same vertices  
    **Pseudograph**: may contain loops

### Handshaking Lemma (undirected)
\[
$\sum_{v \in V} \deg(v) = 2|E|$
\]  
A consequence: the number of vertices with **odd degree** is **even**.

## Visualization

![Graph](./graph.wepb)
```

