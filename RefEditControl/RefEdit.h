#pragma once

#include "enums.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Runtime::InteropServices;
namespace Excel = Microsoft::Office::Interop::Excel;
using namespace System::Reflection;


namespace RefEditControl {

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
	[ToolboxBitmap("C:\\Users\\jens kluge\\source\\repos\\Wavelet CppWForms\\Wavelet CppWForms\\RefEditControl.RefEdit.bmp")]
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
			try
			{
				//Application.MoveAfterReturn = False
				//Application.MoveAfterReturn = True
				if (oExcel != nullptr)
				{
					_Excel->MoveAfterReturn = excelMoveCursorOnEnter;
					oExcel = nullptr;
				}
			}
			catch(Exception^ ex) { }
		}

		
	private: System::Windows::Forms::TextBox^ textRange;
	protected:

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
			this->imageList1 = (gcnew System::Windows::Forms::ImageList(this->components));
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// textRange
			// 
			this->textRange->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textRange->Location = System::Drawing::Point(3, 3);
			this->textRange->Name = L"textRange";
			this->textRange->Size = System::Drawing::Size(154, 22);
			this->textRange->TabIndex = 0;
			this->textRange->TextChanged += gcnew System::EventHandler(this, &RefEdit::textRange_TextChanged);
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button1->AutoSize = true;
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->ImageIndex = 0;
			this->button1->ImageList = this->imageList1;
			this->button1->Location = System::Drawing::Point(163, 3);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(23, 23);
			this->button1->TabIndex = 1;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &RefEdit::button1_Click);
			// 
			// imageList1
			// 
			this->imageList1->ImageStream = (cli::safe_cast<System::Windows::Forms::ImageListStreamer^>(resources->GetObject(L"imageList1.ImageStream")));
			this->imageList1->TransparentColor = System::Drawing::Color::Transparent;
			this->imageList1->Images->SetKeyName(0, L"RefEdit0.bmp");
			this->imageList1->Images->SetKeyName(1, L"RefEdit1.bmp");
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &RefEdit::timer1_Tick);
			// 
			// RefEdit
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Inherit;
			this->AutoSize = true;
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textRange);
			this->Name = L"RefEdit";
			this->Size = System::Drawing::Size(192, 31);
			this->Load += gcnew System::EventHandler(this, &RefEdit::RefEdit_Load);
			this->Enter += gcnew System::EventHandler(this, &RefEdit::RefEdit_Enter);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &RefEdit::RefEdit_KeyDown);
			this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &RefEdit::RefEdit_KeyUp);
			this->Leave += gcnew System::EventHandler(this, &RefEdit::RefEdit_Leave);
			this->Resize += gcnew System::EventHandler(this, &RefEdit::RefEdit_Resize);
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
		/// <summary>
		/// required calls
		/// </summary>
		/// <param name="nVirtKey">na</param>
		/// <returns>na</returns>
		protected:
		[DllImport("user32.dll")]	
		static int GetKeyState(int nVirtKey);
		/// <summary>
		/// required calls
		/// </summary>
		/// <param name="pbKeyState">na</param>
		/// <returns>na</returns>
		protected:
		[DllImport("user32.dll")]	
		static int GetKeyboardState(Byte* pbKeyState);
		/// <summary>
		/// required calls
		/// </summary>
		/// <param name="lppbKeyState">na</param>
		/// <returns>na</returns>
		protected:
		[DllImport("user32.dll")]	
		static int SetKeyboardState(Byte* lppbKeyState);

		private: static const int ENTER_KEY = 13;

		/// <summary>
		/// The event to raise when the cell reference changes
		/// </summary>	   
		public: 
		[Description("Occurs when the cell reference changes")]
		event refeditCellChangeEventHandler^ CellChanged;
		
		/// <summary>
		/// Raises the Cell Changed event
		/// </summary>
		/// <param name="e">EventArgs</param>
		protected: void OnCellChanged(Object^ sender, EventArgs^ e)
		{
			// Invokes the delegates. 
			this->CellChanged(this, e);
		}
	
		/// <summary>
		/// The event to raise when the refedit control restores
		/// </summary>
		public: event refeditRestoreEventHandler^ Restore;

		/// <summary>
		/// Raises the restore event
		/// </summary>
		/// <param name="e">EventArgs</param>
		protected: void OnRestore(EventArgs^ e)
		{
			// Invokes the delegates. 
			this->Restore(this, e);
		}

		/// <summary>
		/// Clicks the refedit button
		/// </summary>
		public: void DoClick()
		{
			//button1_Click(button1, null);
		}

		/// <summary>
		/// Sets the refedit control as the active control
		/// </summary>
		/// <param name="state"></param>
		public: void isActive(bool state)
		{
			timer1->Enabled = state;
			_Entered = state;
		}

	/// <summary>
	/// A reference to the Excel Application
	/// </summary>
	public: [Browsable(false)] property Excel::Application^ _Excel
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

		  private: void setChildren(Control^ o, bool setAs)
		  {
			  for each(Control^ x in o->Controls)
			  {
				  if (x->GetType() == RefEdit::GetType())
				  {
					  if (x != this)
					  {
						  ((RefEdit^)x)->isActive(false);
					  }
				  }
				  else if (x->HasChildren)
				  {
					  setChildren(x, false);
				  }
			  }
		  }

		  private: void setThisControlActive()
		  {
			  isActive(true);

			  if (ParentForm != nullptr)
			  for each(Control^ x in ParentForm->Controls)
			  {
				  if (x->GetType() == RefEdit::GetType())
				  {
					  if (x != this)
					  {
						  ((RefEdit^)x)->isActive(false);
					  }
				  }
				  else if (x->HasChildren)
				  {
					  setChildren(x, false);
				  }

			  }
		  }

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
				//attach events  
				//EventHandler ^ handler = gcnew EventHandler(f, &Functor::Handler);;
				//Excel::ApplicationClass::SheetActivate += handler;
			}
			textRange->TextAlign = _textAlign;
		}
		catch (Exception^ ex)
		{
			//_xlLogger.LogException(MethodBase.GetCurrentMethod().DeclaringType.Name, ex.ToString(), MethodBase.GetCurrentMethod().Name);
		}
		//killEnterKey();
	}

