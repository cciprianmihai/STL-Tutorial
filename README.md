# STL Tutorial

In this tutorial we present examples from the [STL Tutorial](http://www.cmapx.polytechnique.fr/~benaych/stl-tutorial-Weidl.pdf). 

To run the code: 
```
g++ script_name.cpp -o script_name
./script_name
```
<b>Nice Classes.</b> For STL it’s wise to create classes that meet the requirements of <i>Nice Classes</i>. Forexample, Borland C++ expects an object to be stored in a container to have an assignment operatordefined. Additionally, if a container holds its objects in a particular order, a operator like the `operator<<` must be defined (the latter to fix a half-order).

![1](images/1.png)
![2](images/2.png)
