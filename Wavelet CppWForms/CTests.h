#pragma once
#include "DWT.h"



class CTests
{
public: static void testDWT2D() {

		std::vector<double> testvec = 
		{101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116, 
		 201,202,203,204,205,206,207,208,209,210,211,212,213,214,215,216,
		 301,302,303,304,305,306,307,308,309,310,311,312,313,314,315,316,
		 401,402,403,404,405,406,407,408,409,410,411,412,413,414,415,416,
		 501,502,503,504,505,506,507,508,509,510,511,512,513,514,515,516,
		 601,602,603,604,605,606,607,608,609,610,611,612,613,614,615,616,
		 701,702,703,704,705,706,707,708,709,710,711,712,713,714,715,716,
		 801,802,803,804,805,806,807,808,809,810,811,812,813,814,815,816
		};
		
		std::vector<int> dims = { 16, 8 };
		Daublets wvlet = Daublets(4);
		wtn(testvec, dims, 1, wvlet);
		/*
		*  access is to rows first, then to columns
		*  dimensions are expected as: first row width, then column height
		*/

	};
};

