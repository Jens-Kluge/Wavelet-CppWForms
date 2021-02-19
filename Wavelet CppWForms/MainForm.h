#pragma once

#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdlib>
#include "DWT.h"
#include "SignalGenerator.h"
#include "Globals.h"
//Forms that are called from this form
#include "frmSettings.h"
#include "frmSignalSelection.h"
#include "frmDWT2D.h"
#include "frmExport.h"
#include "frmLevels.h"

namespace CppCLRWinformsProjekt {
	
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	//for chart control
	using namespace DataVisualization;

	/// <summary>
	/// Zusammenfassung für MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
		}
	
	//member variables
	public:
		//holds the result of the DWT
		cli::array<double>^ m_DWT;
		int m_SelWvlt = (int) enWavelets::Daubechies4;
		SignalType m_SelSignal = enSignalType::Sawtooth;
		String^ m_ImagePath;
		String^ m_ImageFileName;


	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::ToolStripMenuItem^ selectSignalToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ exportDataToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ inverse2DDWTToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ show1DlevelsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ dDWTToolStripMenuItem;
	
	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ openToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ transformToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ DWTToolStripMenuItem;

	private: System::Windows::Forms::ToolStripMenuItem^ backwardToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ settingsToolStripMenuItem1;
	private: System::Windows::Forms::SplitContainer^ splitContainer1;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chrtSignal;
	private: System::Windows::Forms::ToolStripMenuItem^ dWTSettingsToolStripMenuItem;


	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Title^ title1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->openToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->selectSignalToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->exportDataToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->transformToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->DWTToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->backwardToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dDWTToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->inverse2DDWTToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->show1DlevelsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->settingsToolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->dWTSettingsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->chrtSignal = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chrtSignal))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->fileToolStripMenuItem,
					this->transformToolStripMenuItem, this->settingsToolStripMenuItem1
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(980, 28);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->openToolStripMenuItem,
					this->selectSignalToolStripMenuItem, this->exportDataToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(46, 24);
			this->fileToolStripMenuItem->Text = L"&File";
			// 
			// openToolStripMenuItem
			// 
			this->openToolStripMenuItem->Name = L"openToolStripMenuItem";
			this->openToolStripMenuItem->Size = System::Drawing::Size(178, 26);
			this->openToolStripMenuItem->Text = L"Select &Image";
			this->openToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::openToolStripMenuItem_Click);
			// 
			// selectSignalToolStripMenuItem
			// 
			this->selectSignalToolStripMenuItem->Name = L"selectSignalToolStripMenuItem";
			this->selectSignalToolStripMenuItem->Size = System::Drawing::Size(178, 26);
			this->selectSignalToolStripMenuItem->Text = L"Select &Signal";
			this->selectSignalToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::selectSignalToolStripMenuItem_Click);
			// 
			// exportDataToolStripMenuItem
			// 
			this->exportDataToolStripMenuItem->Name = L"exportDataToolStripMenuItem";
			this->exportDataToolStripMenuItem->Size = System::Drawing::Size(178, 26);
			this->exportDataToolStripMenuItem->Text = L"E&xport Data";
			this->exportDataToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::exportDataToolStripMenuItem_Click);
			// 
			// transformToolStripMenuItem
			// 
			this->transformToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->DWTToolStripMenuItem,
					this->backwardToolStripMenuItem, this->dDWTToolStripMenuItem, this->inverse2DDWTToolStripMenuItem, this->show1DlevelsToolStripMenuItem
			});
			this->transformToolStripMenuItem->Name = L"transformToolStripMenuItem";
			this->transformToolStripMenuItem->Size = System::Drawing::Size(89, 24);
			this->transformToolStripMenuItem->Text = L"&Transform";
			// 
			// DWTToolStripMenuItem
			// 
			this->DWTToolStripMenuItem->Name = L"DWTToolStripMenuItem";
			this->DWTToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->DWTToolStripMenuItem->Text = L"&Forward DWT";
			this->DWTToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::DWTToolStripMenuItem_Click);
			// 
			// backwardToolStripMenuItem
			// 
			this->backwardToolStripMenuItem->Name = L"backwardToolStripMenuItem";
			this->backwardToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->backwardToolStripMenuItem->Text = L"&Inverse DWT";
			this->backwardToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::backwardToolStripMenuItem_Click);
			// 
			// dDWTToolStripMenuItem
			// 
			this->dDWTToolStripMenuItem->Name = L"dDWTToolStripMenuItem";
			this->dDWTToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->dDWTToolStripMenuItem->Text = L"&2D DWT";
			this->dDWTToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::dDWTToolStripMenuItem_Click);
			// 
			// inverse2DDWTToolStripMenuItem
			// 
			this->inverse2DDWTToolStripMenuItem->Name = L"inverse2DDWTToolStripMenuItem";
			this->inverse2DDWTToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->inverse2DDWTToolStripMenuItem->Text = L"In&verse 2D DWT";
			this->inverse2DDWTToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::inverse2DDWTToolStripMenuItem_Click);
			// 
			// show1DlevelsToolStripMenuItem
			// 
			this->show1DlevelsToolStripMenuItem->Name = L"show1DlevelsToolStripMenuItem";
			this->show1DlevelsToolStripMenuItem->Size = System::Drawing::Size(224, 26);
			this->show1DlevelsToolStripMenuItem->Text = L"Show 1D  &levels";
			this->show1DlevelsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::show1DlevelsToolStripMenuItem_Click);
			// 
			// settingsToolStripMenuItem1
			// 
			this->settingsToolStripMenuItem1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->dWTSettingsToolStripMenuItem });
			this->settingsToolStripMenuItem1->Name = L"settingsToolStripMenuItem1";
			this->settingsToolStripMenuItem1->Size = System::Drawing::Size(76, 24);
			this->settingsToolStripMenuItem1->Text = L"&Settings";
			// 
			// dWTSettingsToolStripMenuItem
			// 
			this->dWTSettingsToolStripMenuItem->Name = L"dWTSettingsToolStripMenuItem";
			this->dWTSettingsToolStripMenuItem->Size = System::Drawing::Size(125, 26);
			this->dWTSettingsToolStripMenuItem->Text = L"&DWT";
			this->dWTSettingsToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::dWTSettingsToolStripMenuItem_Click);
			// 
			// splitContainer1
			// 
			this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer1->Location = System::Drawing::Point(0, 0);
			this->splitContainer1->Name = L"splitContainer1";
			this->splitContainer1->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add(this->chrtSignal);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->chart1);
			this->splitContainer1->Size = System::Drawing::Size(980, 591);
			this->splitContainer1->SplitterDistance = 340;
			this->splitContainer1->TabIndex = 2;
			// 
			// chrtSignal
			// 
			chartArea1->Name = L"ChartArea1";
			this->chrtSignal->ChartAreas->Add(chartArea1);
			this->chrtSignal->Dock = System::Windows::Forms::DockStyle::Fill;
			legend1->Name = L"Legend1";
			this->chrtSignal->Legends->Add(legend1);
			this->chrtSignal->Location = System::Drawing::Point(0, 0);
			this->chrtSignal->Name = L"chrtSignal";
			series1->ChartArea = L"ChartArea1";
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			this->chrtSignal->Series->Add(series1);
			this->chrtSignal->Size = System::Drawing::Size(980, 340);
			this->chrtSignal->TabIndex = 0;
			this->chrtSignal->Text = L"chrtSignal";
			title1->Name = L"Signal";
			this->chrtSignal->Titles->Add(title1);
			// 
			// chart1
			// 
			chartArea2->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea2);
			this->chart1->Dock = System::Windows::Forms::DockStyle::Fill;
			legend2->Name = L"Legend1";
			this->chart1->Legends->Add(legend2);
			this->chart1->Location = System::Drawing::Point(0, 0);
			this->chart1->Name = L"chart1";
			series2->ChartArea = L"ChartArea1";
			series2->Legend = L"Legend1";
			series2->Name = L"Series1";
			this->chart1->Series->Add(series2);
			this->chart1->Size = System::Drawing::Size(980, 247);
			this->chart1->TabIndex = 2;
			this->chart1->Text = L"chart1";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(980, 591);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->splitContainer1);
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chrtSignal))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
		//do initializations here
		chrtSignal->Series->Clear();
		chrtSignal->Titles->Add("Signal");

		chart1->Series->Clear();
		chart1->Titles->Add("Wavelet Transform");
	}

	private: void DrawCharts() {

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

		//perform DWT
		Wavelet* wvlt = GetWvlt(GlobalVars::g_SelWvlet);
		wt1(signal, 1, *wvlt);

		//Display the DWT of the signal
		chart1->Series->Clear();
		chart1->ChartAreas[0]->AxisX->Minimum = 0;
		chart1->ChartAreas[0]->AxisX->Maximum = signal.size();
		chart1->ChartAreas[0]->AxisX->Interval = nearestpow10(signal.size())/10;

		DataVisualization::Charting::Series^ series2 = chart1->Series->Add("DWT");
		SetTitle(m_SelWvlt);
		series2->ChartType = DataVisualization::Charting::SeriesChartType::Line;
		
		//copy the DWT into the array m_DWT
		System::Array::Resize(m_DWT, signal.size());
		for (int i = 0; i < signal.size(); i++) {
			series2->Points->AddXY(i, signal[i]);
			m_DWT->SetValue(signal[i], i);
		}
		GlobalVars::g_DWT = m_DWT;
		
	}

	private: void MarkLevelBoundaries(int signalLength) {

		//annotate the level boundaries
		for (int xval = 2; xval < signalLength; xval *= 2) {

			Charting::VerticalLineAnnotation^ annotation = gcnew Charting::VerticalLineAnnotation;

			annotation->IsSizeAlwaysRelative = false;
			annotation->AxisX = chart1->ChartAreas[0]->AxisX;
			annotation->X = xval;
			annotation->LineDashStyle = Charting::ChartDashStyle::Dash;
			annotation->LineColor = Color::Gray;
			annotation->IsInfinitive = true;
			annotation->ClipToChartArea = chart1->ChartAreas[0]->Name;
			annotation->LineWidth = 1;
			annotation->StartCap = Charting::LineAnchorCapStyle::None;
			annotation->EndCap = Charting::LineAnchorCapStyle::None;
			chart1->Annotations->Add(annotation);

		} //xval
	}
	private: void SetTitle(int iSelWvlt){
		System::String^ legendtext;

		legendtext = GetWvltName(iSelWvlt);

		chart1->Titles[0]->Text  = legendtext;
	}
	
	
