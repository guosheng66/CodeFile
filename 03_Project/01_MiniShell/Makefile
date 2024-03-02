OBJ := minishell
OBJS += Main.c
OBJS += Terminal.c
OBJS += Log.c
OBJS += Command.c

$(OBJ):$(OBJS)
	gcc $^ -o $@

.PHONY:
clean:
	rm $(OBJ)