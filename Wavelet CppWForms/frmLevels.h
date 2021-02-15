#pragma once
#include <vector>
#include "DWT.h"
#include "Globals.h"

namespace Wavelet_CppWForms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for frmLevels
	/// </summary>
	public ref class frmLevels : public System::Windows::Forms::Form
	{
	public:
		frmLevels(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmLevels()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chrtSignal;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chrtLevels;


	protected:

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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->chrtSignal = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->chrtLevels = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->tableLayoutPanel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chrtSignal))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chrtLevels))->BeginInit();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				20)));
			this->tableLayoutPanel1->Controls->Add(this->chrtSignal, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->chrtLevels, 0, 1);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(706, 340);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// chrtSignal
			// 
			chartArea1->Name = L"ChartArea1";
			this->chrtSignal->ChartAreas->Add(chartArea1);
			this->chrtSignal->Dock = System::Windows::Forms::DockStyle::Fill;
			legend1->Name = L"Legend1";
			this->chrtSignal->Legends->Add(legend1);
			this->chrtSignal->Location = System::Drawing::Point(3, 3);
			this->chrtSignal->Name = L"chrtSignal";
			series1->ChartArea = L"ChartArea1";
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			this->chrtSignal->Series->Add(series1);
			this->chrtSignal->Size = System::Drawing::Size(700, 164);
			this->chrtSignal->TabIndex = 0;
			this->chrtSignal->Text = L"Signals";
			// 
			// chrtLevels
			// 
			chartArea2->Name = L"ChartArea1";
			this->chrtLevels->ChartAreas->Add(chartArea2);
			this->chrtLevels->Dock = System::Windows::Forms::DockStyle::Fill;
			legend2->Name = L"Legend1";
			this->chrtLevels->Legends->Add(legend2);
			this->chrtLevels->Location = System::Drawing::Point(3, 173);
			this->chrtLevels->Name = L"chrtLevels";
			series2->ChartArea = L"ChartArea1";
			series2->Legend = L"Legend1";
			series2->Name = L"Series1";
			this->chrtLevels->Series->Add(series2);
			this->chrtLevels->Size = System::Drawing::Size(700, 164);
			this->chrtLevels->TabIndex = 1;
			this->chrtLevels->Text = L"Levels";
			// 
			// frmLevels
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(706, 340);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Name = L"frmLevels";
			this->Text = L"frmLevels";
			this->Load += gcnew System::EventHandler(this, &frmLevels::frmLevels_Load);
			this->tableLayoutPanel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chrtSignal))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chrtLevels))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void frmLevels_Load(System::Object^ sender, System::EventArgs^ e) {
		ShowLevels();
	}
	private: void ShowLevels() {

		if (GlobalVars::g_Signal == nullptr || GlobalVars::g_Signal->Length == 0) {
			MessageBox::Show("Select a signal first");
			return;
		}

		chrtSignal->Series->Clear();
		chrtSignal->ChartAreas[0]->AxisX->Minimum = 0;
		chrtSignal->ChartAreas[0]->AxisX->Maximum = GlobalVars::g_Signal->Length;
		chrtSignal->ChartAreas[0]->AxisX->Interval = nearestpow10(GlobalVars::g_Signal->Length) / 10;


		DataVisualization::Charting::Series^ series1 = chrtSignal->Series->Add("Signal");
		series1->ChartType = DataVisualization::Charting::SeriesChartType::Line;
		for (int i = 0; i < GlobalVars::g_Signal->Length; i++) {
			series1->Points->AddXY(i, GlobalVars::g_Signal[i]);
		}

		//copy the array into the std::vector
		std::vector<double> signal(GlobalVars::g_Signal->Length);
		for (int i = 0; i < GlobalVars::g_Signal->Length; i++) {
			signal[i] = GlobalVars::g_Signal[i];
		}

		//Display the level decomposition of the signal
		std::vector<double> vecLevel(signal.size());

		chrtLevels->Series->Clear();
		chrtLevels->ChartAreas[0]->AxisX->Minimum = 0;
		chrtLevels->ChartAreas[0]->AxisX->Maximum = vecLevel.size();
		chrtLevels->ChartAreas[0]->AxisX->Interval = nearestpow10(vecLevel.size()) / 10;

		//perform DWT
		Wavelet* wvlt = GetWvlt(GlobalVars::g_SelWvlet);
		wt1(signal, 1, *wvlt);
		int numlevels = log2(signal.size());
		//show only the highest four levels to avoid cluttering
		int minlevel = max(0, numlevels - 4);
		for (int level = (numlevels-1); level >= minlevel; level--) {

			getlevel(signal, vecLevel, level, true);
			wt1(vecLevel, -1, *wvlt);

			DataVisualization::Charting::Series^ series2 = chrtLevels->Series->Add(String::Format("Level {0}", level));
			//SetTitle(m_SelWvlt);
			series2->ChartType = DataVisualization::Charting::SeriesChartType::Line;

			for (int i = 0; i < vecLevel.size(); i++) {
				series2->Points->AddXY(i, vecLevel[i]);
			}
		} //levels
	}
};
}
