Trying a bunch of vector scaling methods for C++.

Typical output on a  i5-2415M CPU @ 2.30GHz:

 * `-O0`
```
custom scaling: 0.005417 s
cblas scaling:  0.001854 s
uBLAS scaling:  0.023705 s
```
 * `-O1`
```
custom scaling: 0.002454 s
cblas scaling:  0.003001 s
uBLAS scaling:  0.003071 s
```
 * `-O2`
```
custom scaling: 0.002567 s
cblas scaling:  0.002439 s
uBLAS scaling:  0.002279 s
```

 * `-O3`
```
custom scaling: 0.001896 s
cblas scaling:  0.003405 s
uBLAS scaling:  0.001726 s
```
