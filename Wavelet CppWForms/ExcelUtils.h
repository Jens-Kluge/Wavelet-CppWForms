#pragma once
#include "Globals.h"
using namespace System;
using namespace System::Windows::Forms;

void ExportDatasetToExcel(String^ outputPath, cli::array<double, 2>^ arr);

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

