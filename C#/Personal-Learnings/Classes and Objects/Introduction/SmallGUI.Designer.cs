using System;

namespace Introduction
{
    partial class SmallGUI
    {
        private System.ComponentModel.IContainer components = null;
        private System.Windows.Forms.Button startGameButton;
        private System.Windows.Forms.Button startCalculatorButton;
        private System.Windows.Forms.Label resultLabel;

        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        private void InitializeComponent()
        {
            this.startGameButton = new System.Windows.Forms.Button();
            this.startCalculatorButton = new System.Windows.Forms.Button();
            this.resultLabel = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // startGameButton
            // 
            this.startGameButton.Location = new System.Drawing.Point(10, 10);
            this.startGameButton.Name = "startGameButton";
            this.startGameButton.Size = new System.Drawing.Size(100, 30);
            this.startGameButton.TabIndex = 0;
            this.startGameButton.Text = "Start Game";
            this.startGameButton.UseVisualStyleBackColor = true;
            this.startGameButton.Click += new System.EventHandler(this.startGameButton_Click);
            // 
            // startCalculatorButton
            // 
            this.startCalculatorButton.Location = new System.Drawing.Point(120, 10);
            this.startCalculatorButton.Name = "startCalculatorButton";
            this.startCalculatorButton.Size = new System.Drawing.Size(120, 30);
            this.startCalculatorButton.TabIndex = 1;
            this.startCalculatorButton.Text = "Start Calculator";
            this.startCalculatorButton.UseVisualStyleBackColor = true;
            this.startCalculatorButton.Click += new System.EventHandler(this.startCalculatorButton_Click);
            // 
            // resultLabel
            // 
            this.resultLabel.AutoSize = true;
            this.resultLabel.Location = new System.Drawing.Point(10, 50);
            this.resultLabel.Name = "resultLabel";
            this.resultLabel.Size = new System.Drawing.Size(0, 13);
            this.resultLabel.TabIndex = 2;
            // 
            // SmallGUI
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.resultLabel);
            this.Controls.Add(this.startCalculatorButton);
            this.Controls.Add(this.startGameButton);
            this.Name = "SmallGUI";
            this.Text = "SmallGUI";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private void startGameButton_Click(object sender, EventArgs e)
        {
            Game game1 = new Game("FIFA 2020", "EA Sports", 9.5, 2019);
            IGame interfaceObj = game1;
            bool result = interfaceObj.Start("True");
            resultLabel.Text = "Game started: " + result;
        }

        private void startCalculatorButton_Click(object sender, EventArgs e)
        {
            Calculator calc1 = new Calculator();
            IGame interfaceObj = calc1;
            bool result2 = interfaceObj.Start("True");
            resultLabel.Text = "Calculator: " + result2;
        }
    }
}
