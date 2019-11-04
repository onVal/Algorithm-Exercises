all: out/try_union_find

out/try_union_find: structures/try_union_find.c lib/out/union_find.o lib/out/dictionary.o
	mkdir -p out/
	gcc $^ -I include/ -o $@ -g

out/try_dict: structures/try_dict.c lib/out/dictionary.o
	mkdir -p out/
	gcc $^ -I include/ -o $@ -g

out/try_heap: structures/try_heap.c lib/out/heap.o lib/out/utils.o
	mkdir -p out/ 
	gcc $^ -I include/ -o $@ -g

out/ladder_snake: other/ladder_snake_impl.c lib/out/heap.o lib/out/llqueue.o lib/out/linked_list.o lib/out/utils.o
	mkdir -p out/
	gcc $^ -I include/ -o $@ -g

.PHONY: ladder_snake_exe
ladder_snake_exe:
	./out/ladder_snake < ./input_files/ladder_snake_input

out/scritto_12luglio: other/scritto_12luglio.c lib/out/utils.o
	mkdir -p out/
	gcc $^ -I include/ -o $@ -g

out/2_3_tree: structures/try_2_3_tree.c lib/out/2_3_tree.o
	mkdir -p out/
	gcc $^ -I include/ -o $@ -g

out/avl_tree: structures/avl_tree.c lib/out/binary_tree.o lib/out/llqueue.o lib/out/llstack.o lib/out/linked_list.o
	mkdir -p out/
	gcc $^ -I include/ -o $@ -g

out/binsearch_tree: structures/binsearch_tree.c lib/out/binary_tree.o lib/out/llqueue.o lib/out/llstack.o lib/out/linked_list.o
	mkdir -p out/
	gcc $^ -I include/ -o $@ -g

out/shunting_yard: other/shunting_yard.c lib/out/llqueue.o lib/out/llstack.o lib/out/linked_list.o
	mkdir -p out/
	gcc $^ -I include/ -o $@ -g

out/trees: structures/trees.c lib/out/binary_tree.o lib/out/llqueue.o lib/out/llstack.o lib/out/linked_list.o
	mkdir -p out/
	gcc $^ -I include/ -o $@ -g

out/integersort: sorting/integer_sorting_alg.c lib/out/utils.o lib/out/sorting.o
	mkdir -p out/
	gcc $^ -I include/ -o $@ -g

out/trysorting: sorting/trysorting.c lib/out/utils.o lib/out/sorting.o
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
