#pragma once
#include <vector>
using namespace std;

#ifndef _DWT_H_
#define _DWT_H_



struct Wavelet {
	virtual void filter(std::vector<double>& a, const int n, const int isign) = 0;
	//used for wavelets on the interval
	virtual void condition(std::vector<double>& a, const int n, const int isign) {}
};


//general case, using modulo in the filter calculation
//this wavelet represents all Daublets for which coefficients are implemented 
struct Daublets : Wavelet {
	int ncof, ioff, joff;
	std::vector<double> cc, cr;
	static double c4[4], c6[6], c8[8], c10[10], c12[12], c14[14], c16[16], c18[18], c20[20];
	//filter coefficients for Daub4i wavelet at right/left side of interval
	static struct d4h_left { double c0[3]; double c1[5]; d4h_left(); } d4hLeft;
	static struct d4g_left { double c0[3]; double c1[5]; d4g_left(); } g4iLeft;
	static struct d4h_right { double cm2[5]; double cm1[4]; d4h_right(); } h4iRight;
	static struct d4g_right { double cm2[5]; double cm1[4]; d4g_right(); } g4iRight;

	Daublets(int n) : ncof(n), cc(n), cr(n) {
		int i;
		ioff = joff = -(n >> 1);
		// ioff = -2; joff = -n + 2;
		if (n == 4) for (i = 0; i < n; i++) cc[i] = c4[i];
		else if (n == 6) for (i = 0; i < n; i++) cc[i] = c6[i];
		else if (n == 8) for (i = 0; i < n; i++) cc[i] = c8[i];
		else if (n == 10) for (i = 0; i < n; i++) cc[i] = c10[i];
		else if (n == 12) for (i = 0; i < n; i++) cc[i] = c12[i];
		else if (n == 14) for (i = 0; i < n; i++) cc[i] = c14[i];
		else if (n == 16) for (i = 0; i < n; i++) cc[i] = c16[i];
		else if (n == 18) for (i = 0; i < n; i++) cc[i] = c18[i];
		else if (n == 20) for (i = 0; i < n; i++) cc[i] = c20[i];
		else throw("Daublet with n taps not yet implemented");
		double sig = -1.0;
		for (i = 0; i < n; i++) {
			cr[n - 1 - i] = sig * cc[i];
			sig = -sig;
		}
	}
	void filter(std::vector<double>& a, const int n, const int isign);
};

void wt1(std::vector<double>& a, const int isign, Wavelet& wlet);
void getlevel(std::vector<double> in, std::vector<double>& out, int level, bool cum=false);
void getlevel(cli::array<double>^ in, cli::array<double>^& out, int level, bool cum=false);

void wtn(std::vector<double>& a, std::vector<int>& nn, const int isign, Wavelet& wlet);


struct Symlets : Wavelet {
	int ncof, ioff, joff;
	std::vector<double> cc, cr;
	static double c4[4], c6[6], c8[8], c10[10], c12[12], c14[14], c16[16];
	//constructor for Symlet with n filter taps
	Symlets(int n) : ncof(n), cc(n), cr(n) {
		int i;
		ioff = joff = -(n >> 1);
		// ioff = -2; joff = -n + 2;
		if (n == 4) for (i = 0; i < n; i++) cc[i] = c4[i];
		else if (n == 6) for (i = 0; i < n; i++) cc[i] = c6[i];
		else if (n == 8) for (i = 0; i < n; i++) cc[i] = c8[i];
		else if (n == 10) for (i = 0; i < n; i++) cc[i] = c10[i];
		else if (n == 12) for (i = 0; i < n; i++) cc[i] = c12[i];
		else if (n == 14) for (i = 0; i < n; i++) cc[i] = c14[i];
		else if (n == 16) for (i = 0; i < n; i++) cc[i] = c16[i];
		else throw("n not yet implemented in Symlets");
		double sig = -1.0;
		for (i = 0; i < n; i++) {
			cr[n - 1 - i] = sig * cc[i];
			sig = -sig;
		}
	}
	void filter(std::vector<double>& a, const int n, const int isign);
};

struct Coiflets : Wavelet {
	int ncof, ioff, joff;
	std::vector<double> cc, cr;
	static double c6[6], c12[12], c18[18], c24[24], c30[30];
	//constructor for Coiflet with n filter taps
	Coiflets(int n) : ncof(n), cc(n), cr(n) {
		int i;
		ioff = joff = -(n >> 1);
		// ioff = -2; joff = -n + 2;
		if (n == 6) for (i = 0; i < n; i++) cc[i] = c6[i];
		else if (n == 12) for (i = 0; i < n; i++) cc[i] = c12[i];
		else if (n == 18) for (i = 0; i < n; i++) cc[i] = c18[i];
		else if (n == 24) for (i = 0; i < n; i++) cc[i] = c24[i];
		else if (n == 30) for (i = 0; i < n; i++) cc[i] = c30[i];
		else throw("Coiflet with n filter taps not implemented");
		double sig = -1.0;
		for (i = 0; i < n; i++) {
			cr[n - 1 - i] = sig * cc[i];
			sig = -sig;
		}
	}
	void filter(std::vector<double>& a, const int n, const int isign);
};

#endif //_DWT_H_