//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------



int x = 50, y = 70, vx = 4, vy = 2;

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
  Form1->PaintBox1->Canvas->Brush->Color = clWhite;
  Form1->PaintBox1->Canvas->Rectangle(0, 0, Form1->PaintBox1->Width, Form1->PaintBox1->Height);
  Form1->PaintBox1->Canvas->Brush->Color = clBlack;
  Form1->PaintBox1->Canvas->Ellipse(x,y,x + 30,y + 30);
  if (x <= 0 || x >= Form1->PaintBox1->Width - 30)
    vx *= -1;
  if (y <= 0 || y >= Form1->PaintBox1->Height - 30)
    vy *= -1;
  x += vx;
  y += vy;
}
//---------------------------------------------------------------------------
