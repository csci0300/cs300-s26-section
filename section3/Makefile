CC = gcc
FLAGS = -fsanitize=address -Wno-unused-variable -Wno-unused-but-set-variable


all: group_1 group_2 group_3 part_2 bonus


group_1: group_1.c
	$(CC) $(FLAGS) $^ -o $@ -lm


group_2: group_2.c
	$(CC) $(FLAGS) $^ -o $@ -lm


group_3: group_3.c
	$(CC) $(FLAGS) $^ -o $@ -lm


part_2: part_2.c
	$(CC) $(FLAGS) $^ -o $@ -lm


bonus: bonus.c
	$(CC) $(FLAGS) $^ -o $@ -lm


clean:
	rm -f group_1 group_2 group_3 part_2 bonus


.PHONY: clean
