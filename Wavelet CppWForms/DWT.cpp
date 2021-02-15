#include "pch.h"
#include "DWT.h"




//one dimensional wavelet transform
void wt1(std::vector<double>& a, const int isign, Wavelet& wlet)
{
	int nn, n = a.size();
	if (n < 4) return;
	//forward transform
	if (isign >= 0) {
		wlet.condition(a, n, 1);
		for (nn = n; nn >= 4; nn >>= 1) wlet.filter(a, nn, isign);
	}
	//reverse transform
	else {
		for (nn = 4; nn <= n; nn <<= 1) wlet.filter(a, nn, isign);
		wlet.condition(a, n, -1);
	}
}

// N-dimensional wavelet transform
// a: Input/Output vector, 
// order for 2D: {row1, row2, ..., rowN}
// nn:dimension vector, order for 2D: {row width, column height}
// lengths must be powers of two => else use zero padding/reflection or other continuation techniques
// isign: forward/backward transformation
// wlet: Wavelet used for the transformation
void wtn(std::vector<double>& a, std::vector<int>& nn, const int isign, Wavelet& wlet)
{
	int idim, i1, i2, i3, k, n, nnew, nprev = 1, nt, ntot = 1;
	int ndim = nn.size();
	for (idim = 0; idim < ndim; idim++) ntot *= nn[idim];
	if (ntot & (ntot - 1)) throw("all lengths must be powers of 2");
	for (idim = 0; idim < ndim; idim++) {
		n = nn[idim];
		std::vector<double> wksp(n);
		nnew = n * nprev;
		if (n > 4) {
			for (i2 = 0; i2 < ntot; i2 += nnew) {
				for (i1 = 0; i1 < nprev; i1++) {
					for (i3 = i1 + i2, k = 0; k < n; k++, i3 += nprev)
					{
						wksp[k] = a[i3];
						//To find out indexing
						//System::Diagnostics::Debug::Print(System::String::Format("{0};", i3));
					}
					//forward transform
					if (isign >= 0) {
						wlet.condition(wksp, n, 1);
						for (nt = n; nt >= 4; nt >>= 1) wlet.filter(wksp, nt, isign);
					}
					//inverse transform
					else {
						for (nt = 4; nt <= n; nt <<= 1) wlet.filter(wksp, nt, isign);
						wlet.condition(wksp, n, -1);
					}
					//copy workspace back into result vector
					for (i3 = i1 + i2, k = 0; k < n; k++, i3 += nprev) a[i3] = wksp[k];
				}
			}
		}
		nprev = nnew;
	}
}

//same as Daublets::filter
void Coiflets::filter(std::vector<double>& a, const int n, const int isign) {
	double ai, ai1;
	int i, ii, j, jf, jr, k, n1, ni, nj, nh, nmod;
	if (n < 4) return;
	std::vector<double> wksp(n);
	nmod = ncof * n;
	n1 = n - 1;
	nh = n >> 1;
	for (j = 0; j < n; j++) wksp[j] = 0.0;
	if (isign >= 0) {
		for (ii = 0, i = 0; i < n; i += 2, ii++) {
			ni = i + 1 + nmod + ioff;
			nj = i + 1 + nmod + joff;
			for (k = 0; k < ncof; k++) {
				jf = n1 & (ni + k + 1);
				jr = n1 & (nj + k + 1);
				wksp[ii] += cc[k] * a[jf];
				wksp[ii + nh] += cr[k] * a[jr];
			}
		}
	}
	else {
		for (ii = 0, i = 0; i < n; i += 2, ii++) {
			ai = a[ii];
			ai1 = a[ii + nh];
			ni = i + 1 + nmod + ioff;
			nj = i + 1 + nmod + joff;
			for (k = 0; k < ncof; k++) {
				jf = n1 & (ni + k + 1);
				jr = n1 & (nj + k + 1);
				wksp[jf] += cc[k] * ai;
				wksp[jr] += cr[k] * ai1;
			}
		}
	}
	for (j = 0; j < n; j++) a[j] = wksp[j];
};

//Daubechies wavelet coefficients can be found in:
//Filter coefficients to popular wavelets, Pascal Getreuer, 2006
//The coeefficients below are the composition of the decomposition
//high pass filter g
//see also: http://wavelets.pybytes.com/wavelet

//Daub2 wavelet with two vanishing moments and four taps
//indices:-2,-1,0,1,2
double Daublets::c4[4] = { 0.4829629131445341,0.8365163037378079,
0.2241438680420134,-0.1294095225512604 };

