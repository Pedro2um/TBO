gcc -o a *.c
./v < ./input/nearly_sorted/100000.txt > c
./a < ./input/nearly_sorted/100000.txt > p
diff c p > diff.txt
