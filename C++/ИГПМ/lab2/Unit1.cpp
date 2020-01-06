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

void __fastcall TForm1::Button1Click(TObject *Sender)
{
        Memo1->Clear();
        Memo1->Lines->Add("Лабораторна работая №2 \"Аппроксимация функции\"");
        Memo1->Lines->Add("Функция f(x) = 0.1*x^3+x^2-10*sin(x)");
        Memo1->Lines->Add("--------------------------------------------------------------------------------");
        Memo1->Lines->Add("Результаты: ");
        double a  = -4, b =6, m = 11;
        double x[11], y[11], xt[21], fx[21], qx[21], d[21];
        int j=  0, i= 0;

        for(int i = 1;i<=m;i++)
        {
                x[i-1] = a + (i - 1)*(b - a) / (m - 1);
		y[i-1] = 0.1*pow(x[i-1],3)+pow(x[i-1],2) - 10 * sin(x[i-1]);
        }

        for(int j = 1;j<=21;j++ )
                xt[j - 1] = a + (j - 1)*(b - a) / 20;

        while(xt[j]>=x[0] && xt[j]<=x[10])
        {

                if(xt[j] == x[i])
                {
                        fx[j] = qx[j] = y[i];
                        d[j] = fx[j] - qx[j];
                        j++;
                        i++;
                }
                else
                {
                        i = 1;
                        while(xt[j]>x[i])
                                i++;
                        qx[j] = y[i - 1] + (xt[j] - x[i - 1])*((y[i] - y[i - 1]) / (x[i] - x[i - 1]));
                        fx[j] = 0.1*pow(xt[j],3)+pow(xt[j],2) - 10 * sin(xt[j]);
                        d[j] = fabs(fx[j]-qx[j]);
                        j++;
                }
        }

        for(int j = 0; j<21;j++)
        {
                Chart1->Series[0]->AddXY(xt[j],fx[j]);
                Chart1->Series[1]->AddXY(xt[j],qx[j]);
                Memo1->Lines->Add("x["+IntToStr(j+1)+"] = "+FloatToStr(xt[j])+ "    f("+FloatToStr(xt[j])+") = "
                + FloatToStrF(fx[j], ffFixed, 5,4)+"    q("+FloatToStr(xt[j])+") = "+FloatToStrF(qx[j], ffFixed,5,4));
                Memo1->Lines->Add("погрешноть = "+ FloatToStrF(d[j],ffFixed,5,4));
                Memo1->Lines->Add("--------------------------------------------------------------------------------");
        }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
        Memo1->Clear();
          Memo1->Lines->Add("Лабораторна работая №2 \"Аппроксимация функции\"");
        Memo1->Lines->Add("Функция f(x) = 0.1*x^3+x^2-10*sin(x)");
        Memo1->Lines->Add("--------------------------------------------------------------------------------");
        Memo1->Lines->Add("Результаты: ");
}
//---------------------------------------------------------------------------
