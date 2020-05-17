//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Math.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Unit2"
#pragma resource "*.dfm"
TForm1 *Form1;
AnsiString liczba[100];
float licz[100];
int ktora = 0; // Która liczba
int dzialanie; // 0 = dodawanie, 1 = odejmowanie
float wynik = 0; 
AnsiString koniec; // Wynik
int Auto = 0; // Samodzielne równanie poprzez dzia³anie
int wyk = 0; // wykonanie auto
int zmiany = 0; // by nie by³o ba³aganu z tym znakiem równosci
int CommaKlik = 0; // Mo¿liwosc stawiania przecinka; 0 = tak, 1 = nie
int zaoP = 11; // Domyslne zaokraglenie przed przecinkiem
int zaoZ = 2; // Domyslne zaokr¹glenie po przecinku
float PlusMin = 0; AnsiString PlusM; // Zamienianie + na - i vice versa
int DeltaMode = 0; // Tryb delty!
int NewtonMode = 0; // Tryb Newtona
int aaa; int bbb; int ccc; int delta; float PierwiastekD; // do delty
int niuton; // Wynik
int DS; //Default Skin, domyslna skorka
int pomocnikI; float pomocnikF; AnsiString pomocnikA; //Do sprawdzania czy wynik do pierwiastkowania jest ca³kowity!
int n; int k; int nk; int N = 1; int K = 1; int NK = 1; // Dla symbolu Newtona; ma³e s¹ podstaw¹, du¿e silni¹

