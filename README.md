Proficiency Demo Practice
===

This program helps you practice for proficiency demos in CS 162, 163, and 202 at Portland State University.

You will implement functions for linear and circular linked lists. The program will run tests on your code and report whether you have succeeded.

## How?

1. **Clone this project**

    This code will run on Linux or Mac computers (including all MCECS Linux servers).
    
    Enter this command to get a copy of the code:

    ```sh
    git clone https://github.com/pdx-cs-tutors/pdp.git
    ```
    
    The code will be downloaded into a new folder called `pdp`.
    
2. **Build**

   `cd` into the new folder and do an initial build of the project by running `make`:
   
   ```sh 
   cd pdp/
   make
   ```
   It will take a few moments the first time.
   
3. **Run**

    Now run the program:

    ```sh 
    ./run
    ```
    
    You will see a long list of test outputs, like this one:
    
    ``` 
    FAILED  Missing item(s)
    Initial:  [3 -> 2]
    Called:   append(head, 1)
    Expected: [3 -> 2 -> 1]
    Got:      [3 -> 2]
    ```
    
    This output is telling you that we ran the function `append(head, 1)` on a list containing `3 -> 2`. We expected to see a `1` added to the end of the list, but we did not.
    
    Your job is to write a correct `append` function, and to finish all the other functions so that the tests pass.

4. **Write**
    
    The code you need to edit is organized into the `include/` folder (for headers) and the `src/` folder (for implementation). Here are the files:
    
    ```
    ├── include/
    │   ├── cll.h   <- Headers for circular linked list functions
    │   └── lll.h   <- Headers for linear linked list functions
    └── src/
        ├── cll/
        │   ├── insertion.cpp  <- Insertion functions for CLLs
        │   └── removal.cpp    <- Removal functions for CLLs
        └── lll/
            ├── insertion.cpp  <- Insertion functions for LLLs
            └── removal.cpp    <- Removal functions for LLLs
     ```
     
     Go to the `src/lll/insertion.cpp` file and implement the `append` function.
     
     If you need helper functions, you can add them in the header files in the `include/` folder and implement them in the `src/` folder.
     
     Once you're ready, build and run the tests again:
     
    ```sh
    make
    ./run
    ```
    
    Did the tests for `append` pass this time?
     
5. **Repeat**

    Keep implementing functions and re-running the tests until they all pass!
     
#### Command line options

You can run only a certain subset of the tests if you like. Here are some examples:

```sh
./run
    Run ALL the tests
./run lll
    Run all the linear linked list tests
    (That is, all the tests in the src/lll/ folder)
./run cll
    Run all the circular linked list tests
    (That is, all the tests in the src/cll/ folder)
./run lll insertion
    Run all the insertion tests for linear linked lists
    (That is, all the tests for src/lll/insertion.cpp)
./run lll insertion append
    Run only the tests for the append function on LLLs
    (That is, only the tests for append in src/lll/insertion.cpp)

```

### Roadmap

Additions to come. Next on our list:

- Friendlier test outputs
- New tests for copying CLLs and LLLs
- Support for doubly linked lists
- Support for binary search trees

### Contributing

This project attempts to (mostly) stick to the conventions of Portland State's lower division C++ courses, although it does use a few C++11 features.

**Suggestions, bug reports, and contributions are very welcome!** You can make a pull request on Github, or talk with a CS Tutor on Slack or in person if you have questions.
