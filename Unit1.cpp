//---------------------------------------------------------------------------

#include <vcl.h>
#include <math.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

#define PI 3.14159265358979
#define ABS(x) ((x) >= 0 ? (x) : -(x))

TForm1 *Form1;
Graphics::TBitmap *back;
// Координаты курсора
//POINT p;
int dir = 0;

int LevelData[2][400]=
{
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,2,2,2,2,2,2,2,2,2,2,2,2,0,0,0,0,
0,0,0,2,1,1,1,1,1,1,1,1,1,1,1,1,2,0,0,0,
0,0,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,0,0,
0,2,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,2,0,
3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,3,
0,3,1,1,1,1,1,2,2,2,2,2,2,1,1,1,1,1,3,0,
0,0,3,1,1,1,1,2,2,2,2,2,2,1,1,1,1,3,0,0,
0,0,0,3,1,1,1,1,1,1,1,1,1,1,1,1,3,0,0,0,
0,0,0,0,3,1,1,1,1,1,1,1,1,1,1,3,0,0,0,0,
0,0,0,0,0,3,1,1,1,1,1,1,1,1,3,0,0,0,0,0,
0,0,0,0,0,0,3,1,1,1,1,1,1,3,0,0,0,0,0,0,
0,0,0,0,0,0,0,3,1,1,1,1,3,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,3,1,1,3,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,3,3,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,

2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,
3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,

};

class ball; // Объявление класса ball

ball *ball1;

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
  // ------------------------------
  // Назначение: Конструктор класса object
  // Входные параметры: Координаты объекта x1, y1
  // Выходные параметры: отсутствуют
  // ------------------------------
  object (double x1, double y1): x(x1), y(y1){}
  // ------------------------------
  // Назначение: Виртуальная функция рисования
  // Входные параметры: отсутствуют
  // Выходные параметры: отсутствуют
  // ------------------------------
  virtual void Draw (void) {}
};

class block: private object
{
private:
  int lifes;
public:
  block (double x1, double y1, int lf): object(x1, y1), lifes(lf){}
  void Draw (void)
  {
    if (lifes == 3)
      back->Canvas->Brush->Color = clGreen;
    else if (lifes == 2)
      back->Canvas->Brush->Color = clYellow;
    else if (lifes == 1)
      back->Canvas->Brush->Color = clRed;
    else
      back->Canvas->Brush->Color = clWhite;
    back->Canvas->Rectangle(x, y, x + Form1->ClientWidth / 20, y + Form1->ClientHeight / 30);
  }
};

// Класс платформы
class arcon: private object
{
  friend void Collision (ball *ball1, arcon *arcon1); // Дружественная функция Collision
private:
  //Graphics::TBitmap *arcon;
  const double v;
  const int r; // Радиус
public:
  // ------------------------------
  // Назначение: Конструктор класса arcon
  // Входные параметры: отсутствуют
  // Выходные параметры: отсутствуют
  // ------------------------------
  arcon (void): object(Form1->ClientWidth / 2, Form1->ClientHeight), r(50), v(10)
  {
    /*arcon = new Graphics::TBitmap();
    arcon->Canvas->Brush->Color = clBlue;
    arcon->Width = 2 * r;
    arcon->Height = r;
    arcon->Canvas->Ellipse(0, -r, 2 * r, r);
    arcon->Transparent=true;*/
  }
  // ------------------------------
  // Назначение: Виртуальная функция рисования платформы
  // Входные параметры: отсутствуют
  // Выходные параметры: отсутствуют
  // ------------------------------
  virtual void Draw (void)
  {
    back->Canvas->Brush->Color = clBlue;
    back->Canvas->Ellipse(x - r, y - r, x + r, y + r);
    //back->Transparent=true;
  }
  // ------------------------------
  // Назначение: Функция передвижения платформы
  // Входные параметры: Указатель на координаты курсора
  // Выходные параметры: отсутствуют
  // ------------------------------
  void Move ( void )
  {
    x += dir * v;
    if (x < r)
      x = r;
    else if (x > Form1->ClientWidth - r)
      x = Form1->ClientWidth - r;
  }

} *arcon1;