//Daub3 wavelet with three vanishing moments
//indices: -3,-2,-1,0,1,2,3
//h-3=Sqrt[2]*(1 +Sqrt[10]+Sqrt[5 + 2*Sqrt[10]])/32 h-2=Sqrt[2]*(5 +Sqrt[10] + 3*Sqrt[5 + 2*Sqrt[10]])/32
//h-1=Sqrt[2]*(1 -2*Sqrt[10] +2*Sqrt[5 + 2*Sqrt[10]])/32 h0=Sqrt[2]*(10 -2*Sqrt[10] - 2*Sqrt[5 + 2*Sqrt[10]])/32 
//h2= Sqrt[2]*(1 +Sqrt[10] -3*Sqrt[5 + 2*Sqrt[10]])/32, h3=Sqrt[2]*(1 +Sqrt[10] -Sqrt[5 + 2*Sqrt[10]])/32d
double Daublets::c6[6] = { 0.332670552950, 0.806891509311,
	0.459877502118, -0.135011020010,
-0.0854412738820,0.0352262918857 };

double Daublets::c8[8] =
{ 0.230377813309, 0.714846570553, 0.630880767940, -0.027983769417,
	-0.187034811719, 0.030841381836, 0.032883011667, -0.010597401785 };

double Daublets::c10[10] =
{ 0.160102397974, 0.603829269797, 0.724308528438, 0.138428145901,
-0.242294887066, -0.032244869585, 0.077571493840, -0.006241490213,
-0.012580751999, 0.00333572285 };

double Daublets::c12[12] =
{ 0.111540743350, 0.494623890398, 0.751133908021,
0.315250351709,-0.226264693965,-0.129766867567,
0.097501605587, 0.027522865530,-0.031582039318,
0.000553842201, 0.004777257511,-0.001077301085 };

double Daublets::c14[14]
{ 0.077852054085, 0.396539319482, 0.729132090846, 0.469782287405,
-0.143906003929, -0.224036184994, 0.071309219267,0.080612609151,
-0.038029936935, -0.016574541631,0.012550998556, 0.000429577973,
-0.001801640704, 0.000353713800 };

double Daublets::c16[16]
{ 0.054415842243, 0.312871590914, 0.675630736297, 0.585354683654,
-0.015829105256, -0.284015542962, 0.000472484574, 0.128747426620,
-0.017369301002, -0.044088253931, 0.013981027917, 0.008746094047,
-0.004870352993, -0.000391740373, 0.000675449406, -0.000117476784 };

double Daublets::c18[18] =
{ 0.038077947364, 0.243834674613, 0.604823123690, 0.657288078051,
0.133197385825,-0.293273783279, -0.096840783223, 0.148540749338,
0.030725681479, -0.067632829061,0.000250947115, 0.022361662124,
-0.004723204758, -0.004281503682, 0.001847646883,0.000230385764,
-0.000251963189, 0.000039347320 };

double Daublets::c20[20] =
{ 0.026670057901, 0.188176800078, 0.527201188932,
0.688459039454, 0.281172343661,-0.249846424327,
-0.195946274377, 0.127369340336, 0.093057364604,
-0.071394147166,-0.029457536822, 0.033212674059,
0.003606553567,-0.010733175483, 0.001395351747,
0.001992405295,-0.000685856695,-0.000116466855,
0.000093588670,-0.000013264203 };

//filters for Daubechies wavelets on the interval
//low pass filter h, left side of interval
Daublets::d4h_left::d4h_left() {
	//k=0
	double c0[3] = {
	0.603332511928053, //0
	0.90895531839104, //1
	-0.398312997698228 }; //2
	//k=1
	double c1[5] = {
	0.375174604524466e-1, //0
	0.457327659851769, //1
	0.850088102549165, //2
	0.223820356983114, //3
	-0.129222743354319 }; //4
}

//high pass filter g, left side of interval
Daublets::d4g_left::d4g_left() {
	//k=-2	
	double c0[3] = { -0.796543516912183, //0
	0.546392713959015, //1
	-0.258792248333818 //2
	};
	//k=-1
	double c1[5] = {
	0.100372245644139e-1, //0
	0.122351043116799, //1
	0.227428111655837, //2
	-0.836602921223654, //3
	0.483012921773304 }; //4
}

Daublets::d4h_right::d4h_right() {
	//k=-2
	double cm2[5] = {
	0.43149049637559, //-5
	0.767556669298114, //-4	
	0.374955331645687, //-3
	0.190151418429955, //-2
	-0.194233407427412 }; //-1
	//k=-1
	double cm1[3] = {
	0.870508753349866, //-3
	0.434896997965703, //-2
	0.70508753349866 }; //-1
}