private: System::Void RefEdit_Enter(System::Object^ sender, System::EventArgs^ e) {
	if (DesignMode) return;

	if (!Visible || !Enabled) return;

	_Entered = true;

	setThisControlActive();
	
	if (_Excel == nullptr) return;

	try
	{ 
		(safe_cast<Excel::Worksheet^>(_Excel->ActiveSheet))->Range[Text, Type::Missing]->Select();
	}
	catch(Exception^ ex) { }
	timer1->Enabled = true;
	timer1_Tick(nullptr, nullptr);
}

	private: static void killEnterKey()
	{
		Byte* keyStates = new Byte[256];

		GetKeyboardState(keyStates);		  //load the keyboard
		keyStates[ENTER_KEY] = 0;				// turn off the enter key
		SetKeyboardState(keyStates);		  //set the new keyboard state
	}


	//using a timer avoids problems with the Excel event handling
	//by querying the Excel selection in short time intervals
	//downside: it creates some computational overhead
	//overhead is reduced by checking for changes first
	private: void timer1_Tick(Object^ sender, EventArgs^ e)
	{

		try
		{
			if (DesignMode) return;

			if (!Visible || !Enabled) return;

			if (_Excel == nullptr)
			{
				return;
			}

			if (isCollapsed)
			{
				if (GetKeyState(ENTER_KEY) == 1)
				{
				   killEnterKey();
				   button1_Click(nullptr, nullptr);
				   return;
				}
			}

			if (_ActiveSheetName == "")
			{
				Excel::Worksheet^ mSheet = (safe_cast<Excel::Worksheet^>(_Excel->ActiveSheet));
				_ActiveSheetName = mSheet->Name;
			}

			if (_Entered)
			{
				_Entered = false;
				if (textRange->Text->IndexOf("!") != -1)
				{
					thisSheetName = textRange->Text->Substring(0, textRange->Text->IndexOf("!"));
					if (thisSheetName->StartsWith("["))
					{
						thisBookName = thisSheetName->Substring(0, thisSheetName->IndexOf("]") + 1);
						thisSheetName = thisSheetName->Substring(thisBookName->Length);
						thisBookName = thisBookName->Substring(1, thisBookName->Length - 2);
					}
				}
				else
				{
					thisSheetName = (safe_cast<Excel::Worksheet^>(_Excel->ActiveSheet))->Name;
				}
				thisSheetName = thisSheetName->Replace("'", "");
				if (_ActiveSheetName != thisSheetName)
				{
					try
					{
						//needs to be _Worksheet and not Worksheet to disambiguate 'Activate' member access
						Excel::_Worksheet^ ws = safe_cast<Excel::_Worksheet^>(_Excel->Worksheets[thisSheetName]);
						ws->Activate();
					}
					catch(Exception^ ex)
					{
						MessageBox::Show("Cannot access the worksheet referenced in this cell range reference.", "Cell Selection Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
					}
				}
				if (textRange->Text->IndexOf("!") != -1)
				{
					_Excel->Range[textRange->Text->Substring(textRange->Text->IndexOf("!") + 1), Type::Missing]->Select();
				}
				else if (textRange->Text != "")
				{
					try
					{
						_Excel->Range[textRange->Text, Type::Missing]->Select();
					}
					catch (Exception^ e) {}
				}
			}
			else //not _Entered
			{
				thisSheetName = (safe_cast<Excel::Worksheet^>(_Excel->ActiveSheet))->Name;
			}

			//Active Sheet has changed 
			if (_ActiveSheetName != thisSheetName)
			{
				if (_AllowMultipleCells)
				{
					if (thisSheetName->IndexOf(" ") != -1)
					{
						if (textRange->Text != "'" + thisSheetName + "'!" + (safe_cast<Excel::Range^>(_Excel->Selection))->AddressLocal[RowAbsolute, ColAbsolute, A1, Type::Missing, Type::Missing])
						{
							textRange->Text = "'" + thisSheetName + "'!" + (safe_cast<Excel::Range^>(_Excel->Selection))->AddressLocal[RowAbsolute, ColAbsolute, A1, Type::Missing, Type::Missing];
							if (!textRange->IsDisposed)textRange->SelectAll();
						}
					}
					else
					{
						if (textRange->Text != thisSheetName + "!" + (safe_cast<Excel::Range^>(_Excel->Selection))->AddressLocal[RowAbsolute, ColAbsolute, A1, Type::Missing, Type::Missing])
						{
							textRange->Text = thisSheetName + "!" + (safe_cast<Excel::Range^>(_Excel->Selection))->AddressLocal[RowAbsolute, ColAbsolute, A1, Type::Missing, Type::Missing];
							if (!textRange->IsDisposed)textRange->SelectAll();
						}
					}
				}
				else
				{
					if (thisSheetName->IndexOf(" ") != -1)
					{
						if (textRange->Text != "'" + thisSheetName + "'!" + (safe_cast<Excel::Range^>(_Excel->Selection))->AddressLocal[RowAbsolute, ColAbsolute, A1, Type::Missing, Type::Missing])
						{
							textRange->Text = "'" + thisSheetName + "'!" + (safe_cast<Excel::Range^>(_Excel->Selection))->AddressLocal[RowAbsolute, ColAbsolute, A1, Type::Missing, Type::Missing];
						}
					}
					else
					{
						if (textRange->Text != thisSheetName + "!" + (safe_cast<Excel::Range^>(_Excel->Selection))->AddressLocal[RowAbsolute, ColAbsolute, A1, Type::Missing, Type::Missing])
						{
							textRange->Text = thisSheetName + "!" + (safe_cast<Excel::Range^>(_Excel->Selection))->AddressLocal[RowAbsolute, ColAbsolute, A1, Type::Missing, Type::Missing];
						}
					}
					if (textRange->Text->IndexOf(":") != -1)
					{
						textRange->Text = textRange->Text->Substring(0, textRange->Text->IndexOf(":"));
					}
					if (!textRange->IsDisposed)textRange->SelectAll();
				}
			}
			else
			{
				if (_AllowMultipleCells)
				{
					if (textRange->Text != (safe_cast<Excel::Range^>(_Excel->Selection))->AddressLocal[RowAbsolute, ColAbsolute, A1, Type::Missing, Type::Missing])
					{
						textRange->Text = (safe_cast<Excel::Range^>(_Excel->Selection))->AddressLocal[RowAbsolute, ColAbsolute, A1, Type::Missing, Type::Missing];
						if (!textRange->IsDisposed)textRange->SelectAll();
					}
				}
				else if (_AllowTextEntry)
				{
					try
					{
						if (textRange->Text != (safe_cast<Excel::Range^>(_Excel->Selection))->AddressLocal[RowAbsolute, ColAbsolute, A1, Type::Missing, Type::Missing])
						{
							textRange->Text = (safe_cast<Excel::Range^>(_Excel->Selection))->AddressLocal[RowAbsolute, ColAbsolute, A1, Type::Missing, Type::Missing];
							if (textRange->Text->IndexOf(":") != -1)
							{
								textRange->Text = textRange->Text->Substring(0, textRange->Text->IndexOf(":"));
							}
							if (!textRange->IsDisposed) textRange->SelectAll();
						}
					}
					catch(Exception^ ex) { }
				}
				else
				{
					if (textRange->Text != (safe_cast<Excel::Range^>(_Excel->Selection))->AddressLocal[RowAbsolute, ColAbsolute, A1, Type::Missing, Type::Missing])
					{
						textRange->Text = (safe_cast<Excel::Range^>(_Excel->Selection))->AddressLocal[RowAbsolute, ColAbsolute, A1, Type::Missing, Type::Missing];
						if (textRange->Text->IndexOf(":") != -1)
						{
							textRange->Text = textRange->Text->Substring(0, textRange->Text->IndexOf(":"));
						}
						if (!textRange->IsDisposed) textRange->SelectAll();
					}
				}
			}
		}
		catch (Exception^ ex)
		{
			//_xlLogger.LogException(MethodBase.GetCurrentMethod().DeclaringType.Name, ex.ToString(), MethodBase.GetCurrentMethod().Name);
		}
		//finally 
		//{ 
		//} 
	}

	private: void restoreForm(Form^ collapse)
	{
		try
		{
			collapse->Size = *(thisFormSize);
			Location = thisLocation;

			collapse->ActiveControl->SelectNextControl(this, true, false, true, true);

			Parent = parentControl;

			if (CollapseFormStyle == CollapseStyle::CollapseFormAndFitCellSelector)
			{
				Dock = DockStyle::None;
				Anchor = AnchorStyles::None;
				Size = *(thisSize);
				Anchor = anchorControl;
				Dock = dockStyle;
			}
			if (!_AllowCollapsedResize)
			{
				collapse->FormBorderStyle = borderStyle;
			}
			if (MDIForm != nullptr)
			{
				showMDIControls();
				MDIForm->Menu = MDIFormMenu;
				MDIForm->TopMost = topMostForm;
			}
			else
			{
				thisForm->TopMost = topMostForm;
			}
			showControls();
			if (thisFormMenu != nullptr)
			{
				thisForm->Menu = thisFormMenu;
			}
			thisForm->Text = parentCaption;
			Visible = true;
			//				btnState = BtnState.Normal;
			button1->ImageIndex = 0;
		}
		catch (Exception^ ex)
		{
			//_xlLogger.LogException(MethodBase.GetCurrentMethod().DeclaringType.Name, ex.ToString(), MethodBase.GetCurrentMethod().Name);
		}
	}

	private: void collapseForm(Form^ collapse)
	{
		try
		{
			thisFormSize = collapse->Size;
			thisLocation = Location;
			thisSize = Size;

			parentControl = Parent;

			bool visState = Visible;

			Parent = ParentForm;

			Visible = visState;

			hideControls();

			thisForm->Menu = nullptr;
			if (MDIForm != nullptr)
			{
				hideMDIControls();
				MDIForm->Menu = nullptr;
				MDIForm->TopMost = true;
			}
			else
			{
				thisForm->TopMost = true;
			}
			//				btnState = BtnState.Pushed;
			button1->ImageIndex = 1;
			collapse->Text = CollapsedFormCaption;

			//resize the form
			if (!_AllowCollapsedResize)
			{
				borderStyle = collapse->FormBorderStyle;
				if (collapse->FormBorderStyle == FormBorderStyle::SizableToolWindow || collapse->FormBorderStyle == FormBorderStyle::FixedToolWindow)
				{
					collapse->FormBorderStyle = FormBorderStyle::FixedToolWindow;
				}
				else
				{
					collapse->FormBorderStyle = FormBorderStyle::FixedDialog;
				}
			}

			collapse->Height = (Height + (collapse->Height - collapse->ClientSize.Height)) + CollapsedHeightAdjustment;
			if (CollapseFormStyle == CollapseStyle::CollapseFormOnly)
			{
				Location = *(gcnew Point(Left, 0));
			}
			if (CollapseFormStyle == CollapseStyle::CollapseFormAndFitCellSelector)
			{
				Location = *(gcnew Point(0, 0));
				dockStyle = Dock;
				anchorControl = Anchor;
				Dock = DockStyle::Fill;
			}
		}
		catch (Exception^ ex)
		{
			//_xlLogger.LogException(MethodBase.GetCurrentMethod().DeclaringType.Name, ex.ToString(), MethodBase.GetCurrentMethod().Name);
		}

	}
	
	private: int getRealHeight(Form^ collapse)
	{
		int addTop = 0;
		Control^ thisParent = Parent;
		while (thisParent->GetType() != collapse->GetType())
		{
			addTop += thisParent->Top;
			if (thisParent->Parent == nullptr)
			{
				break;
			}
			thisParent = thisParent->Parent;
		}
		return addTop;
	}

	private: static bool IsNumeric(Object^ inValue)
	{
		try
		{
			Double::Parse(inValue->ToString());
			return true;
		}
		catch(Exception^ e)
		{
		}
		return false;
	}

	private: void hideControls()
	{
		try
		{
			visibles = gcnew Hashtable();
			parents = gcnew ArrayList();

			//We have to start at this Control, and go up the hierarchy
			//So, get this controls parent
			Control^ thisParent = Parent;
			while (thisParent != nullptr)
			{
				parents->Add(thisParent->Name);
				hideChildControls(thisParent);
				thisParent = thisParent->Parent;
			}
		}
		catch (Exception^ ex)
		{
			//_xlLogger.LogException(MethodBase.GetCurrentMethod().DeclaringType.Name, ex.ToString(), MethodBase.GetCurrentMethod().Name);
		}
	}

	private: void hideChildControls(Control^ container)
	{
	try
		{
			for each(Control^ ctrl in container->Controls)
			{
				visibles->Add(ctrl, ctrl->Visible);
				if (ctrl->Name != Name && parents->IndexOf(ctrl->Name) == -1)
				{
					ctrl->Visible = false;
				}
			}
		}
		catch (Exception^ ex)
		{
			//_xlLogger.LogException(MethodBase->GetCurrentMethod()->DeclaringType.Name, ex->ToString(), MethodBase->GetCurrentMethod()->Name);
		}
	}
	
	private: void hideMDIControls()
	{
		try
		{
				MDIvisibles = gcnew Hashtable();
				for each(Control^ ctrl in MDIForm->Controls)
				{
					 MDIvisibles->Add(ctrl, ctrl->Visible);
					 if (ctrl != ParentForm && ctrl != this && ctrl->Name != Parent->Name)
					 {
						   ctrl->Visible = false;
					 }
				}
		}
		catch (Exception^ ex)
		{
			//_xlLogger.LogException(MethodBase.GetCurrentMethod().DeclaringType.Name, ex.ToString(), MethodBase.GetCurrentMethod().Name);
		}
	}
	

	private: void showControls()
	{
		try
		{
			for each(DictionaryEntry^ ctrl in visibles)
			{
				   ((Control^)ctrl->Key)->Visible = (bool)ctrl->Value;
			}
		}
		catch (Exception^ ex)
		{
			//_xlLogger.LogException(MethodBase.GetCurrentMethod().DeclaringType.Name, ex.ToString(), MethodBase.GetCurrentMethod().Name);
		}
	}

	private: void showMDIControls()
	{
		try
		{
			for each(DictionaryEntry^ ctrl in MDIvisibles)
			{
				 ((Control^)ctrl->Key)->Visible = (bool)ctrl->Value;
			}
		}
		catch (Exception^ ex)
		{
			//_xlLogger.LogException(MethodBase.GetCurrentMethod().DeclaringType.Name, ex.ToString(), MethodBase.GetCurrentMethod().Name);
		}
	}

	private: void excelEvents_SheetSelectionChange(Object^ Sh, Excel::Range^ Target)
	{
		if (!Visible || !Enabled) return;

		if (ParentForm != nullptr && ParentForm->ActiveControl != nullptr)
		{
			if (Name != ParentForm->ActiveControl->Name)
			{
				return;
			}
		}

		textRange->Text = "";
		timer1_Tick(nullptr, nullptr);
	}

private: System::Void RefEdit_KeyUp(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	try
	{
		if (DesignMode) return;

		if (!Visible || !Enabled) return;

		String^ thisKey = ((TextBox^)(sender))->Text;
		if (thisKey->IndexOf("!") != -1)
		{
			thisSheetName = thisKey->Substring(0, thisKey->IndexOf("!"));
			if (thisSheetName->StartsWith("["))
			{
				thisBookName = thisSheetName->Substring(0, thisSheetName->IndexOf("]") + 1);
				thisSheetName = thisSheetName->Substring(thisBookName->Length);
				thisBookName = thisBookName->Substring(1, thisBookName->Length - 2);
			}
		}
		else
		{
			thisSheetName = ((Excel::Worksheet^)(_Excel->ActiveSheet))->Name;
		}
		if (thisSheetName->StartsWith("["))
		{
			thisBookName = thisSheetName->Substring(0, thisSheetName->IndexOf("]") + 1);
			thisSheetName = thisSheetName->Substring(thisBookName->Length);
			thisBookName = thisBookName->Substring(1, thisBookName->Length - 2);
		}
		thisSheetName = thisSheetName->Replace("'", "");
		if (_ActiveSheetName != thisSheetName)
		{
			try
			{
				((Excel::_Worksheet^)(_Excel->Worksheets[thisSheetName]))->Activate();
			}
			catch(Exception^ ex)
			{
			}
		}
		if (thisKey->IndexOf("!") != -1)
		{
			_Excel->Range[thisKey->Substring(thisKey->IndexOf("!") + 1), Type::Missing]->Select();
		}
		else
		{
			if (thisKey != "") _Excel->Range[thisKey, Type::Missing]->Select();
		}
	}
	catch (Exception^ ex)
	{
		//_xlLogger.LogException(MethodBase.GetCurrentMethod().DeclaringType.Name, ex.ToString(), MethodBase.GetCurrentMethod().Name);
	}
}
private: System::Void RefEdit_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	try
	{
		if (DesignMode) return;

		if (!Visible || !Enabled) return;

		timer1->Enabled = false;
		if ((e->KeyCode == Keys::Enter) && isCollapsed)
		{
			button1_Click(nullptr, nullptr);
			return;
		}
		if (e->KeyCode == Keys::F4)
		{
			if (_Relativity == ReferenceStyle::Absolute)
			{
				Relativity = ReferenceStyle::RowRelative;
			}
			else if (_Relativity == ReferenceStyle::RowRelative)
			{
				Relativity = ReferenceStyle::ColumnRelative;
			}
			else if (_Relativity == ReferenceStyle::ColumnRelative)
			{
				Relativity = ReferenceStyle::Relative;
			}
			else if (_Relativity == ReferenceStyle::Relative)
			{
				Relativity = ReferenceStyle::Absolute;
			}
			timer1_Tick(nullptr, nullptr);
		}
		else
		{
			_Entered = false;
			timer1->Enabled = false;
		}
	}
	catch (Exception^ ex)
	{
		//_xlLogger.LogException(MethodBase.GetCurrentMethod().DeclaringType.Name, ex.ToString(), MethodBase.GetCurrentMethod().Name);
	}
}

	/// <summary>
	/// Occurs when the control is resized
	/// </summary>
	/// <param name="e"></param>
	protected: void OnResize(EventArgs^ e) override
	{
		  //the following properties ensure good scaling:
		  //Control: Autoscale=true; AutosiyeMode=Inherit, Buton: Autoscale=true
		  UserControl::OnResize(e);

		  if (DesignMode) return;
		  if (!Visible || !Enabled) return;

		  //Make the button square
		  button1->Height = textRange->Height;
		  button1->Width = button1->Height;

		   //make the height of the control match the textbox
		   Height = textRange->Height;

		   //Now, hide the text box, if property is set
		   if (!_showEditField)
		   {
			   Size = button1->Size;
		   }

		   Invalidate();
	   }

