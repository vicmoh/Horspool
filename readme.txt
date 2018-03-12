/***********************************
 * Vicky Mohammad
 * 0895381
 ***********************************/

-------------------------<<((  How to Run the Program  ))>>-------------------------- 

- Go to directory
- Type "make" to compile
- Type "make run", if fail, type "./bin/run"

--------------------------------<<((  Assumptions  ))>>------------------------------ 

- WARNING!: the garbage value in the data file may cause the program to infinite loop or segfault!
- Assuming that there can be multiple matches of a pattern on a single line
- When running the program it the time depends on the computer hardware
- If running time is 0.0000, It means that the time is faster than it can ouput hence, it is 0.0001
- The brutes forces take much longer the longer the file

--------------------------<<((  Analysis of Algoritms  ))>>---------------------------

Test case   |    Brute Force     |      Horspool       |    Boyer-Moore      |   #
------------------------------------------------------------------------------------
"university"|3296581/187 = 17,628| 430549/15 = 28,703  | 2983147/15 = 198,876 |  177 
"admission" |3296582/171 = 19,278| 427335/15 = 28,489  | 2175318/15 = 145,021 |  1363
"students"  |3296583/156 = 21,131| 505340/15 = 33,689  | 2561715/15 = 170,781 |  4201
"running"   |3296584/140 = 23,547| 527136/15 = 35,142  | 3063934/31 = 98,836  |  0
"school"    |3296585/125 = 26,372| 594187/15 = 39,612  | 2866365/15 = 191,091 |  211
"money"     |3296586/109 = 30,243| 754346/15 = 50,289  | 3151914/31 = 101,674 |  2
"test"      |3296587/93 = 33,447 | 920621/15 = 61,374  | 2877119/31 = 92,810  |  253
"hey"       |3296588/78 = 42,263 | 1171961/15 = 78,130 | 3222204/15 = 214,813 |  431
"ok"        |3296589/78 = 42,263 | 1691152/31 = 54,517 | 3291795/15 = 219,453 |  206
"a"         |3296590/62 = 53,170 | 3296590/31 = 106,341| 3296590/15 = 219,772 |  212358
-----------------------------------------------------------------------------------
Avg Ratios: |      30,934        |       36,718        |       165,312        |

# = occurances
Ratio = Pattern Shift / Running Time = Shifts Per Milisecond.


--------------------------<<((  About the Algorithm  ))>>---------------------------

- Bruteforce is easiest to implement but the least efficent, and takes time to search.
- Horsepool is implemet, by shifting based on the wasted character to compare, hence it has lest
patter switch and much faster to get to the work you are looking for
- boyer-moore is used with bad character and a good suffix to shift to the next index, 
it is supposedly to be faster when the search is a big length. 

---------------------------<<((  Amount of shifts  ))>>------------------------------

- The amount of shifts in Boyer-Moore is always equal-to or less-than horspool, but for some reason
I get a high number of pattern shift, I may calculate the pattern wrong 
- Brute force is always the max amount of shifts, since I subtract based on input search
the brute force patern decrease as my search length gets bigger

---------------------------------<<((  Ratios:  ))>>----------------------------------

- The ratio for brute force is often higher because it is doing many smaller shifts 
per second, as it is only shifting by one position
- The ratio for horspool and Boyer-Moore are supposed to be identical, they often only 
differ in execution time by a few miliseconds, but since the I may calculate the pattern
wrong on the boyer wrong it cause gives the wrong output, but overall, the time is similar.

---------------------------<<((  Size of search word ))>>------------------------------

- when gradually searching bigger word, brute force takes a longer time to execute and 
and the pattern shift deacrease buy a little bit based on how big the word search is
- when gradually searching bigger words, the run times for horspool and boyer-moore 
remain consistent value at around 01-40. The amount of shift for both decrease, but since
I may miss calculate the booyer moore the patern was not undetical to horsepool then it should

---------------------------------<<((  efficency ))>>----------------------------------

- it is most effective for brute force when the search word is very small such as one character
- when search is increase pass one chara cter Horspool and Boyer-Moore become more efficient, 
and siginificantly faster.
-time for horsepool and boyermoore is roughly more or less the same.