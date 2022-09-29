# A recursive solver for the Solitaire game

I found this in an archive. I must have written it about 25 years ago for a DOS 
machine. I remember that, at the time, my PC at work was an Apricot machine with 
a 386 SX processor. A bit like this: http://www.computinghistory.org.uk/det/15816/Apricot-XEN-i-386-45/ 
but without the funky LCD screen keyboard and perhaps with a 16 MHz clock.

It took hours to solve the Solitaire - I left it running overnight.

My current machine has cores like this:

    processor       : 15
    vendor_id       : GenuineIntel
    cpu family      : 6
    model           : 141
    model name      : 11th Gen Intel(R) Core(TM) i7-11800H @ 2.30GHz
    stepping        : 1
    microcode       : 0x3e
    cpu MHz         : 2517.915
    cache size      : 24576 KB

The program runs like this:

    :; gcc -Wall -O3 soli_linux.c -o soli_linux ; time ./soli_linux > out
    real    0m0.685s
    user    0m0.681s
    sys     0m0.004s

Let's say it took about an hour before ...

    :; octave
    octave:1> 3600 / 0.7
    ans =  5142.9
    octave:2>

Five thousand times faster over 25 years.

https://en.wikipedia.org/wiki/Moore%27s_law talks about about transistor density 
doubling every couple of years. If I assume, instead, that computing power doubles every 
couple of years, instead, then for 25 years, I'd expect this:

    :; octave
    octave:1> 2 ^ (25 / 2)
    ans =  5792.6
    octave:2>

Which is pretty close :-)
