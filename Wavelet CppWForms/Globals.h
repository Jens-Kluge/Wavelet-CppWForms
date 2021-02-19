#pragma once
#include "Utilities.h"

namespace Excel = Microsoft::Office::Interop::Excel;

ref class GlobalVars
{
public:
	static Excel::Application^ g_Excel = nullptr;
	static cli::array<double>^ g_Signal;
	static cli::array<double>^ g_DWT;
	static cli::array<int, 2>^ g_Image;
	static cli::array<double, 2>^ g_2DDWT;

	static int g_SelWvlet = (int)enWavelets::Daubechies2;
};

