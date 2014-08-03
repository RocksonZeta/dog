namespace face
{
    partial class fm_dog
    {
        /// <summary>
        /// 必需的设计器变量。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 清理所有正在使用的资源。
        /// </summary>
        /// <param name="disposing">如果应释放托管资源，为 true；否则为 false。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows 窗体设计器生成的代码

        /// <summary>
        /// 设计器支持所需的方法 - 不要
        /// 使用代码编辑器修改此方法的内容。
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(fm_dog));
            this.setup = new System.Windows.Forms.Button();
            this.tb_console = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.btn_tearup = new System.Windows.Forms.Button();
            this.tray = new System.Windows.Forms.NotifyIcon(this.components);
            this.tb_messages = new System.Windows.Forms.DataGridView();
            this.btn_load = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.tb_messages)).BeginInit();
            this.SuspendLayout();
            // 
            // setup
            // 
            this.setup.Location = new System.Drawing.Point(29, 12);
            this.setup.Name = "setup";
            this.setup.Size = new System.Drawing.Size(75, 23);
            this.setup.TabIndex = 0;
            this.setup.Text = "setup";
            this.setup.UseVisualStyleBackColor = true;
            this.setup.Click += new System.EventHandler(this.setup_Click);
            // 
            // tb_console
            // 
            this.tb_console.Location = new System.Drawing.Point(29, 76);
            this.tb_console.Multiline = true;
            this.tb_console.Name = "tb_console";
            this.tb_console.Size = new System.Drawing.Size(583, 90);
            this.tb_console.TabIndex = 1;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(27, 49);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(53, 12);
            this.label1.TabIndex = 2;
            this.label1.Text = "console:";
            // 
            // btn_tearup
            // 
            this.btn_tearup.Location = new System.Drawing.Point(537, 12);
            this.btn_tearup.Name = "btn_tearup";
            this.btn_tearup.Size = new System.Drawing.Size(75, 23);
            this.btn_tearup.TabIndex = 3;
            this.btn_tearup.Text = "tearup";
            this.btn_tearup.UseVisualStyleBackColor = true;
            this.btn_tearup.Click += new System.EventHandler(this.btn_tearup_Click);
            // 
            // tray
            // 
            this.tray.BalloonTipIcon = System.Windows.Forms.ToolTipIcon.Info;
            this.tray.Icon = ((System.Drawing.Icon)(resources.GetObject("tray.Icon")));
            this.tray.Text = "tray";
            this.tray.Visible = true;
            this.tray.Click += new System.EventHandler(this.tray_Click);
            // 
            // tb_messages
            // 
            this.tb_messages.AllowUserToOrderColumns = true;
            this.tb_messages.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.tb_messages.Location = new System.Drawing.Point(29, 205);
            this.tb_messages.Name = "tb_messages";
            this.tb_messages.RowTemplate.Height = 23;
            this.tb_messages.Size = new System.Drawing.Size(583, 242);
            this.tb_messages.TabIndex = 4;
            // 
            // btn_load
            // 
            this.btn_load.Location = new System.Drawing.Point(527, 173);
            this.btn_load.Name = "btn_load";
            this.btn_load.Size = new System.Drawing.Size(75, 23);
            this.btn_load.TabIndex = 5;
            this.btn_load.Text = "load";
            this.btn_load.UseVisualStyleBackColor = true;
            this.btn_load.Click += new System.EventHandler(this.btn_load_Click);
            // 
            // fm_dog
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(642, 459);
            this.Controls.Add(this.btn_load);
            this.Controls.Add(this.tb_messages);
            this.Controls.Add(this.btn_tearup);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.tb_console);
            this.Controls.Add(this.setup);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "fm_dog";
            this.Text = "Dog";
            this.SizeChanged += new System.EventHandler(this.fm_dog_SizeChanged);
            ((System.ComponentModel.ISupportInitialize)(this.tb_messages)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button setup;
        private System.Windows.Forms.TextBox tb_console;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Button btn_tearup;
        private System.Windows.Forms.NotifyIcon tray;
        private System.Windows.Forms.DataGridView tb_messages;
        private System.Windows.Forms.Button btn_load;
    }
}

