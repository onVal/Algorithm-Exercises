all: out/trees

out/trees: structures/trees.c lib/out/llqueue.o lib/out/llstack.o lib/out/linked_list.o
	mkdir -p out/
	gcc $^ -I include/ -o $@ -g

out/bubblesort: sorting/bubblesort.c lib/out/utils.o
	mkdir -p out/
	gcc $^ -I include/ -o $@ -g

out/stack_array: structures/stack_array.c lib/out/utils.o lib/out/array_stack.o
	mkdir -p out/
	gcc $^ -I include/ -o $@ -g

out/queue_linkedlist: structures/queue_linkedlist.c lib/out/utils.o lib/out/llqueue.o lib/out/linked_list.o
	mkdir -p out/
	gcc $^ -I include/ -o $@ -g

out/stack_linkedlist: structures/stack_linkedlist.c lib/out/utils.o lib/out/llstack.o lib/out/linked_list.o
	mkdir -p out/
	gcc $^ -I include/ -o $@ -g

lib/out/%.o: lib/%.c
	mkdir -p lib/out
	gcc -c $< -I include/ -o $@ -g

.PHONY: clean
clean:
	 -rm -r out/ lib/out
