## Conways game of life

This program will simulate Conways Game of Life.  

Note: Currently this only works on windows due to the conio library being used.  
To make this cross platform, will have to implement a different terminal library

#### How to use it:

1. Make a text file with the initial area you want. Ideally seperate each tile with a space.
   Eg:
<pre>
   0 0 0 1 1 0 0 0 1 1  
   1 0 0 0 1 0 0 0 1 1  
   0 1 0 1 1 0 1 1 0 0  
   0 0 0 0 0 0 0 0 0 0  
   0 0 1 1 0 0 1 0 0 0  
   0 0 1 1 0 0 0 1 0 0  
   0 0 0 0 0 0 1 1 0 0  
</pre>
2. In the terminal, run the program with your text file as the argument.
3. It will display the area you typed, and then show the next area.
