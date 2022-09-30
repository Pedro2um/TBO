compile:
	gcc -o exec *.c -lm
run:
	./exec
tests:
	./exec < in/nearly_sorted/1Knearly_sorted.txt > results/bubble/nearly/1kout
	./exec < in/nearly_sorted/10Knearly_sorted.txt > results/bubble/nearly/10kout
	./exec < in/nearly_sorted/100Knearly_sorted.txt > results/bubble/nearly/100kout
	./exec < in/reverse_sorted/1Kreverse_sorted.txt > results/bubble/reverse/1kout
	./exec < in/reverse_sorted/10Kreverse_sorted.txt > results/bubble/reverse/10kout
	./exec < in/reverse_sorted/100Kreverse_sorted.txt > results/bubble/reverse/100kout
	./exec < in/sorted/1Ksorted.txt > results/bubble/sorted/1kout
	./exec < in/sorted/10Ksorted.txt > results/bubble/sorted/10kout
	./exec < in/sorted/100Ksorted.txt > results/bubble/sorted/100kout
	./exec < in/unif_rand/1Kunif_rand.txt > results/bubble/unif_rand/1kout
	./exec < in/unif_rand/10Kunif_rand.txt > results/bubble/unif_rand/10kout
	./exec < in/unif_rand/100Kunif_rand.txt > results/bubble/unif_rand/100kout
valgrind:
	valgrind ./exec
time:
	time ./exec
clean:
	rm exec