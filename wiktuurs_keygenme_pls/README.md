# wiktuurs_keygenme_pls

This one is an easy C# start

- open it with [dnSpy 32-bit][0] and debug it
- the `base.Name` is `"Form1"`
  - keyboxes names and sequences are determined in `InitializeComponent()`
    - `this.keyBox1.Location = new Point(44, 85);`
    - `this.keyBox2.Location = new Point(160, 85);`
    - `this.keyBox3.Location = new Point(282, 85);`
  - the 1st keybox needs to be `key3`, which is `"122"` + `"54"` + `"Form1"[2]` = `"12254r"`
  - the 2nd keybox needs to be `key1`, which is `"Form1"[strlen("Form1") - 1]` + `"118"` + `"Form1"[strlen("Form1") - 3]` + `"4"` = `"1118r4"`
  - the 3rd keybox needs to be `key2`, which is `"132"` + `"Form1"[3]` + `"5"` + `"Form1"[3]` = `"132m5m"`
- the `username` is totally ignored

[0]: <https://github.com/dnSpy/dnSpy/releases>