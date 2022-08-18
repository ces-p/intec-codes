## function that converts an ASCII character to its numerical equivalent
def ascii_to_num(ascii_char):
    if ascii_char.isdigit():
        return int(ascii_char)
    else:
        return ord(ascii_char)
    
print(ascii_to_num('A'))

## function that converts a number to it's ASCII equivalent 
def num_to_ascii(num):
    return chr(num)

print(num_to_ascii(65))

## function that converts from binary to decimmal
def bin_to_dec(binary):
    return int(binary, 2)

print(bin_to_dec('01000001'))