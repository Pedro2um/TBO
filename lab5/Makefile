default:
	clear
script:
	make compile
	bash s.sh
	clear
	cat diff.txt
compile:
	gcc -o a *.c
	g++ -o v *.cpp
small:
	make compile
	echo -e "Meu =\n"
	./a < int
	echo -e "Validator =\n"
	./v < int