private: System::Void RefEdit_Resize(System::Object^ sender, System::EventArgs^ e) {
	try
	{
		if (DesignMode) return;

		if (!Visible || !Enabled) return;

		textRange->Location = Drawing::Point(0, 0);
		textRange->Size = Drawing::Size(this->Width - button1->Width, Height);
		button1->Location = Drawing::Point(textRange->Width, 0);
	}
	catch (Exception^ ex)
	{
		//_xlLogger.LogException(MethodBase.GetCurrentMethod().DeclaringType.Name, ex.ToString(), MethodBase.GetCurrentMethod().Name);
	}
}

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	try
	{

		if (DesignMode) return;

		if (!Visible || !Enabled) return;

		textRange->Focus();
		_Entered = true;
		if (CollapseFormStyle == CollapseStyle::none)  return;

		Form^ collapse = (MDIForm != nullptr ? MDIForm : thisForm);
		collapse->SuspendLayout();
		if (isCollapsed)
		{
			if (oExcel != nullptr)
			{
				oExcel->MoveAfterReturn = excelMoveCursorOnEnter;
			}
			_showEditField = oldshowEditField;
			restoreForm(collapse);
			timer1->Enabled = false;
			OnRestore(e);
		}
		else
		{
			if (oExcel != nullptr)
			{
				oExcel->MoveAfterReturn = false;
			}

			parentCaption = thisForm->Text;
			_showEditField = true;
			collapseForm(collapse);
			timer1->Enabled = true;
		}
		collapse->ResumeLayout();
		isCollapsed = !(isCollapsed);
	}
	catch (Exception^ ex)
	{
		//_xlLogger.LogException(MethodBase.GetCurrentMethod().DeclaringType.Name, ex.ToString(), MethodBase.GetCurrentMethod().Name);
	}
}

//this needs to be connected to an Excel selection change event
//may not be necessary due to timer operating already 
private: void docEvents_SelectionChange(Excel::Range^ Target)
{
		   if (!Visible || !Enabled) return;

		   timer1_Tick(nullptr, nullptr);
}

private: System::Void textRange_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	OnCellChanged(textRange, e);
}

//stopping the timer again after 
//the user has left the refedit control
private: System::Void RefEdit_Leave(System::Object^ sender, System::EventArgs^ e) {
	if (DesignMode) return;

	if (!Visible || !Enabled) return;

	_Entered = false;
	timer1->Enabled = false;
}
};
}
