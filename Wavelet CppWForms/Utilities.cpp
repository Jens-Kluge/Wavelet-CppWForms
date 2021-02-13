#include "pch.h"
#include "Utilities.h"
#include "DWT.h"

int nextpow2(int x) {
	int power = 1;
	while (power < x)
		power *= 2;
	return power;
};

/* 
* nearest power of 10 (for determining tick mark spacing)
*/
int nearestpow10(int x) {
	int power = 1;
	while (power < x)
		power *= 10;
	
	if (power - x < x - power/10) {
		return power;
	}
	else {
		return power / 10;
	}
};

/*
 pad a signal with zeros
 padmode: padding at beginning, with centered signal, at the end
*/
std::vector<double> padsignal(std::vector<double> signal, int padmode) {
	int newsize = nextpow2(signal.size());
	int sizediff;
	int npadbegin;

	//append zeros at the end
	if (padmode == enpadmode::end) {
		signal.resize(newsize);
	}
	//append zeros at the beginning
	else if (padmode == enpadmode::begin) {
		sizediff = newsize - signal.size();
		signal.insert(std::begin(signal), sizediff, 0);
	}
	//append zeros at beginning and end, so that signal is centered
	else if (padmode == enpadmode::center) {
		sizediff = newsize - signal.size();
		npadbegin = sizediff / 2;
		signal.insert(std::begin(signal), npadbegin, 0);
		signal.resize(newsize);
	}
	return signal;
};

Wavelet* GetWvlt(int iSelWvlt) {
	Wavelet* pwvlt;
	switch (iSelWvlt) {
	case (int)enWavelets::Daubechies2:
		pwvlt = new Daublets(4);
		break;
	case (int)enWavelets::Daubechies3:
		pwvlt = new Daublets(6);
		break;
	case (int)enWavelets::Daubechies4:
		pwvlt = new Daublets(8);
		break;
	case (int)enWavelets::Daubechies5:
		pwvlt = new Daublets(10);
		break;
	case (int)enWavelets::Daubechies6:
		pwvlt = new Daublets(12);
		break;
	case (int)enWavelets::Daubechies7:
		pwvlt = new Daublets(14);
		break;
	case (int)enWavelets::Daubechies8:
		pwvlt = new Daublets(16);
		break;
	case (int)enWavelets::Daubechies9:
		pwvlt = new Daublets(18);
		break;
	case (int)enWavelets::Daubechies10:
		pwvlt = new Daublets(20);
		break;
	case (int)enWavelets::Symlet2:
		pwvlt = new Symlets(4);
		break;
	case (int)enWavelets::Symlet3:
		pwvlt = new Symlets(6);
		break;
	case (int)enWavelets::Symlet4:
		pwvlt = new Symlets(8);
		break;
	case (int)enWavelets::Symlet5:
		pwvlt = new Symlets(10);
		break;
	case (int)enWavelets::Symlet6:
		pwvlt = new Symlets(12);
		break;
	case (int)enWavelets::Symlet7:
		pwvlt = new Symlets(14);
		break;
	case (int)enWavelets::Symlet8:
		pwvlt = new Symlets(16);
		break;
	case (int)enWavelets::Coiflet1:
		pwvlt = new Coiflets(6);
		break;
	case (int)enWavelets::Coiflet2:
		pwvlt = new Coiflets(12);
		break;
	case (int)enWavelets::Coiflet3:
		pwvlt = new Coiflets(18);
		break;
	case (int)enWavelets::Coiflet4:
		pwvlt = new Coiflets(24);
		break;
	case (int)enWavelets::Coiflet5:
		pwvlt = new Coiflets(30);
		break;
	default:
		return NULL;
		break;
	}
	return pwvlt;
};

String^ GetWvltName(int iSelWvlt) {
	String^ legendtext;

	switch (iSelWvlt) {
	case (int)enWavelets::Daubechies2:
		legendtext = "DWT, Daubechies 2";
		break;
	case (int)enWavelets::Daubechies3:
		legendtext = "DWT, Daubechies 3";
		break;
	case (int)enWavelets::Daubechies4:
		legendtext = "DWT, Daubechies 4";
		break;
	case (int)enWavelets::Daubechies5:
		legendtext = "DWT, Daubechies 5";
		break;
	case (int)enWavelets::Daubechies6:
		legendtext = "Daubechies 6";
		break;
	case (int)enWavelets::Daubechies7:
		legendtext = "Daubechies 7";
		break;
	case (int)enWavelets::Daubechies8:
		legendtext = "Daubechies 8";
		break;
	case (int)enWavelets::Daubechies9:
		legendtext = "Daubechies 9";
		break;
	case (int)enWavelets::Daubechies10:
		legendtext = "Daubechies 10";
		break;
	case (int)enWavelets::Symlet2:
		legendtext = "Symlet 2";
		break;
	case (int)enWavelets::Symlet3:
		legendtext = "Symlet 3";
		break;
	case (int)enWavelets::Symlet4:
		legendtext = "Symlet 4";
		break;
	case (int)enWavelets::Symlet5:
		legendtext = "Symlet 5";
		break;
	case (int)enWavelets::Symlet6:
		legendtext = "Symlet 6";
		break;
	case (int)enWavelets::Symlet7:
		legendtext = "Symlet 7";
		break;
	case (int)enWavelets::Symlet8:
		legendtext = "Symlet 8";
		break;
	case (int)enWavelets::Coiflet1:
		legendtext = "Coiflet 1";
		break;
	case (int)enWavelets::Coiflet2:
		legendtext = "Coiflet 2";
		break;
	case (int)enWavelets::Coiflet3:
		legendtext = "Coiflet 3";
		break;
	case (int)enWavelets::Coiflet4:
		legendtext = "Coiflet 4";
		break;
	case (int)enWavelets::Coiflet5:
		legendtext = "Coiflet 5";
		break;
	default:
		legendtext = "";
		break;
	}

	return legendtext;
};