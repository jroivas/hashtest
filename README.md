# Hashtest

Tool to compare different hashing algorithms. Plugin architecture for algorithms.


## Installation


    $ mkdir build
    $ cd build
    $ cmake ..
    $ make


## Testing

Run it inside the build folder

    $ LD_LIBRARY_PATH=./algorithms/dummy:./algorithms/murmur2:./algorithms/murmur3 ./src/hashtest words.txt murmur2 murmur3 dummy
    Adding murmur2
    Adding murmur3
    Adding dummy
    11 collisions in murmur2
    5 collisions in murmur3
    2 collisions in dummy


## Algorithms

Murmur2 and Murmur3:
* https://code.google.com/p/smhasher/source/browse/trunk/

DJB2, DJB2a and SDBM:
* http://www.cse.yorku.ca/~oz/hash.html
