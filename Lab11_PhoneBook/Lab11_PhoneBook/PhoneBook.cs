using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;
using System.Windows.Forms;

namespace Lab11_PhoneBook {
	public class PhoneBook {
		public SortedDictionary<String, List<String>> dict;
		public PhoneBook() {
			dict = new SortedDictionary<String, List<String>>();
			if (File.Exists("E:\\Lab11_PhoneBook\\Lab11_PhoneBook\\phonebook.txt")) {
				try {
					using (StreamReader sr = new StreamReader("phonebook.txt", Encoding.Default)) {
						String line;
						while ((line = sr.ReadLine()) != null) {
							List<String> listOfNewStrings;
							listOfNewStrings = line.Split(new String[] { ";" }, StringSplitOptions.RemoveEmptyEntries).ToList();
							dict.Add(listOfNewStrings.ElementAt(0), listOfNewStrings.Skip(1).ToList());
						}
					}
				} catch (Exception ex) {
					Debug.WriteLine("Error while reading file: " + ex.ToString());
				}
			} else {
				File.Open("E:\\Lab11_PhoneBook\\Lab11_PhoneBook\\phonebook.txt", FileMode.Create);
			}
		}
		public bool Add(String name, String phone) {
			Regex nameRegex = new Regex("[А-Я][а-я]+(-[А-Я][а-я]+)? [А-Я][а-я]+(-[А-Я][а-я]+)? [А-Я][а-я]+(-[А-Я][а-я]+)?");
			Regex phoneRegex = new Regex("\\+?\\d{1,2}-\\d{3}-\\d{3}-\\d{2}-\\d{2}");
			if (!(nameRegex.IsMatch(name) && phoneRegex.IsMatch(phone))) {
				MessageBox.Show("Невереный формат имени или телефона! Правильный формат: " + Environment.NewLine + "Имя: \"Фамилия Имя Отчество\"" + Environment.NewLine + "Номер телефона: \"+X-XXX-XXX-XX-XX\" (+ не обязателен)", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
				return false;
			}
			foreach (KeyValuePair<String, List<String>> kvp in dict) {
				if (kvp.Value.Contains(phone)) {
					DialogResult answer = MessageBox.Show("Данный номер телефона уже записан у абонента с ФИО: " + Environment.NewLine + kvp.Key + Environment.NewLine + "Хотите продолжить?", "Предупреждение", MessageBoxButtons.YesNo, MessageBoxIcon.Warning);
					if (answer == DialogResult.Yes)
						break;
					else
						return false;
				}
			}
			if (dict.ContainsKey(name)) {
				if (dict[name].Contains(phone)) {
					MessageBox.Show("Данная пара абонент-номер уже существует в базе!", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
					return false;
				} else
					dict[name].Add(phone);
			} else
				dict.Add(name, new List<string>() { phone });
			return true;
		}
		public bool Replace(String name, String oldPhone, String newPhone) {
			if (!dict[name].Contains(oldPhone)) {
				MessageBox.Show("Абонент с таким номер телефона не существует!", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
				return false;
			}
			dict[name][dict[name].FindIndex(x => x == oldPhone)] = newPhone;
			return true;
		}
		public bool DelPhone(String name, String phone, bool debugInf) {
			if (!dict[name].Contains(phone)) {
				if (debugInf)
					MessageBox.Show("Абонент с таким номер телефона не существует!", "Ошибка", MessageBoxButtons.OK, MessageBoxIcon.Error);
				return false;
			}
			dict[name].Remove(phone);
			if (dict[name].Count == 0) {
				if (debugInf)
					MessageBox.Show("У абонента больше нет номера телефона, поэтому он будет удалён.", "Предупреждение", MessageBoxButtons.OK, MessageBoxIcon.Warning);
				dict.Remove(name);
			}
			return true;
		}
		public void Save() {
			try {
				using (FileStream fs = new FileStream("phonebook.txt", FileMode.Create)) {
					StreamWriter sw = new StreamWriter(fs);
					StringBuilder output = new StringBuilder();
					foreach (KeyValuePair<String, List<String>> kvp in dict) {
						output.Append(kvp.Key + ";");
						foreach (string str in kvp.Value)
							output.Append(str + ";");
						sw.Write(output + Environment.NewLine);
					}
				}
			} catch (Exception ex) {
				Debug.WriteLine("Can't open open file: " + ex.ToString());
			}
		}
		public void Load() {
			if (File.Exists("phonebook.txt")) {
				try {
					using (StreamReader sr = new StreamReader("phonebook.txt", Encoding.Default)) {
						String line;
						while ((line = sr.ReadLine()) != null) {
							List<String> listOfNewStrings;
							listOfNewStrings = line.Split(new String[] { ";" }, StringSplitOptions.RemoveEmptyEntries).ToList();
							dict.Add(listOfNewStrings.ElementAt(0), listOfNewStrings.Skip(1).ToList());

						}
					}
				} catch (Exception ex) {
					Debug.WriteLine("Error while reading file: " + ex.ToString());
				}
			} else {
				File.Open("phonebook.txt", FileMode.Create);
			}
		}
		public void Clear() {
			dict.Clear();
		}
	}
}
