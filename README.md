# Fractol

The term fractal was first used by mathematician Benoit Mandelbrot in 1974, he based it on the Latin word fractus, meaning "broken" or "fractured".
A fractal is an abstract mathematical object, like a curve or a surface, which has a similar pattern whatever the scale.

Program is able to produce:
- [Mandelbrot set](https://en.wikipedia.org/wiki/Mandelbrot_set)
- [Julia set](https://en.wikipedia.org/wiki/Julia_set)
- [Burning Ship](https://en.wikipedia.org/wiki/Burning_Ship_fractal)

![julia](https://github.com/vrudyka/school-42/blob/main/fractol/screenshots/fractal3.png) | ![julia](https://github.com/vrudyka/school-42/blob/main/fractol/screenshots/fractal0.png)
:-------------------------:|:-------------------------:
![burning](https://github.com/vrudyka/school-42/blob/main/fractol/screenshots/fractal4.png) | ![burning](https://github.com/vrudyka/school-42/blob/main/fractol/screenshots/fractal2.png)


# FdF

This project is about creating a simplified graphic “wireframe” (“fils de fer” in french,
hence the name of the project) representation of a relief landscape linking various points
(x, y, z) via segments. The coordinates of this landscape are stored in a file passed as
a parameter to the program.

Each number corresponds to a point in space:
- The horizontal position corresponds to its axis
- The vertical position corresponds to its ordinate
- The value corresponds to its altitude

| Isometric projection | Paralel projection in motion |
:-----------------------:|:-------------------------:
![iso](https://github.com/vrudyka/school-42/blob/main/fdf/img/elem.png) | ![paralel](https://github.com/vrudyka/school-42/blob/main/fdf/img/anim.gif)

# RTv1

RTv1 is a simple ray tracing program.

![gnomes](https://github.com/vrudyka/school-42/blob/main/RTv1/img/gnomes.png) 

# fillit

A group project with Serhii Yolankyi.
Program that assembles given Tetrimino set altogether in the smallest possible square. Using <b>Knuth's Algorithm X<b/>.

```bash
...#  ....  .###  ....
...#  ....  ...#  ..##
...#  ....  ....  .##.
...#  ####  ....  ....

....  ....  ##..  ....
.##.  ....  .#..  ###.
.##.  ##..  .#..  .#..
....  .##.  ....  ....
```

![speed](https://github.com/vrudyka/school-42/blob/main/fillit/screenshot.png)


# abstract-vm
  
AbstractVM is a machine that uses a stack to compute simple arithmetic expressions.
These arithmetic expressions are provided to the machine as basic assembly programs.

It can run programs from a file passed as a parameter and from the standard input.

```bash
$>cat test1.avm
push int32(42)
push int32(33)
add ;poney
push float(44.55)
mul
push double(42.42)
;commentaire de ouf
push int32(42)
dump
pop
assert double(42.42)

$>./avm test1.avm 
42
42.42
3341.25
```
