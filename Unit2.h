//---------------------------------------------------------------------------


#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TFrame2 : public TFrame
{
__published:	// IDE-managed Components
        TLabel *A;
        TLabel *B;
        TLabel *C;
		TImage *Tloo;
        TEdit *EditA;
        TEdit *EditB;
        TEdit *EditC;
private:	// User declarations
public:		// User declarations
        __fastcall TFrame2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrame2 *Frame2;
//---------------------------------------------------------------------------
#endif
