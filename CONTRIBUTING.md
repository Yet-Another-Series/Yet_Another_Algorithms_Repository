## Contents

* [Getting started](#getting-started)
* [Writing code](#writing-code)
* [Adding unit tests](#adding-unit-tests)
* [Opening a pull request](#opening-a-pull-request)
* [Code of conduct](#code-of-conduct)

## Getting started



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

## Adding unit tests

* As stated above, all algorithms and data structures are verified via unit tests.
  
* Please make sure that your contribution includes a variety of unit tests and that all of your unit tests pass.

* You can find more information about writing unit tests [here](../C++/CONTRIBUTING.md). 

## Opening a pull request

Follow these steps when you're ready to submit your code:

1. Locally merge (or rebase) the upstream development branch into your branch:

   ```bash
   git pull [--rebase] upstream master
   ```

1. Push your branch up to your fork:

   ```bash
   git push origin <branch-name>
   ```

1. [Open a pull request][pr-guide] with a clear title and description against the
   `master` branch. Your pull request should reference the same issue you created 
   above.

1. Once your pull request has been opened, we'll review it and go from there. :smile:

## Code of Conduct

This project has a [Code of Conduct](CODE_OF_CONDUCT.md). Please follow it in all your interactions with the project.

## How to contribute an implementation (code)?

* Have a look at open issues. They contain the list of algorithms/DS we plan to be implemented. Pick an unassigned issue.
* You can also create a new issue for an algorithm that is not in the list.
* Make sure you are assigned for the issue.
* Code the algorithm/DS following the styleguide defined below.
* Send a PR. 
* Be sure to not include any compiled binaries in the patch.
* While sending a PR make sure you follow one issue per PR rule.


<a name="sa"></a>

## Suggesting an algorithm / DS

* First make sure you are not suggesting a duplicate.
* If not, proceed and create the issue. Make sure that you specify only one language in an issue. Create multiple issues for different languages.
* Title of issue should be of the following format -
    ```
        Algorithm/DS Name [Language]
    ```
* Please include at least one external link for the algorithm/DS in the issue's body for each issue. The link should explain the algorithm/problem/DS in detail.


<a name="cs"></a>

## Code Styleguide

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
* We have defined [skeleton codes](#samples) for some popular languages below. Please follow them whenever possible.





<a name="improving"></a>

## Improving an implementation

* If you feel you can improve upon an implementation, feel free to open an issue discussing the improvements.



