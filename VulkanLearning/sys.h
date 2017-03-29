#pragma once
#include <cstdint>

namespace KEngine::Sys {

	/**
	* This is a top level file and we'll include all of our top level stuff here for now...
	*/
	//Numeric typdefs
	typedef int8_t		i8;
	typedef int16_t		i16;
	typedef int32_t		i32;
	typedef int64_t		i64;
	typedef uint8_t		u8;
	typedef uint16_t	u16;
	typedef uint32_t	u32;
	typedef uint64_t	u64;
	typedef float		f32;
	typedef double		f64;
	typedef u8			byte;

	constexpr u64 Kilobytes(u64 n);
	constexpr u64 Megabytes(u64 n);
	constexpr u64 Gigabytes(u64 n);
	constexpr u64 Terabytes(u64 n);

	void sys_assert(bool predicate);
	enum class Status {
		Success,
		Failure
	};
	/*
	Allocate a large block of memory
	*/
	Status sys_allocate_block(u64 num_bytes, byte** out);
	Status sys_deallocate_block(byte* block);





}