private: System::Void dWTSettingsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	Wavelet_CppWForms::frmSettings^ fmSettings = gcnew Wavelet_CppWForms::frmSettings();
	fmSettings->ShowDialog();
	m_SelWvlt = fmSettings->m_SelWvlt;
}

/*----------------------------------------------------
* 
* Calculate the Inverse DWT of the array m_DWT
* 
*----------------------------------------------------*/
private: System::Void backwardToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	
	//if resultset is empty do nothing
	if (m_DWT->Length == 0) return;
	int length = m_DWT->Length;
	//clr allows only members of managed type 
	//=> need to do an ugly member-wise copy here
	std::vector<double> signal(length); 
	for (int i = 0; i < length; i++) {
		signal[i] = System::Convert::ToDouble(m_DWT->GetValue(i));
	}
	Wavelet* wvlt = GetWvlt(m_SelWvlt);
	wt1(signal, -1, *wvlt);
	
	chrtSignal->Series->Clear();
	chrtSignal->ChartAreas[0]->AxisX->Minimum = 0;
	chrtSignal->ChartAreas[0]->AxisX->Maximum = signal.size();
	chrtSignal->ChartAreas[0]->AxisX->Interval = nearestpow10(GlobalVars::g_Signal->Length) / 10;

	Charting::Series^ series = chrtSignal->Series->Add("IDWT");
	SetTitle(m_SelWvlt);
	series->ChartType = DataVisualization::Charting::SeriesChartType::Line;
	for (int i = 0; i < signal.size(); i++) {
		series->Points->AddXY(i, signal[i]);
	}
}
//call the signal selection dialog
private: System::Void signalToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	Wavelet_CppWForms::frmSignalSelection^ fmSignalSelection = gcnew Wavelet_CppWForms::frmSignalSelection;
	fmSignalSelection->ShowDialog();
	m_SelSignal = fmSignalSelection->m_SelSignal;
}
private: System::Void openToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	openFileDialog1->Title = "Open Image";
	openFileDialog1->FileName = "";
	openFileDialog1->Filter = "Image Files (*.bmp;*.jpg;*.jpeg,*.png,*.gif)|*.BMP;*.JPG;*.JPEG;*.PNG;*.GIF";
	Wavelet_CppWForms::frmDWT2D^ fmDWT2D = gcnew Wavelet_CppWForms::frmDWT2D;
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		m_ImagePath = openFileDialog1->FileName;
		m_ImageFileName = openFileDialog1->SafeFileName;
	}
}
private: System::Void dDWTToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	Wavelet_CppWForms::frmDWT2D^ fmDWT2D = gcnew  Wavelet_CppWForms::frmDWT2D;

	if (m_ImagePath == nullptr) {
		MessageBox::Show("Select an image file first");
		return;
	}
	fmDWT2D->m_ImagePath = m_ImagePath;
	fmDWT2D->m_ImageFileName = m_ImageFileName;
	fmDWT2D->ShowDialog();
}

private: System::Void DWTToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	DrawCharts();
}
private: System::Void selectSignalToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	Wavelet_CppWForms::frmSignalSelection^ fmSignalSelection = gcnew Wavelet_CppWForms::frmSignalSelection;
	fmSignalSelection->ShowDialog();
	m_SelSignal = fmSignalSelection->m_SelSignal;
}
private: System::Void exportDataToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	Wavelet_CppWForms::frmExport^ fmExport = gcnew Wavelet_CppWForms::frmExport;
	fmExport->ShowDialog();
}
private: System::Void inverse2DDWTToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show("Not yet implemented");
}

private: System::Void show1DlevelsToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
	Wavelet_CppWForms::frmLevels^ fmLevels = gcnew Wavelet_CppWForms::frmLevels;
	fmLevels->ShowDialog();
}
};
}
