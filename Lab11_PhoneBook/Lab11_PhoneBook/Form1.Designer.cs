namespace Lab11_PhoneBook {
	partial class Form1 {
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		private System.ComponentModel.IContainer components = null;

		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		/// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
		protected override void Dispose(bool disposing) {
			if (disposing && (components != null)) {
				components.Dispose();
			}
			base.Dispose(disposing);
		}

		#region Код, автоматически созданный конструктором форм Windows

		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		private void InitializeComponent() {
			this.listView = new System.Windows.Forms.ListView();
			this.button1 = new System.Windows.Forms.Button();
			this.button2 = new System.Windows.Forms.Button();
			this.button_add = new System.Windows.Forms.Button();
			this.groupBox_edit = new System.Windows.Forms.GroupBox();
			this.button_Clear = new System.Windows.Forms.Button();
			this.button_Load = new System.Windows.Forms.Button();
			this.button_Save = new System.Windows.Forms.Button();
			this.groupBox_search = new System.Windows.Forms.GroupBox();
			this.textBox_search_phone = new System.Windows.Forms.TextBox();
			this.label_search_phone = new System.Windows.Forms.Label();
			this.label_search_name = new System.Windows.Forms.Label();
			this.textBox_search_name = new System.Windows.Forms.TextBox();
			this.groupBox_edit.SuspendLayout();
			this.groupBox_search.SuspendLayout();
			this.SuspendLayout();
			// 
			// listView
			// 
			this.listView.Location = new System.Drawing.Point(13, 13);
			this.listView.MultiSelect = false;
			this.listView.Name = "listView";
			this.listView.Size = new System.Drawing.Size(477, 242);
			this.listView.TabIndex = 0;
			this.listView.UseCompatibleStateImageBehavior = false;
			// 
			// button1
			// 
			this.button1.Location = new System.Drawing.Point(6, 48);
			this.button1.Name = "button1";
			this.button1.Size = new System.Drawing.Size(96, 23);
			this.button1.TabIndex = 6;
			this.button1.Text = "Изменить ";
			this.button1.UseVisualStyleBackColor = true;
			this.button1.Click += new System.EventHandler(this.ChangeItem);
			// 
			// button2
			// 
			this.button2.Location = new System.Drawing.Point(6, 77);
			this.button2.Name = "button2";
			this.button2.Size = new System.Drawing.Size(96, 23);
			this.button2.TabIndex = 7;
			this.button2.Text = "Удалить";
			this.button2.UseVisualStyleBackColor = true;
			this.button2.Click += new System.EventHandler(this.DeleteItem);
			// 
			// button_add
			// 
			this.button_add.Location = new System.Drawing.Point(6, 19);
			this.button_add.Name = "button_add";
			this.button_add.Size = new System.Drawing.Size(96, 23);
			this.button_add.TabIndex = 8;
			this.button_add.Text = "Добавить";
			this.button_add.UseVisualStyleBackColor = true;
			this.button_add.Click += new System.EventHandler(this.AddItem);
			// 
			// groupBox_edit
			// 
			this.groupBox_edit.Controls.Add(this.button_Clear);
			this.groupBox_edit.Controls.Add(this.button_Load);
			this.groupBox_edit.Controls.Add(this.button_Save);
			this.groupBox_edit.Controls.Add(this.button_add);
			this.groupBox_edit.Controls.Add(this.button2);
			this.groupBox_edit.Controls.Add(this.button1);
			this.groupBox_edit.Location = new System.Drawing.Point(502, 13);
			this.groupBox_edit.Name = "groupBox_edit";
			this.groupBox_edit.Size = new System.Drawing.Size(211, 114);
			this.groupBox_edit.TabIndex = 9;
			this.groupBox_edit.TabStop = false;
			this.groupBox_edit.Text = "Редактировать";
			// 
			// button_Clear
			// 
			this.button_Clear.Location = new System.Drawing.Point(108, 77);
			this.button_Clear.Name = "button_Clear";
			this.button_Clear.Size = new System.Drawing.Size(96, 23);
			this.button_Clear.TabIndex = 11;
			this.button_Clear.Text = "Очистить";
			this.button_Clear.UseVisualStyleBackColor = true;
			this.button_Clear.Click += new System.EventHandler(this.ClearBase);
			// 
			// button_Load
			// 
			this.button_Load.Location = new System.Drawing.Point(108, 48);
			this.button_Load.Name = "button_Load";
			this.button_Load.Size = new System.Drawing.Size(96, 23);
			this.button_Load.TabIndex = 10;
			this.button_Load.Text = "Перезагрузка";
			this.button_Load.UseVisualStyleBackColor = true;
			this.button_Load.Click += new System.EventHandler(this.ReloadBase);
			// 
			// button_Save
			// 
			this.button_Save.Location = new System.Drawing.Point(109, 19);
			this.button_Save.Name = "button_Save";
			this.button_Save.Size = new System.Drawing.Size(96, 23);
			this.button_Save.TabIndex = 9;
			this.button_Save.Text = "Сохранить";
			this.button_Save.UseVisualStyleBackColor = true;
			this.button_Save.Click += new System.EventHandler(this.SaveBase);
			// 
			// groupBox_search
			// 
			this.groupBox_search.Controls.Add(this.textBox_search_phone);
			this.groupBox_search.Controls.Add(this.label_search_phone);
			this.groupBox_search.Controls.Add(this.label_search_name);
			this.groupBox_search.Controls.Add(this.textBox_search_name);
			this.groupBox_search.Location = new System.Drawing.Point(502, 135);
			this.groupBox_search.Name = "groupBox_search";
			this.groupBox_search.Size = new System.Drawing.Size(211, 120);
			this.groupBox_search.TabIndex = 10;
			this.groupBox_search.TabStop = false;
			this.groupBox_search.Text = "Поиск по...";
			// 
			// textBox_search_phone
			// 
			this.textBox_search_phone.Location = new System.Drawing.Point(6, 80);
			this.textBox_search_phone.Name = "textBox_search_phone";
			this.textBox_search_phone.Size = new System.Drawing.Size(198, 20);
			this.textBox_search_phone.TabIndex = 3;
			this.textBox_search_phone.TextChanged += new System.EventHandler(this.SearchPhone);
			// 
			// label_search_phone
			// 
			this.label_search_phone.AutoSize = true;
			this.label_search_phone.Location = new System.Drawing.Point(6, 63);
			this.label_search_phone.Name = "label_search_phone";
			this.label_search_phone.Size = new System.Drawing.Size(98, 13);
			this.label_search_phone.TabIndex = 2;
			this.label_search_phone.Text = "Номеру телефона";
			// 
			// label_search_name
			// 
			this.label_search_name.AutoSize = true;
			this.label_search_name.Location = new System.Drawing.Point(6, 20);
			this.label_search_name.Name = "label_search_name";
			this.label_search_name.Size = new System.Drawing.Size(43, 13);
			this.label_search_name.TabIndex = 1;
			this.label_search_name.Text = "Ф.И.О.";
			// 
			// textBox_search_name
			// 
			this.textBox_search_name.Location = new System.Drawing.Point(6, 36);
			this.textBox_search_name.Name = "textBox_search_name";
			this.textBox_search_name.Size = new System.Drawing.Size(198, 20);
			this.textBox_search_name.TabIndex = 0;
			this.textBox_search_name.TextChanged += new System.EventHandler(this.SearchName);
			// 
			// Form1
			// 
			this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
			this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
			this.ClientSize = new System.Drawing.Size(727, 268);
			this.Controls.Add(this.groupBox_search);
			this.Controls.Add(this.groupBox_edit);
			this.Controls.Add(this.listView);
			this.Name = "Form1";
			this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
			this.Text = "Личный телефонный справочник";
			this.groupBox_edit.ResumeLayout(false);
			this.groupBox_search.ResumeLayout(false);
			this.groupBox_search.PerformLayout();
			this.ResumeLayout(false);

		}

		#endregion

		private System.Windows.Forms.ListView listView;
		private System.Windows.Forms.Button button1;
		private System.Windows.Forms.Button button2;
		private System.Windows.Forms.Button button_add;
		private System.Windows.Forms.GroupBox groupBox_edit;
		private System.Windows.Forms.GroupBox groupBox_search;
		private System.Windows.Forms.TextBox textBox_search_phone;
		private System.Windows.Forms.Label label_search_phone;
		private System.Windows.Forms.Label label_search_name;
		private System.Windows.Forms.TextBox textBox_search_name;
		private System.Windows.Forms.Button button_Clear;
		private System.Windows.Forms.Button button_Load;
		private System.Windows.Forms.Button button_Save;
	}
}

