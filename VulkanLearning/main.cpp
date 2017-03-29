#include <cstdio>
#include "sys.h"
#include "Arena.h"

using namespace KEngine::Sys;
using namespace KEngine;
int main(int argc, char* argv[]) {
	byte* data = nullptr;
	auto status = sys_allocate_block(10000, &data);
	for (int i = 0; i < 10000; i++) {
		data[i] = 1;
	}
	sys_assert(status == Status::Success);
	sys_deallocate_block(data);

	Arena test = Arena(10000);
	auto ints = test.push<int>(1000);
	printf("Hello, world\n");
	return 0;
}