//Класс мяча
class ball: private object
{
  friend void Collision (ball *ball1, arcon *arcon1); // Дружественная функция Collision
private:
  int lifes;
  //Graphics::TBitmap *ball;
  const int r; // Радиус
  const double maxv; // Максимальная скорость
  double vx, vy; // Скорость в проэкции на оси x и y
public:
  // ------------------------------
  // Назначение: Конструктор шарика
  // Входные параметры: отсутствуют
  // Выходные параметры: отсутствуют
  // ------------------------------
  ball( void ): object(50, 70), r(15), vx(4), vy(5), maxv(sqrt(16 + 25)), lifes(3)
  {
    //ball=new Graphics::TBitmap();
    /*ball->Canvas->Brush->Color = clBlack;
    ball->Width = 2 * r;
    ball->Height = 2 * r;
    ball->Canvas->Ellipse(0, 0, 2 * r, 2 * r);
    ball->Transparent=true;*/
  }
  // ------------------------------
  // Назначение: Функция передвижения шарика
  // Входные параметры: отсутствуют
  // Выходные параметры: отсутствуют
  // ------------------------------
  void Move( void )
  {
    if (x <= r || x >= back->Width - r)
      vx *= -1;
    if (y <= r)
      vy *= -1;
    if (y >= back->Height - r)
    {
      if (lifes > 0)
      {
        lifes--;
        vy *= -1;
        char s1[] = "Осталось жизней:  ";
        s1[17] = lifes + '0';
        MessageBox( NULL, s1,
                    "",
                    MB_OK |
                    MB_DEFBUTTON1 |
                    MB_ICONEXCLAMATION |
                    MB_DEFAULT_DESKTOP_ONLY
                  );
      }
      else
      {
        int b = MessageBox( NULL, "Начать новую игру?",
                    "Game over!",
                    MB_YESNO |
                    MB_DEFBUTTON1 |
                    MB_ICONEXCLAMATION |
                    MB_DEFAULT_DESKTOP_ONLY
                  );
        free(ball1);
        if (b == IDYES)
          ball1 = new ball();
        else
          exit(0);
      }
    }
    x += vx;
    y += vy;
  }
  // ------------------------------
  // Назначение: Виртуальная функция рисования шарика
  // Входные параметры: отсутствуют
  // Выходные параметры: отсутствуют
  // ------------------------------
  virtual void Draw( void )
  {
    back->Canvas->Brush->Color = clBlack;
    back->Canvas->Ellipse(x - r, y - r, x + r, y + r);
    //back->Transparent=true;
  }
};
  // ------------------------------
  // Назначение: Функция взаимодействия мяча и платформы
  // Входные параметры: Указатели на шарик и платформу
  // Выходные параметры: отсутствуют
  // ------------------------------
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
    //nvx = -ABS(nvx);
    if (cosa < - ball1->vx / ball1->maxv)
      nvy = -nvy;
    ball1->vx = - nvx * cosa + nvy * sina;
    ball1->vy = nvx * sina + nvy * cosa;
    IsCol = true;
  }
  else if (len2 > (ball1->r + arcon1->r) * (ball1->r + arcon1->r))
    IsCol = false;
}

void __fastcall TForm1::FormCreate(TObject *Sender)
{
back=new Graphics::TBitmap();
back->Width=Form1->ClientWidth;
back->Height=Form1->ClientHeight;
ball1=new ball();
arcon1 = new arcon();
/*Bita=new Graphics::TBitmap();
Bita->LoadFromFile("Бита.bmp");
Bita->Transparent=true;*/
//dx=Form1->ClientWidth;
//dy=Form1->ClientHeight;
//LoadBlockPicture();
//LoadLevel(CurrentLevel);
}

  // ------------------------------
  // Назначение: Функция таймера
  // Входные параметры: указатель на объект
  // Выходные параметры: отсутствуют
  // ------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
  back->Canvas->Brush->Color = clWhite;
  back->Canvas->Rectangle(0, 0, back->Width, back->Height);
  ball1->Draw();
  arcon1->Draw();
  ball1->Move();
  arcon1->Move();
  //GetCursorPos(&p);
  Collision(ball1, arcon1);
  Form1->Canvas->Draw(0,0,back);
}


void __fastcall TForm1::FormKeyPress(TObject *Sender, char &Key)
{
  if (Key == 'a' || Key == 'A' || Key == 'ф' || Key == 'Ф')
    dir = -1;
  if (Key == 'd' || Key == 'D' || Key == 'В' || Key == 'в')
    dir = 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
  if (Key == 'a' || Key == 'A' || Key == 'ф' || Key == 'Ф')
    dir = 0;
  if (Key == 'd' || Key == 'D' || Key == 'В' || Key == 'в')
    dir = 0;
}
//---------------------------------------------------------------------------

