gcc -o a *.c
./v < ./in/nearly_sorted/100000.txt > c
./a < ./in/nearly_sorted/100000.txt > p
diff c p > diff.txt
