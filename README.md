# Data Structures Study

A deep study about Data Structures with help of C language

## Algorithm Complexity Analysis

The algorithm efficiency can be measured in a lot of ways, the most famous are:

- Temporal complexity.
- Spatial complexity.

### Specific Algorithm Analysis

We try to understand how much it costs for an specific algorithm to solve a problem.

These are some of the characteristics we study about the algorithm:

- How many times each part of the algorithm must be executed.

- How much memory is needed for the algorithm data structures.

### Algorithm Class Analysis

We try to understand what is the algorithm with the less possible cost to solve a particular problem (per example, ordering and searching algorithms).

All the algorithm family is studied. So we try to find the better one. Being minded about it, we can create limits for the computational complexity of the algorithms that belong to that family.

### Cost Measurement

If we use the same cost measure for different algorithms, we are able to compare them and choose the better one.

We can measure the algorithm cost in the following ways:

#### Algorithm Execution

Most of the time this measurement is not the better one, since the results depends on compiler, hardware and memory utilization.

Even though, sometimes it is a good measurement when we need to compare distinct algorithms to solve the same problem and they have the same order of magnitude or we need to make an analysis of how the algorithm behave in the context it will be applied.

#### Mathematical Model

We use a mathematical model based on a idealized computer.

Usually we use the RAM Model (Random Access Machine):

- A processor that executes an action per time.

- A memory that stores the data.

- Basic operations with constant cost (memory access, conditionals, arithmetic operation, etc.).

We need to specify the algorithm operations and their execution costs (usually we only consider the cost of the most significant operations).

### Algorithm Cost

When we determine the cheaper cost possible to solve a algorithm class problem, we find the inherently difficult to solve that problem.

A top algorithm is the one with cost equals to the cheaper problem cost. 

### Complexity Function

The execution cost of a algorithm is found by a cost function, or complexity function.

**f(n)** is the cost measurement needed to execute a algorithm with size of **n**.

- **Temporal Complexity Function:** **f(n)** measures the cost in number of operations to execute a algorithm in a problem of size **n**.

- **Spatial Complexity Function:** **f(n)** measures the memory needed to execute a algorithm in a problem of size **n**.

In general, we use **f(n)** as a temporal complexity function, but, be minded that it does not represent the time directly, instead, it represents the amount of times a specific operation considered to be relevant is executed.

#### Example: Find max number in an array.

The cost is **F(n) = n - 1** since we have a loop with **n - 1** iterations in which we make a comparison.

```c
int maxValue (int *A, int n) {
	int i, temp;

	temp = A[0];

	for (i = 1; i < n; i++) {
		if (temp < A[i]) {
			temp = A[i];
		}
	}

	return temp;
} 
```

The execution cost measurement of an algorithm is a function with the same size of the data input.

In some algorithms, the execution cost depends on the data organization as well. In these cases, we will have different complexity functions to represent the best, worst and average case.

- **Best case:** Least execution time in all the input of size **n**.

- **Worst case:** Biggest execution in all input of size **n**.

- **Average case:** Average of all execution time of all input of size **n**.
	- (best case + worst case) / 2

#### Example: Sequential search (each record has an unique key).

The **best case** is when the record is the first one read: **F(n) = 1**.

The **worst case** is when the record is the last one read or it is not even on the store: **F(n) = n**.

The **average case** is when the record is in the middle of the store: **F(n) = (n + 1) / 2**.

```c
int searchIndex (Store *A, int n, int key) {
	int i;

	i = 0;

	while(i < n) {
		if (A[i].key == key) {
			break;
		}

		i++;
	}

	return i;
}
```

### Algorithms Comparison

When we compare algorithms of the same class, sometimes we are able to understand what is the limit inferior of that class.

The limit inferior shows us the better complexity function that can be found for an algorithms class.

## Asymptotic Complexity

It is important to study the algorithm cost for big values of **n** (n → ∞).

We call asymptotic complexity analysis, when we analysis the algorithm when the value of **n** tends to infinity.

In that case, we do not need to worry about constants and terms of less growing.

### Asymptotic Dominance

A function **f(n)** dominates asymptotically a function **g(n)** if there are two positive constants **c** and **m** for **n >= m**, we have **|g(n)|<= c|f(n)|**.

<img src="./resources/asymptotic-dominance.png"></img>

### Asymptotic Notations

#### O (Big-O)

Specifies the limit superior for **g(n)** (the worst case).

**g(n) = O(f(n))** if **f(n)** dominates asymptotically **g(n)**.

**g(n) is order of f(n)**, or **O of f(n)**.

<img src="./resources/big-o.png"></img>

- Useful operations:

<img src="./resources/big-o-operations.png"></img>

- Example:

<img src="./resources/big-o-example-1.png"></img>

#### Ω (Big-Omega)

Specifies the limit inferior for g(n).

A function **g(n)** is **Ω(f(n))** if there are two constants **c** and **m** in which **g(n) >= cf(n)** for each **n >= m**.

<img src="./resources/big-omega.png"></img>

#### Θ (Big-Theta)

A function **g(n)** is **Θ(f(n))** if there are positive constants **c1, c2 and m** in which **0 <= c1f(n) <= g(n) <= c2f(n)** for every **n >= m**.

<img src="./resources/big-theta.png"></img>

For every **n >= m**, the function **g(n)** is equal **f(n)**.

### Asymptotic Class Behavior

In general, it is interesting to group algorithms and problems by asymptotic behavior class, that determines the inherit complexity of the algorithm.

When two algorithms have the same asymptotic behavior class, we call them equivalent (in that case, we need to make a better analysis of the complexity function or its performance in real systems).

#### f(n) = O(1): Constant Complexity

The algorithms is not dependent of **n**.

The algorithm instructions are executed a fixed number of times.

#### f(n) = O(log n): Logarithm Complexity

Usually algorithms that turns a problem into smaller problems.

#### f(n) = O(n): Linear Complexity

In general, a small work is done in every element of the input.

Everytime **n** doubles its size, the time of execution gets doubled as well.

#### f(n) = O(n log n)

Usually algorithms that break problems in smaller ones, and so, solve each one independently and making the solution adjustments later.

#### f(n) = O(n²): Quadratic Complexity

Usually when the input data is processed in pairs, per example doing a loop inside another.

#### f(n) = O(n³): Cubic Complexity

Useful to solve smaller problems.

#### f(n) = O(2^n): Exponential Complexity

Usually are not useful at a practical sight of view.

Happens when we try to solve problems by brute force.

#### f(n) = O(n!)

An algorithm of complexity O(n!) is called to have exponential complexity, even being too much worse than **O(2^n)**.

Happens when we try to solve problems by brute force.

### Asymptotic Class Behavior Comparison

<img src="./resources/complexity-comparison.png"></img>
