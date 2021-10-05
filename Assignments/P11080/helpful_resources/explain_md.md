Each call to `isBipartite` I created a `temp` vector and copy
the color vector created for that call only to `temp`. Below is an
example that had three calls. We ignore the -1's:

```
Call 1 => [ 1  0  1 -1 -1] (smallest set is 0 or 1 guard)
Call 2 => [-1 -1 -1  1 -1] (smallest set is 1  or 1 guard)
Call 3 => [-1 -1 -1 -1  1] (smallest set is 1  or 1 guard)

1 + 1 + 1 = 3 (correct answer)
```

An extreme example is 5 vertices 0 edges. The answer is automatically
5 guards, but to show the above logic works, here is the printout
of `temp` at each call to isBipartite:

```
Call 1 => [ 1 -1 -1 -1 -1] (each call has a 1 for the vertex that needs a guard)
Call 2 => [-1  1 -1 -1 -1]
Call 3 => [-1 -1  1 -1 -1]
Call 4 => [-1 -1 -1  1 -1]
Call 5 => [-1 -1 -1 -1  1]

1 + 1 + 1 + 1 + 1 = 5
```

Of course a fully connected graph would only call `isBipartite` 1 time. The
graph below:

```
1
5 5
0 1
0 2
0 3
4 1
4 3
```

returns:

```
[1 0 0 0 1] (Three zeros and two ones. Two ones is smallest set or 2 guards)
```

