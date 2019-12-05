# Clingo C/C++ Example

This example shows how a minimal cmake based project can use the clingo
library.

The easiest way to get started is to install the required tools via [conda]. (I
would recommend to install Miniconda but Anaconda works, too.) The commands
below assume that you are using Linux. Other operating systems might require
slightly different commands/packages to be installed.

We assume that conda is already installed and the base environment is activated.

Next, we create a new environment called `potassco` and install the required
software:

```bash
conda create -n potassco
conda install -n potassco -c potassco clingo cmake gxx_linux-64
```

We can then activate the newly created environment:
```bash
conda activate potassco
```

With this we can setup and compile our project:
```bash
cmake -H. -Bbuild -DCMAKE_BUILD_TYPE=Release
cmake --build build
```

This builds two example programs, each implementing the same functionality. One
uses clingo's C and the other the C++ API. We can then run a program on a small
example:

```bash
$ echo "a. #program prog. b." | ./build/src/c-example
example version 1.0.0
Reading from stdin
Solving...
Answer: 1
a
SATISFIABLE

Models       : 1+
Calls        : 1
Time         : 0.000s (Solving: 0.00s 1st Model: 0.00s Unsat: 0.00s)
CPU Time     : 0.000s

$ echo "a. #program prog. b." | ./build/src/c-example --program prog
example version 1.0.0
Reading from stdin
Solving...
Answer: 1
b
SATISFIABLE

Models       : 1+
Calls        : 1
Time         : 0.000s (Solving: 0.00s 1st Model: 0.00s Unsat: 0.00s)
CPU Time     : 0.000s
```

[conda]: https://docs.conda.io/projects/conda/en/latest/user-guide/install/linux.html
