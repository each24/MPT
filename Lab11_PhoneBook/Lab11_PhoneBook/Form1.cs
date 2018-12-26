using System;
using System.Collections.Generic;
using System.Windows.Forms;
namespace Lab11_PhoneBook {
	public partial class Form1 : Form {
		public static PhoneBook Pb { set; get; }
		public Form1() {
			InitializeComponent();
			Pb = new PhoneBook();
			listView.View = View.Details;
			listView.Columns.Add("Ф.И.О.");
			listView.Columns[0].Width = -2;
			listView.Columns.Add("Номер Телефона");
			listView.Columns[1].Width = -2;
			FillListView();
		}

		private void FillListView() {
			foreach (KeyValuePair<String, List<String>> kvp in Pb.dict)
				foreach (string phonenumber in kvp.Value)
					listView.Items.Add(new ListViewItem(new String[] { kvp.Key, phonenumber }));
		}

		private void SaveBase(object sender, EventArgs e) {
			Pb.Save();
		}

		private void ReloadBase(object sender, EventArgs e) {
			ClearAll();
			Pb.Load();
			FillListView();
			listView.Columns[0].Width = -1;
			listView.Columns[1].Width = -2;
		}

		private void ClearBase(object sender, EventArgs e) {
			ClearAll();
		}

		private void ClearAll() {
			Pb.Clear();
			listView.Items.Clear();
		}

		private void DeleteItem(object sender, EventArgs e) {
			if (listView.SelectedItems.Count == 1) {
				ListViewItem item = listView.SelectedItems[0];
				if (Pb.DelPhone(item.SubItems[0].Text, item.SubItems[1].Text, true))
					listView.Items.Remove(item);
			} else
				MessageBox.Show("Выберите элемент для удаления!", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
		}

		private void ChangeItem(object sender, EventArgs e) {
			if (listView.SelectedItems.Count == 1) {
				ListViewItem item = listView.SelectedItems[0];
				EditItem newForm = new EditItem(item.SubItems[0].Text, item.SubItems[1].Text);
				Hide();
				newForm.ShowDialog();
				Show();
				listView.Items.Clear();
				FillListView();
			} else
				MessageBox.Show("Выберите элемент для изменения!", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
		}

		private void AddItem(object sender, EventArgs e) {
			AddItemForm newForm = new AddItemForm();
			Hide();
			newForm.ShowDialog();
			Show();
			listView.Items.Clear();
			FillListView();
		}

		private void SearchName(object sender, EventArgs e) {
			listView.Items.Clear();
			if (textBox_search_name.Text == "") {
				FillListView();
				return;
			}
			foreach (KeyValuePair<String, List<String>> kvp in Pb.dict)
				if (kvp.Key.StartsWith(textBox_search_name.Text))
					foreach (string phonenumber in kvp.Value)
						listView.Items.Add(new ListViewItem(new String[] { kvp.Key, phonenumber }));
		}

		private void SearchPhone(object sender, EventArgs e) {
			listView.Items.Clear();
			if (textBox_search_phone.Text == "") {
				FillListView();
				return;
			}
			foreach (KeyValuePair<String, List<String>> kvp in Pb.dict)
				foreach (string phonenumber in kvp.Value)
					if (phonenumber.StartsWith(textBox_search_phone.Text))
						listView.Items.Add(new ListViewItem(new String[] { kvp.Key, phonenumber }));
		}
	}
}
