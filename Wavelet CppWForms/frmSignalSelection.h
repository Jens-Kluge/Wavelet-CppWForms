#pragma once
#include "SignalGenerator.h"
#include "Globals.h"
#include "ExcelUtils.h"
#include "Utilities.h"

namespace Wavelet_CppWForms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Runtime::InteropServices;
	namespace Excel = Microsoft::Office::Interop::Excel;
	using namespace System::Reflection;

	/// <summary>
	/// Summary for SignalSelection
	/// </summary>
	public ref class frmSignalSelection : public System::Windows::Forms::Form
	{
	public:
		frmSignalSelection(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::Button^ btnStartXL;
	private: RefEditControl::RefEdit^ refEdit1;
	private: System::Windows::Forms::Button^ btnExtendRange;
	private: System::Windows::Forms::ToolTip^ toolTip1;
	private: System::Windows::Forms::Button^ btnRead;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::ListBox^ lstSignal;
	private: System::Windows::Forms::GroupBox^ groupBox3;
	private: System::Windows::Forms::RadioButton^ rbCenter;
	private: System::Windows::Forms::RadioButton^ rbBeginning;
	private: System::Windows::Forms::RadioButton^ rbEnd;
	
	//member variables
	public:
		cli::array<double>^ m_Signal = nullptr;
		SignalType m_SelSignal;

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~frmSignalSelection()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:

	private: System::Windows::Forms::Button^ btnOK;
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(frmSignalSelection::typeid));
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->btnOK = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->btnRead = (gcnew System::Windows::Forms::Button());
			this->btnExtendRange = (gcnew System::Windows::Forms::Button());
			this->refEdit1 = (gcnew RefEditControl::RefEdit());
			this->btnStartXL = (gcnew System::Windows::Forms::Button());
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->lstSignal = (gcnew System::Windows::Forms::ListBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->rbCenter = (gcnew System::Windows::Forms::RadioButton());
			this->rbBeginning = (gcnew System::Windows::Forms::RadioButton());
			this->rbEnd = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->groupBox2->SuspendLayout();
			this->groupBox3->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnOK
			// 
			this->btnOK->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->btnOK->Location = System::Drawing::Point(602, 348);
			this->btnOK->Name = L"btnOK";
			this->btnOK->Size = System::Drawing::Size(81, 30);
			this->btnOK->TabIndex = 2;
			this->btnOK->Text = L"&OK";
			this->btnOK->UseVisualStyleBackColor = true;
			this->btnOK->Click += gcnew System::EventHandler(this, &frmSignalSelection::btnOK_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->btnRead);
			this->groupBox1->Controls->Add(this->btnExtendRange);
			this->groupBox1->Controls->Add(this->refEdit1);
			this->groupBox1->Controls->Add(this->btnStartXL);
			this->groupBox1->Location = System::Drawing::Point(24, 19);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(244, 114);
			this->groupBox1->TabIndex = 3;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Excel Import";
			// 
			// btnRead
			// 
			this->btnRead->Enabled = false;
			this->btnRead->Location = System::Drawing::Point(134, 67);
			this->btnRead->Name = L"btnRead";
			this->btnRead->Size = System::Drawing::Size(104, 28);
			this->btnRead->TabIndex = 4;
			this->btnRead->Text = L"&Import data";
			this->btnRead->UseVisualStyleBackColor = true;
			this->btnRead->Click += gcnew System::EventHandler(this, &frmSignalSelection::btnRead_Click);
			// 
			// btnExtendRange
			// 
			this->btnExtendRange->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnExtendRange.BackgroundImage")));
			this->btnExtendRange->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->btnExtendRange->Location = System::Drawing::Point(201, 33);
			this->btnExtendRange->Name = L"btnExtendRange";
			this->btnExtendRange->Size = System::Drawing::Size(21, 25);
			this->btnExtendRange->TabIndex = 3;
			this->toolTip1->SetToolTip(this->btnExtendRange, L"Extend range downwards");
			this->btnExtendRange->UseVisualStyleBackColor = true;
			this->btnExtendRange->Click += gcnew System::EventHandler(this, &frmSignalSelection::btnExtendRange_Click);
			// 
			// refEdit1
			// 
			this->refEdit1->_Excel = nullptr;
			this->refEdit1->AllowCollapsedFormResize = false;
			this->refEdit1->AutoSize = true;
			this->refEdit1->Location = System::Drawing::Point(6, 31);
			this->refEdit1->Name = L"refEdit1";
			this->refEdit1->Size = System::Drawing::Size(197, 28);
			this->refEdit1->TabIndex = 2;
			// 
			// btnStartXL
			// 
			this->btnStartXL->Location = System::Drawing::Point(6, 67);
			this->btnStartXL->Name = L"btnStartXL";
			this->btnStartXL->Size = System::Drawing::Size(104, 28);
			this->btnStartXL->TabIndex = 1;
			this->btnStartXL->Text = L"&Start Excel";
			this->btnStartXL->UseVisualStyleBackColor = true;
			this->btnStartXL->Click += gcnew System::EventHandler(this, &frmSignalSelection::btnStartXL_Click);
			// 
			// chart1
			// 
			this->chart1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(24, 155);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(659, 177);
			this->chart1->TabIndex = 4;
			this->chart1->Text = L"chart1";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->lstSignal);
			this->groupBox2->Location = System::Drawing::Point(318, 19);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(166, 114);
			this->groupBox2->TabIndex = 5;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Generated Signal";
			// 
			// lstSignal
			// 
			this->lstSignal->FormattingEnabled = true;
			this->lstSignal->ItemHeight = 16;
			this->lstSignal->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Sawtooth", L"Sine", L"Square", L"Triangle" });
			this->lstSignal->Location = System::Drawing::Point(15, 21);
			this->lstSignal->Name = L"lstSignal";
			this->lstSignal->Size = System::Drawing::Size(79, 68);
			this->lstSignal->TabIndex = 1;
			this->lstSignal->SelectedIndexChanged += gcnew System::EventHandler(this, &frmSignalSelection::lstSignal_SelectedIndexChanged);
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->rbCenter);
			this->groupBox3->Controls->Add(this->rbBeginning);
			this->groupBox3->Controls->Add(this->rbEnd);
			this->groupBox3->Location = System::Drawing::Point(507, 19);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(121, 114);
			this->groupBox3->TabIndex = 6;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Padding";
			// 
			// rbCenter
			// 
			this->rbCenter->AutoSize = true;
			this->rbCenter->Location = System::Drawing::Point(7, 78);
			this->rbCenter->Name = L"rbCenter";
			this->rbCenter->Size = System::Drawing::Size(71, 21);
			this->rbCenter->TabIndex = 2;
			this->rbCenter->TabStop = true;
			this->rbCenter->Text = L"Center";
			this->rbCenter->UseVisualStyleBackColor = true;
			// 
			// rbBeginning
			// 
			this->rbBeginning->AutoSize = true;
			this->rbBeginning->Location = System::Drawing::Point(7, 50);
			this->rbBeginning->Name = L"rbBeginning";
			this->rbBeginning->Size = System::Drawing::Size(92, 21);
			this->rbBeginning->TabIndex = 1;
			this->rbBeginning->TabStop = true;
			this->rbBeginning->Text = L"Beginning";
			this->rbBeginning->UseVisualStyleBackColor = true;
			// 
			// rbEnd
			// 
			this->rbEnd->AutoSize = true;
			this->rbEnd->Location = System::Drawing::Point(7, 22);
			this->rbEnd->Name = L"rbEnd";
			this->rbEnd->Size = System::Drawing::Size(54, 21);
			this->rbEnd->TabIndex = 0;
			this->rbEnd->TabStop = true;
			this->rbEnd->Text = L"End";
			this->rbEnd->UseVisualStyleBackColor = true;
			// 
			// frmSignalSelection
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(721, 390);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->btnOK);
			this->Name = L"frmSignalSelection";
			this->Text = L"SignalSelection";
			this->Load += gcnew System::EventHandler(this, &frmSignalSelection::SignalSelection_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void btnOK_Click(System::Object^ sender, System::EventArgs^ e) {
		GlobalVars::g_SelWvlet = lstSignal->SelectedIndex;
		Close();
	}

	private: void GenerateSignal() {

		m_SelSignal = (SignalType)lstSignal->SelectedIndex;
		
		const int arrlen = 512;
		
		Array::Resize(GlobalVars::g_Signal, arrlen);

		double step = 0.01 * 2 * M_PI;
		SignalGenerator^ SigGen = gcnew SignalGenerator;
		SigGen->sigType = m_SelSignal;

		//initialize signal
		for (int i = 0; i < arrlen; i++) {
			GlobalVars::g_Signal[i] = SigGen->GetValue((float)(10 * i) / (arrlen - 1));
		}
		
	}

	private: System::Void SignalSelection_Load(System::Object^ sender, System::EventArgs^ e) {

		lstSignal->SelectedIndex = enSignalType::Sawtooth;
		//Excel has been started by the application
		
		//Excel has not yet been started by the application
		if (GlobalVars::g_Excel == nullptr) {
			refEdit1->Enabled = false;
			btnStartXL->Enabled = true;
			btnRead->Enabled = false;
		}
		else {
			
			refEdit1->_Excel = GlobalVars::g_Excel;
			btnStartXL->Enabled = false;
			btnRead->Enabled = true;

			try {
				GlobalVars::g_Excel->Visible = true;
			}
			//Excel has been terminated by the user
			catch (Exception^ ex) {
				refEdit1->Enabled = false;
				btnStartXL->Enabled = true;
				btnRead->Enabled = false;
			}
		}
		
		rbEnd->Checked = true;
	}
	private: System::Void btnStartXL_Click(System::Object^ sender, System::EventArgs^ e) {
		try {
			GlobalVars::g_Excel = gcnew Excel::ApplicationClass();
			GlobalVars::g_Excel->Visible = true;
			refEdit1->_Excel = GlobalVars::g_Excel;
			refEdit1->Enabled = true;
			btnStartXL->Enabled = false;
			btnRead->Enabled = true;
		}
		catch (Exception^ ex) {
			MessageBox::Show(ex->Message);
		}
	}

	/*
		extend XL range downwards until no numeric value is found
	*/
	private: System::Void btnExtendRange_Click(System::Object^ sender, System::EventArgs^ e) {
		Excel::Range^ rg1 = nullptr;
		Excel::Range^ rg2 = nullptr;
		bool ok = false;
		String^ addr;


		ExcelUtils::GetRange(rg1, refEdit1->Text, ok);
		if (!ok) return;

		ExcelUtils::ExtendRange2(rg1, rg2);
		rg2->Select();
		addr = rg2->Address[false, false, Excel::XlReferenceStyle::xlA1, Type::Missing, Type::Missing];
		/*if (refEdit1->IncludeSheetName) {
			addr = "'" + safe_cast<Excel::Worksheet^>(refEdit1->_Excel->ActiveSheet)->Name + "'!" + addr;
		}*/
		refEdit1->Text = addr;
	}

	//This is too slow for large data sizes
	private: System::Void btnRead_Click(System::Object^ sender, System::EventArgs^ e) {
		
		Excel::Range^ rg = nullptr;
		bool ok;

		this->Cursor = Cursors::WaitCursor;

		ExcelUtils::GetRange(rg, refEdit1->Text, ok);
		if (!ok) {
			this->Cursor = Cursors::Arrow;
			return;
		}

		/* dispose previous m_signal bef allocating new one?*/
		std::vector<double> signal(rg->Rows->Count);
	
		cli::array<Object^, 2>^ arrData = safe_cast<cli::array<Object^, 2>^>(rg->Value[Excel::XlRangeValueDataType::xlRangeValueDefault]);

		/* copy values into signal vector*/
		for (int i = 0; i < signal.size(); i++) {
			signal[i] = Convert::ToDouble(arrData[i + 1, 1]);
		}
		
		std::vector<double> paddedsignal;
		/* pad the signal vector*/
		if (rbEnd->Checked) {
			 paddedsignal = padsignal(signal);
		} 
		else if (rbCenter->Checked) {
			paddedsignal = padsignal(signal, enpadmode::center);
		}
		else if (rbBeginning->Checked) {
			paddedsignal = padsignal(signal, enpadmode::begin);
		}

		/* now copy padded signal vector into global vector*/
		Array::Resize(GlobalVars::g_Signal, paddedsignal.size());
		for (int i = 0; i < paddedsignal.size(); i++) {
			GlobalVars::g_Signal[i] = paddedsignal[i];
		}

		DisplaySignal();

		this->Cursor = Cursors::Arrow;
	}
	//Read out m_Signal and display signal in chart control
	private: void DisplaySignal() {
		chart1->Series->Clear();
		chart1->ChartAreas[0]->AxisX->Minimum = 0;
		chart1->ChartAreas[0]->AxisX->Maximum = GlobalVars::g_Signal->Length;

		DataVisualization::Charting::Series^ series1 = chart1->Series->Add("Signal");
		series1->ChartType = DataVisualization::Charting::SeriesChartType::Line;
		for (int i = 0; i < GlobalVars::g_Signal->Length; i++) {
			series1->Points->AddXY(i, GlobalVars::g_Signal[i]);
		}
	}

	private: System::Void lstSignal_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		GenerateSignal();
		DisplaySignal();
	}
}; //ref class
}  //namespace