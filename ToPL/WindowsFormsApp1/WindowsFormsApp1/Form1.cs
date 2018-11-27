using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;


public struct Cep
{
    public string A;
    public int B;
    public int C;
};

public struct Pravila
{
    public string A;
    public List<string> B;
    public int C;
    public int D;
};



namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            ;
        }
        public static string Replaceonce(string A, string B, string C)
        {
            return A.Substring(0, A.IndexOf(B)) + C + A.Substring(A.IndexOf(B) + B.Length);
        }
        public static bool Checking(string A, char[] NT, int amount)
        {
            for(int i = 0; i < amount; ++i)
            {
                if (A.IndexOf(NT[i]) > -1)
                    return true;
            }
            return false;
        }
        private void button1_Click(object sender, EventArgs e)
        {
            int nA = 0, nB = 0;
            string Target = this.textBox7.Text;
            nA = Convert.ToInt32(this.textBox5.Text);
            nB = Convert.ToInt32(this.textBox6.Text);
            string VT = this.textBox1.Text;
            string NT = this.textBox2.Text;
            string P = this.textBox3.Text;
            Exception E = new Exception();
            if(NT.IndexOf(Target) == -1)
            {
                Target = "S";
            }
            string S = "S";
            int PN = 6;
            char[] vt, nt;
            vt = new char[VT.Length];
            nt = new char[NT.Length];
            int Cnt = NT.Length;
            for(int i = 0; i < VT.Length; i++)
            {
                vt[i] = VT[i];
            }
            for (int i = 0; i < NT.Length; i++)
            {
                nt[i] = NT[i];
            }
            int t = 0, lMax = 0;
            List<Pravila> Rules = new List<Pravila>();
            P = P.Replace("\n", "");
            P = P.Replace("\r", "");
            P = P.Replace(" ", "");
            List<string> Answers = new List<string>();
            while(P.Length > 0)
            {
                t = 0;
                Pravila temp = new Pravila();
                int pos = P.IndexOf('=');
                temp.A = P.Substring(0, pos);
                P = P.Substring(pos+1);
                int tpos = P.IndexOf(';');
                temp.B = new List<string>();
                while (P[0] != ';')
                {
                    if (P.IndexOf('|') > tpos || P.IndexOf('|') == -1)
                    {
                        temp.B.Add(P.Substring(0, P.IndexOf(';')));
                        P = P.Substring(P.IndexOf(';') + 1);
                        break;
                    }
                    else
                    {
                        temp.B.Add(P.Substring(0, P.IndexOf('|')));
                        t = P.IndexOf('|') + 1;
                        P = P.Substring(P.IndexOf('|') + 1);
                    }
                    tpos -= t;
                }
                for(int i = 0; i < temp.B.Count(); ++i)
                {
                    temp.B[i] = temp.B[i].Replace("`", "");
                }
                Rules.Add(temp);
            }
            List<Cep> ceps = new List<Cep>();
            
            Cep slovo = new Cep() { A = Target, B = 0 };
            ceps.Add(slovo);
            int index = 0;
            while (ceps.Count() > 0)
            {
                for(int i = 0; i < Rules.Count(); i++)
                {
                    for (int j = 0; j < Rules[i].B.Count(); j++)
                    {
                        if (Rules[i].B[j].Length >= lMax)
                            lMax = Rules[i].B[j].Length;
                        if (ceps[index].A.Contains(Rules[i].A))
                        {
                            string subs = ceps[index].A;
                            subs = Replaceonce(subs, Rules[i].A, Rules[i].B[j]);
                            Cep temp = new Cep() { A = subs, B = 0, C = 0 };
                            if (Checking(temp.A, nt, Cnt))
                            {
                                if (temp.A.Length <= (PN + lMax))
                                {
                                    ceps.Add(temp);
                                }
                            }
                            else
                            {
                                if (temp.A.Length <= nB && temp.A.Length >= nA)
                                    Answers.Add(temp.A);
                            }
                        }
                    }
                }
                ceps.Remove(ceps[0]);
            }
            for (int i = 0; i < Answers.Count(); ++i)
                textBox4.Lines = Answers.ToArray();
            
        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void textBox5_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
