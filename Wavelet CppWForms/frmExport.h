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
			this->SuspendLayout();
			// 
			// btnClose
			// 
			this->btnClose->Location = System::Drawing::Point(68, 92);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(116, 29);
			this->btnClose->TabIndex = 0;
			this->btnClose->Text = L"&Close";
			this->btnClose->UseVisualStyleBackColor = true;
			this->btnClose->Click += gcnew System::EventHandler(this, &frmExport::btnClose_Click);
			// 
			// btnExport
			// 
			this->btnExport->Location = System::Drawing::Point(68, 38);
			this->btnExport->Name = L"btnExport";
			this->btnExport->Size = System::Drawing::Size(116, 31);
			this->btnExport->TabIndex = 1;
			this->btnExport->Text = L"E&xport to Excel";
			this->btnExport->UseVisualStyleBackColor = true;
			this->btnExport->Click += gcnew System::EventHandler(this, &frmExport::btnExport_Click);
			// 
			// frmExport
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(257, 150);
			this->Controls->Add(this->btnExport);
			this->Controls->Add(this->btnClose);
			this->Name = L"frmExport";
			this->Text = L"frmExport";
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

		//copy signal data into 2D array
		if (GlobalVars::g_Signal == nullptr) return;

		cli::array<double, 2>^ arrtest = gcnew cli::array<double,2>(GlobalVars::g_Signal->Length, 1);
		for (int i = 0; i < GlobalVars::g_Signal->Length; i++) {
			arrtest[i,0] = GlobalVars::g_Signal[i];
		}
		ExportDatasetToExcel(fname, arrtest);
	}
	private: System::Void btnClose_Click(System::Object^ sender, System::EventArgs^ e) {
		Close();
	}
	};
}
