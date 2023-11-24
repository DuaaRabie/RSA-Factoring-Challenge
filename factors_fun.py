#!/usr/bin/python3
def factors(line):
    number = int(line)
    i = int(number/2)
    while i * i >= number:
        if number / i:
            print("{d}={:d}*{:d}".format(number, i, number/i))
            return 0
        else:
            i += 1
    return -1
