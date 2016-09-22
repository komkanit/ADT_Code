.PHONY: run
run:
	@g++ $(ARGS)
	@echo "Compiling $(ARGS) complete."
	@./a.out
	@rm ./a.out
