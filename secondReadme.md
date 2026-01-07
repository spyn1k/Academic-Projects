#ELEVATE.C#

*The elevate program is a command line tool for optimizing elevator efficiency.*

*It calculates the optimal floors for an elevator to stop at to minimize the total walking cost (stairs) for all passengers.*

• **--mode=<mode>** _Selects the algorithm: recurse, brute, memoize, or dp_

• **--debug** _Enables debug printing (displays the DP cost table)_

                                                               COMPILE WITH
gcc -Os -c -Wall -Wextra -Werror -pedantic elevate.c
gcc -Os -c -Wall -Wextra -Werror -pedantic recurse.c
gcc -Os -c -Wall -Wextra -Werror -pedantic brute.c
gcc -Os -c -Wall -Wextra -Werror -pedantic memoize.c
gcc -Os -c -Wall -Wextra -Werror -pedantic dp.c
gcc -Os -o elevate recurse.o brute.o memoize.o dp.o elevate.o

                                                              COMMAND GUIDE
Default Run (Production Mode)
-
./elevate input.txt

*Runs the optimized Dynamic Programming solution (default).*

Recursive Method
-
./elevate input.txt --mode=recurse

*Naive recursive implementation. Recommended only for small inputs.*

Brute Force Method
-
./elevate input.txt --mode=brute

*Generates all possible combinations. Useful for verification.*

Memoization Method
-
./elevate input.txt --mode=memoize

*Recursive approach with caching. Faster than standard recursion.*

Debug Mode
-
./elevate input.txt --mode=dp --debug

*Prints the internal cost table used to make the decision.*

                                                               INPUT FORMAT
***The program expects an input file formatted as follows:***

<sub><numPeople> <numStops><sub>
<sub><dest_1> <dest_2> ... <dest_N><sub>

**Example (5 people, 2 stops):**
5 2
11 2 7 13 7

                                                          PRODUCTION CHOICE
***Why Dynamic Programming (DP) is the default:***

After benchmarking all four methods, **Dynamic Programming (Bottom-Up)** was selected as the production-ready solution.

* **Performance:** Unlike `recurse` and `brute`, which have exponential complexity, DP solves the problem in polynomial time (**O(N*M)**), making it viable for large inputs.
* **Stability:** Unlike `memoize`, which relies on recursion and can lead to **Stack Overflow** errors on very large inputs (deep recursion trees), the DP approach is purely iterative.
* **Efficiency:** It fills the cost table systematically, ensuring distinct CPU cache usage and zero redundant calculations.

                                                                  SOURCES
***1.*** _Wikipedia – Recursion_ https://en.wikipedia.org/wiki/Recursion_(computer_science)

***2.*** _Wikipedia – Brute-force search_ https://en.wikipedia.org/wiki/Brute-force_search

***3.*** _Wikipedia – Memoization_ https://en.wikipedia.org/wiki/Memoization

***4.*** _Wikipedia – Dynamic Programming_ https://en.wikipedia.org/wiki/Dynamic_programming
