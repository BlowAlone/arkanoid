//---------------------------------------------------------------------------

#include <vcl.h>
#include <math.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

#define WIDTH 1000
#define HEIGHT 450
#define PI 3.14159265358979
#define ABS(x) ((x) >= 0 ? (x) : -(x))

TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

// Основной класс, от которого наследуються все остальные классы
class object
{
protected:
  double x, y; // Координаты
  object (double x1, double y1): x(x1), y(y1){}  // Конструктор
  object ( void ){} // Стандартный конструктор
  virtual void Draw (void) {}  // Виртуальная функция рисования
};

class ball; // Объявление класса ball

// Класс платформы
class arcon: private object
{
  friend void Collision (ball *ball1, arcon *arcon1); // Дружественная функция Collision
private:
  const int r; // Радиус
public:
  arcon (void): object(WIDTH / 2 - 50, HEIGHT), r(50){} // Конструктор
  virtual void Draw (void) // Виртуальная функция рисования
  {
    Form1->PaintBox1->Canvas->Brush->Color = clBlue;
    Form1->PaintBox1->Canvas->Ellipse(x - r,y - r,x + r,y + r);
  }
  void Move (POINT *p) // Функция передвижения
  {
    x = p->x;
    if (x < r)
      x = r;
    else if (x > WIDTH - r)
      x = WIDTH - r;
  }

} *arcon1 = new arcon();

//Класс мяча
class ball: private object
{
  friend void Collision (ball *ball1, arcon *arcon1); // Дружественная функция Collision
private:
  const int r; // Радиус
  const double maxv; // Максимальная скорость
  double vx, vy; // Скорость в проэкции на оси x и y
public:
  ball( void ): object(50, 70), r(15), vx(4), vy(5), maxv(sqrt(16 + 25)) // Конструктор
  {
  }
  void Move( void ) // Функция передвижения
  {
    if (x <= r || x >= Form1->PaintBox1->Width - r)
      vx *= -1;
    if (y <= r || y >= Form1->PaintBox1->Height - r)
      vy *= -1;
    x += vx;
    y += vy;
  }
  virtual void Draw( void ) // Виртуальная функция рисования
  {
    Form1->PaintBox1->Canvas->Brush->Color = clBlack;
    Form1->PaintBox1->Canvas->Ellipse(x - r, y - r, x + r, y + r);
  }
} *ball1 = new ball();

// Функция взаимодействия мяча и платформы
void Collision (ball *ball1, arcon *arcon1)
{
  static bool IsCol = true;
  double x1 = arcon1->x, x2 = ball1->x,
         y1 = arcon1->y, y2 = ball1->y;
  double len2 = (x1 - x2) * (x1 - x2) +
                (y1 - y2) * (y1 - y2);
  if (len2 <= (ball1->r + arcon1->r) * (ball1->r + arcon1->r) && !IsCol)
  {
    double nx = x2 - x1, ny = y2 - y1,
      nlen = sqrt(nx * nx + ny * ny);
    double cosa = (nx / nlen), sina = -(ny / nlen);
    double nvx = ball1->maxv * (ball1->vx * nx + ball1->vy * ny) / ball1->maxv / nlen,
      nvy = sqrt(ball1->maxv * ball1->maxv - nvx * nvx);
    if (cosa < - ball1->vx / ball1->maxv)
      nvy = - nvy;
    ball1->vx = - nvx * cosa + nvy * sina;
    ball1->vy = nvx * sina + nvy * cosa;
    IsCol = true;
  }
  else if (len2 > (ball1->r + arcon1->r) * (ball1->r + arcon1->r))
    IsCol = false;
}

// Координаты курсора
POINT p;

// Функция таймера
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
  Form1->Width = WIDTH + 8;
  Form1->Height = HEIGHT + 31;
  Form1->PaintBox1->Width = WIDTH;
  Form1->PaintBox1->Height = HEIGHT;
  Form1->PaintBox1->Canvas->Brush->Color = clWhite;
  Form1->PaintBox1->Canvas->Rectangle(0, 0, Form1->PaintBox1->Width, Form1->PaintBox1->Height);
  ball1->Draw();
  arcon1->Draw();
  ball1->Move();
  arcon1->Move(&p);
  GetCursorPos(&p);
  Collision(ball1, arcon1);
}
//---------------------------------------------------------------------------
