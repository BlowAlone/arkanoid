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
bool IsComplite = false;

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
class block;
ball *ball1;
block *blocks[400];

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
  friend void Collision (ball *ball1, block *block1);
private:
  int lifes;
  const double width, height;
public:
  block (double x1, double y1, int lf): object(x1, y1), lifes(lf), width(Form1->ClientWidth / 20),
                                        height(Form1->ClientHeight / 30) {}
  void Draw (void)
  {
    if (lifes == 3)
      back->Canvas->Brush->Color = clGreen;
    else if (lifes == 2)
      back->Canvas->Brush->Color = clYellow;
    else if (lifes == 1)
      back->Canvas->Brush->Color = clRed;
    if (lifes > 0)
    back->Canvas->Rectangle(x, y, x + width, y + height);
  }
  bool IsAlive( void )
  {
    return lifes > 0;
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
  friend void Collision (ball *ball1, block *block1);
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
  ball( void ): object(Form1->ClientWidth / 2, Form1->ClientHeight - 100), r(15), maxv(6), lifes(3)
  {
    srand(time(NULL));
    vx = ((rand() % 2) * 2.0 - 1) * rand() * 6.0 / RAND_MAX;
    vy = - sqrt((double)maxv * maxv - vx * vx);
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
        free(arcon1);
        for (int i = 0; i < 400; i++)
          free(blocks[i]);
        if (b == IDYES)
        {
          ball1=new ball();
          arcon1 = new arcon();
          int b = MessageBox( NULL, "Загрузить уровень 1? (Иначе загрузиться уровень 2)",
                              "Выбор уровня",
                              MB_YESNO |
                              MB_DEFBUTTON1 |
                              MB_ICONEXCLAMATION |
                              MB_DEFAULT_DESKTOP_ONLY
                             );
          int lvl;
          if (b == IDYES)
            lvl = 0;
          else
            lvl = 1;
          for(int i = 0; i < 400; i++)
            blocks[i] = new block((i % 20) * Form1->ClientWidth / 20,
                                  (i / 20) * Form1->ClientHeight / 30, LevelData[lvl][i]);
        }
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
  //static bool IsCol = true;
  double x1 = arcon1->x, x2 = ball1->x,
         y1 = arcon1->y, y2 = ball1->y;
  double len2 = (x1 - x2) * (x1 - x2) +
                (y1 - y2) * (y1 - y2);
  if (len2 <= (ball1->r + arcon1->r) * (ball1->r + arcon1->r)/* && !IsCol*/)
  {
    double nx = x2 - x1, ny = y2 - y1,
      nlen = sqrt(nx * nx + ny * ny);
    double cosa = (nx / nlen), sina = -(ny / nlen);
    double nvx = ball1->maxv * (ball1->vx * nx + ball1->vy * ny) / ball1->maxv / nlen,
      nvy = sqrt(ball1->maxv * ball1->maxv - nvx * nvx);
    if (ball1->vx * nx + ball1->vy * ny > 0)
      nvx = -ball1->maxv, nvy = 0;
    else if (cosa < - ball1->vx / ball1->maxv)
      nvy = -nvy;
    ball1->vx = - nvx * cosa + nvy * sina;
    ball1->vy = nvx * sina + nvy * cosa;
    //IsCol = true;
  }
  /*else if (len2 > (ball1->r + arcon1->r) * (ball1->r + arcon1->r))
    IsCol = false;*/
}

void Collision (ball *ball1, block *block1)
{
  if (block1->lifes == 0)
    return;
  if (ball1->x >= block1->x && ball1->x < block1->x + block1->width)
  {
    if (ball1->y >= block1->y - ball1->r && ball1->y < block1->y + block1->height + ball1->r)
      ball1->vy *= -1, block1->lifes--;
  }
  else if (ball1->y >= block1->y && ball1->y < block1->y + block1->height)
  {
    if (ball1->x >= block1->x - ball1->r && ball1->x < block1->x + block1->width + ball1->r)
      ball1->vx *= -1, block1->lifes--;
  }
  else if (ball1->y >= block1->y - ball1->r && ball1->y < block1->y &&
           ball1->x >= block1->x - ball1->r && ball1->x < block1->x)
  {
    double nx = ball1->x - block1->x, ny = ball1->y - block1->y,
      nlen = sqrt(nx * nx + ny * ny);
    double cosa = (nx / nlen), sina = (ny / nlen);
    ball1->vx = - ABS(ball1->maxv * cosa),
    ball1->vy = - ABS(ball1->maxv * sina),
    block1->lifes--;
  }
  else if (ball1->y >= block1->y - ball1->r && ball1->y < block1->y &&
           ball1->x >= block1->x + block1->width && ball1->x < block1->x + block1->width + ball1->r)
  {
    double nx = ball1->x - block1->x, ny = ball1->y - block1->y,
      nlen = sqrt(nx * nx + ny * ny);
    double cosa = (nx / nlen), sina = (ny / nlen);
    ball1->vx = ABS(ball1->maxv * cosa),
    ball1->vy = - ABS(ball1->maxv * sina),
    block1->lifes--;
  }
  else if (ball1->y >= block1->y + block1->height && ball1->y < block1->y + block1->height + ball1->r &&
           ball1->x >= block1->x - ball1->r && ball1->x < block1->x)
  {
    double nx = ball1->x - block1->x, ny = ball1->y - block1->y,
      nlen = sqrt(nx * nx + ny * ny);
    double cosa = (nx / nlen), sina = (ny / nlen);
    ball1->vx = - ABS(ball1->maxv * cosa),
    ball1->vy = ABS(ball1->maxv * sina),
    block1->lifes--;
  }
  else if (ball1->y >= block1->y + block1->height && ball1->y < block1->y + block1->height + ball1->r &&
           ball1->x >= block1->x + block1->width && ball1->x < block1->x + block1->width + ball1->r)
  {
    double nx = ball1->x - block1->x, ny = ball1->y - block1->y,
      nlen = sqrt(nx * nx + ny * ny);
    double cosa = (nx / nlen), sina = (ny / nlen);
    ball1->vx = ABS(ball1->maxv * cosa),
    ball1->vy = ABS(ball1->maxv * sina),
    block1->lifes--;
  }
}

void __fastcall TForm1::FormCreate(TObject *Sender)
{
  back=new Graphics::TBitmap();
  back->Width=Form1->ClientWidth;
  back->Height=Form1->ClientHeight;
  ball1=new ball();
  arcon1 = new arcon();
  int b = MessageBox( NULL, "Загрузить уровень 1? (Иначе загрузиться уровень 2)",
                    "Выбор уровня",
                    MB_YESNO |
                    MB_DEFBUTTON1 |
                    MB_ICONEXCLAMATION |
                    MB_DEFAULT_DESKTOP_ONLY
                  );
  int lvl;
  if (b == IDYES)
    lvl = 0;
  else
    lvl = 1;
  for(int i = 0; i < 400; i++)
    blocks[i] = new block((i % 20) * Form1->ClientWidth / 20,
                               (i / 20) * Form1->ClientHeight / 30, LevelData[lvl][i]);
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
  for (int i = 0; i < 400; i++)
    blocks[i]->Draw();
  ball1->Move();
  arcon1->Move();
  //GetCursorPos(&p);
  Collision(ball1, arcon1);
  for (int i = 0; i < 400; i++)
    Collision(ball1, blocks[i]);
  Form1->Canvas->Draw(0,0,back);
  IsComplite = true;
  for (int i = 0; i < 400; i++)
    if(blocks[i]->IsAlive())
      IsComplite = false;
  if (IsComplite)
  {
    MessageBox( NULL, "Вы прошли уровень!",
                    "Вы выиграли!",
                    MB_OK |
                    MB_DEFBUTTON1 |
                    MB_ICONEXCLAMATION |
                    MB_DEFAULT_DESKTOP_ONLY
                  );
    exit(0);
  }
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

