#include "Arena.h"
#include <cstring>
namespace KEngine {

	Arena::Arena(u64 size) {
		sys_assert(sys_allocate_block(size, &mData) == Status::Success);

		mSize			= size;
		mStackPointer	= mData;
		mCurrentlyUsed	= 0;
	}

	Arena::~Arena() {
		sys_assert(sys_deallocate_block(mData) == Status::Success);
	}

	void KEngine::Arena::clear() {
		memset(mData, 0, mSize);
		mStackPointer	= mData;
		mCurrentlyUsed	= 0;
	}
}
