## Contents

* [Getting started](#getting-started)



## Getting started

* 


## Writing code

* Commit your changes in logical chunks. Use Git's [interactive rebase][rebase-guide]
  feature to tidy up your commits before making them public.

* For each algorithm, mention its **time complexity** and **space complexity**
  in the _"description comment"_ of its implementation. In case the average-case
  and worst-case complexities are different, mention both of them.

    The format for the _"description comment"_ (which is written at the beginning) should be:

    ```text
    <Name of algorithm>
    -------------------
    <Brief description>

    Time complexity
    ---------------
    O(...), where <description of variable(s)>

    Space complexity
    ----------------
    O(...), where <description of variable(s)>
    ```

* Before you push your changes to GitHub, make sure that your code compiles and runs without any errors or warnings.
* Code submitted should be modular. 
* Don't use global variables.
* Use separate folders for each concept. Folder name should be in full lowercase. If the algorithm/DS name has multiple words, separate them by underscores. (eg `longest_common_subsequence`)
* Filename should be derived from the folder name. (eg `longest_common_subsequence` becomes `longestCommonSubsequence.c` or `LongestCommonSubsequence.java`)
* Name of master function of the code should be kept same as filename to the best extent possible.
* Prefer classes instead of multiple helper functions (where applicable).
* Currently we are accepting contributions in C, C++, C#, Java, Python, Go and JavaScript but other languages may be considered after a discussion.
* Define `tester` code only in `main` routine.
* Use meaningful variable, method and function names and comments.
* No profanity.
* Use external libraries only when no other solution is possible/plausible.
* If you feel you can improve upon an implementation, feel free to open an issue discussing the improvements.

## Opening a pull request

1. [Open a pull request][pr-guide] with a clear title and description against the
   `master` branch. Your pull request should reference the same issue you created 
   above.

1. Once your pull request has been opened, we'll review it and go from there. :smile:



* First make sure you are not suggesting a duplicate.






