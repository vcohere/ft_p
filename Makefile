all:
	$(MAKE) -C client
	$(MAKE) -C serveur

clean:
	$(MAKE) clean -C client
	$(MAKE) clean -C serveur

fclean:
	$(MAKE) fclean -C client
	$(MAKE) fclean -C serveur

re:
	$(MAKE) re -C client
	$(MAKE) re -C serveur