//---------------------------------------------------------------------------//////////////////////////////////////////////////////
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
        liczba[ktora] += 1;
        Wynik->Text = liczba[ktora];
        zmiany = 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
        liczba[ktora] += 2;
        Wynik->Text = liczba[ktora];
        zmiany = 1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
        liczba[ktora] += 3;
        Wynik->Text = liczba[ktora]; zmiany = 1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
        liczba[ktora] += 4;
        Wynik->Text = liczba[ktora];  zmiany = 1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
        liczba[ktora] += 5;
        Wynik->Text = liczba[ktora]; zmiany = 1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)
{
        liczba[ktora] += 6;
        Wynik->Text = liczba[ktora]; zmiany = 1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button7Click(TObject *Sender)
{
        liczba[ktora] += 7;
        Wynik->Text = liczba[ktora]; zmiany = 1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button8Click(TObject *Sender)
{
        liczba[ktora] += 8;          zmiany = 1;
        Wynik->Text = liczba[ktora];
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button9Click(TObject *Sender)
{
        liczba[ktora] += 9;
        Wynik->Text = liczba[ktora]; zmiany = 1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button10Click(TObject *Sender)
{
        liczba[ktora] += 0;
        Wynik->Text = liczba[ktora];
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button11Click(TObject *Sender)
{
        if (zmiany == 1)
        {
        licz[ktora] = StrToFloat(Wynik->Text);            // RÓWNA SIE
            CommaKlik = 0;
                if (dzialanie == 0)
                 {
                        if (wyk == 0)
                        {
                        wynik += licz[ktora-1] + licz[ktora];
                        wyk = 1;
                        }
                        else if (wyk == 1)
                        {
                                wynik += licz[ktora];
                        }
                 }
                else if (dzialanie == 1)
                {
                        if (wyk == 0)
                        {
                        wynik = licz[ktora-1] - licz[ktora];
                        wyk = 1;
                        }
                        else if (wyk == 1)
                        {
                                wynik -= licz[ktora];
                        }
                }
                else if (dzialanie == 2)
                {
                        if (wyk == 0)
                        {
                        wynik = licz[ktora-1] * licz[ktora];
                        wyk = 1;
                        }
                        else if (wyk == 1)
                        {
                                wynik *= licz[ktora];
                        }
                }
                else if (dzialanie == 3)
                {
                        if (wyk == 0)
                        {
                        wynik = licz[ktora-1] / licz[ktora];
                        wyk = 1;
                        }
                        else if (wyk == 1)
                        {
                                wynik /= licz[ktora];
                        }
                }

        koniec = FloatToStrF(wynik, ffNumber, zaoP, zaoZ);
        ktora++;
        Wynik->Text = koniec;   zmiany = 0;
        }
        if (DeltaMode == 1)
        {
                if (A->Text != "" && A->Text != "0")
                {
                        aaa = StrToInt(A->Text);
                        bbb = StrToInt(B->Text);
                        ccc = StrToInt(C->Text);
                        delta = (bbb * bbb) - 4*aaa*ccc;
                        koniec = IntToStr(delta);
                        if (delta >= 0)
                        {
                        PierwiastekD = sqrt(delta);
                        }
                        else
                        {
                        PierwiastekD = 0;
                        }
                        pomocnikI = PierwiastekD;
                        pomocnikF = PierwiastekD;
                        DeltaW->Text = koniec;
                        if (pomocnikI == pomocnikF)
                        {
                                koniec = FloatToStr(PierwiastekD);
                        }
                        else
                        {
                                pomocnikA = IntToStr(delta);
                                koniec = "/" + pomocnikA;

                        }
                        Pierwiastek->Text = koniec;


                }
        }
        if (NewtonMode == 1 && A->Text != "" && B->Text != "")
        {
                n = StrToInt(A->Text);
                k = StrToInt(B->Text);
                nk = n - k;
                while (n > 0)
                {
                        N *= n;
                        n--;
                }
                while (k > 0)
                {
                        K *= k;
                        k--;
                }
                while (nk > 0)
                {
                        NK *= nk;
                        nk--;
                }
                niuton = N / (K * NK);
                koniec = IntToStr(niuton);
                 DeltaW->Text = koniec;
                 N = 1;
                 K = 1;
                 NK = 1;
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button12Click(TObject *Sender)
{
                                                     // DODAWANIE
        if (zmiany == 1)
        {
        zmiany = 0;     CommaKlik = 0;
        if (Auto == 0)
        {
        licz[ktora] = StrToFloat(Wynik->Text);
        ktora++;
          Auto = 1;
        }
        else if (Auto == 1)
        {
                licz[ktora] = StrToFloat(Wynik->Text);
                if (dzialanie == 0)
                 {
                        if (wyk == 0)
                        {
                        wynik += licz[ktora-1] + licz[ktora];
                        wyk = 1;
                        }
                        else if (wyk == 1)
                        {
                                wynik += licz[ktora];
                        }
                 }
                else if (dzialanie == 1)
                {
                        if (wyk == 0)
                        {
                        wynik = licz[ktora-1] - licz[ktora];
                        wyk = 1;
                        }
                        else if (wyk == 1)
                        {
                                wynik -= licz[ktora];
                        }
                }
                else if (dzialanie == 2)
                {
                        if (wyk == 0)
                        {
                        wynik = licz[ktora-1] * licz[ktora];
                        wyk = 1;
                        }
                        else if (wyk == 1)
                        {
                                wynik *= licz[ktora];
                        }
                }
                else if (dzialanie == 3)
                {
                        if (wyk == 0)
                        {
                        wynik = licz[ktora-1] / licz[ktora];
                        wyk = 1;
                        }
                        else if (wyk == 1)
                        {
                                wynik /= licz[ktora];
                        }
                }
                ktora++;
                koniec = FloatToStrF(wynik, ffNumber, zaoP, zaoZ);
                Wynik->Text = koniec;
        }
        }
        dzialanie = 0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button13Click(TObject *Sender)
{

        if (zmiany == 1)
        {                                                // ODEJMOWANIE
        zmiany = 0;  CommaKlik = 0;
        if (Auto == 0)
        {
        licz[ktora] = StrToFloat(Wynik->Text);
        ktora++;
        Auto = 1;
        }
        else if (Auto == 1)
        {
                licz[ktora] = StrToFloat(Wynik->Text);
                if (dzialanie == 0)
                 {
                        if (wyk == 0)
                        {
                        wynik += licz[ktora-1] + licz[ktora];
                        wyk = 1;
                        }
                        else if (wyk == 1)
                        {
                                wynik += licz[ktora];
                        }
                 }
                else if (dzialanie == 1)
                {
                        if (wyk == 0)
                        {
                        wynik = licz[ktora-1] - licz[ktora];
                        wyk = 1;
                        }
                        else if (wyk == 1)
                        {
                                wynik -= licz[ktora];
                        }
                }
                else if (dzialanie == 2)
                {
                        if (wyk == 0)
                        {
                        wynik = licz[ktora-1] * licz[ktora];
                        wyk = 1;
                        }
                        else if (wyk == 1)
                        {
                                wynik *= licz[ktora];
                        }
                }
                else if (dzialanie == 3)
                {
                        if (wyk == 0)
                        {
                        wynik = licz[ktora-1] / licz[ktora];
                        wyk = 1;
                        }
                        else if (wyk == 1)
                        {
                                wynik /= licz[ktora];
                        }
                }
                ktora++;
                koniec = FloatToStrF(wynik, ffNumber, zaoP, zaoZ);
                Wynik->Text = koniec;
        }
        }
        dzialanie = 1;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button14Click(TObject *Sender)
{
        while (ktora >= 0)     //Czyszczenie
        {
                licz[ktora] = 0;
                liczba[ktora] = "";
                ktora--;
        }
        ktora = 0;
        Wynik->Text = "";   Auto = 0;   wyk = 0; zmiany = 0;
        A->Text = ""; B->Text = ""; C->Text = ""; DeltaW->Text = "";
        Pierwiastek->Text = "";
}
//---------------------------------------------------------------------------


void __fastcall TForm1::MnozenieClick(TObject *Sender)
{


        if (zmiany == 1)
        {
        zmiany = 0;  CommaKlik = 0;
        if (Auto == 0)
        {
        licz[ktora] = StrToFloat(Wynik->Text);
        ktora++;
             Auto = 1;
        }
        else if (Auto == 1)
        {
                licz[ktora] = StrToFloat(Wynik->Text);
                if (dzialanie == 0)
                 {
                        if (wyk == 0)
                        {
                        wynik += licz[ktora-1] + licz[ktora];
                        wyk = 1;
                        }
                        else if (wyk == 1)
                        {
                                wynik += licz[ktora];
                        }
                 }
                else if (dzialanie == 1)
                {
                        if (wyk == 0)
                        {
                        wynik = licz[ktora-1] - licz[ktora];
                        wyk = 1;
                        }
                        else if (wyk == 1)
                        {
                                wynik -= licz[ktora];
                        }
                }
                else if (dzialanie == 2)
                {
                        if (wyk == 0)
                        {
                        wynik = licz[ktora-1] * licz[ktora];
                        wyk = 1;
                        }
                        else if (wyk == 1)
                        {
                                wynik *= licz[ktora];
                        }
                }
                else if (dzialanie == 3)
                {
                        if (wyk == 0)
                        {
                        wynik = licz[ktora-1] / licz[ktora];
                        wyk = 1;
                        }
                        else if (wyk == 1)
                        {
                                wynik /= licz[ktora];
                        }
                }
                 ktora++;
                koniec = FloatToStrF(wynik, ffNumber, zaoP, zaoZ);
                Wynik->Text = koniec;
        }
        }
         dzialanie = 2;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DzielnikClick(TObject *Sender)
{

        if (zmiany == 1)
        {
        zmiany = 0;  CommaKlik = 0;
        if (Auto == 0)
        {
        licz[ktora] = StrToFloat(Wynik->Text);
        ktora++;
             Auto = 1;
        }
        else if (Auto == 1)
        {
                licz[ktora] = StrToFloat(Wynik->Text);
                if (dzialanie == 0)
                 {
                        if (wyk == 0)
                        {
                        wynik += licz[ktora-1] + licz[ktora];
                        wyk = 1;
                        }
                        else if (wyk == 1)
                        {
                                wynik += licz[ktora];
                        }
                 }
                else if (dzialanie == 1)
                {
                        if (wyk == 0)
                        {
                        wynik -= licz[ktora-1] + licz[ktora];
                        wyk = 1;
                        }
                        else if (wyk == 1)
                        {
                                wynik -= licz[ktora];
                        }
                }
                else if (dzialanie == 2)
                {
                        if (wyk == 0)
                        {
                        wynik = licz[ktora-1] * licz[ktora];
                        wyk = 1;
                        }
                        else if (wyk == 1)
                        {
                                wynik *= licz[ktora];
                        }
                }
                else if (dzialanie == 3)
                {
                        if (wyk == 0)
                        {
                        wynik = licz[ktora-1] / licz[ktora];
                        wyk = 1;
                        }
                        else if (wyk == 1)
                        {
                                wynik /= licz[ktora];
                        }
                }
                ktora++;
                koniec = FloatToStrF(wynik, ffNumber, zaoP, zaoZ);
                Wynik->Text = koniec;
        }
        }
        dzialanie = 3;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::commaClick(TObject *Sender)
{
        if (Wynik->Text != "" && CommaKlik == 0 && zmiany == 1)
        {
        liczba[ktora] += ",";
        Wynik->Text = liczba[ktora]; zmiany = 1; CommaKlik = 1;
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Niebieskigradient1Click(TObject *Sender)
{
        Tlo->Picture->LoadFromFile("img/tlo.bmp");
        DS = 8;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Rowygradent1Click(TObject *Sender)
{
        Tlo->Picture->LoadFromFile("img/tloRoz.bmp");
        DS = 7;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::tygradient1Click(TObject *Sender)
{
        Tlo->Picture->LoadFromFile("img/tloZol.bmp");
        DS = 6;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Czarnygradient1Click(TObject *Sender)
{
        Tlo->Picture->LoadFromFile("img/tloCza.bmp");
        DS = 5;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Srebrnygradient1Click(TObject *Sender)
{
        Tlo->Picture->LoadFromFile("img/tloSre.bmp");
        DS = 0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N11Click(TObject *Sender)
{
        zaoP = 3;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N21Click(TObject *Sender)
{
        zaoP = 5;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N31Click(TObject *Sender)
{
        zaoP = 7;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N41Click(TObject *Sender)
{
        zaoP = 9;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N51Click(TObject *Sender)
{
        zaoP = 11;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N61Click(TObject *Sender)
{
        zaoP = 13;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N71Click(TObject *Sender)
{
        zaoP = 15;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N81Click(TObject *Sender)
{
        zaoP = 100;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N01Click(TObject *Sender)
{
        zaoZ = 0;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N22Click(TObject *Sender)
{
        zaoZ = 2;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N42Click(TObject *Sender)
{
        zaoZ = 4;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N62Click(TObject *Sender)
{
        zaoZ = 6;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N82Click(TObject *Sender)
{
        zaoZ = 8;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Brakogranicze1Click(TObject *Sender)
{
        zaoZ = 100;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Zielonygradient1Click(TObject *Sender)
{
         Tlo->Picture->LoadFromFile("img/tloZie.bmp");
         DS = 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::PlusMinusClick(TObject *Sender)
{
        PlusMin = StrToFloat(Wynik->Text);
        PlusMin = 0 - PlusMin;
        PlusM = FloatToStrF(PlusMin, ffNumber, zaoP, zaoZ);
        Wynik->Text = PlusM;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Purpurowygradient1Click(TObject *Sender)
{
          Tlo->Picture->LoadFromFile("img/tloPur.bmp");
          DS = 2;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Db1Click(TObject *Sender)
{
           Tlo->Picture->LoadFromFile("img/tloDab.bmp");
           DS = 3;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Bordowygradient1Click(TObject *Sender)
{
            Tlo->Picture->LoadFromFile("img/tloBor.bmp");
            DS = 4;
}
//---------------------------------------------------------------------------




void __fastcall TForm1::DeltaClick(TObject *Sender)
{
        A->Text = "";
        B->Text = "";
        C->Text = "";
        DeltaW->Text = "";
        Pierwiastek->Text = "";
        if (DeltaMode == 0 || DeltaW->Text != "")
        {
        A->Visible = true;
        B->Visible = true;
        C->Visible = true;
        Aa->Visible = true;
        Bb->Visible = true;
        Cc->Visible = true;
        DeltaW->Visible = true;
        Del->Visible = true;
        Pierw->Visible = true;
        Pierwiastek->Visible = true;
        DeltaMode = 1;
        Aa->Caption = "A:";
        Bb->Caption = "B:";
        Del->Caption = "Delta:";
        Form1->Height = 550;
       }
       else
       {
        A->Visible = false;
        B->Visible = false;
        C->Visible = false;
        Aa->Visible = false;
        Bb->Visible = false;
        Cc->Visible = false;
        DeltaW->Visible = false;
        Del->Visible = false;
        Pierw->Visible = false;
        Pierwiastek->Visible = false;
        DeltaMode = 0;
        Form1->Height = 374;
       }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button15Click(TObject *Sender)
{
        A->Text = "";
        B->Text = "";
        C->Text = "";
        DeltaW->Text = "";
        Pierwiastek->Text = "";
        ///////////////////////////////////////////////// SYMBOL NEWTONA
        if (DeltaMode == 0 && NewtonMode == 0)
        {
                A->Visible = true;
                B->Visible = true;
                Aa->Visible = true;
                Bb->Visible = true;
                Aa->Caption = "n:";
                Bb->Caption = "k:";
                DeltaW->Visible = true;
                Del->Visible = true;
                Del->Caption = "Wynik:";
                Form1->Height = 520;
                NewtonMode = 1;
        }
        else if (DeltaMode == 1)
        {
                C->Visible = false;
                Cc->Visible = false;
                Aa->Caption = "n:";
                Bb->Caption = "k:";
                Del->Caption = "Wynik:";
                Pierw->Visible = false;
                Pierwiastek->Visible = false;
                DeltaMode = 0; // Delta raus!
                NewtonMode = 1;
                Form1->Height = 520;
                Del->Caption = "Wynik:";
        }
        else if (NewtonMode == 1)
        {
                A->Visible = false;
                B->Visible = false;
                Aa->Visible = false;
                Bb->Visible = false;
                DeltaW->Visible = false;
                Del->Visible = false;
                Pierwiastek->Visible = false;
                NewtonMode = 0;
                Form1->Height = 374;
        }



}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------


void __fastcall TForm1::WynikKeyPress(TObject *Sender, char &Key)
{
        if (Key == 0x31 || Key == VK_NUMPAD1)
        {
        liczba[ktora] += 1;
        Wynik->Text = liczba[ktora];
        zmiany = 1;
        }
        if (Key == 0x32 || Key == VK_NUMPAD2)
        {
        liczba[ktora] += 2;
        Wynik->Text = liczba[ktora];
        zmiany = 1;
        }
        if (Key == 0x33 || Key == VK_NUMPAD3)
        {
        liczba[ktora] += 3;
        Wynik->Text = liczba[ktora];
        zmiany = 1;
        }
        if (Key == 0x34 || Key == VK_NUMPAD4)
        {
        liczba[ktora] += 4;
        Wynik->Text = liczba[ktora];
        zmiany = 1;
        }
        if (Key == 0x35 || Key == VK_NUMPAD5)
        {
        liczba[ktora] += 5;
        Wynik->Text = liczba[ktora];
        zmiany = 1;
        }
        if (Key == 0x36 || Key == VK_NUMPAD6)
        {
        liczba[ktora] += 6;
        Wynik->Text = liczba[ktora];
        zmiany = 1;
        }
        if (Key == 0x37 || Key == VK_NUMPAD7)
        {
        liczba[ktora] += 7;
        Wynik->Text = liczba[ktora];
        zmiany = 1;
        }
        if (Key == 0x38 || Key == VK_NUMPAD8)
        {
        liczba[ktora] += 8;
        Wynik->Text = liczba[ktora];
        zmiany = 1;
        }
        if (Key == 0x39 || Key == VK_NUMPAD9)
        {
        liczba[ktora] += 9;
        Wynik->Text = liczba[ktora];
        zmiany = 1;
        }
        if (Key == 0x30 || Key == VK_NUMPAD0)
        {
        liczba[ktora] += 0;
        Wynik->Text = liczba[ktora];
       // zmiany = 1;
        }
        if (Key == 0x0D || Key == VK_RETURN)  // KONIECZNIE OGARN¥Æ WYWO£ANIE F-CJI!!!!!
        {
        if (zmiany == 1)
        {
        licz[ktora] = StrToFloat(Wynik->Text);            // RÓWNA SIE
            CommaKlik = 0;
                if (dzialanie == 0)
                 {
                        if (wyk == 0)
                        {
                        wynik += licz[ktora-1] + licz[ktora];
                        wyk = 1;
                        }
                        else if (wyk == 1)
                        {
                                wynik += licz[ktora];
                        }
                 }
                else if (dzialanie == 1)
                {
                        if (wyk == 0)
                        {
                        wynik = licz[ktora-1] - licz[ktora];
                        wyk = 1;
                        }
                        else if (wyk == 1)
                        {
                                wynik -= licz[ktora];
                        }
                }
                else if (dzialanie == 2)
                {
                        if (wyk == 0)
                        {
                        wynik = licz[ktora-1] * licz[ktora];
                        wyk = 1;
                        }
                        else if (wyk == 1)
                        {
                                wynik *= licz[ktora];
                        }
                }
                else if (dzialanie == 3)
                {
                        if (wyk == 0)
                        {
                        wynik = licz[ktora-1] / licz[ktora];
                        wyk = 1;
                        }
                        else if (wyk == 1)
                        {
                                wynik /= licz[ktora];
                        }
                }

        koniec = FloatToStrF(wynik, ffNumber, zaoP, zaoZ);
        ktora++;
        Wynik->Text = koniec;   zmiany = 0;
        }
        if (DeltaMode == 1)
        {
                if (A->Text != "" && A->Text != "0")
                {
                        aaa = StrToInt(A->Text);
                        bbb = StrToInt(B->Text);
                        ccc = StrToInt(C->Text);
                        delta = (bbb * bbb) - 4*aaa*ccc;
                        koniec = IntToStr(delta);
                        PierwiastekD = sqrt(delta);
                        pomocnikI = PierwiastekD;
                        pomocnikF = PierwiastekD;
                        DeltaW->Text = koniec;
                        if (pomocnikI == pomocnikF)
                        {
                                koniec = FloatToStr(PierwiastekD);
                        }
                        else
                        {
                                pomocnikA = IntToStr(delta);
                                koniec = "/" + pomocnikA;

                        }
                        Pierwiastek->Text = koniec;


                }
        }
        if (NewtonMode == 1 && A->Text != "" && B->Text != "")
        {
                n = StrToInt(A->Text);
                k = StrToInt(B->Text);
                nk = n - k;
                while (n > 0)
                {
                        N *= n;
                        n--;
                }
                while (k > 0)
                {
                        K *= k;
                        k--;
                }
                while (nk > 0)
                {
                        NK *= nk;
                        nk--;
                }
                niuton = N / (K * NK);
                koniec = IntToStr(niuton);
                 DeltaW->Text = koniec;
                 N = 1;
                 K = 1;
                 NK = 1;
        }
        }
}
//---------------------------------------------------------------------------



