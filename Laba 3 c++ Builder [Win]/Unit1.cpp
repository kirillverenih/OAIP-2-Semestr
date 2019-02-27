//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int n;
bool recursiveMethod = false;

//---------------------------------------------------------------------------
int f(int a)
 {
    if (a==1 || a==2)
        return 1;
    if (a==0)
        return 0;
    return f(a-1)+f(a-2);
 }
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RadioButton1Click(TObject *Sender)
{
        recursiveMethod = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RadioButton2Click(TObject *Sender)
{
        recursiveMethod = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
    int cache1 = 1;
    int cache2 = 1;
    int cache3;

    if(recursiveMethod == true){
        cache3 = f(n);
    } else {

        for (int i = 3; i <= n; i++) {
        cache3 = cache1 + cache2;

        cache1 = cache2;
        cache2 = cache3;
    }
    }
Label1->Caption ="Ответ: "+IntToStr(cache3);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Edit1Change(TObject *Sender)
{
     n = Edit1->Text.ToInt();
}
//---------------------------------------------------------------------------
//1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377
//1  2  3  4  5  6  7   8   9   10  11  12   13   14
