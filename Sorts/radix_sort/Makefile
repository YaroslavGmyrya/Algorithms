GXX = g++
CXXFLAGS = -std=c++20 -g
INPUT_FILES_CPP = *.cpp
OUTPUT_FILE = radix_sort.out
TEST_FILE = radix_sort_test.txt

.PHONY: all run test clean graph

all:
	@$(GXX) $(CXXFLAGS) $(INPUT_FILES_CPP) -o $(OUTPUT_FILE) && \
	printf "\n ===== Compilation completed successfully ===== \n\n"
run:
	@./$(OUTPUT_FILE)

test:
	@./$(OUTPUT_FILE) > test/$(TEST_FILE)

graph:
	@python3 ../graph.py test/$(TEST_FILE)

clean:
	@rm -rf *.out $(TEST_FILE) && \
	cd test && \
	rm -rf *.txt