//high pass filter g, right side
Daublets::d4g_right::d4g_right() {
	//k=-2
	double cm2[4] = {
		0.231557595006790, //-5
		0.401069519430217, //-4
		-0.717579999353722 //-3
		- 0.363906959570891, //-2
		0.371718966535296 }; //-1
	double cm1[3] = {
		0.539822500731772, //-3
		-0.801422961990337, //-2
		0.257512919478482 }; //-1
}

/*
* parameters:
* a: input/output vector
* n: number of filter taps
* isign: 1 for forward transform, -1 for inverse transform
*/
void Daublets::filter(std::vector<double>& a, const int n, const int isign) {
	double ai, ai1;
	int i, ii, j, jf, jr, k, n1, ni, nj, nh, nmod;
	if (n < 4) return;
	std::vector<double> wksp(n);
	nmod = ncof * n;
	n1 = n - 1;
	nh = n >> 1;
	for (j = 0; j < n; j++) wksp[j] = 0.0;
	if (isign >= 0) {
		for (ii = 0, i = 0; i < n; i += 2, ii++) {
			ni = i + 1 + nmod + ioff;
			nj = i + 1 + nmod + joff;
			for (k = 0; k < ncof; k++) {
				jf = n1 & (ni + k + 1);
				jr = n1 & (nj + k + 1);
				wksp[ii] += cc[k] * a[jf];
				wksp[ii + nh] += cr[k] * a[jr];
			}
		}
	}
	else {
		for (ii = 0, i = 0; i < n; i += 2, ii++) {
			ai = a[ii];
			ai1 = a[ii + nh];
			ni = i + 1 + nmod + ioff;
			nj = i + 1 + nmod + joff;
			for (k = 0; k < ncof; k++) {
				jf = n1 & (ni + k + 1);
				jr = n1 & (nj + k + 1);
				wksp[jf] += cc[k] * ai;
				wksp[jr] += cr[k] * ai1;
			}
		}
	}
	for (j = 0; j < n; j++) a[j] = wksp[j];
}

double Symlets::c4[4] =
{ 0.482962913145, 0.836516303737,
0.224143868042, -0.129409522551 };

double Symlets::c6[6] =
{ 0.332670552951, 0.806891509313, 0.459877502119,
-0.135011020010, -0.085441273882, 0.035226291882 };

double Symlets::c8[8] =
{ 0.032223100604, -0.012603967262, -0.099219543577,
0.297857795606, 0.803738751807, 0.497618667633,
-0.029635527646, -0.075765714789 };

double Symlets::c10[10] =
{ 0.019538882735, -0.021101834025, -0.175328089908,
0.016602105765, 0.633978963458, 0.723407690402,
0.199397533977, -0.039134249302, 0.029519490926,
0.027333068345 };

double Symlets::c12[12] =
{ -0.007800708325, 0.001767711864, 0.044724901771,
-0.021060292512, -0.072637522786, 0.337929421728,
0.787641141030, 0.491055941927, -0.048311742586,
-0.117990111148, 0.003490712084, 0.015404109327
};

double Symlets::c14[14] =
{ 0.010268176709, 0.004010244872, -0.107808237704, -0.140047240443,
0.288629631752, 0.767764317003, 0.536101917092, 0.017441255087,
-0.049552834937,  0.067892693501, 0.030515513166,-0.012636303403,
-0.001047384889, 0.002681814568
};

double Symlets::c16[16] =
{ 0.001889950333, -0.000302920515, -0.014952258337, 0.003808752014,
0.049137179674, -0.027219029917, -0.051945838108, 0.364441894835,
0.777185751701, 0.481359651258, -0.061273359068, -0.143294238351,
0.007607487325, 0.031695087811, -0.000542132332, -0.003382415951 };

