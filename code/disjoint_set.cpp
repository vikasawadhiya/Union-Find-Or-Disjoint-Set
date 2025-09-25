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

#include "disjoint_set.hpp"
#include "disjoint_set_imp.hpp"

using namespace std;

namespace graphLibrary {

	DisjointSet::DisjointSet(std::size_t elementCount, MergeOptimization mergOpt):
		imp(MergeOptimization::Rank == mergOpt ?
			unique_ptr<DisjointSetImp>(new DisjointSetRankImp(elementCount) ) :
			unique_ptr<DisjointSetImp>(new DisJointSetSizeImp(elementCount) ) )	{

	}

	DisjointSet::~DisjointSet() = default;

	bool DisjointSet::merge(size_t element1, size_t element2) {

		return imp->merge(element1, element2);
	}

	size_t DisjointSet::find(size_t element) const {

		return imp->find(element);
	}

	size_t DisjointSet::setCount() const {

		return imp->setCount();
	}
}
