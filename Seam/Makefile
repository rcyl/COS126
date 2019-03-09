SRC := $(wildcard *.cpp)
OBJ := $(patsubst %.cpp, %.o, $(SRC))
INC := -Iinclude
CC := g++
LD_FLAGS := 
CC_FLAGS := -Wall -Werror -g -std=c++11
OUT = seam

$(OUT): $(OBJ)
	$(CC) $(LD_FLAGS) -o $@ $^
	@echo All done

%.o: %.cpp
	$(CC) $(INC) $(CC_FLAGS) -c -o $@ $< 

clean:
	rm -rf bin/* $(OUT)
	@echo Clean done
	
shout:
	@echo $(SRC)
	@echo $(OBJ)
