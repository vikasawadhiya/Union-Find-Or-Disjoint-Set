# Union-Find / Disjoint-Set

<p align="justify">
Union-Find or Disjoint-Set is an implicit forest (trees) data structure. It contains disjoint sets as trees where the root 
of a tree uniquely identify the set and used as a representative of the set. As an implicit forest/group of trees data structure, 
nodes are not used to represent the trees rather indices are used to maintain the parent-child relationship.

To find the set an element belongs to or to union/merge two sets requires almost $O(1)$ constant time complexity. To insert 
an element/set requires $O(1)$ constant time complexity in best case and $O(n)$ linear time complexity in worst case.

Union-Find/Disjoint-Set data structure requires $O(n)$ linear space complexity.
</p>

## Tutorial Document

<p align="justify">
Tutorial document 
<a href="https://github.com/vikasawadhiya/Union-Find-Or-Disjoint-Set/blob/main/UnionFind.pdf">UnionFind.pdf</a> 
explains data structure in detail. The tutorial document begins with introduction then explains how union-find
data structure is different from Red-Black tree and Hash-Table data structures. It then explains how union-find as an
implicit tree maintains the parent-child relationship among the elements.

Tutorial then discuss union/merge operation by explaining how Rank and Size based optimization are used for optimal merge of sets. 
Then it discuss find operation and also explains how find operation applies branch compression/flatting optimization technique in 
each call.

This document doesn't require any programming background to understand.
</p>

## Usage

<p align="justify">
Implementation can be used by initializing union-find/disjoint-set data structure. 
</p>

#### Object Initialization

<p align="justify">
Union-Find or Disjoint-Set data structure can be initialize by parameterized constructor by passing the number of elements 
or initial number of sets as a parameter. The rank based merge optimization is used as default but can be changed by passing the 
required optimization operation as a second parameter to the constructor.
</p>

```cpp
graphLibrary::DisjointSet disSet = graphLibrary::DisjointSet(13, graphLibrary::DisjointSet::MergeOptimization::Size);
```

#### Union/Merge operations

To merge the sets represented by element $0$ and by element $1$.

```cpp
bool mergeStatus = disSet.merge(0, 1);
```

It returns true if merge succeeds otherwise returns false.

#### Find operations

To find the set an element belongs to,

```cpp
 std::size_t setRepresentative = disSet.find(0);
 ```

It return representative/root element of the set, element $0$ belongs to.

## Example

<p align="justify">
The following array <code lang="cpp"> arr[] = {1, 2, 5, 2, 5, 5, 5, 6, 8, 8, 11, 11, 11};</code> as an implicit tree represents an 
instance of disjoint-set. The tree view of this disjoint-set is shown in figure below.
</p>

<p align="center">
<img src="https://github.com/vikasawadhiya/Union-Find-Or-Disjoint-Set/blob/main/unionFindImage.svg" alt="Graph and Minimum spanning tree.">
</p>

## License

The code is licensed under the [MIT License](https://github.com/vikasawadhiya/Union-Find-Or-Disjoint-Set/blob/main/LICENSE).</br>
The tutorial document [UnionFind.pdf](https://github.com/vikasawadhiya/Union-Find-Or-Disjoint-Set/blob/main/UnionFind.pdf) and 
[unionFindImage.svg](https://github.com/vikasawadhiya/Union-Find-Or-Disjoint-Set/blob/main/unionFindImage.svg) 
are licensed under the [CC-BY 4.0](https://creativecommons.org/licenses/by/4.0/).