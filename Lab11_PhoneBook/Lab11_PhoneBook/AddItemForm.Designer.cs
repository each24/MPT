namespace Lab11_PhoneBook {
	partial class AddItemForm {
		/// <summary>
		/// Required designer variable.
		/// </summary>
		private System.ComponentModel.IContainer components = null;

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		/// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
		protected override void Dispose(bool disposing) {
			if (disposing && (components != null)) {
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		#region Windows Form Designer generated code

		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent() {
			this.button_add = new System.Windows.Forms.Button();
			this.label1 = new System.Windows.Forms.Label();
			this.textBox_name = new System.Windows.Forms.TextBox();
			this.label2 = new System.Windows.Forms.Label();
			this.textBox_phone = new System.Windows.Forms.TextBox();
			this.button_cancel = new System.Windows.Forms.Button();
			this.SuspendLayout();
			// 
			// button_add
			// 
			this.button_add.Location = new System.Drawing.Point(13, 100);
			this.button_add.Name = "button_add";
			this.button_add.Size = new System.Drawing.Size(75, 23);
			this.button_add.TabIndex = 0;
			this.button_add.Text = "Добавить";
			this.button_add.UseVisualStyleBackColor = true;
			this.button_add.Click += new System.EventHandler(this.AddItem);
			// 
			// label1
			// 
			this.label1.AutoSize = true;
			this.label1.Location = new System.Drawing.Point(13, 13);
			this.label1.Name = "label1";
			this.label1.Size = new System.Drawing.Size(43, 13);
			this.label1.TabIndex = 1;
			this.label1.Text = "Ф.И.О.";
			// 
			// textBox_name
			// 
			this.textBox_name.Location = new System.Drawing.Point(13, 30);
			this.textBox_name.Name = "textBox_name";
			this.textBox_name.Size = new System.Drawing.Size(211, 20);
			this.textBox_name.TabIndex = 2;
			// 
			// label2
			// 
			this.label2.AutoSize = true;
			this.label2.Location = new System.Drawing.Point(13, 57);
			this.label2.Name = "label2";
			this.label2.Size = new System.Drawing.Size(95, 13);
			this.label2.TabIndex = 3;
			this.label2.Text = "Номер Телефона";
			// 
			// textBox_phone
			// 
			this.textBox_phone.Location = new System.Drawing.Point(13, 74);
			this.textBox_phone.Name = "textBox_phone";
			this.textBox_phone.Size = new System.Drawing.Size(211, 20);
			this.textBox_phone.TabIndex = 4;
			// 
			// button_cancel
			// 
			this.button_cancel.Location = new System.Drawing.Point(149, 100);
			this.button_cancel.Name = "button_cancel";
			this.button_cancel.Size = new System.Drawing.Size(75, 23);
			this.button_cancel.TabIndex = 5;
			this.button_cancel.Text = "Отмена";
			this.button_cancel.UseVisualStyleBackColor = true;
			this.button_cancel.Click += new System.EventHandler(this.Cancel);
			// 
			// AddItemForm
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(238, 136);
			this.Controls.Add(this.button_cancel);
			this.Controls.Add(this.textBox_phone);
			this.Controls.Add(this.label2);
			this.Controls.Add(this.textBox_name);
			this.Controls.Add(this.label1);
			this.Controls.Add(this.button_add);
			this.Name = "AddItemForm";
			this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
			this.Text = "Добавить";
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.Button button_add;
		private System.Windows.Forms.Label label1;
		private System.Windows.Forms.TextBox textBox_name;
		private System.Windows.Forms.Label label2;
		private System.Windows.Forms.TextBox textBox_phone;
		private System.Windows.Forms.Button button_cancel;
	}
}