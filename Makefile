vector_operations.o: vector_operations.c vector_operations.h structures.h
	gcc -c vector_operations.c

ray_tracer.o: ray_tracer.c
	gcc -c ray_tracer.c

utils.o: utils.c utils.h
	gcc -c utils.c

ray_tracer: ray_tracer.o vector_operations.o utils.o
	gcc vector_operations.o ray_tracer.o utils.o -o ray_tracer -lm
