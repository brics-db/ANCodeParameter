# Lower Bound-oriented Parameter Calculation for AN Coding

The hardware as well as software communities have recently experienced a shift towards mitigating bit flips issues in software, rather than completely mitigating only in hardware. For this software error mitigation, arithmetic error coding schemes like AN coding are increasingly applied because arithmetic operations can be directly executed without decoding and bit flip detection is provided in an end-to-end fashion. In this case, each encoded data word is computed by multiplying the original data word with a constant integer value A. To reliably detect b bit flips in each code word, the value A has to be well-chosen, so that a minimum Hamming distance of $b+1$ can be guaranteed. However, the value A depends on the data word length as well as on the desired minimum Hamming distance.  Up to now, a very expensive brute force approach for computation of the value for $A$ is applied. To tackle that in a more efficient way, we developed a lower bound-oriented approach for this calculation. The overall approach is described in the following paper:

* Juliana Hildebrandt, Till Kolditz, Dirk Habich, Wolfgang Lehner: Lower Bound-oriented Parameter Calculation for AN Coding. Appears in the 2018 International Symposium on Information Theory and Its Applications (ISITA, Singapur, October 28 - 31), 2018

How to run the program:

```
make
./lowerBoundAComputation
```

The program should work on Linux, Windows, or Mac OS X.  It works on x86-64 only, because it requires 64-bit instructions.
