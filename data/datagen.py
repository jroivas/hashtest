#!/usr/bin/python

import sys
import uuid

def genNumbers(filedesc, count):
    """ Generate numbers and write them to file descriptor

    >>> genNumbers(sys.stdout, 1)
    1
    >>> genNumbers(sys.stdout, 2)
    1
    2
    >>> genNumbers(sys.stdout, 12) # doctest: +ELLIPSIS
    1
    2
    ...
    11
    12
    >>> genNumbers(sys.stdout, 9999) # doctest: +ELLIPSIS
    1
    2
    ...
    9998
    9999
    >>> genNumbers(sys.stdout, 0) # doctest: +ELLIPSIS
    Traceback (most recent call last):
    ...
    ValueError: Count needs to be 1 or more
    >>> genNumbers(sys.stdout, -1) # doctest: +ELLIPSIS
    Traceback (most recent call last):
    ...
    ValueError: Count needs to be 1 or more
    """
    if count < 1:
        raise ValueError('Count needs to be 1 or more')

    for num in xrange(1, count + 1):
        filedesc.write('%s\n' % num)

def genUUID(filedesc, count):
    """ Generate UUIDs

    >>> genUUID(sys.stdout, 0) # doctest: +ELLIPSIS
    Traceback (most recent call last):
    ...
    ValueError: Count needs to be 1 or more
    """
    if count < 1:
        raise ValueError('Count needs to be 1 or more')

    for num in xrange(1, count + 1):
        filedesc.write('%s\n' % str(uuid.uuid4()))

def genLongLines(filedesc, count):
    """ Generate UUIDs

    >>> genLongLines(sys.stdout, 1) # doctest: +ELLIPSIS
    a
    >>> genLongLines(sys.stdout, 2) # doctest: +ELLIPSIS
    a
    b
    >>> genLongLines(sys.stdout, 3) # doctest: +ELLIPSIS
    a
    b
    c
    >>> genLongLines(sys.stdout, 30) # doctest: +ELLIPSIS
    a
    b
    c
    ...
    y
    aa
    bb
    cc
    dd
    ee
    >>> genLongLines(sys.stdout, 100) # doctest: +ELLIPSIS
    a
    ...
    wwww
    xxxx
    yyyy
    >>> genLongLines(sys.stdout, 1020) # doctest: +ELLIPSIS
    a
    ...
    sssssssssssssssssssssssssssssssssssssssss
    ttttttttttttttttttttttttttttttttttttttttt
    >>> genLongLines(sys.stdout, 0) # doctest: +ELLIPSIS
    Traceback (most recent call last):
    ...
    ValueError: Count needs to be 1 or more
    """
    if count < 1:
        raise ValueError('Count needs to be 1 or more')

    for num in xrange(1, count + 1):
        the_range = (ord('z') - ord('a'))
        line = (1 + (num - 1) / the_range) * chr(ord('a') + (num - 1) % the_range)
        filedesc.write('%s\n' % line)

def usage():
    print ('Usage: %s tool output_file [number_of_items]' % sys.argv[0])
    print ('Tools:')
    print ('       number')
    print ('       longlines')
    print ('       uuid')
    print ('\nBy default generates 100000 items')

if __name__ == '__main__':
    if len(sys.argv) < 3:
        usage()
        sys.exit(1)

    tool = sys.argv[1]
    if tool == 'number':
        gentool = genNumbers
    elif tool == 'uuid':
        gentool = genUUID
    elif tool == 'longlines':
        gentool = genLongLines
    else:
        print ('ERROR: Invalid tool: %s\n' % tool)
        usage()
        sys.exit(1)

    filename = sys.argv[2]
    if len(sys.argv) == 4:
        itemcnt = int(sys.argv[3])
    else:
        itemcnt = 100000

    if filename == '-':
        gentool(sys.stdout, itemcnt)
    else:
        with open(filename, 'w') as filedesc:
            gentool(filedesc, itemcnt)
