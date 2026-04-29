CC = g++
CSRC = main.c log.cpp

run: $(CSRC)
	@$(CC) $(CFLAGS) $(CSRC)
	@./a.out 


clean:
	rm -f run *.o *.out *.ans

.PHONY: run clean