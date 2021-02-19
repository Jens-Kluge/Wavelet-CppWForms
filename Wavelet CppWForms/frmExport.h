#pragma once
#include "ExcelUtils.h"

namespace Wavelet_CppWForms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for frmExport
	/// </summary>
	public ref class frmExport : public System::Windows::Forms::Form
	{
	public:
		frmExport(void)
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
		~frmExport()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnClose;
	private: System::Windows::Forms::Button^ btnExport;
	private: System::Windows::Forms::SaveFileDialog^ sfdExport;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::RadioButton^ rb2DDWT;
	private: System::Windows::Forms::RadioButton^ rb1DDWT;
	private: System::Windows::Forms::RadioButton^ rbImage;
	private: System::Windows::Forms::RadioButton^ rbSignal;
	protected:

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
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->btnExport = (gcnew System::Windows::Forms::Button());
			this->sfdExport = (gcnew System::Windows::Forms::SaveFileDialog());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->rbSignal = (gcnew System::Windows::Forms::RadioButton());
			this->rbImage = (gcnew System::Windows::Forms::RadioButton());
			this->rb1DDWT = (gcnew System::Windows::Forms::RadioButton());
			this->rb2DDWT = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnClose
			// 
			this->btnClose->Location = System::Drawing::Point(197, 133);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(139, 29);
			this->btnClose->TabIndex = 0;
			this->btnClose->Text = L"&Close";
			this->btnClose->UseVisualStyleBackColor = true;
			this->btnClose->Click += gcnew System::EventHandler(this, &frmExport::btnClose_Click);
			// 
			// btnExport
			// 
			this->btnExport->Location = System::Drawing::Point(197, 79);
			this->btnExport->Name = L"btnExport";
			this->btnExport->Size = System::Drawing::Size(139, 31);
			this->btnExport->TabIndex = 1;
			this->btnExport->Text = L"E&xport to Excel file";
			this->btnExport->UseVisualStyleBackColor = true;
			this->btnExport->Click += gcnew System::EventHandler(this, &frmExport::btnExport_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->rb2DDWT);
			this->groupBox1->Controls->Add(this->rb1DDWT);
			this->groupBox1->Controls->Add(this->rbImage);
			this->groupBox1->Controls->Add(this->rbSignal);
			this->groupBox1->Location = System::Drawing::Point(26, 31);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(124, 137);
			this->groupBox1->TabIndex = 2;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Dataset";
			// 
			// rbSignal
			// 
			this->rbSignal->AutoSize = true;
			this->rbSignal->Location = System::Drawing::Point(8, 21);
			this->rbSignal->Name = L"rbSignal";
			this->rbSignal->Size = System::Drawing::Size(68, 21);
			this->rbSignal->TabIndex = 0;
			this->rbSignal->TabStop = true;
			this->rbSignal->Text = L"Signal";
			this->rbSignal->UseVisualStyleBackColor = true;
			// 
			// rbImage
			// 
			this->rbImage->AutoSize = true;
			this->rbImage->Location = System::Drawing::Point(8, 75);
			this->rbImage->Name = L"rbImage";
			this->rbImage->Size = System::Drawing::Size(67, 21);
			this->rbImage->TabIndex = 1;
			this->rbImage->TabStop = true;
			this->rbImage->Text = L"Image";
			this->rbImage->UseVisualStyleBackColor = true;
			// 
			// rb1DDWT
			// 
			this->rb1DDWT->AutoSize = true;
			this->rb1DDWT->Location = System::Drawing::Point(8, 48);
			this->rb1DDWT->Name = L"rb1DDWT";
			this->rb1DDWT->Size = System::Drawing::Size(83, 21);
			this->rb1DDWT->TabIndex = 2;
			this->rb1DDWT->TabStop = true;
			this->rb1DDWT->Text = L"1D DWT";
			this->rb1DDWT->UseVisualStyleBackColor = true;
			// 
			// rb2DDWT
			// 
			this->rb2DDWT->AutoSize = true;
			this->rb2DDWT->Location = System::Drawing::Point(8, 102);
			this->rb2DDWT->Name = L"rb2DDWT";
			this->rb2DDWT->Size = System::Drawing::Size(83, 21);
			this->rb2DDWT->TabIndex = 3;
			this->rb2DDWT->TabStop = true;
			this->rb2DDWT->Text = L"2D DWT";
			this->rb2DDWT->UseVisualStyleBackColor = true;
			// 
			// frmExport
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(375, 210);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->btnExport);
			this->Controls->Add(this->btnClose);
			this->Name = L"frmExport";
			this->Text = L"frmExport";
			this->Load += gcnew System::EventHandler(this, &frmExport::frmExport_Load);
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnExport_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ fname;
		//set properties of select file control
		sfdExport->Filter = "Excel files (*.xlsx)|*.xlsx";
		sfdExport->FileName = "Mydata.xlsx";


		sfdExport->InitialDirectory = Environment::GetFolderPath(Environment::SpecialFolder::Desktop);

		if (sfdExport->ShowDialog() == Windows::Forms::DialogResult::OK) {
			fname = sfdExport->FileName;
		}
		else {
			return;
		}
		

		if (rbSignal->Checked) {
			if (GlobalVars::g_Signal == nullptr) return;
			cli::array<double, 2>^ arrsignal = gcnew cli::array<double, 2>(GlobalVars::g_Signal->Length, 1);
			for (int i = 0; i < GlobalVars::g_Signal->Length; i++) {
				arrsignal[i, 0] = GlobalVars::g_Signal[i];
			}
			ExportDatasetToExcel(fname, arrsignal, "Signal");
		}
		else if (rb1DDWT->Checked) {
			if (GlobalVars::g_DWT == nullptr) return;
			cli::array<double, 2>^ arrsignal = gcnew cli::array<double, 2>(GlobalVars::g_DWT->Length, 1);
			for (int i = 0; i < GlobalVars::g_DWT->Length; i++) {
				arrsignal[i, 0] = GlobalVars::g_DWT[i];
			}
			ExportDatasetToExcel(fname, arrsignal, "1D DWT");
		}
		else if (rbImage->Checked) {
			if (GlobalVars::g_Image == nullptr) return;
			ExportDatasetToExcel(fname, GlobalVars::g_Image, "Image");
		}
		else if (rb2DDWT->Checked) {
			if (GlobalVars::g_2DDWT == nullptr) return;
			ExportDatasetToExcel(fname, GlobalVars::g_2DDWT, "2D DWT");
		}
	}

	private: System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e) {
		Close();
	}

	private: System::Void frmExport_Load(System::Object^ sender, System::EventArgs^ e) {
		rbSignal->Checked = true;
	}
};
}
