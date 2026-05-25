SRC         =   src/main.cpp \
				src/Guesser.cpp

CXX         =   g++
OBJDIR      =   .obj
OBJ         =   $(patsubst %.cpp, $(OBJDIR)/%.o, $(SRC))

NAME        =   game
CXXFLAGS    +=  -Wall -Wextra -Werror -iquote include/ -g
LFLAGS      =   -lpthread
TEST_FLAGS  =   -lgtest -lgtest_main

$(OBJDIR)/%.o: %.cpp
	mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

all:    $(NAME)

$(NAME):    $(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(LFLAGS)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME) plazza_tests

re: fclean all

.PHONY: all clean fclean re tests_run