#pragma once
#include "sys.h"
#include <type_traits>
namespace KEngine {
	using namespace Sys;
	class Arena {
	public:
				Arena(u64 size);
				~Arena();
		template<typename T>
		T*		push(u64 num_objects = 1);
		void	clear();
	private:
		byte*	mData;
		byte*	mStackPointer;
		u64		mSize;
		u64		mCurrentlyUsed;
	};
	template<typename T>
	inline T * Arena::push(u64 num_objects) {
		sys_assert(num_objects > 0);
		sys_assert(mCurrentlyUsed + sizeof(T)*num_objects < mSize);
		sys_assert(std::is_pod<T>());
		auto temp = mStackPointer;
		mStackPointer += sizeof(T)*num_objects;
		return (T*)temp;
	}
}

