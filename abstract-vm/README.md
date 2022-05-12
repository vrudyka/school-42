# abstract-vm
AbstractVM is a machine that uses a stack to compute simple arithmetic expressions.
These arithmetic expressions are provided to the machine as basic assembly programs.

It can run programs from a file passed as a parameter and from the standard input.

Example:
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
The assembly language of AbstractVM is generated from the following grammar:
```
S := INSTR [SEP INSTR]* #

INSTR :=
  push VALUE
| pop
| dump
| assert VALUE
| add
| sub
| mul
| div
| mod
| print
| exit

VALUE :=
  int8(N)
| int16(N)
| int32(N)
| float(Z)
| double(Z)

N := [-]?[0..9]+

Z := [-]?[0..9]+.[0..9]+

SEP := '\n'+
```
