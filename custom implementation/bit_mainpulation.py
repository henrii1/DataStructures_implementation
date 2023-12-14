n1 = 28
n2 = 19      # bit wise operations are performed on normal numbers. use the bin method to view output in bits

# AND    (1 and 1 is 1, otherwise 0)
n3 = n1 & n2
print(bin(n3)[2:])

# OR     (0 or 0 is 0, otherwise 1)
n4 = n1 | n2
print(bin(n4)[2:])

# XOR    (1 XOR 0 = 1, 0 XOR 1 = 1, otherwise 0)
n5 = n1 ^ n2
print("0" + bin(n5)[2:])     # we added zero because the terminal won't display leading zeros

# NOT
print(bin(~n1))      # the not symbol doesn't invert the number as it is supposed to. we do it another way

print("0" + bin(0b111111111111 - n1)[2:]) #'0b' indicates we are writing a binary, "1's" should equal the length of the number to convert

# SHIFTS   (equivalent to adding a zero at the end)

number = 20
print(bin(number)[2:])   # 10100
number <<= 1       #  left shifting once '1'
print(number)   # 40
print(bin(number)[2:]) # 101000
number >>= 2  # right shift two places
print(number)   #10
print(bin(number)[2:])  #1010