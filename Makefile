KthPermutationSequence: KthPermutationSequence.o
	g++ -g -o KthPermutationSequence.exe KthPermutationSequence.o -pthread    

KthPermutationSequence.o: KthPermutationSequence/KthPermutationSequence.cpp
	g++ -g  -c -pthread KthPermutationSequence/KthPermutationSequence.cpp
