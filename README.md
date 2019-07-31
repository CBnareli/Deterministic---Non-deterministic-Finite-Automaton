# Deterministic---Non-deterministic-Finite-Automaton
    DESCRIPTION
Program in C, which accepts as input from a txt file the description of a finite automaton and from the keyboard different words 
and answers whether or not each word belongs to the language of the automaton.
The program first asks for the name of the file from which to read the automatic definition. The file must contain all the information 
necessary for the manufacture of the automatic.

E.g.

	3 \* The automatic has three modes *\
	1 \* Initial state is 1 *\
	2 \* There are two final states *\
	23 \* The final states are 2 and 3 *\
	6  \* There are 6 transitions (darts) *\
	1a2 \* Transition description. For example if the auto is in the state *\
	1b1 \* 1 and read the symbol a goes to state 2. Use a *\
	2a3 \* special character, $, to indicate the empty word. *\
	2b1 \* There is an implied match between the names of the states *\
	3a3 \* A, B and C and in the numbers 1, 2, 3, .... Essentially for your program the *\
	3b1 \* the names of the states in the above figure have no meaning. *\

The program reads the description of an automatic, then reads characters from the keyboard. As he reads characters one by one "remembers"
what he is in (in the case of a non-determinist automatic he remembers what situations he is in and selects one of them each time 
(as unique) to continue). As soon as the user presses the special character ":", the word is considered to have been completed and 
a corresponding message is displayed on the screen, depending on whether the auto-shutdown is finished or not. 
Immediately after the program asks the user if he will enter a new word coke. The program is terminated by a related menu.

	Description of the code
    
Were used 3 data structures: Linked List, Queue & Stack

The alphabet is {a, b,$}

>STEPS

>step 0. Reads the file name, and opens it.

>step 0.0. Constructs the list of vertices. Reads the number of states from the file and creates the corresponding number of vertices.

>step 2.3. Sets 1, in the "ffinal" field of these nodes that are final

>step 2.4. Adds edges according to the transitions described in the file. In more detail, it reads line by line of document and holds the 3 data we are interested in.
He then binds a node in memory, and looks for the top with the name which is identical with that of the node to be moved.
After finding it, it links it to the corresponding field of the node that we just committed, saves the character, 
and links this new node to the rest in the edge list.
In addition to remembering what situations it is in, the stack structure was used.
Specifically 3 stacks were added to the struct korifi, one for each letter of the alphabet.

>step 4.1. At this point the user types the word he wants to know if it is
accepted by automatic or not. And CurPtr moves on the corresponding graph so that it can "remember" where it is at any time. The motion on the graph is accomplished by the Removee () function, which briefly finds the edge to follow and returns the head node.

>step 5.Print the relevant message

    Comments on NFA

The way to choose from the number of transitions is random using the existing function c, rand ().
Rand () "decides" a number ranging from 1 to the number of existing transitions (for letters a,b respectively) and from 0 to the number for e-transitions.
After deciding, it extracts from the corresponding stack as many transitions as the number, and "holds" the latter.
He then puts back the transitions (which we keep temporarily in a stack of temp) to keep it intact.
Still, to know the number of transitions for each letter in each node a 3-position table was added,
where the number is kept in each position the transitions made by the node with the corresponding letter.
Also, if there are e-transitions; it automatically decides whether to move to another node, once before a letter and once after a letter.
Therefore, after the first letter is given, the automatic decides whether will move by e-transition twice in a row.

