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

#ifndef DISJOINT_SET_IMP
#define DISJOINT_SET_IMP

#include <vector>

namespace graphLibrary {

	/// @brief It is a base class of actually implements Union-Find / Disjoint-Set data structure.
	/// It implements implements all functionality except merge operation and the concrete classes
	/// implement merge according to the Rank and Size based merge optimization.
	/// 
	class DisjointSetImp {

	protected:
		mutable std::size_t numOfSets;
		mutable std::vector<std::size_t> parent;
		mutable std::vector<std::size_t> rankOrSize;

	public:
		/// @brief A parameterized constructor.
		/// @param elementCount It represents total number of elements or initial set count.
		/// 
		explicit DisjointSetImp(std::size_t elementCount);

		/// @brief A virtual distructor.
		virtual ~DisjointSetImp();

		/// @brief A pure virtual function specifies merge function.
		/// 
		virtual bool merge(std::size_t element1, std::size_t element2) = 0;

		/// @brief Finds the set an element belongs to.
		/// @param element An element.
		/// @return The representative of a set the element passed as a parameter belongs to.
		/// 
		std::size_t find(std::size_t element) const;

		/// @brief  Evaluate number of disjoint sets present.
		/// @return Total number of disjoint sets.
		/// 
		std::size_t setCount() const;
	};

	/// @brief It is a concrete class offers merge operation based on Rank optimization.
	/// 
	class DisjointSetRankImp : public DisjointSetImp {

	public:
		explicit DisjointSetRankImp(std::size_t elementCount);

		/// @brief Merges two sets.
		/// @param element1 A representative of a set or an element belongs to a set.
		/// @param element2 A representative of a set or an element belongs to a set.
		/// @return True if merge operation succeeds.
		/// 
		bool merge(std::size_t element1, std::size_t element2);
	};

	/// @brief It is a concrete class offers merge operation based on Size optimization.
	/// 
	class DisJointSetSizeImp : public DisjointSetImp {

	public:
		explicit DisJointSetSizeImp(std::size_t elementCount);

		/// @brief Merges two sets.
		/// @param element1 A representative of a set or an element belongs to a set.
		/// @param element2 A representative of a set or an element belongs to a set.
		/// @return True if merge operation succeeds.
		/// 
		bool merge(std::size_t element1, std::size_t element2);
	};
}

#endif // !DISJOINT_SET_IMP

