import mathmodule

sq = mathmodule.square(8)
print(sq)

pow_fun = mathmodule.poww
p = pow(2,10)
print(p)

print("Mathmodule name:", mathmodule.__name__)
print("This module name:",__name__)

print("names defined in mathmodule:")
print(dir(mathmodule))
