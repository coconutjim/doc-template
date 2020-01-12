//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit3.h"
int y;
int i1;
int i;
int col;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
AnsiString o;
AnsiString oo;
AnsiString o1;
AnsiString o2;
AnsiString n;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
}
//--------------------------------------------------------------------------
void __fastcall TForm3::ComboBox1Change(TObject *Sender)
{
int col;
int iq;
int qq;
int iq2;
AnsiString a="";
a=ComboBox1->Text;
ADOTable2->Filtered=false;
if (a!="")
{
ADOTable1->Filtered=false;
ADOTable1->Filter="DocName='" + AnsiString(a) + "'";
ADOTable1->Filtered=true;
}
o=ADOTable1->FieldByName("DocCode")->Value;
ADOTable2->Filter="DocCode='" + AnsiString(o) + "'";
ADOTable2->Filtered=true;
DBGrid2->Visible=true;
Edit1->Visible=true;
Button1->Visible=true;
Label2->Visible=true;
Label3->Visible=true;
StringGrid1->Visible=true;
//------------------------
Form3->Height=323;
DBGrid2->Height=182;
StringGrid1->Height=182;
qq=StringGrid1->RowCount;
for (iq2 = 1; iq2 <= qq; iq2++)
{
StringGrid1->Cells[0][iq2]="";
}
col=ADOTable2->RecordCount;
StringGrid1->RowCount=col+1;
if (col>5)
{
DBGrid2->Height=182+23*(col-5);
StringGrid1->Height=182+23*(col-5);
Form3->Height=323+23*(col-5);
}
}
//---------------------------------------------------------------------------






void __fastcall TForm3::Button1Click(TObject *Sender)
{
int h;
int ioo;
n=Edit1->Text;
ADOTable3->Filtered = false;
ADOTable3->Filter = "DocCode='" +AnsiString(o) + "'";
ADOTable3->Filtered=true;
h=ADOTable3->RecordCount;
if (h>0)
{
ADOTable3->Last();
i=ADOTable3->FieldByName("VersCode")->Value+1;
}
else
{
i=1;
}
ADOTable3->Filtered = false;
ADOTable2->Filtered=false;
ADOTable2->Filter="DocCode='" + AnsiString(o) + "'";
ADOTable2->Filtered=true;
col=ADOTable2->RecordCount;
for (ioo = 1; ioo <= col; ioo++)
{
ADOTable2->RecNo=ioo;
ADOTable3->Append();
ADOTable3->FieldByName("DocCode")->Value=o;
ADOTable3->FieldByName("SemCode")->Value=ADOTable2->FieldByName("SemCode")->Value;
ADOTable3->FieldByName("VersCode")->Value=i;
ADOTable3->FieldByName("VersName")->Value=n;
ADOTable3->FieldByName("SemName")->Value=StringGrid1->Cells[0][ioo];
StringGrid1->Cells[0][ioo]="";
}
Edit1->Clear();
Button2->Visible=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button2Click(TObject *Sender)
{
int n1;
int n2;
ADOTable3->Filter="VersName='" + AnsiString(n) + "'";
ADOTable3->Filtered=true;
n1=ADOTable3->RecordCount;
if (n1>0)
{
for (n2 = n1; n2>0; n2=n2-1)
{
ADOTable3->Delete();
}
}
ADOTable3->Filtered=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::Button3Click(TObject *Sender)
{
ADOTable3->Append();
ADOTable3->FieldByName("DocCode")->Value="0";
ADOTable3->FieldByName("SemCode")->Value="0";
ADOTable3->FieldByName("VersCode")->Value="0";
ADOTable3->FieldByName("VersName")->Value="0";
ADOTable3->FieldByName("SemName")->Value="0";
ADOTable3->Sort="DocCode ASC, VersCode ASC, SemCode ASC";
ADOTable3->Active=false;
ADOTable3->Active=true;
ADOTable1->Filtered=false;
ADOTable2->Filtered=false;
ADOTable3->Filtered=false;
Form3->Close();
}
//---------------------------------------------------------------------------




void __fastcall TForm3::FormClose(TObject *Sender, TCloseAction &Action)
{
ADOTable3->Append();
ADOTable3->FieldByName("DocCode")->Value="0";
ADOTable3->FieldByName("SemCode")->Value="0";
ADOTable3->FieldByName("VersCode")->Value="0";
ADOTable3->FieldByName("VersName")->Value="0";
ADOTable3->FieldByName("SemName")->Value="0";
ADOTable3->Sort="DocCode ASC, VersCode ASC, SemCode ASC";
ADOTable3->Active=false;
ADOTable3->Active=true;
ADOTable1->Filtered=false;
ADOTable2->Filtered=false;
ADOTable3->Filtered=false;
Button1->Visible=false;
Button2->Visible=false;
DBGrid2->Visible=false;
StringGrid1->Visible=false;
Edit1->Visible=false;
Label2->Visible=false;
Label3->Visible=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::FormShow(TObject *Sender)
{
ADOTable1->Filtered=false;
ADOTable2->Filtered=false;
ADOTable3->Filtered=false;
ADOTable1->Active=false;
ADOTable1->Active=true;
ADOTable2->Active=false;
ADOTable2->Active=true;
ADOTable3->Active=false;
ADOTable3->Active=true;
StringGrid1->Cells[0][0]="��������:";
int x;
int i;
AnsiString y;
ComboBox1->Items->Clear();
ADOTable1->Sort="DocName ASC";
x=ADOTable1->RecordCount;
for (i = 1; i<=x; i++)
{
ADOTable1->RecNo=i;
y=ADOTable1->FieldByName("DocName")->Value;
ComboBox1->Items->Add(y);
}
ComboBox1->Visible=true;
ADOTable1->Sort="DocCode ASC";
ComboBox1->Text="";
ADOTable1->Filtered=false;
ADOTable2->Filtered=false;
ADOTable3->Filtered=false;
}
//---------------------------------------------------------------------------



