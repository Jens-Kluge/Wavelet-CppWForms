#pragma once

#include <vector>
#include "Utilities.h"
#include "DWT.h"


namespace Wavelet_CppWForms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	

	/// <summary>
	/// Summary for frmSettings
	/// </summary>
	public ref class frmSettings : public System::Windows::Forms::Form
	{
	public:
		frmSettings(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

		int m_SelWvlt;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmSettings()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ListBox^ listBox1;
	protected:
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chrtWavelet;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btnOK;
	private: System::Windows::Forms::TrackBar^ trackBar1;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea3 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->chrtWavelet = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnOK = (gcnew System::Windows::Forms::Button());
			this->trackBar1 = (gcnew System::Windows::Forms::TrackBar());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chrtWavelet))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->BeginInit();
			this->SuspendLayout();
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 16;
			this->listBox1->Items->AddRange(gcnew cli::array< System::Object^  >(21) {
				L"Daubechies 2 (4 taps)", L"Daubechies 3 (6 taps)",
					L"Daubechies 4 (8 taps)", L"Daubchies 5 (10 taps)", L"Daubechies 6 (12 taps)", L"Daubechies 7 (14 taps)", L"Daubechies 8 (16 taps)",
					L"Daubechies 9 (18 taps)", L"Daubechies10 (20 taps)", L"Symlet 2 (4 taps)", L"Symlet 3 (6 taps)", L"Symlet 4 (8 taps)", L"Symlet 5 (10 taps)",
					L"Symlet 6 (12 taps)", L"Symlet 7 (14 taps)", L"Symlet 8 (16 taps)", L"Coiflet 1 (6 taps)", L"Coiflet 2 (12 taps)", L"Coiflet 3 (18 taps)",
					L"Coiflet 4 (24 taps)", L"Coiflet 5 (30 taps)"
			});
			this->listBox1->Location = System::Drawing::Point(27, 45);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(159, 372);
			this->listBox1->TabIndex = 0;
			this->listBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &frmSettings::listBox1_SelectedIndexChanged);
			this->listBox1->DoubleClick += gcnew System::EventHandler(this, &frmSettings::listBox1_DoubleClick);
			// 
			// chrtWavelet
			// 
			this->chrtWavelet->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			chartArea3->Name = L"ChartArea1";
			this->chrtWavelet->ChartAreas->Add(chartArea3);
			legend3->Name = L"Legend1";
			this->chrtWavelet->Legends->Add(legend3);
			this->chrtWavelet->Location = System::Drawing::Point(224, 45);
			this->chrtWavelet->Name = L"chrtWavelet";
			series3->ChartArea = L"ChartArea1";
			series3->Legend = L"Legend1";
			series3->Name = L"Series1";
			this->chrtWavelet->Series->Add(series3);
			this->chrtWavelet->Size = System::Drawing::Size(486, 247);
			this->chrtWavelet->TabIndex = 1;
			this->chrtWavelet->Text = L"chart1";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(24, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(59, 17);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Wavelet";
			// 
			// btnOK
			// 
			this->btnOK->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->btnOK->Location = System::Drawing::Point(589, 385);
			this->btnOK->Name = L"btnOK";
			this->btnOK->Size = System::Drawing::Size(121, 32);
			this->btnOK->TabIndex = 3;
			this->btnOK->Text = L"&OK";
			this->btnOK->UseVisualStyleBackColor = true;
			this->btnOK->Click += gcnew System::EventHandler(this, &frmSettings::btnOK_Click);
			// 
			// trackBar1
			// 
			this->trackBar1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->trackBar1->Location = System::Drawing::Point(224, 361);
			this->trackBar1->Maximum = 1023;
			this->trackBar1->Name = L"trackBar1";
			this->trackBar1->Size = System::Drawing::Size(303, 56);
			this->trackBar1->TabIndex = 4;
			this->trackBar1->TickFrequency = 20;
			this->trackBar1->Scroll += gcnew System::EventHandler(this, &frmSettings::trackBar1_Scroll);
			// 
			// frmSettings
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(770, 449);
			this->Controls->Add(this->trackBar1);
			this->Controls->Add(this->btnOK);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->chrtWavelet);
			this->Controls->Add(this->listBox1);
			this->Name = L"frmSettings";
			this->Text = L"DWT Settings";
			this->Load += gcnew System::EventHandler(this, &frmSettings::frmSettings_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chrtWavelet))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->trackBar1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


