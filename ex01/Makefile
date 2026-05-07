NAME        = bureaucrat_forms
CXX         = c++
CXXFLAGS    = -Wall -Wextra -Werror -std=c++98 -MMD -MP

# Añadimos Form.cpp a la lista
SRCS        = main.cpp Bureaucrat.cpp Form.cpp
OBJS        = $(SRCS:.cpp=.o)
DEPS        = $(SRCS:.cpp=.d)

# --- Config Bar ---
TOTAL_FILES := $(words $(SRCS))
CURR_FILE   := 0

# Color and Style
G = \033[0;32m
R = \033[0;31m
Y = \033[0;33m
B = \033[0;34m
RESET = \033[0m

all: $(NAME)

$(NAME): $(OBJS) Makefile
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "\n$(G)[✔] $(NAME) is ready to rock!$(RESET)"

%.o: %.cpp Makefile
	@$(eval CURR_FILE=$(shell echo $$(($(CURR_FILE)+1))))
	@printf "$(Y)[%2d/%2d] $(B)Compiling: $(RESET)%-20s $(G)" $(CURR_FILE) $(TOTAL_FILES) $<
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@printf "✔$(RESET)\n"

-include $(DEPS)

clean:
	@rm -f $(OBJS) $(DEPS)
	@echo "$(R)[-] Objects and dependencies cleaned.$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(R)[-] $(NAME) deleted.$(RESET)"

re: fclean all

.PHONY: all clean fclean re