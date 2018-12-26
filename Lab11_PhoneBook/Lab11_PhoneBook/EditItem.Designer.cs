namespace Lab11_PhoneBook {
	partial class EditItem {
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
			this.button_change = new System.Windows.Forms.Button();
			this.label1 = new System.Windows.Forms.Label();
			this.textBox_name = new System.Windows.Forms.TextBox();
			this.label2 = new System.Windows.Forms.Label();
			this.textBox_phone = new System.Windows.Forms.TextBox();
			this.button_cancel = new System.Windows.Forms.Button();
			this.SuspendLayout();
			// 
			// button_change
			// 
			this.button_change.Location = new System.Drawing.Point(13, 100);
			this.button_change.Name = "button_change";
			this.button_change.Size = new System.Drawing.Size(75, 23);
			this.button_change.TabIndex = 0;
			this.button_change.Text = "Изменить";
			this.button_change.UseVisualStyleBackColor = true;
			this.button_change.Click += new System.EventHandler(this.ChangeItem);
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
			// EditItem
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(238, 136);
			this.Controls.Add(this.button_cancel);
			this.Controls.Add(this.textBox_phone);
			this.Controls.Add(this.label2);
			this.Controls.Add(this.textBox_name);
			this.Controls.Add(this.label1);
			this.Controls.Add(this.button_change);
			this.Name = "EditItem";
			this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
			this.Text = "Изменить";
			this.ResumeLayout(false);
			this.PerformLayout();

		}

		#endregion

		private System.Windows.Forms.Button button_change;
		private System.Windows.Forms.Label label1;
		private System.Windows.Forms.TextBox textBox_name;
		private System.Windows.Forms.Label label2;
		private System.Windows.Forms.TextBox textBox_phone;
		private System.Windows.Forms.Button button_cancel;
	}
}