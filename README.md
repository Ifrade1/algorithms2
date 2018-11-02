# algorithms2

#Things to do:

  *Create main function file
  
  *In main function, write a loop that scans in input, if string = command then excecute the command, else check next command, else spit out error for that line. 
  
   *Create file for insert, delete, search, min max.
   
   *Write Makefile!!!!! 


Insert function: if head points to null, then assign that leaf to header. 

__________________________________________________________________________________
Create an implementation of a binary search tree in C that allows for non-unique non-negative integer keys. Your tree will only store keys, no associated data.

Implement all 7 dictionary operations:

- Insert a given key, return key value, -1 if unsuccessful (run out of space).

- Delete a key (all nodes with the given key), return number of nodes deleted.

- Search for a key, return 1 if found, 0 otherwise.

- Min, Max: Return the minimum/maximum key in the tree, -1 if the tree is empty.

- Successor/Predecessor: Given a key that exists in the tree, return the next bigger/smaller key in the tree. Return -1 if the given element is the biggest/smallest in the tree, or if the given key cannot be found in the tree.

For the purposes of our project, the height of an empty tree will be -1.

Your program should be able to parse input provided in the standard input, each line of which performs one dictionary operation. Each line has one directive and potentially one key (dependent on the operation), separated by a single space character. You can assume that the input has no errors. The directives are:

INS: Insertion
DEL: Deletion
SEA: Search
MIN: Minimum
MAX: Maximum
PRE: Predecessor
SUC: Successor
HEI: Tree height

Example input file:

INS 45
INS 31
INS 45
DEL 10
SEA 31
SEA 11
DEL 45
MIN
SUC 80
INS 1
SUC 1
HEI

Which should produce the following output:

45
31
45
0
1
0
2
31
-1
1
31
1

Please note that the height of the tree may depend on your implementation, due to the non-unique keys.

Your program can consist of multiple files, and should be accompanied by a makefile. When compiled with the command ‘make’, an executable called bst should be created. That executable will parse input from its standard input and produce all output in its standard output. No other output except the required output mentioned above should be sent to the standard output.

You should archive your files, without creating any directories, using zip. The make utility should run correctly and create the appropriate executable in the directory where the files are extracted.

I prepared a sample testing program and test cases to ensure you adhere to the stated requirements at a minimal level. You can download the testing.zip file, un-archive it in the same directory with your zip file with your program (and only your zip file), and run the run.pl program.

HINT: One of the easier ways to implement this binary search tree that allows for duplicate keys is to create linked lists for records items with duplicate keys, instead of inserting such items in separate tree nodes.
