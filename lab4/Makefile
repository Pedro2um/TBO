compile:
	gcc -w -o exec *.c -lm
	
run:
	./exec
tests:
	./exec 100000  	< ./in/nearly_sorted/100000.txt > ./results/merge4/nearly/100kout
	./exec 1000000 	< ./in/nearly_sorted/1000000.txt > ./results/merge4/nearly/1Mout

	./exec 100000	< ./in/reverse_sorted/100000.txt > ./results/merge4/reverse/100kout
	./exec 1000000	< ./in/reverse_sorted/1000000.txt > ./results/merge4/reverse/1Mout

	./exec 100000	< ./in/sorted/100000.txt > ./results/merge4/sorted/100kout
	./exec 1000000	< ./in/sorted/1000000.txt > ./results/merge4/sorted/1Mout

	./exec 100000	< ./in/unif_rand/100000.txt > ./results/merge4/unif_rand/100kout
	./exec 1000000	< ./in/unif_rand/1000000.txt > ./results/merge4/unif_rand/1Mout
	
valgrind:
	valgrind ./exec
time:
	time ./exec
clean:
	rm exec