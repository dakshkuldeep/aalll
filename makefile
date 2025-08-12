all: main array_qs

main: main.c aalll.c
	gcc -o main main.c aalll.c

array_qs: miscellaneous/array_qs.c
	gcc -o arqs miscellaneous/array_qs.c

clean:
	rm -f main array_qs arqs
