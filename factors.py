#!/usr/bin/python3
import sys
with open(sys.argv[1], 'r') as file:
    for line in file:
        number = int(line)
        i = number/2
        while i * i >= number:
            if number / i:
                print("{}={}*{}".format(number, i, int(number//i)))
                break;
            else:
                i += 1
