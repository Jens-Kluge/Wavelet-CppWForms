#pragma once
#include "Utilities.h"
#include "DWT.h"
#include "Globals.h"

#include <algorithm> //min, max element

namespace Wavelet_CppWForms {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Summary for frmDWT2D
	/// </summary>
	public ref class frmDWT2D : public System::Windows::Forms::Form
	{
	public:
		frmDWT2D(void)
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
		~frmDWT2D()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::SplitContainer^ splitContainer1;
	protected:
	private: System::Windows::Forms::PictureBox^ pbImage;
	private: System::Windows::Forms::PictureBox^ pbDWT;


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
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->pbImage = (gcnew System::Windows::Forms::PictureBox());
			this->pbDWT = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbImage))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbDWT))->BeginInit();
			this->SuspendLayout();
			// 
			// splitContainer1
			// 
			this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer1->Location = System::Drawing::Point(0, 0);
			this->splitContainer1->Name = L"splitContainer1";
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->AutoScroll = true;
			this->splitContainer1->Panel1->Controls->Add(this->pbImage);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->AutoScroll = true;
			this->splitContainer1->Panel2->Controls->Add(this->pbDWT);
			this->splitContainer1->Size = System::Drawing::Size(528, 301);
			this->splitContainer1->SplitterDistance = 254;
			this->splitContainer1->TabIndex = 0;
			// 
			// pbImage
			// 
			this->pbImage->Location = System::Drawing::Point(0, 0);
			this->pbImage->Name = L"pbImage";
			this->pbImage->Size = System::Drawing::Size(254, 301);
			this->pbImage->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pbImage->TabIndex = 0;
			this->pbImage->TabStop = false;
			// 
			// pbDWT
			// 
			this->pbDWT->Location = System::Drawing::Point(0, 0);
			this->pbDWT->Name = L"pbDWT";
			this->pbDWT->Size = System::Drawing::Size(270, 301);
			this->pbDWT->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pbDWT->TabIndex = 0;
			this->pbDWT->TabStop = false;
			// 
			// frmDWT2D
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(528, 301);
			this->Controls->Add(this->splitContainer1);
			this->Name = L"frmDWT2D";
			this->Text = L"frmDWT2D";
			this->Load += gcnew System::EventHandler(this, &frmDWT2D::frmDWT2D_Load);
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel1->PerformLayout();
			this->splitContainer1->Panel2->ResumeLayout(false);
			this->splitContainer1->Panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbImage))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbDWT))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion

		//member variables
		public:
			String^ m_ImagePath;
			String^ m_ImageFileName;

			cli::array<int, 2>^ m_GreyImage;
			cli::array<int, 2>^ m_padGreyImage;

	private: System::Void frmDWT2D_Load(System::Object^ sender, System::EventArgs^ e) {
		
		//Set form caption
		if (m_ImageFileName != nullptr) {
			this->Text = String::Format("{0} {1}",m_ImageFileName, GetWvltName(GlobalVars::g_SelWvlet));
		}
		//Load Image, Calculate 2D DWT and display result
		pbImage->Load(m_ImagePath);
		
		ReadImageData();
		CreatePaddedImage();
		
		std::vector<double> data;
		int width, height;
		ComputeDWT2D(data, width, height);
		Bitmap^ bmp = WriteImageData(data, width, height);
		pbDWT->Image = bmp;

	}

	//for debug purposes, to check if grey image is correct
	private: void DisplayGreyImage() {
		int i, j;

		int width, height;
		height = m_padGreyImage->GetLength(0);
		width = m_padGreyImage->GetLength(1);
		Bitmap^ output = gcnew Bitmap(width, height);

		Imaging::BitmapData^ bitmapData1 = output->LockBits(Rectangle(0, 0, width, height),
			Imaging::ImageLockMode::ReadOnly, Imaging::PixelFormat::Format32bppArgb);

		IntPtr^ pbm = bitmapData1->Scan0;
		Byte* imagePointer1 = (Byte*)pbm->ToPointer();

		int index, intvalue;
		for (i = 0; i < height; i++)
		{
			for (j = 0; j < width; j++)
			{
				intvalue = m_padGreyImage[i, j];
				imagePointer1[0] = (Byte)intvalue;
				imagePointer1[1] = (Byte)intvalue;
				imagePointer1[2] = (Byte)intvalue;
				imagePointer1[3] = 255;
				//4 bytes per pixel
				imagePointer1 += 4;
			}//end for j
			//4 bytes per pixel
			imagePointer1 += (bitmapData1->Stride - (bitmapData1->Width * 4));
		}//end for i

		output->UnlockBits(bitmapData1);
		pbDWT->Image = output;
	}

	private: void ComputeDWT2D(std::vector<double> &a, int &width, int&height) {

		// Write image data into vector<double> 
		height = m_padGreyImage->GetLength(0);
		width = m_padGreyImage->GetLength(1);
		
		std::vector<int> dims = {width, height};
		std::vector<double> data(width * height);
		
		int index = 0;
		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				data[index] = m_padGreyImage[i, j];
				index++;
			}
		}
		
		Wavelet* pwvlt = GetWvlt(GlobalVars::g_SelWvlet);
		wtn(data, dims, 1, *pwvlt);
		a = data;
	}

	private: void ReadImageData() {

		int i, j;
		
		try {

			FileStream^ fs = gcnew FileStream(m_ImagePath, FileMode::Open, FileAccess::Read);
			Bitmap^ bm = gcnew Bitmap(fs);
			m_GreyImage = gcnew cli::array<int, 2>(bm->Height, bm->Width);

			Imaging::BitmapData^ bitmapData1 = bm->LockBits(Rectangle(0, 0, bm->Width, bm->Height),
				Imaging::ImageLockMode::ReadOnly, Imaging::PixelFormat::Format32bppArgb);

			IntPtr^ pbm = bitmapData1->Scan0;

			Byte* imagePointer1 = (Byte*)pbm->ToPointer();
			for (i = 0; i < bitmapData1->Height; i++)
			{
				for (j = 0; j < bitmapData1->Width; j++)
				{
					m_GreyImage[i, j] = (int)((imagePointer1[0] + imagePointer1[1] + imagePointer1[2]) / 3.0);
					//4 bytes per pixel
					imagePointer1 += 4;
				}//end for j
				//4 bytes per pixel
				imagePointer1 += bitmapData1->Stride - (bitmapData1->Width * 4);
			}//end for i
			bm->UnlockBits(bitmapData1);
		}
		catch(Exception^ ex) {
			MessageBox::Show(ex->Message);
		}
		return;
	}

	private: void CreatePaddedImage() {

		int height = m_GreyImage->GetLength(0);
		int width = m_GreyImage->GetLength(1);
		int padheight = nextpow2(height);
		int padwidth = nextpow2(width);

		m_padGreyImage = gcnew cli::array<int, 2>(padheight, padwidth);

		int topmargin = (padheight - height) / 2;
		int leftmargin = (padwidth - width) / 2;

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				m_padGreyImage[topmargin+i,leftmargin+j] =  m_GreyImage[i, j];
			}
		}
		GlobalVars::g_Image = m_padGreyImage;
	}

	private: Bitmap^ WriteImageData(vector<double> data, int width, int height) {
		int i, j;

		Bitmap^ output = gcnew Bitmap(width, height);
		GlobalVars::g_2DDWT = gcnew cli::array<double,2>(width, height);

		Imaging::BitmapData^ bitmapData1 = output->LockBits(Rectangle(0, 0, width, height),
			Imaging::ImageLockMode::ReadOnly, Imaging::PixelFormat::Format32bppArgb);

		IntPtr^ pbm = bitmapData1->Scan0;
		Byte* imagePointer1 = (Byte*)pbm->ToPointer();
		
		//compute scaling factor for display
		double min = *std::min_element(data.begin(), data.end());
		double max = *std::max_element(data.begin(), data.end());
		double value;
		int intvalue;

		int index;
		//read out data in row major order 
		//=> loop through columns in inner loop
		for (i = 0; i < height; i++)
		{
			for (j = 0; j < width; j++)
			{	
				index = i * width + j;
				value = data[index];
				
				//store result in global variable
				GlobalVars::g_2DDWT[i, j] = value;
				// apply dynamic range compression
				// by logarithmic scaling
				Color col;
				//for better visualization set small values to white
				if (abs(value) < 10) {
					col = Color::White;
				}
				else {
					if (value < 0) {
						value = -log(1 + abs(value));
						value = value / log(1 + abs(min));
					}
					else {
						value = log(1 + value);
						value = value / log(1 + abs(max));
					}
					//map value into range [0,1]
					value = value / 2.0 + 0.5;
					_ASSERT_EXPR(value >= 0 && value <= 1, L"value not in [0,1]!");
					//apply color coding
					col = Utilities::RainbowNumberToColor(value);
				}
				
				
				imagePointer1[0] = (Byte)col.B;
				imagePointer1[1] = (Byte)col.G;
				imagePointer1[2] = (Byte)col.R;
				imagePointer1[3] = 255;
				//4 bytes per pixel
				imagePointer1 += 4;
			}//end for j
			//4 bytes per pixel
			imagePointer1 += (bitmapData1->Stride - (bitmapData1->Width * 4));
		}//end for i
		
		output->UnlockBits(bitmapData1);
		return output;// col;
	}
	

};
}
