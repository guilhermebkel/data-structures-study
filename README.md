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