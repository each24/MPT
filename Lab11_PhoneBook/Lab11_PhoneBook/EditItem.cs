using System.Windows.Forms;

namespace Lab11_PhoneBook {
	public partial class EditItem : Form {
		string name;
		string phone;
		public EditItem() {
			InitializeComponent();
		}
		public EditItem(string nameToEdit, string phoneToEdit) {
			name = nameToEdit;
			phone = phoneToEdit;
			InitializeComponent();
			textBox_name.Text += name;
			textBox_phone.Text += phone;
		}

		private void Cancel(object sender, System.EventArgs e) {
			Close();
		}

		private void ChangeItem(object sender, System.EventArgs e) {
			string newName = textBox_name.Text;
			string newPhone = textBox_phone.Text;
			if (name == newName) {
				if (Form1.Pb.Replace(name, phone, newPhone))
					Close();
			} else
			if (Form1.Pb.Add(newName, newPhone)) {
				Form1.Pb.DelPhone(name, phone, false);
				Close();
			}
		}
	}
}