//same as Daublets::filter
void Symlets::filter(std::vector<double>& a, const int n, const int isign) {
	double ai, ai1;
	int i, ii, j, jf, jr, k, n1, ni, nj, nh, nmod;
	if (n < 4) return;
	std::vector<double> wksp(n);
	nmod = ncof * n;
	n1 = n - 1;
	nh = n >> 1;
	for (j = 0; j < n; j++) wksp[j] = 0.0;
	if (isign >= 0) {
		for (ii = 0, i = 0; i < n; i += 2, ii++) {
			ni = i + 1 + nmod + ioff;
			nj = i + 1 + nmod + joff;
			for (k = 0; k < ncof; k++) {
				jf = n1 & (ni + k + 1);
				jr = n1 & (nj + k + 1);
				wksp[ii] += cc[k] * a[jf];
				wksp[ii + nh] += cr[k] * a[jr];
			}
		}
	}
	else {
		for (ii = 0, i = 0; i < n; i += 2, ii++) {
			ai = a[ii];
			ai1 = a[ii + nh];
			ni = i + 1 + nmod + ioff;
			nj = i + 1 + nmod + joff;
			for (k = 0; k < ncof; k++) {
				jf = n1 & (ni + k + 1);
				jr = n1 & (nj + k + 1);
				wksp[jf] += cc[k] * ai;
				wksp[jr] += cr[k] * ai1;
			}
		}
	}
	for (j = 0; j < n; j++) a[j] = wksp[j];
}

//Coiflet1
double Coiflets::c6[6] =
{ -0.072732619513, 0.337897662458, 0.852572020212,
0.384864846864, -0.072732619513, -0.015655728135 };

//Coiflet2
double Coiflets::c12[12] =
{ 0.016387336464, -0.041464936782, -0.067372554722, 0.386110066823,
0.812723635450, 0.417005184424, -0.076488599079, -0.059434418647,
0.023680171946, 0.005611434819, -0.001823208871, -0.000720549445
};

//Coiflet3
double Coiflets::c18[18] =
{ -0.003793512864, 0.007782596427, 0.023452696142, -0.065771911282,
-0.061123390003, 0.405176902410, 0.793777222626, 0.428483476378,
-0.071799821619, -0.082301927107, 0.034555027573, 0.015880544864,
-0.009007976137, -0.002574517689, 0.001117518771, 0.000466216960,
-0.000070983303, -0.000034599773 };

//Coiflet4
double Coiflets::c24[24] =
{ 0.000892313669, -0.001629492013, -0.007346166328, 0.016068943965,
0.026682300156, -0.081266699681, -0.056077313317, 0.415308407030,
0.782238930921, 0.434386056491, -0.066627474263, -0.096220442034,
0.039334427123, 0.025082261845, -0.015211731528, -0.005658286687,
0.003751436157, 0.001266561929, -0.000589020756, -0.000259974552,
0.000062339034, 0.000031229876, -0.000003259680, -0.000001784985 };

//Coiflet5
double Coiflets::c30[30] =
{ -0.000212080840, 0.000358589688, 0.002178236358, -0.004159358782,
-0.010131117521,  0.023408156788, 0.028168028974, -0.091920010569,
-0.052043163181, 0.421566206733, 0.774289603730, 0.437991626216,
-0.062035963969, -0.105574208714, 0.041289208754, 0.032683574270,
-0.019761778945, -0.009164231163, 0.006764185449, 0.002433373213,
-0.001662863702, -0.000638131343, 0.000302259582, 0.000140541150,
-0.000041340432, -0.000021315027, 0.000003734655, 0.000002063762,
-0.000000167443, -0.000000095177 };

//input: 
//vector in, which contains a one dimensional DWT
//level, the level to be retrieved
//out: a vector where all components outside the level are set to zero
//cum: sum together the effect of all lower levels (cumulative)
void getlevel(std::vector<double> in, std::vector<double>& out, int level, bool cum) {
	int N;
	N = log2(in.size());
	//for a full decompositions, the levels are 0,..., N-1
	if (level > (N - 1)) return;
	out = in;
	//set all components outside of [2^(N-level-1), 2^(N-level)-1] to zero
	int lowerboundary;
	if (!cum) {
		lowerboundary = pow(2, level) - 1;
	}
	else {
		lowerboundary = 0;
	}
	for (int i = 0; i < in.size(); i++) {
		if (i < lowerboundary || i > (pow(2, level+1) - 1)) {
			out[i] = 0;
		}
	}
}

// same as above, but for cli::array
void getlevel(cli::array<double>^ in, cli::array<double>^& out, int level, bool cum) {
	int N;
	N = log2(in->Length);
	//there is only a maximum of N levels
	if (level > (N - 1)) return;
	out = in;
	//set all components outside of [2^(N-level-1), 2^(N-level)-1] to zero
	int lowerboundary;
	if (!cum) {
		lowerboundary = pow(2, level) - 1;
	}
	else {
		lowerboundary = 0;
	}
	for (int i = 0; i < in->Length; i++) {
		if (i < lowerboundary || i >(pow(2, level + 1) - 1)) {
			out[i] = 0;
		}
	}
};