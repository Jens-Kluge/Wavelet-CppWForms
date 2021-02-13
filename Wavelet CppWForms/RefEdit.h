#pragma once
#include "enums.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Runtime::InteropServices;
namespace Excel =  Microsoft::Office::Interop::Excel;
using namespace System::Reflection;

namespace refeditControl {

	/// <summary>
	/// Event handler for the CellChange Event
	/// </summary>
	/// <param name="sender"></param>
	/// <param name="e"></param>
	public delegate void refeditCellChangeEventHandler(Object^ sender, EventArgs^ e);

	/// <summary>
	/// Event handler for Restore (form)  Event
	/// </summary>
	/// <param name="sender"></param>
	/// <param name="e"></param>
	public delegate void refeditRestoreEventHandler(Object^ sender, EventArgs^ e);

	/// <summary>
	/// Summary for RefEdit
	/// </summary>
	[ToolboxBitmap(RefEdit::typeid, "RefEdit.bmp")]
	public ref class RefEdit : public System::Windows::Forms::UserControl
	{
	public:
		RefEdit(void)
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
		~RefEdit()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textRange;
	protected:
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::ImageList^ imageList1;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(RefEdit::typeid));
			this->textRange = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->imageList1 = (gcnew System::Windows::Forms::ImageList(this->components));
			this->SuspendLayout();
			// 
			// textRange
			// 
			this->textRange->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textRange->Location = System::Drawing::Point(3, 3);
			this->textRange->Name = L"textRange";
			this->textRange->Size = System::Drawing::Size(131, 22);
			this->textRange->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->button1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.Image")));
			this->button1->Location = System::Drawing::Point(140, 3);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(26, 22);
			this->button1->TabIndex = 1;
			this->button1->UseVisualStyleBackColor = true;
			// 
			// imageList1
			// 
			this->imageList1->ColorDepth = System::Windows::Forms::ColorDepth::Depth8Bit;
			this->imageList1->ImageSize = System::Drawing::Size(16, 16);
			this->imageList1->TransparentColor = System::Drawing::Color::Transparent;
			// 
			// RefEdit
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textRange);
			this->Name = L"RefEdit";
			this->Size = System::Drawing::Size(169, 31);
			this->Load += gcnew System::EventHandler(this, &RefEdit::RefEdit_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private:
		Excel::Application^ oExcel;
		const Excel::XlReferenceStyle A1 = Excel::XlReferenceStyle::xlA1;
		String^ _CollapsedFormCaption = "Select Range";
		String^ parentCaption;
		String^ _ActiveSheetName = "";
		String^ thisBookName = "";
		String^ thisSheetName = "";
		String^ _DisplayResultSeparator = " ";
		ResultSeparator _ResultSeparator = ResultSeparator::Space;
		HorizontalAlignment _textAlign = HorizontalAlignment::Left;
		bool _AllowMultipleCells = true;
		bool _AllowCollapsedResize;
		bool _AllowTextEntry = true;
		bool _showEditField = true;
		bool oldshowEditField = true;
		bool excelMoveCursorOnEnter = true;
		int _bigSize = 150;
		bool isCollapsed;
		bool _Entered;
		bool RowAbsolute;
		bool ColAbsolute;
		int _adjustHeight;
		bool topMostForm;
		Point thisLocation;
		System::Drawing::Size^ thisSize;
		System::Drawing::Size^ thisFormSize;
		Control^ parentControl;
		Form^ thisForm;
		Form^ MDIForm;
		MainMenu^ thisFormMenu;
		MainMenu^ MDIFormMenu;
		//readonly Logger _xlLogger = new Logger();
		AnchorStyles anchorControl;
		DockStyle dockStyle;
		FormBorderStyle borderStyle;

		ReferenceStyle _Relativity = ReferenceStyle::Absolute;
		CollapseStyle _CollapseStyle = CollapseStyle::CollapseFormAndFitCellSelector;
		DisplayStyle _DisplayStyle = DisplayStyle::AddressRange;

		Hashtable^ visibles;
		ArrayList^ parents;
		Hashtable^ MDIvisibles;

	public:
		refeditCellChangeEventHandler^ OnCellChanged;
		/// <summary>
		/// The event to raise when the cell reference changes
		/// </summary>
		[Description("Occurs when the cell reference changes")]
		event refeditCellChangeEventHandler^ CellChanged {
			void add(refeditCellChangeEventHandler^ p) {
				OnCellChanged = static_cast<refeditCellChangeEventHandler^> (Delegate::Combine(OnCellChanged, p));
			}

			void remove(refeditCellChangeEventHandler^ p) {
				OnCellChanged = static_cast<refeditCellChangeEventHandler^> (Delegate::Remove(OnCellChanged, p));
			}

			void raise(Object^ sender, EventArgs^ e) {
				if (OnCellChanged != nullptr)
					OnCellChanged->Invoke(sender, e);
			}
		}

		refeditRestoreEventHandler^ OnRestore;
		/// <summary>
		/// The event to raise when the refedit control restores
		/// </summary>
		event refeditRestoreEventHandler^ Restore {

			void add(refeditRestoreEventHandler^ p) {
				OnRestore = static_cast<refeditRestoreEventHandler^> (Delegate::Combine(OnRestore, p));
			}

			void remove(refeditRestoreEventHandler^ p) {
				OnRestore = static_cast<refeditRestoreEventHandler^> (Delegate::Remove(OnRestore, p));
			}

			void raise(Object^ sender, EventArgs^ e) {
				if (OnRestore != nullptr)
					OnRestore->Invoke(sender, e);
			}
		}


		/// <summary>
		/// A reference to the Excel Application
		/// </summary>
		public: [Browsable(false)]  property Excel::Application^ _Excel
		{
			Excel::Application^ get()
			{
				try
				{
					if (oExcel != nullptr)
					{
						return oExcel;
					}
				}
				catch (Exception^ ex)
				{
					//_xlLogger.LogException(MethodBase.GetCurrentMethod().DeclaringType.Name, ex.ToString(), MethodBase.GetCurrentMethod().Name);
				}
				return nullptr;
			}


			void set(Excel::Application^ value)
			{
				try
				{
					oExcel = value;
				}
				catch (Exception^ ex)
				{
					//_xlLogger.LogException(MethodBase.GetCurrentMethod().DeclaringType.Name, ex.ToString(), MethodBase.GetCurrentMethod().Name);
				}
			}
		};
		/// <summary>
		/// Returns the Collapsed state of the control
		/// </summary>
		[Browsable(false)] property bool collapsedButtonState
		{
				bool get()
				{
					  return isCollapsed;
				 }
		 };

		 /// <summary>
		 /// Indicates how the text should be aligned
		 /// </summary>
		 [Category("Appearance"), Description("Indicates how the text should be aligned"), DefaultValue(HorizontalAlignment::Left)] 
		 property HorizontalAlignment TextAlign
		 {
				  HorizontalAlignment get()
				  {
					  return _textAlign;
				  }
				  void set(HorizontalAlignment value)
				  {
					  _textAlign = value;
				  }
		  };


		 /// <summary>
		/// The Row/Column relatively of the displayed range
		/// </summary>
		 [Category("Refedit"), Description("The Row/Column relatively of the displayed range"), DefaultValue(ReferenceStyle::Absolute)] 
		 property ReferenceStyle Relativity
		 {
			 ReferenceStyle get()
			 {
				 return _Relativity;
			 }
			 void set(ReferenceStyle value)
			 {
				 _Relativity = value;
				 RowAbsolute = ((_Relativity == ReferenceStyle::Absolute) | (_Relativity == ReferenceStyle::ColumnRelative));
				 ColAbsolute = ((_Relativity == ReferenceStyle::Absolute) | (_Relativity == ReferenceStyle::RowRelative));
			 }
		 };

		 /// <summary>
		 /// The Text displayed in the control
		 /// </summary>
		 [Category("Refedit"), Description("The Text displayed in the control"), DefaultValue("")] 
		 property String^ Text 
		 {
			 String^ get() override
			 {
				 return textRange->Text;
			 }
			 void set(String^ value) override
			 {
				 textRange->Text = value;
			 }
		 };

		/// <summary>
		/// The behaviour of the parent form when the selector button is clicked
		/// </summary>
		 [Category("Refedit"), Description("The behaviour of the parent form when the selector button is clicked"), DefaultValue(CollapseStyle::CollapseFormAndFitCellSelector)]
		 property CollapseStyle CollapseFormStyle
		 {
			 CollapseStyle get()
			 {
				 return _CollapseStyle;
			 }
			 void set(CollapseStyle value)
			 {
				 _CollapseStyle = value;
			 }
		 };

		/// <summary>
		/// The caption to display on the form while it is in a collapsed state
		/// </summary>
		 [Category("Refedit"), Description("The caption to display on the form while it is in a collapsed state"), DefaultValue("Select Range")]
		 property String^ CollapsedFormCaption
		 {
			 String^ get()
			 {
				 return _CollapsedFormCaption;
			 }
			 void set(String^ value)
			 {
				 _CollapsedFormCaption = value;
			 }
		 };

		 /// <summary>
		/// Determines whether the control's parent form can be resized when it is in Collapsed mode
		/// </summary>
		 [Category("Refedit"), Description("Determines whether the control's parent form can be resized when it is in Collapsed mode"), DefaultValue(true)]
		 property bool AllowCollapsedFormResize
		 {
			 bool get()
			 {
				 return _AllowCollapsedResize;
			 }
			 void set(bool value)
			 {
				 _AllowCollapsedResize = value;
			 }
		 };

		 /// <summary>
		/// Determines whether single cell or multiple cell selection is allowed
		/// </summary>
		 [Category("Refedit"), Description("Determines whether single cell or multiple cell selection is allowed"), DefaultValue(true)]
		 property bool AllowMultipleCells
		 {
			 bool get()
			 {
				 return _AllowMultipleCells;
			 }
			 void set(bool value)
			 {
				 _AllowMultipleCells = value;
			 }
		 };
		 
		 /// <summary>
		 /// Determines whether typing into this control is Allowed (If False, a valid entry can only be made by selecting cell reference(s) in a worksheet
		 /// </summary>
		 [Category("Refedit"), Description("Determines whether typing into this control is Allowed (If False, a valid entry can only be made by selecting cell reference(s) in a worksheet"), DefaultValue(true)]
		 property bool AllowTextEntry
		 {
			 bool get()
			 {
				 return _AllowTextEntry;
			 }
			 void set(bool value)
			 {
				 _AllowTextEntry = value;
			 }
		 };
		 
		 /// <summary>
		 /// Display the Text Edit control. If False, only the selector button is displayed
		 /// </summary>
		 [Category("Refedit"), Description("Display the Text Edit control. If False, only the selector button is displayed"), DefaultValue(true)]
		 property bool ShowEditField
		 {
			 bool get()
			 {
				 return _showEditField;
			 }
			 void set(bool value)
			 {
				 _showEditField = value;
				 if (!_showEditField)
				 {
					 _bigSize = Width;
					 Size = button1->Size;
				 }
				 else
				 {
					 Width = _bigSize;
				 }
				 Invalidate(true);
			 }
		 };

		 /// <summary>
		/// A unit of Measure that can be used to correct the Form Height when in it's collapsed state.
		/// </summary>
		 [Category("Refedit"), Description("A unit of Measure that can be used to correct the Form Height when in it's collapsed state."), DefaultValue(0)]
		 property int CollapsedHeightAdjustment
		 {
			 int get()
			 {
				 return _adjustHeight;
			 }
			 void set(int value)
			 {
				 _adjustHeight = value;
			 }
		 };

	private: System::Void RefEdit_Load(System::Object^ sender, System::EventArgs^ e) {
		try
		{
			//oldshowEditField = ShowEditField;
			thisForm = ParentForm;
			if (thisForm != nullptr)
			{
				topMostForm = thisForm->TopMost;
				thisFormMenu = thisForm->Menu;
			}
			parentControl = Parent;

			//thisForm.LostFocus+=new EventHandler(ParentForm_LostFocus);

			if (thisForm != nullptr && thisForm->MdiParent != nullptr)
			{
				MDIForm = thisForm->MdiParent;
				MDIFormMenu = MDIForm->Menu;
				topMostForm = MDIForm->TopMost;
				parentCaption = MDIForm->Text;
			}
			if (_Excel != nullptr)
			{
				Excel::Worksheet^ mSheet = ((Excel::Worksheet^)(_Excel->ActiveSheet));
				_ActiveSheetName = mSheet->Name;
				excelMoveCursorOnEnter = _Excel->MoveAfterReturn;
			}
			textRange->TextAlign = _textAlign;
		}
		catch (Exception^ ex)
		{
			//_xlLogger.LogException(MethodBase.GetCurrentMethod().DeclaringType.Name, ex.ToString(), MethodBase.GetCurrentMethod().Name);
		}
		//killEnterKey();
	}

	
}; //ref class refedit
}
