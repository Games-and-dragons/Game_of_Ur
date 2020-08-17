NAME = Ur

all:

clean:
	rm -f $(OBJS)

fclean: clean
	rm -rf $(NAME)

push: clean
	git add .
	git commit -m "$(MSG)"
	git push origin master

re: fclean all
