//---------------------------------------------------------------------------

#ifndef Unit3H
#define Unit3H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Data.DB.hpp>
#include <Data.Win.ADODB.hpp>
#include <Vcl.DBGrids.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.Imaging.jpeg.hpp>
//---------------------------------------------------------------------------
class TForm3 : public TForm
{
__published:	// IDE-managed Components
	TImage *Image1;
	TComboBox *ComboBox1;
	TADOTable *ADOTable2;
	TADOTable *ADOTable3;
	TDataSource *DataSource2;
	TDataSource *DataSource3;
	TEdit *Edit1;
	TLabel *Label2;
	TDBGrid *DBGrid2;
	TLabel *Label1;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	TLabel *Label3;
	TStringGrid *StringGrid1;
	TADOTable *ADOTable1;
	TDataSource *DataSource1;
	TADOConnection *ADOConnection1;
	void __fastcall ComboBox1Change(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
	void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm3(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm3 *Form3;
//---------------------------------------------------------------------------
#endif
