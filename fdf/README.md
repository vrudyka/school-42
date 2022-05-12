# FdF

This project is about creating a simplified graphic “wireframe” (“fils de fer” in french,
hence the name of the project) representation of a relief landscape linking various points
(x, y, z) via segments. The coordinates of this landscape are stored in a file passed as
a parameter to the program.

Each number corresponds to a point in space:
- The horizontal position corresponds to its axis.
- The vertical position corresponds to its ordinate.
- The value corresponds to its altitude.

<b>How to launch:</b>
```bash
git clone https://github.com/vrudyka/fdf.git
cd fdf
make
./fdf ./test_maps/42.fdf
```

<table width="100%">
<thead>
<tr>
<td width="65%" height="60px" align="center" cellpadding="0">
<strong>Action</strong>
</td>
<td width="10%" align="center" cellpadding="0">
<span style="width:70px">&nbsp;</span><strong>Key(s)</strong><span style="width:50px">&nbsp;</span>
</td>
</tr>
</thead>
<tbody>
<tr>
<td valign="top" height="30px">Rotate Y-Axis</td>
<td valign="top" align="center"><kbd>NUM6</kbd><kbd>NUM4</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Rotate X-Axis</td>
<td valign="top" align="center"><kbd>NUM8</kbd><kbd>NUM2</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Rotate Z-Axis</td>
<td valign="top" align="center"><kbd>NUM9</kbd><kbd>NUM7</kbd></td></td>
</tr>
<tr>
<td valign="top" height="30px">Set to Isometric Projection</td>
<td valign="top" align="center"><kbd>I</kbd></td></td>
</tr>
</tbody>
</table>

<p align="center">
  <b>Isometric projection</b>
</p>

![iso](https://github.com/vrudyka/fdf/blob/master/img/elem.png)

<p align="center">
  <b>Paralel projection in motion</b>
</p>

![paralel](https://github.com/vrudyka/fdf/blob/master/img/anim.gif)
