using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Lab6
{
    public partial class Form1 : Form
    {
        private int a;
        private int b;
        private int m;
        private double h;
        private double eps;
        private Control[] xBoxes;
        private Control[] yBoxes;
        private List<int> iterations;

        public Form1()
        {
            InitializeComponent();

            iterations = new List<int>();

            chart1.ChartAreas[0].AxisX.ScaleView.Zoom(2, 12);
            chart1.ChartAreas[0].CursorX.IsUserEnabled = true;
            chart1.ChartAreas[0].CursorX.IsUserSelectionEnabled = true;
            chart1.ChartAreas[0].AxisY.ScaleView.Zoom(-4, 4);
            chart1.ChartAreas[0].CursorY.IsUserEnabled = true;
            chart1.ChartAreas[0].CursorY.IsUserSelectionEnabled = true;

            chart2.ChartAreas[0].AxisX.ScaleView.Zoom(0, 6);
            chart2.ChartAreas[0].CursorX.IsUserEnabled = true;
            chart2.ChartAreas[0].CursorX.IsUserSelectionEnabled = true;
            chart2.ChartAreas[0].CursorY.IsUserEnabled = true;
            chart2.ChartAreas[0].CursorY.IsUserSelectionEnabled = true;

            buttonCalculateFunc.Visible = false;
            button1.Visible = false;
            button2.Visible = false;
            chart1.Visible = false;
            chart2.Visible = false;
            button3.Visible = false;
            labelMin.Visible = false;
            labelAproax.Visible = false;
            textBoxAproax.Visible = false;
        }

        private void buttonConfirm_Click(object sender, EventArgs e)
        {
            a = int.Parse(textBoxA.Text);
            b = int.Parse(textBoxB.Text);
            m = int.Parse(textBoxM.Text);
            eps = double.Parse(textBoxE.Text);
            h = (double)(b - a) / m;
            Label labelH = new Label()
            {
                Location = new Point(labelE.Location.X + 90, labelE.Location.Y),
                Size = labelE.Size,
                Text = "h"
            };
            TextBox textBoxH = new TextBox()
            {
                Location = new Point(textBoxE.Location.X + 90, textBoxM.Location.Y),
                Size = textBoxE.Size,
                Text = h.ToString("0.0000"),
                ReadOnly = true
            };

            Controls.Add(labelH);
            Controls.Add(textBoxH);

            buttonCalculateFunc.Visible = true;
        }

        private void buttonCalculateFunc_Click(object sender, EventArgs e)
        {
            xBoxes = new Control[m + 1];
            yBoxes = new Control[m + 1];

            Size size = new Size(50, 20);
            int posX = 120, posY;
            double x, y;

            Label labelX = new Label() { Location = new Point(140, 100), Text = "X[i] = ", Size = new Size(25, 25)};
            Label labelY = new Label() { Location = new Point(140, 125), Text = "Y[i] = ", Size = new Size(25, 25)};
            Controls.Add(labelX);
            Controls.Add(labelY);

            for (int i = 0; i <= m; i++)
            {
                posX += 50;
                posY = 100;

                x = a + i * (double)(b - a) / m;
                xBoxes[i] = new TextBox()
                {
                    Location = new Point(posX, posY),
                    Size = size,
                    TextAlign = HorizontalAlignment.Center,
                    ReadOnly = true,
                    Text = x.ToString("0.0000")
                };
                Controls.Add(xBoxes[i]);

                y = Func(x);
                yBoxes[i] = new TextBox()
                {
                    Location = new Point(posX, posY + 25),
                    Size = size,
                    TextAlign = HorizontalAlignment.Center,
                    ReadOnly = true,
                    Text = y.ToString("0.0000")
                };

                Controls.Add(yBoxes[i]);

                button1.Visible = true;
                button2.Visible = true;
                button3.Visible = true;
                labelMin.Visible = true;
            }
        }

        private double Func(double x)
        {
            return Math.Log(x) - 5 * Math.Cos(x) * Math.Cos(x);
            //return (x * Math.Sin(x)) - (10 * Math.Pow(Math.Sin(x), 2));
        }

        private void button1_Click(object sender, EventArgs e)
        {
            chart1.Visible = true;
            for (int i = 0; i < m + 1; i++)
            {
                chart1.Series[0].Points.AddXY(double.Parse(xBoxes[i].Text), double.Parse(yBoxes[i].Text));
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            labelAproax.Visible = !labelAproax.Visible;
            textBoxAproax.Visible = !textBoxAproax.Visible;
            if (button2.Text[0] == 'Р')
            {
                button2.Text = "Подтвердить";
                textBoxAproax.Text = "";
            }

            else if (button2.Text[0] == 'П')
            {
                button2.Text = "Расчет минимума";
                double x = double.Parse(textBoxAproax.Text);
                double res = CalcMin(x);
                labelMin.Text += res.ToString("0.000") + "; ";
               // labelMin.Text += "-8.453; ";
            }
        }

        private double CalcMin(double x0)
        {
            double y0, x1, y1;
            double h = this.h/2;
            x1 = x0;
            y1 = Func(x1);
            int i = 0;
            do
            {
                i++;
                x0 = x1;
                y0 = y1;
                x1 = x0 + h;
                y1 = Func(x1);
                if(y1 > y0)
                {
                    h = -h / 4;
                    if (Math.Abs(h) < eps / 4) break;
            }
            } while (true);
            iterations.Add(i);
            return x0;
        }

        private void button3_Click(object sender, EventArgs e)
        {
            iterations.Clear();
            chart2.Visible = true;
            for (int i = -2; i > -6; i--)
            {
                eps = Math.Pow(10, i);
                CalcMin(double.Parse(xBoxes[2].Text));
            }

            for (int i = 0; i < iterations.Capacity; i++)
            {
                chart2.Series[0].Points.AddXY(i+2, iterations[i]);
            }
        }

        private void chart1_Click(object sender, EventArgs e)
        {

        }
    }
}
