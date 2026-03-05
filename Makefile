
# -------------------------------     HEAD     ------------------------------- #
# -------------------------------   preamble   ------------------------------- #
NAME		= libasm
DIR_BUILD	= .build/

ASM			= nasm -f elf64
RM			= rm -rf
AR			= ar -crs
MKDIR		= mkdir -p $(shell dirname $@)
ECHO		= echo

# -------------------------------    source    ------------------------------- #
include src.mk

# -------------------------------    colors    ------------------------------- #
COLOR_GREEN	= \033[0;32m
COLOR_WHITE	= \033[0m

# -------------------------------   message   ------------------------------- #
MSG_OK		= $(COLOR_GREEN)[OK]$(COLOR_WHITE)
MSG_RULE	= $(ECHO) "$(MSG_OK) $(NAME) => Rule: $@"
MSG_OBJECT	= $(ECHO) "$(basename $(notdir $@))"
MSG_OBJECTS	= $(ECHO) "$(MSG_OK) compilation object"

# ----------------------------------  obj  ---------------------------------- #
OBJ		= $(addprefix $(DIR_BUILD), $(addsuffix .o, $(SRCS)))

# -------------------------------    RULES    ------------------------------- #
# -------------------------------     all     ------------------------------- #
.DEFAULT_GOAL	:= all
.PHONY	: all
all		: $(NAME)

# -------------------------------     ASM     ------------------------------- #
$(NAME)	: $(OBJ)
	@$(MSG_OBJECTS)
	$(AR) $(addsuffix .a, $@) $(OBJ)
	@$(MSG_RULE)

# # -------------------------------    object    ------------------------------- #
$(DIR_BUILD)%.o : $(DIR_SRC)%.s
	@$(MKDIR)
	$(ASM) $< -o $@

# -------------------------------    clean    ------------------------------- #
.PHONY	: clean
clean	:
	@$(RM) $(DIR_BUILD)
	@$(MSG_RULE)

# -------------------------------    fclean    ------------------------------- #
.PHONY	: fclean
fclean	: clean
	@$(RM) $(NAME)
	@$(MSG_RULE)

# -------------------------------      re      ------------------------------- #
.PHONY	: re
re		: fclean all
	@$(MSG_RULE)