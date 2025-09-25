/*********************************************************************************
** MIT License
**
** Copyright (c) 2025 Vikas Awadhiya
**
** Permission is hereby granted, free of charge, to any person obtaining a copy
** of this software and associated documentation files (the "Software"), to deal
** in the Software without restriction, including without limitation the rights
** to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
** copies of the Software, and to permit persons to whom the Software is
** furnished to do so, subject to the following conditions:

** The above copyright notice and this permission notice shall be included in all
** copies or substantial portions of the Software.

** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
** IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
** FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
** AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
** OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
** SOFTWARE.
*********************************************************************************/

#include "disjoint_set_imp.hpp"

#include <stack>

using namespace std;

namespace graphLibrary {

	DisjointSetImp::DisjointSetImp(size_t elementCount) :
		numOfSets(elementCount),
		parent(elementCount),
		rankOrSize(elementCount) {

		for (size_t i = 0; i < elementCount; ++i) {

			parent[i] = i;
		}
	}

	DisjointSetImp::~DisjointSetImp() {

	}

	size_t DisjointSetImp::find(size_t element) const {

		if ( element == parent.at(element) ) {

			return element;
		}

		std::stack< size_t, vector<size_t> > elementStack;

		while (element != parent[element]) {

			elementStack.push(element);

			element = parent[element];
		}

		size_t rootElement = element;

		if (elementStack.size() > 1) {

			do {
				element = elementStack.top();
				elementStack.pop();

				parent[element] = rootElement;

			} while ( !elementStack.empty() );
		}

		return rootElement;
	}

	size_t DisjointSetImp::setCount() const {

		return numOfSets;
	}


	DisjointSetRankImp::DisjointSetRankImp(size_t elementCount) : DisjointSetImp(elementCount) {

	}

	bool DisjointSetRankImp::merge(size_t element1, size_t element2) {

		size_t rootElement1 = find(element1);
		size_t rootElement2 = find(element2);

		if (rootElement1 == rootElement2) {

			return false;
		}

		if (rankOrSize[rootElement1] == rankOrSize[rootElement2]) {

			parent[rootElement1] = rootElement2;
			rankOrSize[rootElement2] += 1;
		}
		else if (rankOrSize[rootElement1] < rankOrSize[rootElement2]){

			parent[rootElement1] = rootElement2;
		}
		else {
			parent[rootElement2] = rootElement1;
		}

		--numOfSets;

		return true;
	}

	DisJointSetSizeImp::DisJointSetSizeImp(size_t elementCount): DisjointSetImp(elementCount) {

		for (auto it = rankOrSize.begin(); rankOrSize.end() != it; ++it) {

			*it = 1;
		}
	}

	bool DisJointSetSizeImp::merge(size_t element1, size_t element2) {

		size_t rootElement1 = find(element1);
		size_t rootElement2 = find(element2);

		if (rootElement1 == rootElement2) {

			return false;
		}

		if (rankOrSize[rootElement1] <= rankOrSize[rootElement2]) {

			parent[rootElement1] = rootElement2;
			rankOrSize[rootElement2] += rankOrSize[rootElement1];
		}
		else {
			parent[rootElement2] = rootElement1;
			rankOrSize[rootElement1] += rankOrSize[rootElement2];
		}

		--numOfSets;

		return true;
	}
}
