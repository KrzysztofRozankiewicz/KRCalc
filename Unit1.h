//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <Menus.hpp>
#include "Unit2.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TEdit *Wynik;
        TButton *Button1;
        TButton *Button2;
        TButton *Button3;
        TButton *Button4;
        TButton *Button5;
        TButton *Button6;
        TButton *Button7;
        TButton *Button8;
        TButton *Button9;
        TButton *Button10;
        TButton *Button11;
        TButton *Button12;
        TButton *Button13;
        TButton *Button14;
        TButton *Mnozenie;
        TShape *Kreska;
        TButton *Dzielnik;
        TImage *Tlo;
        TButton *comma;
        TMainMenu *MainMenu;
        TMenuItem *Opcje1;
        TMenuItem *Zmieto1;
        TMenuItem *Niebieskigradient1;
        TMenuItem *Rowygradent1;
        TMenuItem *tygradient1;
        TMenuItem *Czarnygradient1;
        TMenuItem *Srebrnygradient1;
        TMenuItem *Opcjezakrglania1;
        TMenuItem *Ilo1;
        TMenuItem *Iloliczbpoprzecinku1;
        TMenuItem *N11;
        TMenuItem *N21;
        TMenuItem *N31;
        TMenuItem *N41;
        TMenuItem *N51;
        TMenuItem *N61;
        TMenuItem *N71;
        TMenuItem *N81;
        TMenuItem *N01;
        TMenuItem *N22;
        TMenuItem *N42;
        TMenuItem *N62;
        TMenuItem *N82;
        TMenuItem *Brakogranicze1;
        TMenuItem *Zielonygradient1;
        TButton *PlusMinus;
        TMenuItem *Purpurowygradient1;
        TMenuItem *Db1;
        TMenuItem *Bordowygradient1;
        TPaintBox *PaintBox1;
        TEdit *DeltaW;
        TButton *Delta;
        TEdit *A;
        TEdit *B;
        TEdit *C;
        TLabel *Aa;
        TLabel *Bb;
        TLabel *Cc;
        TLabel *Del;
        TEdit *Pierwiastek;
        TLabel *Pierw;
        TButton *Button15;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall Button6Click(TObject *Sender);
        void __fastcall Button7Click(TObject *Sender);
        void __fastcall Button8Click(TObject *Sender);
        void __fastcall Button9Click(TObject *Sender);
        void __fastcall Button10Click(TObject *Sender);
        void __fastcall Button11Click(TObject *Sender);
        void __fastcall Button12Click(TObject *Sender);
        void __fastcall Button13Click(TObject *Sender);
        void __fastcall Button14Click(TObject *Sender);
        void __fastcall MnozenieClick(TObject *Sender);
        void __fastcall DzielnikClick(TObject *Sender);
        void __fastcall commaClick(TObject *Sender);
        void __fastcall Niebieskigradient1Click(TObject *Sender);
        void __fastcall Rowygradent1Click(TObject *Sender);
        void __fastcall tygradient1Click(TObject *Sender);
        void __fastcall Czarnygradient1Click(TObject *Sender);
        void __fastcall Srebrnygradient1Click(TObject *Sender);
        void __fastcall N11Click(TObject *Sender);
        void __fastcall N21Click(TObject *Sender);
        void __fastcall N31Click(TObject *Sender);
        void __fastcall N41Click(TObject *Sender);
        void __fastcall N51Click(TObject *Sender);
        void __fastcall N61Click(TObject *Sender);
        void __fastcall N71Click(TObject *Sender);
        void __fastcall N81Click(TObject *Sender);
        void __fastcall N01Click(TObject *Sender);
        void __fastcall N22Click(TObject *Sender);
        void __fastcall N42Click(TObject *Sender);
        void __fastcall N62Click(TObject *Sender);
        void __fastcall N82Click(TObject *Sender);
        void __fastcall Brakogranicze1Click(TObject *Sender);
        void __fastcall Zielonygradient1Click(TObject *Sender);
        void __fastcall PlusMinusClick(TObject *Sender);
        void __fastcall Purpurowygradient1Click(TObject *Sender);
        void __fastcall Db1Click(TObject *Sender);
        void __fastcall Bordowygradient1Click(TObject *Sender);
        void __fastcall DeltaClick(TObject *Sender);
        void __fastcall Button15Click(TObject *Sender);
        void __fastcall WynikKeyPress(TObject *Sender, char &Key);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
