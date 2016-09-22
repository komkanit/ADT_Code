.PHONY: run
run:
	@g++ $(TARGET)
	@echo "Compiling $(TARGET) complete."
	@./a.out
	@rm ./a.out
