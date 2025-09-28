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

#include <iostream>

#include "disjoint_set.hpp"

using namespace std;
using namespace graphLibrary;

/// @brief It resembles the Union-Find / Disjoint-Set data structure 
/// shown in figure 13 of tutorial document.
/// 
/// @param dis A disjoint-set.
/// 
void mergeSetsAsTutorialFig13(DisjointSet& dis) {

	dis.merge(0, 1);
	dis.merge(2, 3);
	dis.merge(4, 5);
	dis.merge(7, 6);
	dis.merge(8, 9);
	dis.merge(10, 11);

	dis.merge(1, 2);
	dis.merge(6, 5);
	dis.merge(11, 12);

	dis.merge(2, 5);
}

int main(int , char*[]) {

	/// A disjoint-set with total 13 elements.
	/// 
	DisjointSet dis(13);

	mergeSetsAsTutorialFig13(dis);

	size_t setRepresentative = dis.find(0);

	cout << "Element 0 belongs to the set represented by element " << setRepresentative << "." << endl;
}