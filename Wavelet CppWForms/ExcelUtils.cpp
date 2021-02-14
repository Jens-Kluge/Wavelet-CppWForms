#include "pch.h"
#include "ExcelUtils.h"
#include "Globals.h"

void ExportDatasetToExcel(String^ outputPath, cli::array<double, 2>^ arr) {
    // Create the Excel Application object
    Excel::Application^ excelApp;
    excelApp = gcnew Excel::Application;
    //excelApp = GlobalVars::g_Excel

    //Create a new Excel Workbook
    Excel::Workbook^ wb =  excelApp->Workbooks->Add(Type::Missing);
       
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
      
        Array::Copy(arr,objArr, arr->Length);
   
        //Calculate the final column letter
        String^ finalColLetter = String::Empty;

        String^ colCharset = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        int colCharsetLen = colCharset->Length;

        //if col is beyond Z compute the 2 letter code AA-ZZ
        //which can accomodate another 26^2 = 676 cols
        if (nCols > colCharsetLen) {
            finalColLetter = colCharset->Substring((nCols - 1) / colCharsetLen - 1, 1);
        }
        finalColLetter += colCharset->Substring((nCols - 1) % colCharsetLen, 1);

        //Create a new Sheet
        excelSheet = safe_cast<Excel::Worksheet^> (wb->Sheets->Add(wb->Sheets[1],
            Type::Missing, 1, Excel::XlSheetType::xlWorksheet));

        excelSheet->Name = "Data Import";

        //write the data onto the new sheet
        String^ excelRange = String::Format("A1:{0}{1}", finalColLetter, nRows);
        excelSheet->Range[excelRange, Type::Missing]->Value2 = objArr;

        //Save and Close the Workbook
        wb->SaveAs(outputPath, Excel::XlFileFormat::xlOpenXMLWorkbook, Type::Missing, Type::Missing, false, false,
            Excel::XlSaveAsAccessMode::xlNoChange, Excel::XlSaveConflictResolution::xlUserResolution, true,
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

}