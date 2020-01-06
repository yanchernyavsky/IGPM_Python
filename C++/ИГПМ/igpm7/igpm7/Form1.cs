using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace igpm7
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            double a = 1;
            double b = 4;
            
        }

        private double f1(double x, double u1, double u2)
        {
            return (u1 * Math.Exp(x) / (x * u2));
        }

        private double f2(double x, double u1, double u2)
        {
            return 2 * u1 + u2 - 4 * x;
        }

        private void FPR(double x, double[] y, double[] F, double ny)
        {
            F[0] = f1(x, y[0], y[1]);
            F[1] = f2(x, y[0], y[1]);
        }

        private void OUT(double x, double[] y, double ny)
        {
            double u1 = 2 * x;
            double u2 = Math.Exp(x);

            chart1.Series[0].Points.AddXY(x, y[0]);
            chart1.Series[1].Points.AddXY(x, y[1]);

            richTextBox1.Text += "\n\nx=" + x + " y1=" + y[0] + " u1=" + u1 + " d1=" + (u1 - y[0]) + " y2=" + y[1] + " u2=" + u2 + " d2=" + (u2 - y[1]);
        }

        private void M4(double a, double b, double nx, double np, int ny, double[] y)
        {
            double h = (b - a) / nx;
            double x = a;
            if (np == 0)
                np = nx + 1;
            OUT(x, y, ny);

            for(int n=0; n<nx; n++)
            {
                double[] f = new double[2];
             
                FPR(x, y, f, ny);
                x = x + h / 2;

                double[] yp = new double[ny];
                for(int i =0; i<ny; i++)
                {
                    yp[i] = y[i] + h / 2 * f[i];

                }

                FPR(x, yp, f, ny);
                x = x + h / 2;

                for(int i = 0; i<ny; i++)
                {
                    y[i] = y[i] + h * f[i];
                }

                if (n % np == 0)
                    OUT(x, y, ny);
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            double a = double.Parse(textBox1.Text);
            double b = double.Parse(textBox2.Text);
            double nx = double.Parse(textBox3.Text);
            double np = 0.5;
            int ny = 2;
            chart1.Series[0].Points.Clear();
            chart1.Series[1].Points.Clear();
            richTextBox1.Text = "";
            M4(a, b, nx, np, ny, new double[2] { 2 * a, Math.Exp(a) });
        }
    }
}
