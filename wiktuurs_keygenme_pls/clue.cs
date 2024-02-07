
base.Name "Form1"


private void InitializeComponent()
{
	this.SubBut = new Button();
	this.nameBox = new TextBox();
	this.keyBox1 = new TextBox();
	this.keyBox2 = new TextBox();
	this.keyBox3 = new TextBox();
	this.label1 = new Label();
	this.label2 = new Label();
	this.label3 = new Label();
	this.label4 = new Label();
	this.crBox = new CheckBox();
	base.SuspendLayout();
	this.SubBut.Location = new Point(16, 134);
	this.SubBut.Name = "SubBut";
	this.SubBut.Size = new Size(363, 51);
	this.SubBut.TabIndex = 0;
	this.SubBut.Text = "Submit";
	this.SubBut.UseVisualStyleBackColor = true;
	this.SubBut.Click += this.SubBut_Click;
	this.nameBox.Location = new Point(74, 34);
	this.nameBox.Name = "nameBox";
	this.nameBox.Size = new Size(100, 20);
	this.nameBox.TabIndex = 2;
	this.keyBox1.Location = new Point(44, 85);
	this.keyBox1.Name = "keyBox1";
	this.keyBox1.Size = new Size(100, 20);
	this.keyBox1.TabIndex = 3;
	this.keyBox2.Location = new Point(160, 85);
	this.keyBox2.Name = "keyBox2";
	this.keyBox2.Size = new Size(100, 20);
	this.keyBox2.TabIndex = 4;
	this.keyBox3.Location = new Point(282, 85);
	this.keyBox3.Name = "keyBox3";
	this.keyBox3.Size = new Size(100, 20);
	this.keyBox3.TabIndex = 5;
	this.label1.AutoSize = true;
	this.label1.Location = new Point(13, 37);
	this.label1.Name = "label1";
	this.label1.Size = new Size(55, 13);
	this.label1.TabIndex = 6;
	this.label1.Text = "Username";
	this.label2.AutoSize = true;
	this.label2.Location = new Point(13, 88);
	this.label2.Name = "label2";
	this.label2.Size = new Size(25, 13);
	this.label2.TabIndex = 7;
	this.label2.Text = "Key";
	this.label3.AutoSize = true;
	this.label3.Location = new Point(144, 88);
	this.label3.Name = "label3";
	this.label3.Size = new Size(10, 13);
	this.label3.TabIndex = 8;
	this.label3.Text = "-";
	this.label4.AutoSize = true;
	this.label4.Location = new Point(266, 88);
	this.label4.Name = "label4";
	this.label4.Size = new Size(10, 13);
	this.label4.TabIndex = 9;
	this.label4.Text = "-";
	this.crBox.AutoSize = true;
	this.crBox.Enabled = false;
	this.crBox.Location = new Point(16, 111);
	this.crBox.Name = "crBox";
	this.crBox.Size = new Size(115, 17);
	this.crBox.TabIndex = 10;
	this.crBox.Text = "Is the key Correct?";
	this.crBox.UseVisualStyleBackColor = true;
	base.AutoScaleDimensions = new SizeF(6f, 13f);
	base.AutoScaleMode = AutoScaleMode.Font;
	base.ClientSize = new Size(391, 195);
	base.Controls.Add(this.crBox);
	base.Controls.Add(this.label4);
	base.Controls.Add(this.label3);
	base.Controls.Add(this.label2);
	base.Controls.Add(this.label1);
	base.Controls.Add(this.keyBox3);
	base.Controls.Add(this.keyBox2);
	base.Controls.Add(this.keyBox1);
	base.Controls.Add(this.nameBox);
	base.Controls.Add(this.SubBut);
	base.Name = "Form1";
	this.Text = "Form1";
	base.ResumeLayout(false);
	base.PerformLayout();
}


// Token: 0x06000006 RID: 6 RVA: 0x000020F4 File Offset: 0x000002F4
private string Key1(string name)
{
	return this.nameParser(base.Name)[this.namelength(base.Name) - 1].ToString() + 118.ToString() + this.nameParser(base.Name)[this.namelength(base.Name) - 3].ToString() + 4.ToString();
}

// Token: 0x06000007 RID: 7 RVA: 0x00002168 File Offset: 0x00000368
private string Key2(string name)
{
	return 132.ToString() + this.nameParser(base.Name)[3].ToString() + 5.ToString() + this.nameParser(base.Name)[3].ToString();
}

// Token: 0x06000008 RID: 8 RVA: 0x000021C4 File Offset: 0x000003C4
private string Key3(string name)
{
	return 122.ToString() + 54.ToString() + this.nameParser(base.Name)[2].ToString();
}

// Token: 0x06000009 RID: 9 RVA: 0x00002208 File Offset: 0x00000408
private bool Check(string s1, string s2, string s3, string name)
{
	return s1 == this.Key3(name) & s3 == this.Key2(name) & s2 == this.Key1(name);
}

private void SubBut_Click(object sender, EventArgs e)
{
	this.crBox.Checked = this.Check(this.keyBox1.Text, this.keyBox2.Text, this.keyBox3.Text, this.getName());
}