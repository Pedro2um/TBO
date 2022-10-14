for((i=1; i <= 7; ++i));do

        ./exec < ./in/nearly_sorted/100000.txt > ./results/merge$i/nearly/100kout
	./exec < ./in/nearly_sorted/1000000.txt > ./results/merge$i/nearly/1Mout
	
	./exec < ./in/reverse_sorted/100000.txt > ./results/merge$i/reverse/100kout
	./exec < ./in/reverse_sorted/1000000.txt > ./results/merge$i/reverse/1Mout
	
	./exec < ./in/sorted/100000.txt > ./results/merge$i/sorted/100kout
	./exec < ./in/sorted/1000000.txt > ./results/merge$i/sorted/1Mout
	
	./exec < ./in/unif_rand/100000.txt > ./results/merge$i/unif_rand/100kout
	./exec < ./in/unif_rand/1000000.txt > ./results/merge$i/unif_rand/1Mout
done