#include "sys.h"
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <cassert>
namespace KEngine::Sys {

	constexpr u64 Kilobytes(u64 n) {
		return 1024ul * n;
	}
	constexpr u64 Megabytes(u64 n) {
		return 1024ul * Kilobytes(n);
	}
	constexpr u64 Gigabytes(u64 n) {
		return 1024ul * Megabytes(n);
	}
	constexpr u64 Terabytes(u64 n) {
		return 1024ul * Gigabytes(n);
	}

	void sys_assert(bool predicate) {
#ifdef _DEBUG
		assert(predicate);
#endif
	}

	Status sys_allocate_block(u64 num_bytes, byte** out) {
		void* ret;

		sys_assert(num_bytes > 0);
		ret  = VirtualAlloc(NULL, num_bytes, MEM_COMMIT | MEM_RESERVE, PAGE_READWRITE);
		*out = (byte*)ret;
		if (ret)
			return Status::Success;
		return Status::Failure;
	}
	Status sys_deallocate_block(byte * block) {
		if (VirtualFree(block, 0, MEM_RELEASE))
			return Status::Success;
		return Status::Failure;
	}
}
