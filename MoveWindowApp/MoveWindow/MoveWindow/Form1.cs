using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Runtime.InteropServices;

namespace MoveWindow
{
    public partial class Form1 : Form
    {
        [DllImport("user32.dll", EntryPoint = "FindWindow")]
        private static extern IntPtr FindWindowEx(IntPtr hwndParent, IntPtr hwndChildAfter, string lpszClass, string lpszWindow);
        [DllImport("user32.dll")]
        private static extern int GetWindowText(int hWnd, StringBuilder title, int size);
        [DllImport("user32.dll")]
        private static extern bool IsWindowVisible(int hWnd);
        [DllImport("user32.dll")]
        private static extern int GetWindowTextLength(int hWnd);
        [DllImport("USER32.DLL")]
        private static extern IntPtr FindWindow(string lpClassName, string lpWindowName);
        [DllImport("USER32.DLL")]
        private static extern bool ShowWindow(IntPtr hWnd, uint nCmdShow);
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            IntPtr Hwnd = FindWindowEx(IntPtr.Zero, IntPtr.Zero, null, "DGN-AM测试");   //获得按钮的句柄   
            System.Console.WriteLine(Hwnd.ToInt32());
        }
    }
}
