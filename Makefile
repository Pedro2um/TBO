default:
	clear
script:
	bash s.sh
compile:
	gcc -o a *.c
small:
	make compile
	./v < int > c
	./a < int > p
	diff c p
