OBJ := minishell
OBJS += Main.c
OBJS += Termianl.c
OBJS += Command.c
OBJS += Log.c

$(OBJ):$(OBJS)
	gcc $^ -o $@

.PHONY
clean:
	rm $(OBJ)