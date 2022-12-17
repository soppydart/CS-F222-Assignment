# CS-F222-Assignment
## Objective:
The main objective of the assignment is to report if two undirected graphs are isomorphic
or not.
The assignment will consist of two parts.
You can assume that the given graphs are not multigraphs. Your programs must be in C.
### Part A:
Given a graph, you need to output the degree sequence of the graph.
The degree sequence is obtained by determining the degrees of each node in the graph
and arranging it as a sequence in non-increasing order. Recall from class that the degree
sequence is a graph invariant.<br/><br/>
You would be given the name of the input file as a command-line argument.<br/><br/>
The first line of the input would be an integer n - the number of nodes.
Second line of the input would be an integer e - the number of edges
The next e lines contain a pair x and y ( 1≤ x,y ≤ n and x ≠ y) , to indicate that there is an
edge between nodes numbered x and y.<br/><br/>
You need to output the degree sequence in non-increasing order.
Output should be printed in standard output.<br/><br/>
You can assume the value of n ≤ 20, e ≤ 45. <br/><br/>
Test Case 1: <br/>
Input (a.txt): <br/>
5 <br/>
6 <br/>
1 2 <br/>
1 3 <br/>
4 5 <br/>
3 5 <br/>
2 3 <br/>
1 4 <br/>
Output (out-a.txt): <br/>
3 3 2 2 2 <br/><br/>
Test Case 2: <br/>
Input (b.txt): <br/>
8 <br/>
10 <br/>
1 2 <br/>
1 5 <br/>
1 4 <br/>
2 3 <br/>
3 4 <br/>
4 8 <br/>
5 6 <br/>
5 8 <br/>
6 7 <br/>
7 8 <br/>
Ouput (out-b.txt): <br/>
3 3 3 3 2 2 2 2 <br/><br/>
### Part B:
Now, you have to determine if two given input graphs are isomorphic or not.<br/><br/>
First, you have to check for some invariants, namely you have to check if the number of
nodes, number of edges, degree sequence are same for both graphs or not.
If any of these invariant does not come out to be equal, the graph cannot be isomorphic,
so in this case output just “Not Isomorphic” and terminate the program.<br/><br/>
Now let’s say all of the invariants are equal, then you have determine if the graphs are
isomorphic or not.
You have to look at all permutations of the vertices and check if you can construct a
bijection between the nodes of the two graphs for which the adjacency relation is
preserved. See definition of graph isomorphism from class.<br/><br/>
The names of the two input files containing each of the graphs would be given as
command line arguments and you have to output to standard output (i,e, to the console,
via printf).<br/>
The input format and the constraints would be same as Part 1.<br/>If the graphs come out to isomorphic output “Isomorphic” and also output a bijective
mapping of the nodes that preserves adjacency (explanation given below). If there are
multiple correct bijections, output one of them.<br/><br/>
However, if the graphs turn out to be non isomorphic output “Not Isomorphic, no
bijection found.”<br/><br/>
Test Case 1:<br/>
Input 1 (a.txt):<br/>
5<br/>
6<br/>
1 2<br/>
1 3<br/>
4 5<br/>
3 5<br/>
2 3<br/>
1 4<br/>
Input 2 (c.txt):<br/>
5<br/>
6<br/>
1 5<br/>
1 4<br/>
4 5<br/>
3 4<br/>
2 3<br/>
1 2<br/>
Ouput (out-ac.txt):<br/>
Isomorphic.<br/>
1 1<br/>
2 5<br/>
3 4<br/>
4 2<br/>
5 3<br/>
Explanation (your program should not output this):<br/>
The given graphs are isomorphic.<br/>
Then there are 5 lines (for 5 nodes), which consist of a pair of node numbers indicating 
the bjection between the respective nodes in the two graphs.<br/><br/>
Test Case 2:<br/>
Input 1 (b.txt):<br/>
7<br/>
10<br/>
1 2<br/>
1 5<br/>
1 4<br/>
2 3<br/>
3 4<br/>
4 8<br/>
5 6<br/>
5 8<br/>
6 7<br/>
7 8<br/>
Input 2 (d.txt):<br/>
8<br/>
10<br/>
1 2<br/>
1 4<br/>
1 5<br/>
2 3<br/>
3 4<br/>
3 7<br/>
5 6<br/>
6 7<br/>
7 8<br/>
5 8<br/>
Ouput (out-bd.txt):<br/>
Not Isomorphic, no bijection found.<br/>
Explanation:<br/>
The given graphs are not isomorphic even though they have the same degree sequence.
