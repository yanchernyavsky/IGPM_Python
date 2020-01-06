namespace Lab6
{
    partial class Form1
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            System.Windows.Forms.DataVisualization.Charting.ChartArea chartArea1 = new System.Windows.Forms.DataVisualization.Charting.ChartArea();
            System.Windows.Forms.DataVisualization.Charting.Legend legend1 = new System.Windows.Forms.DataVisualization.Charting.Legend();
            System.Windows.Forms.DataVisualization.Charting.Series series1 = new System.Windows.Forms.DataVisualization.Charting.Series();
            System.Windows.Forms.DataVisualization.Charting.Title title1 = new System.Windows.Forms.DataVisualization.Charting.Title();
            System.Windows.Forms.DataVisualization.Charting.ChartArea chartArea2 = new System.Windows.Forms.DataVisualization.Charting.ChartArea();
            System.Windows.Forms.DataVisualization.Charting.Legend legend2 = new System.Windows.Forms.DataVisualization.Charting.Legend();
            System.Windows.Forms.DataVisualization.Charting.Series series2 = new System.Windows.Forms.DataVisualization.Charting.Series();
            System.Windows.Forms.DataVisualization.Charting.Title title2 = new System.Windows.Forms.DataVisualization.Charting.Title();
            this.lblFunc = new System.Windows.Forms.Label();
            this.lblA = new System.Windows.Forms.Label();
            this.lblB = new System.Windows.Forms.Label();
            this.textBoxA = new System.Windows.Forms.TextBox();
            this.textBoxB = new System.Windows.Forms.TextBox();
            this.lblM = new System.Windows.Forms.Label();
            this.textBoxM = new System.Windows.Forms.TextBox();
            this.textBoxE = new System.Windows.Forms.TextBox();
            this.labelE = new System.Windows.Forms.Label();
            this.buttonConfirm = new System.Windows.Forms.Button();
            this.buttonCalculateFunc = new System.Windows.Forms.Button();
            this.button1 = new System.Windows.Forms.Button();
            this.chart1 = new System.Windows.Forms.DataVisualization.Charting.Chart();
            this.button2 = new System.Windows.Forms.Button();
            this.textBoxAproax = new System.Windows.Forms.TextBox();
            this.labelAproax = new System.Windows.Forms.Label();
            this.labelMin = new System.Windows.Forms.Label();
            this.button3 = new System.Windows.Forms.Button();
            this.chart2 = new System.Windows.Forms.DataVisualization.Charting.Chart();
            ((System.ComponentModel.ISupportInitialize)(this.chart1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.chart2)).BeginInit();
            this.SuspendLayout();
            // 
            // lblFunc
            // 
            this.lblFunc.AutoSize = true;
            this.lblFunc.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.lblFunc.Location = new System.Drawing.Point(27, 30);
            this.lblFunc.Name = "lblFunc";
            this.lblFunc.Size = new System.Drawing.Size(164, 20);
            this.lblFunc.TabIndex = 0;
            this.lblFunc.Text = "f(x) =xsin(x)-10sin^2(x)";
            // 
            // lblA
            // 
            this.lblA.AutoSize = true;
            this.lblA.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.lblA.Location = new System.Drawing.Point(288, 12);
            this.lblA.Name = "lblA";
            this.lblA.Size = new System.Drawing.Size(16, 17);
            this.lblA.TabIndex = 1;
            this.lblA.Text = "a";
            // 
            // lblB
            // 
            this.lblB.AutoSize = true;
            this.lblB.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.lblB.Location = new System.Drawing.Point(389, 12);
            this.lblB.Name = "lblB";
            this.lblB.Size = new System.Drawing.Size(16, 17);
            this.lblB.TabIndex = 2;
            this.lblB.Text = "b";
            // 
            // textBoxA
            // 
            this.textBoxA.Location = new System.Drawing.Point(267, 32);
            this.textBoxA.Name = "textBoxA";
            this.textBoxA.Size = new System.Drawing.Size(56, 20);
            this.textBoxA.TabIndex = 3;
            // 
            // textBoxB
            // 
            this.textBoxB.Location = new System.Drawing.Point(366, 32);
            this.textBoxB.Name = "textBoxB";
            this.textBoxB.Size = new System.Drawing.Size(56, 20);
            this.textBoxB.TabIndex = 4;
            // 
            // lblM
            // 
            this.lblM.AutoSize = true;
            this.lblM.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.lblM.Location = new System.Drawing.Point(484, 12);
            this.lblM.Name = "lblM";
            this.lblM.Size = new System.Drawing.Size(19, 17);
            this.lblM.TabIndex = 5;
            this.lblM.Text = "m";
            // 
            // textBoxM
            // 
            this.textBoxM.Location = new System.Drawing.Point(463, 32);
            this.textBoxM.Name = "textBoxM";
            this.textBoxM.Size = new System.Drawing.Size(56, 20);
            this.textBoxM.TabIndex = 6;
            // 
            // textBoxE
            // 
            this.textBoxE.Location = new System.Drawing.Point(550, 32);
            this.textBoxE.Name = "textBoxE";
            this.textBoxE.Size = new System.Drawing.Size(56, 20);
            this.textBoxE.TabIndex = 7;
            // 
            // labelE
            // 
            this.labelE.AutoSize = true;
            this.labelE.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelE.Location = new System.Drawing.Point(571, 12);
            this.labelE.Name = "labelE";
            this.labelE.Size = new System.Drawing.Size(15, 17);
            this.labelE.TabIndex = 8;
            this.labelE.Text = "ε";
            // 
            // buttonConfirm
            // 
            this.buttonConfirm.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.buttonConfirm.Location = new System.Drawing.Point(31, 71);
            this.buttonConfirm.Name = "buttonConfirm";
            this.buttonConfirm.Size = new System.Drawing.Size(96, 42);
            this.buttonConfirm.TabIndex = 9;
            this.buttonConfirm.Text = "Подвердить значения ";
            this.buttonConfirm.UseVisualStyleBackColor = true;
            this.buttonConfirm.Click += new System.EventHandler(this.buttonConfirm_Click);
            // 
            // buttonCalculateFunc
            // 
            this.buttonCalculateFunc.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.buttonCalculateFunc.Location = new System.Drawing.Point(31, 134);
            this.buttonCalculateFunc.Name = "buttonCalculateFunc";
            this.buttonCalculateFunc.Size = new System.Drawing.Size(96, 42);
            this.buttonCalculateFunc.TabIndex = 10;
            this.buttonCalculateFunc.Text = "Рассчитать значения f(x)";
            this.buttonCalculateFunc.UseVisualStyleBackColor = true;
            this.buttonCalculateFunc.Click += new System.EventHandler(this.buttonCalculateFunc_Click);
            // 
            // button1
            // 
            this.button1.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.button1.Location = new System.Drawing.Point(31, 195);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(96, 42);
            this.button1.TabIndex = 11;
            this.button1.Text = "График функции f(x)";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // chart1
            // 
            chartArea1.Name = "ChartArea1";
            this.chart1.ChartAreas.Add(chartArea1);
            legend1.Name = "Legend1";
            this.chart1.Legends.Add(legend1);
            this.chart1.Location = new System.Drawing.Point(31, 378);
            this.chart1.Name = "chart1";
            series1.ChartArea = "ChartArea1";
            series1.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Spline;
            series1.Legend = "Legend1";
            series1.Name = "Series1";
            this.chart1.Series.Add(series1);
            this.chart1.Size = new System.Drawing.Size(522, 300);
            this.chart1.TabIndex = 12;
            this.chart1.Text = "chart1";
            title1.Name = "Title1";
            title1.Text = "График функции y = x*sin(x)-10sin^2(x)";
            this.chart1.Titles.Add(title1);
            this.chart1.Click += new System.EventHandler(this.chart1_Click);
            // 
            // button2
            // 
            this.button2.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.button2.Location = new System.Drawing.Point(31, 267);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(96, 42);
            this.button2.TabIndex = 13;
            this.button2.Text = "Расчет минимума";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // textBoxAproax
            // 
            this.textBoxAproax.Location = new System.Drawing.Point(291, 289);
            this.textBoxAproax.Name = "textBoxAproax";
            this.textBoxAproax.Size = new System.Drawing.Size(56, 20);
            this.textBoxAproax.TabIndex = 14;
            // 
            // labelAproax
            // 
            this.labelAproax.AutoSize = true;
            this.labelAproax.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelAproax.Location = new System.Drawing.Point(146, 289);
            this.labelAproax.Name = "labelAproax";
            this.labelAproax.Size = new System.Drawing.Size(142, 15);
            this.labelAproax.TabIndex = 15;
            this.labelAproax.Text = "Введите приближение:";
            // 
            // labelMin
            // 
            this.labelMin.AutoSize = true;
            this.labelMin.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelMin.Location = new System.Drawing.Point(28, 344);
            this.labelMin.Name = "labelMin";
            this.labelMin.Size = new System.Drawing.Size(147, 17);
            this.labelMin.TabIndex = 16;
            this.labelMin.Text = "Минимумы функции: ";
            // 
            // button3
            // 
            this.button3.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.button3.Location = new System.Drawing.Point(836, 308);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(96, 42);
            this.button3.TabIndex = 17;
            this.button3.Text = "График f(ε)";
            this.button3.UseVisualStyleBackColor = true;
            this.button3.Click += new System.EventHandler(this.button3_Click);
            // 
            // chart2
            // 
            chartArea2.Name = "ChartArea1";
            this.chart2.ChartAreas.Add(chartArea2);
            legend2.Name = "Legend1";
            this.chart2.Legends.Add(legend2);
            this.chart2.Location = new System.Drawing.Point(592, 378);
            this.chart2.Name = "chart2";
            series2.ChartArea = "ChartArea1";
            series2.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Spline;
            series2.Legend = "Legend1";
            series2.Name = "Series1";
            this.chart2.Series.Add(series2);
            this.chart2.Size = new System.Drawing.Size(583, 300);
            this.chart2.TabIndex = 18;
            this.chart2.Text = "chart2";
            title2.Name = "Title1";
            title2.Text = "График y = f(ε)";
            this.chart2.Titles.Add(title2);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1350, 729);
            this.Controls.Add(this.chart2);
            this.Controls.Add(this.button3);
            this.Controls.Add(this.labelMin);
            this.Controls.Add(this.labelAproax);
            this.Controls.Add(this.textBoxAproax);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.chart1);
            this.Controls.Add(this.button1);
            this.Controls.Add(this.buttonCalculateFunc);
            this.Controls.Add(this.buttonConfirm);
            this.Controls.Add(this.labelE);
            this.Controls.Add(this.textBoxE);
            this.Controls.Add(this.textBoxM);
            this.Controls.Add(this.lblM);
            this.Controls.Add(this.textBoxB);
            this.Controls.Add(this.textBoxA);
            this.Controls.Add(this.lblB);
            this.Controls.Add(this.lblA);
            this.Controls.Add(this.lblFunc);
            this.Name = "Form1";
            this.Text = "Лабораторная работа №6";
            ((System.ComponentModel.ISupportInitialize)(this.chart1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.chart2)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label lblFunc;
        private System.Windows.Forms.Label lblA;
        private System.Windows.Forms.Label lblB;
        private System.Windows.Forms.TextBox textBoxA;
        private System.Windows.Forms.TextBox textBoxB;
        private System.Windows.Forms.Label lblM;
        private System.Windows.Forms.TextBox textBoxM;
        private System.Windows.Forms.TextBox textBoxE;
        private System.Windows.Forms.Label labelE;
        private System.Windows.Forms.Button buttonConfirm;
        private System.Windows.Forms.Button buttonCalculateFunc;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.DataVisualization.Charting.Chart chart1;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.TextBox textBoxAproax;
        private System.Windows.Forms.Label labelAproax;
        private System.Windows.Forms.Label labelMin;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.DataVisualization.Charting.Chart chart2;
    }
}

