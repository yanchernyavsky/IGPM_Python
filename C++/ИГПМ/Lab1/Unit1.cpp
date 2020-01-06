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

void __fastcall TForm1::BitBtn1Click(TObject *Sender)
{
        double **A, *B, *x, *xn, norma, w , eps;
        int n= 0, k = 0;
         int temp=0;
         
        w = Edit3->Text.ToDouble();
        eps = Edit2->Text.ToDouble();
        n = Edit1->Text.ToInt();
        Memo1->Clear();

        A = new double*[n];
        for(int i = 0; i<n;i++)
                A[i] = new double[n];
        B = new double[n];
        x = new double[n];
        xn = new double[n];

        for(int i = 0;i<n;i++)
        {
                B[i] = StringGrid2->Cells[0][i].ToDouble();
                for(int j = 0; j<n;j++)
                        A[i][j] = StringGrid1->Cells[j][i].ToDouble();
        }

        for(int i = 0; i<n; i++)
        {
                xn[i] = 0;
                x[i] = 0;
        }

        do
        {
                k++;
                norma = 0;
                for(int i = 0; i<n;i++)
                {
                        xn[i] = B[i];
                        for(int j = 0;j<n;j++)
                        {
                                if(i!=j)
                                        xn[i]-= A[i][j]*x[j];
                        }
                        temp= xn[i];
                        xn[i]/=A[i][i];
                        if(w>0)

                                xn[i] = w*xn[i]+(1-w)*x[i];
                       for(int i = 0; i<n;i++)
                {
                        if (fabs(x[i] - xn[i]) > norma)
                                norma = fabs(x[i] - xn[i]); }
                        x[i]=xn[i];
                }




                Memo1->Lines->Add("�������� �"+IntToStr(k)+": ");
                Memo1->Lines->Add("�����������: "+FloatToStr(norma));
                for (int i = 0; i < n; i++)
                {
                        Memo1->Lines->Add("X["+IntToStr(i)+"] = " +FloatToStr(x[i]));
                }
        } while(norma>eps && k<=100);
        
        if(k>100)
                Memo1->Lines->Add("���������� �������� ��������� 100.");
        else
        {

                Memo1->Lines->Add("���������� ��������: "+IntToStr(k));
                for(int i = 0; i<n;i++)
                        Memo1->Lines->Add("X["+IntToStr(i)+"] = " +FloatToStr(x[i]));
        }

        for(int i = 0; i<n;i++)
                delete[] A[i];
        delete[] A;
        delete[] B;
        delete[] x;
        delete[] xn;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit1Exit(TObject *Sender)
{
        int n = Edit1->Text.ToInt();
        StringGrid1->ColCount = n;
        StringGrid1->RowCount = n;
        StringGrid2->RowCount = n;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit1KeyPress(TObject *Sender, char &Key)
{
        if(Key == VK_RETURN)
        {
                int n = Edit1->Text.ToInt();
                StringGrid1->ColCount = n;
                StringGrid1->RowCount = n;
                StringGrid2->RowCount = n;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormCreate(TObject *Sender)
{
        Edit1->Clear();
        Edit2->Clear();
        Edit3->Clear();
        Memo1->Clear();
        Memo1->Lines->Add("����������: ");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
        double **A, *B, *x, *xn, norma, w , eps, wmin = 0;
        int n= 0, k = 0, kmin = 100;

        eps = Edit2->Text.ToDouble();
        n = Edit1->Text.ToInt();
        Chart1->Series[0]->Clear();

        A = new double*[n];
        for(int i = 0; i<n;i++)
                A[i] = new double[n];
        B = new double[n];
        x = new double[n];
        xn = new double[n];

        for(int i = 0;i<n;i++)
        {
                B[i] = StringGrid2->Cells[0][i].ToDouble();
                for(int j = 0; j<n;j++)
                        A[i][j] = StringGrid1->Cells[j][i].ToDouble();
        }

        for( w = 0.2; w<=2;w+=0.2)
        {
                for(int i = 0; i<n; i++)
                {
                        xn[i] = 0;
                        x[i] = 0;
                }

                k = 0;

                do
                {
                        k++;
                        norma = 0;
                        for(int i = 0; i<n;i++)
                        {
                                xn[i] = B[i];
                                for(int j = 0;j<n;j++)
                                {
                                        if(i!=j)
                                                xn[i]-= A[i][j]*x[j];
                                }
                                xn[i]/=A[i][i];
                                if(w>0)
                                        xn[i] = w*xn[i]+(1-w)*x[i];
                                if (fabs(x[i] - xn[i]) > norma)
                                        norma = fabs(x[i] - xn[i]);
                                x[i]=xn[i];
                        }
                } while(norma>eps && k<=100);
                Chart1->Series[0]->AddXY(w,k);
                if(k<kmin)
                {
                        kmin = k;
                        wmin = w;
                }
        }
        Memo1->Lines->Add("����������� ���������� �������� k = "+ IntToStr(kmin)+ " ��� w = " + FloatToStr(wmin));

        for(int i = 0; i<n;i++)
                delete[] A[i];
        delete[] A;
        delete[] B;
        delete[] x;
        delete[] xn;
}
//---------------------------------------------------------------------------