private: System::Void btnOK_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
private: System::Void listBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	GlobalVars::g_SelWvlet = m_SelWvlt = listBox1->SelectedIndex;
	DisplayWavelet(listBox1->SelectedIndex,-1);
}
private: void DisplayWavelet(int wltIdx, int idx) {
	//The Wavelet shape is given by the inverse transform of a unit vector
	int displayidx;
	System::String^ legendtext;
	const int arrlen = 1024;
	std::vector<double> signal(arrlen);

	Wavelet* pwvlt;

	switch (wltIdx) {
	case (int)enWavelets::Daubechies2:
		pwvlt = new Daublets(4);
		legendtext = "Daub2";
		displayidx = 4;
		break;
	case (int)enWavelets::Daubechies3:
		pwvlt = new Daublets(6);
		legendtext = "Daub3";
		displayidx = 5;
		break;
	case (int)enWavelets::Daubechies4:
		pwvlt = new Daublets(8);
		legendtext = "Daub4";
		displayidx = 10;
		break;
	case (int)enWavelets::Daubechies5:
		pwvlt = new Daublets(10);
		legendtext = "Daub5";
		displayidx = 11;
		break;
	case (int)enWavelets::Daubechies6:
		pwvlt = new Daublets(12);
		legendtext = "Daub6";
		displayidx = 11;
		break;
	case (int)enWavelets::Daubechies7:
		pwvlt = new Daublets(14);
		legendtext = "Daub7";
		displayidx = 11;
		break;
	case (int)enWavelets::Daubechies8:
		pwvlt = new Daublets(16);
		legendtext = "Daub8";
		displayidx = 11;
		break;
	case (int)enWavelets::Daubechies9:
		pwvlt = new Daublets(18);
		legendtext = "Daub9";
		displayidx = 22;
		break;
	case (int)enWavelets::Daubechies10:
		pwvlt = new Daublets(20);
		legendtext = "Daub10";
		displayidx = 23;
		break;
	case (int)enWavelets::Symlet2:
		pwvlt = new Symlets(4);
		legendtext = "Symlet2";
		displayidx = 4;
		break;
	case (int)enWavelets::Symlet3:
		pwvlt = new Symlets(6);
		legendtext = "Symlet3";
		displayidx = 5;
		break;
	case (int)enWavelets::Symlet4:
		pwvlt = new Symlets(8);
		legendtext = "Symlet4";
		displayidx = 10;
		break;
	case (int)enWavelets::Symlet5:
		pwvlt = new Symlets(10);
		legendtext = "Symlet5";
		displayidx = 11;
		break;
	case (int)enWavelets::Symlet6:
		pwvlt = new Symlets(12);
		legendtext = "Symlet6";
		displayidx = 11;
		break;
	case (int)enWavelets::Symlet7:
		pwvlt = new Symlets(14);
		legendtext = "Symlet7";
		displayidx = 11;
		break;
	case (int)enWavelets::Symlet8:
		pwvlt = new Symlets(16);
		legendtext = "Symlet8";
		displayidx = 11;
		break;
	case (int)enWavelets::Coiflet1:
		pwvlt = new Coiflets(6);
		legendtext = "Coiflet1";
		displayidx = 5;
		break;
	case (int)enWavelets::Coiflet2:
		pwvlt = new Coiflets(12);
		legendtext = "Coiflet2";
		displayidx = 11;
		break;
	case (int)enWavelets::Coiflet3:
		pwvlt = new Coiflets(18);
		legendtext = "Coiflet3";
		displayidx = 10;
		break;
	case (int)enWavelets::Coiflet4:
		pwvlt = new Coiflets(24);
		legendtext = "Coiflet4";
		displayidx = 11;
		break;
	case (int)enWavelets::Coiflet5:
		pwvlt = new Coiflets(30);
		legendtext = "Coiflet5";
		displayidx = 11;
		break;
	default:
		return;
		break;
	}

	if (idx == -1) {
		idx = displayidx;
	}
	trackBar1->Value = idx;
	legendtext = String::Format("{0}({1})", legendtext, idx);
	signal[idx] = 1;
	if (idx == -1) {
		idx = displayidx;
	}
	trackBar1->Value = idx;
	legendtext = String::Format("{0}({1})", legendtext, idx);
	signal[idx] = 1;
	
	//perform inverse wavelet transform
	wt1(signal, -1, *pwvlt);
	delete pwvlt;

	chrtWavelet->ChartAreas[0]->AxisX->Minimum = 0;
	chrtWavelet->ChartAreas[0]->AxisX->Maximum = 1024;
	chrtWavelet->ChartAreas[0]->AxisX->Interval = 100;

	chrtWavelet->Series->Clear();
	DataVisualization::Charting::Series^ series = chrtWavelet->Series->Add("Wavelet");
	series->ChartType = DataVisualization::Charting::SeriesChartType::Spline; 
	series->LegendText = legendtext;
	for (int i = 0; i < signal.size(); i++) {
		series->Points->AddXY(i, signal[i]);
	}
}

private: System::Void trackBar1_Scroll(System::Object^ sender, System::EventArgs^ e) {
	
	DisplayWavelet(listBox1->SelectedIndex, trackBar1->Value);
	
}
private: System::Void frmSettings_Load(System::Object^ sender, System::EventArgs^ e) {
	chrtWavelet->Series->Clear();
}
private: System::Void listBox1_DoubleClick(System::Object^ sender, System::EventArgs^ e) {
	m_SelWvlt = listBox1->SelectedIndex;
	Close();
}
};
}
