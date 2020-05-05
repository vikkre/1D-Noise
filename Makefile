EXEC = run
CPP_FILES = main.cpp noise.cpp
H_FILES = noise.h

LIB_FLAGS = 
CXX_FLAGS = -std=c++17 -Wall -Wextra

OBJ_FILES = $(CPP_FILES:%.cpp=%.o)

all: $(EXEC)

$(EXEC): $(OBJ_FILES) $(H_FILES)
	$(CXX) $^ -o $@ $(LIB_FLAGS)

%.o: %.cpp
	$(CXX) -c $< -o $@ $(CXX_FLAGS)

clean:
	$(RM) $(EXEC) $(OBJ_FILES)
	