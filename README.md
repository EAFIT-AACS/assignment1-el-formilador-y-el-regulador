# 📌 Project README
```
███████╗ ██████╗     
██╔════╝██╔═══██╗    
█████╗  ██║   ██║    
██╔══╝  ██║▄▄ ██║    
███████╗╚██████╔╝    
╚══════╝ ╚══▀▀═╝     

███████╗████████╗ █████╗ ████████╗███████╗███████╗
██╔════╝╚══██╔══╝██╔══██╗╚══██╔══╝██╔════╝██╔════╝
███████╗   ██║   ███████║   ██║   █████╗  ███████╗
╚════██║   ██║   ██╔══██║   ██║   ██╔══╝  ╚════██║
███████║   ██║   ██║  ██║   ██║   ███████╗███████║
╚══════╝   ╚═╝   ╚═╝  ╚═╝   ╚═╝   ╚══════╝╚══════╝
```


## 📖 Description
- This project implement the algorithm proposed by Kozen in lecture 14 of his book Automata and Computability, to find equivalent states in a DFA

## 📚 Class Information
- **Class Number:** 7308  

## 👨‍🏫 Teacher
- **Adolfo Andrés Castro Sánchez** 

## 👨‍🎓 Students
- **Jeronimo Campuzano Castaño** 
- **Andres Perez Quinchia**  

## 💻 System Information
- **OS:** Ubuntu 24.04.2 LTS x86_64  
- **Programming Language:** C++  
- **Compiler Version:** g++ 13.3.0  

---

## 🚀 Running 
- **Compilation** To compile the project, use a C++ compiler to produce the binary file. Ensure to include all the .cpp files, here is an example with g++ in linux
```bash
g++ -o a main.cpp DFA.cpp Reader.cpp Printer.cpp
```
- **Execution** After this you will have the binary file in the same location you ran the comand.

```bash
./a
```

- Important:  Please note the following points to run the program

1. Input file exactly named like this "input.txt"
2. The format of the input file is the proper one and is in the same directory as the binary
3. In this repository we include a file example so you can test it.




## 🚀 Explanation
- Read file
  
First of all, we need to read the input.txt file. We do this using the Reader.cpp class, which will open the file using the provided path and process the first line to determine the number of cases to analyze. This value represents the number of automata and the number of times the following structure will be repeated.

The first line will indicate the number of cases the automaton presents, followed by another line showing the alphabet it can process. Next, there will be a list of final states, and finally, the transition function will be processed using this structure. Each transition will be stored as a triplet in the format (starting state, processed character, destination state), allowing us to analyze a table with n characters and m states.

- Algorithm

Within the DFA class, the algorithm is implemented in the findEquivalentStates method. It begins with step number one of the algorithm, which states that all possible pairs of automaton states should be created, regardless of order. This is implemented using a vector of pairs of strings.

Taking advantage of the fact that we are creating the pairs within the loop, we will implement step 2, which consists of filtering out the state pairs where exactly one of the components is a final state.

```cpp

vector<pair<string, string>> statePairs;
for (int i = 0; i < states.size(); i++)
{
    for (int j = i + 1; j < states.size(); j++)
    {
        if (find(finals.begin(), finals.end(), states[i]) != finals.end() ^
            find(finals.begin(), finals.end(), states[j]) != finals.end())
        {
            continue;
        }
        statePairs.push_back(make_pair(states[i], states[j]));
    }
}
```

The next step proposed by the algorithm is to start marking state pairs that, when processing a string, lead to a previously marked pair. This process is repeated until no changes occur after an evaluation.

We implement this using a do-while loop, which will run at least once, creating a vector that clones the data from statePairs.

Within this loop, the first step is to assign statePairs the values contained in prevPairs. Then, we enter two nested loops: the first iterates over each pair in prevPairs, and the second processes them with each element of the alphabet using the transition function. This checks whether the resulting pair is present in the vector.

If it is not found, we check two additional conditions: whether the permutation of the pair exists in the vector or whether the pair consists of two identical elements. If neither condition is met, the pair is marked for removal from the set of possible equivalent states at the end of the cycle.


```cpp
vector<pair<string, string>> prevPairs = statePairs;

pair<string, string> pairToDisect;

do
{
    statePairs = prevPairs;
    for (int i = 0; i < prevPairs.size(); i++)
    {

        bool destroy = false;
        for (int j = 0; j < alphabet.size(); j++)
        {
            pairToDisect = make_pair(transitionFunction(prevPairs[i].first, alphabet[j]), transitionFunction(prevPairs[i].second, alphabet[j]));
            if ((find(prevPairs.begin(), prevPairs.end(), pairToDisect) == prevPairs.end()))
            {

                destroy = true;

                if ((find(prevPairs.begin(), prevPairs.end(), make_pair(pairToDisect.second, pairToDisect.first)) != prevPairs.end()))
                {
                    destroy = false;
                }

                if (pairToDisect.first == pairToDisect.second)
                {
                    destroy = false;
                }
            }
        }
        if (destroy)
        {
            prevPairs.erase(prevPairs.begin() + i);
            --i;
        }
    }
} while (prevPairs != statePairs);

```
And finally, we assign the statePairs vector to the equivalentStates attribute of the DFA.

