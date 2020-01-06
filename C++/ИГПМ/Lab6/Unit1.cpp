//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include <math.h>
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

static int itr[3];
static int i = 0;

double custom_round(double x, int precision)
{
        int mul = 10;

        for (int i = 0; i < precision; i++)
		mul *= mul;
        if (x > 0)
		return floor(x * mul + .5) / mul;
	else
		return ceil(x * mul - .5) / mul;
}

double f(double x)
{
        return (x * sin(x)) - (10 * pow(sin(x), 2));
}

double d1(double x)
{
        return x*cos(x)-20*sin(x)*cos(x)+sin(x);
}

double MDP(double a, double b ,double e)
{
        double x1 = 0, x2 = 0, y1 = 0, y2 = 0;
        int it = 0;

        do
        {
                it++;
                x1 = (a+b-e)/2;
                x2 = (a+b+e)/2;
                y1 = f(x1);
                y2 = f(x2);
                if(y1>y2)
                        a = x1;
                else
                        b = x2;
        }while(fabs(b-a)>=2*e);

        itr[i++] = it;

        return (a+b)/2;
}

void __fastcall TForm1::Button1Click(TObject *Sender)
{
        i = 0;
        
        double a, b, m, e, x, y, h, res[100];
        int k = 0;

        if(!TryStrToFloat(Edit1->Text,a) || !TryStrToFloat(Edit2->Text,b)
        || !TryStrToFloat(Edit3->Text,m) || !TryStrToFloat(Edit4->Text,e))
        {
            ShowMessage("Исходные данные введены некорректно!");
            return;
        }

        Memo1->Clear();
        Memo1->Lines->Add("Результаты: ");
        Memo1->Lines->Add("-----------------------------------------------------------------------------");
        Chart1->Series[0]->Clear();

        h = (b-a)/m;
        x = a;

        while(x<=b)
        {
                y = f(x);

                Chart1->Series[0]->AddXY(x, y);
                Memo1->Lines->Add("x = "+FloatToStrF(x,ffFixed,5,4)+"   y = "+FloatToStrF(y,ffFixed,5,4));

                if(d1(x-h)<0 && d1(x)>0)
                {
                        res[k] = MDP(x-h,x,e);
                        k++;
                }

                x+=h;
                x = custom_round(x,3);
        }

        Memo1->Lines->Add("-----------------------------------------------------------------------------");
        Memo1->Lines->Add("Минимум функции: ");
        Memo1->Lines->Add("-----------------------------------------------------------------------------");

        for(int j = 0; j<k;j++)
                Memo1->Lines->Add("x = "+FloatToStrF(res[j],ffFixed,5,4)+"   y = "+FloatToStrF(f(res[j]),ffFixed,5,4)
                + "  Количество итераций:"+ IntToStr(itr[j]));
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
        Edit1->Clear();
        Edit2->Clear();
        Edit3->Clear();
        Edit4->Clear();
        Memo1->Clear();
}
//---------------------------------------------------------------------------


