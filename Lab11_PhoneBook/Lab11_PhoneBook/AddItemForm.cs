using System.Windows.Forms;

namespace Lab11_PhoneBook {
	public partial class AddItemForm : Form {
		public AddItemForm() {
			InitializeComponent();
		}

		private void Cancel(object sender, System.EventArgs e) {
			Close();
		}

		private void AddItem(object sender, System.EventArgs e) {
			string name = textBox_name.Text;
			string phone = textBox_phone.Text;
			if (Form1.Pb.Add(name, phone))
				Close();
		}
	}
}
