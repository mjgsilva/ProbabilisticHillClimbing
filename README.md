# Probabilistic Hill Climbing

## An approach to Maximally Diverse Group Problem using a Probabilistic Hill Climbing Algorithm

[Example:](http://classconnection.s3.amazonaws.com/608/flashcards/1910608/jpg/fig_4_1_hill-climbing1349062649219.jpg/ "Hill Climbing")

### How it works
First: Generate a random solution.
Second: Start the Hill Climbing Algorithm to try finding a better solution (higher value)
Sometimes the algorithm accepts a lower value to avoid being stucked in a local maximum value.
Third: Compares if the algorithm gets the best solution


### Matrix (RanInt_n010_ss_01.txt)

  0   1   2   3   4   5   6   7   8   9
0 x  69 100  73  71  72   6  66  12  58
   
1 69  x   3  26  75  65  48   9  72  80 

2 100 3   x  84  10  90  36  83  16   2

3 73 26  84   x  65   1  40  48  39  75

4 71 75  10  65   x  96  84  70  35  13

5 72 65  90   1  96   x  63  57   7   1

6  6 48  36  40  84  63   x  66  90  10
 
7 66  9  83  48  70  57  66   x  65  68

8 12 72  16  39  35   7  90  65   x  39

9 58 80   2  75  13   1  10  68  39   x

First line of the file defines the number of elements and the number of groups.
Example: 10 2 means that the solution supports two groups of five elements each.

[1 2 3 4 5 | 6 7 8 9 0]

### Solution Fitness formula:
Group 1 + Group 2

Group 1: 1 -> 2 + 1 -> 3 + 1 -> 4 + 1 -> 5 + 2 -> 3 + 2 -> 4 + 2 -> 5 + 3 -> 4 + 3 -> 5 + 4 -> 5
Group 1 = 3 + 26 + 75 + 65 + 84 + 10 + 90 + 65 + 1 + 96
		= 515

Group 2: 6 -> 7 + 6 -> 8 + 6 -> 9 + 6 -> 10 + 7 -> 8 + 7 -> 9 + 7 -> 10 + 8 -> 9 + 8 -> 0 + 9 -> 0
Group 2 = 66 + 90 + 10 + 6 + 65 + 68 + 66 + 39 + 12 + 58 
		= 480

Final fitness = 515 + 480
			  = 995

### Config params (paramconfig.txt)
	runs: 10
	iterations: 500
	swap: 2 -> Exchange two elements always avoiding exchanges between elements in the same group.
	prob: 0.01 -> There is a probability of 1% of choosing a solution with lower value. If you want to use a standart Hill Climbing Algorithm then just define this using 0.

