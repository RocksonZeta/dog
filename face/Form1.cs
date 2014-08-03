using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace face
{
    public partial class fm_dog : Form
    {
        public fm_dog()
        {
            InitializeComponent();
            addTrayItem();
        }


        void addTrayItem()
        {
            MenuItem exitItem= new MenuItem();
            exitItem.Text = "退出";
            exitItem.Click += new System.EventHandler(this.on_tray_close);
            MenuItem openItem = new MenuItem();
            openItem.Text = "打开主面板";
            openItem.Click += new System.EventHandler(this.on_tray_open);

            MenuItem[] items = new MenuItem[2];
            items[1] = exitItem;
            items[0] = openItem;
            ContextMenu notifyiconMnu = new ContextMenu(items);
            tray.ContextMenu = notifyiconMnu;
        }
        private void on_tray_close(object sender, System.EventArgs e)
        {
            tray.Visible = false;
            this.Close();
        }

        private void on_tray_open(object sender, System.EventArgs e)
        {
            show_window();
        }

        void log(String s)
        {
            tb_console.Text +=  s + Environment.NewLine;
        }


        private void setup_Click(object sender, EventArgs e)
        {
            int r = Setup.watch32();
            int os_bit = Setup.get_system_bits();
            if (64 == os_bit)
            {
                log("system is 64 bit system");
            }
            log("hahaah");

            tb_console.Text += "os "+os_bit+" ,setup " + r + Environment.NewLine;
        }

        private void btn_tearup_Click(object sender, EventArgs e)
        {
            int r = Setup.unwatch32();
            int os_bit = Setup.get_system_bits();
            if (64 == os_bit)
            {
                
            }
            tb_console.Text += "tearup " + r + Environment.NewLine;
        }




        private void fm_dog_SizeChanged(object sender, EventArgs e)
        {
            if (this.WindowState == FormWindowState.Minimized)
            {
                this.Hide();
                this.tray.Visible = true;
            }
        }

        private void tray_Click(object sender, EventArgs e)
        {
            if (this.WindowState == FormWindowState.Minimized || false == this.TopMost)
            {
                show_window();
            }
        }

        void show_window()
        {
            this.TopMost = true;
            this.ShowInTaskbar = true;
            this.Visible = true;
            this.WindowState = FormWindowState.Normal;
            this.TopMost = false;
        }

        private void btn_load_MouseClick(object sender, MouseEventArgs e)
        {
            
        }

        private void btn_load_Click(object sender, EventArgs e)
        {
            Messages.instance.LoadData(tb_messages);
        }


    }
}
