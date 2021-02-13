#pragma once
#include <vector>
#include "DWT.h"

class CTests
{
	static void testDWT2D() {
		
		std::vector<double> testvec = {1,2,3,4, 1,2,3,4} ;
		std::vector<int> dims = { 2,4 };
		wvlet = Daublets(4);
		wtn(testvec, dims, 1, wvlt);

	};
};

