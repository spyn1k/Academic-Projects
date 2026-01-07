ELEVATE.C
*The elevate program is a command line tool for optimizing elevator efficiency.*

*It calculates the optimal floors for an elevator to stop at to minimize the total walking cost (stairs) for all passengers.*

• **--mode=<mode>** _Selects the algorithm: recurse, brute, memoize, or dp_
• **--debug** _Enables debug printing (displays the DP table in dp mode)_

                                                               COMPILE WITH
# Compile object files
gcc -Os -c -Wall -Wextra -Werror -pedantic elevate.c
gcc -Os -c -Wall -Wextra -Werror -pedantic recurse.c
gcc -Os -c -Wall -Wextra -Werror -pedantic brute.c
gcc -Os -c -Wall -Wextra -Werror -pedantic memoize.c
gcc -Os -c -Wall -Wextra -Werror -pedantic dp.c

# Link program
gcc -Os -o elevate recurse.o brute.o memoize.o dp.o elevate.o

                                                              COMMAND GUIDE
Default Run (Best Mode)
-
./elevate input.txt

*Uses the optimized Dynamic Programming solution by default.*

Brute Force Method
-
./elevate input.txt --mode=brute

*Generates all possible stop combinations. Useful for verifying correctness on small inputs.*

Recursive Method
-
./elevate input.txt --mode=recurse

*Naive recursive implementation. Very slow for large inputs.*

Memoization Method
-
./elevate input.txt --mode=memoize

*Recursive approach with caching. Significantly faster than recurse.*

Debug View (DP Only)
-
./elevate input.txt --mode=dp --debug

*Prints the internal cost table used to make the decision.*

                                                        PRODUCTION CHOICE
***Why Dynamic Programming (DP) is the default:***

After benchmarking all four methods, **Dynamic Programming (bottom-up)** was selected as the production-ready solution.

* **Performance:** Unlike `recurse` and `brute`, which have exponential complexity, DP solves the problem in polynomial time (O(K*N^2)).
* **Stability:** Unlike `memoize`, which relies on recursion and can lead to Stack Overflow errors on very large inputs, the DP approach is iterative.
* **Efficiency:** It fills the cost table systematically (from 0 stops to N stops), ensuring no redundant calculations and efficient cache usage.

                                                                  SOURCES
***1.*** _Wikipedia – Recursion_ https://en.wikipedia.org/wiki/Recursion_(computer_science)

***2.*** _Wikipedia – Brute-force search_ https://en.wikipedia.org/wiki/Brute-force_search

***3.*** _Wikipedia – Memoization_ https://en.wikipedia.org/wiki/Memoization

***4.*** _Wikipedia – Dynamic Programming_ https://en.wikipedia.org/wiki/Dynamic_programming

***5.*** _Json.org – The JSON format_ https://www.json.org/json-en.html

***6.*** _Model Context Protocol (MCP)_ https://modelcontextprotocol.io/docs/getting-started/intro
