#pragma once
#include "Globals.h"
using namespace System;
using namespace System::Windows::Forms;

template<typename T>
void ExportDatasetToExcel(String^ outputPath, cli::array<T, 2>^ arr, String^ title) {
    // Create the Excel Application object
    Excel::Application^ excelApp;
    excelApp = gcnew Excel::Application;
    //excelApp = GlobalVars::g_Excel

    //Create a new Excel Workbook
    Excel::Workbook^ wb = excelApp->Workbooks->Add(Type::Missing);

    int col, row;
    Excel::Worksheet^ excelSheet;

    int nCols = arr->GetLength(1);
    int nRows = arr->GetLength(0);
    //Copy the input array to an object array
    cli::array<Object^, 2>^ objArr = gcnew cli::array<Object^, 2>(nRows, nCols);
    try {
        //ProgressBar1.Maximum = dt.Rows.Count
        //ProgressBar1.Value = 0
        //ProgressBar1.Update()

        Array::Copy(arr, objArr, arr->Length);

        //Create a new Sheet
        excelSheet = safe_cast<Excel::Worksheet^> (wb->Sheets->Add(wb->Sheets[1],
            Type::Missing, 1, Excel::XlSheetType::xlWorksheet));

        excelSheet->Name = "Data Import";

        //write the data onto the new sheet
        excelSheet->Range["A1", Type::Missing]->Value2 = title;
        //String^ excelRange = String::Format("A2:{0}{1}", finalColLetter, nRows + 1);
        
        Excel::Range^ rg = excelSheet->Range["A2:A2", Type::Missing];
        Excel::Range^ rg2 = rg->Resize[nRows, nCols];
        rg2->Value2 = objArr;

        //Save and Close the Workbook
        wb->SaveAs(outputPath, Excel::XlFileFormat::xlOpenXMLWorkbook, Type::Missing, Type::Missing, false, false,
            Excel::XlSaveAsAccessMode::xlNoChange, Excel::XlSaveConflictResolution::xlLocalSessionChanges, true,
            Type::Missing, Type::Missing, Type::Missing);
    }
    catch (Exception^ ex) {
        MessageBox::Show(ex->Message);
    }

    excelSheet = nullptr;
    wb->Close(true, Type::Missing, Type::Missing);
    wb = nullptr;
    //Release the Application object
    excelApp->Quit();
    excelApp = nullptr;

    //Collect the unreferenced objects
    GC::Collect();
    GC::WaitForPendingFinalizers();

};

ref class ExcelUtils
{

public: static void GetRange(Excel::Range^& rg, String^ s, bool& ok) {

    //Get range with address s, set ok to true if this address Is valid
    ok = true;
    try {
        rg = safe_cast<Excel::Worksheet^>(GlobalVars::g_Excel->ActiveSheet)->Range[s, Type::Missing];
        return;
    }
    catch (Exception^ ex) {
        ok = false;
        return;
    }
} //get range

//this works very fast
public: static void ExtendRange2(Excel::Range^ rg, Excel::Range^ &rg1 )
{
    long n;
    n = rg->Columns->Count;

    long lastRow = rg->End[Excel::XlDirection::xlDown]->Row;
    long firstRow = safe_cast<Excel::Range^>(rg->Cells[1, 1])->Row;
    rg1 = safe_cast<Excel::Range^>(rg->Cells[1, 1])->Resize[lastRow - firstRow + 1, n];
}

//This is too slow for large data sizes!!
public: static void ExtendRange(Excel::Range^ rg, Excel::Range^ &rg1) {

          //For a given range rg, return range rg1 which extends the first row of rg until a row of empty cells is found
          //If the end of the kth column is reached continue downwards in next column
          long n, j;

          bool bFinish;

          Excel::Range^ ce;
          Excel::Range^ ce1;

          if (rg == nullptr) {
              return;
          }

          n = rg->Columns->Count;
          ce = (Excel::Range^)(rg->Cells[1, 1]);

          try {
              //go down one row until no more value in cell
              do {
                  bFinish = true;
                  ce = safe_cast<Excel::Range^>(ce->Offset[1, 0]);

                  while (ce->Value2 != nullptr) {
                      //go into next row for ce
                      ce = safe_cast<Excel::Range^>(ce->Offset[1, 0]);
                      //go into next column for ce1
                      ce1 = safe_cast<Excel::Range^>(ce->Offset[0, 1]);
                      //go through all columns
                      for (j = 2; j <= n; j++) {
                          
                          if (ce1->Value2 != nullptr) {
                              bFinish = false;
                              break;
                          }

                          ce1 = safe_cast<Excel::Range^>(ce1->Offset[0, 1]);
                      } //for

                  } //while != nullptr
              } //do
              while (!bFinish);

              rg1 = safe_cast<Excel::Range^>(rg->Cells[1, 1])->Resize[ce->Row - safe_cast<Excel::Range^>(rg->Cells[1, 1])->Row, n];
          }//try
          catch (Exception^ ex) {
              MessageBox::Show(ex->Message);
          }
} //end function

};

