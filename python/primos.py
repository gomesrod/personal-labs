"""
This module tests some prime numbers
"""

for n in range(2, 20):
    for i in range(2, n):
        if (n % i) == 0:
            print(n, "divisivel por", i)
            break
    else:
        # entra no else quando todos os elementos do for
        # esgotaram sem passar no break
        print(n, "eh PRIMO")



