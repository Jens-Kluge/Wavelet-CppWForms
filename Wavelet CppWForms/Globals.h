#pragma once
#include "Utilities.h"

namespace Excel = Microsoft::Office::Interop::Excel;

ref class GlobalVars
{
public:
	static Excel::Application^ g_Excel = nullptr;
	static cli::array<double>^ g_Signal;
	static cli::array<double>^ g_DWT;
	static int g_SelWvlet = (int)enWavelets::Daubechies2;
};

