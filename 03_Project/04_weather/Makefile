OBJ := wea
OBJS += Main.c
OBJS += Function.c
OBJS += cJSON.c

$(OBJ):$(OBJS)
	gcc $^ -o $@

.PHONY:
clean:
	rm $(OBJ)