
# -------------------------------     HEAD     ------------------------------- #
# -------------------------------   preamble   ------------------------------- #
NAME		= libasm
NAME_LIB	= $(addsuffix .a, $(NAME))
DIR_BUILD	= .build/


ASM_GDBF	= -g -F dwarf
ASM_F		= -f elf64 
ASM			= nasm $(ASM_F) $(ASM_GDBF)

RM_GDBF		= -rf
RM			= rm $(RM_GDBF)

AR_GDBF		= -crs
AR			= ar $(AR_GDBF)

MKDIR		= mkdir -p $(shell dirname $@)
ECHO		= echo

GCC_GDBF	= -g3
GCC			= gcc $(GCC_GDBF)

# -------------------------------    source    ------------------------------- #
include src.mk

SRCS	= $(MANDATORY_SRCS)

# -------------------------------    bonus    ------------------------------- #

ifdef BONUS
	SRCS += $(BONUS_SRCS)
endif

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
$(NAME)	: $(NAME_LIB)

$(NAME_LIB) : $(OBJ)
	@$(MSG_OBJECTS)
	$(AR) $(NAME_LIB) $(OBJ)
	@$(MSG_RULE)


# -------------------------------    object    ------------------------------- #
$(DIR_BUILD)%.o : $(DIR_SRC)%.s
	@$(MKDIR)
	$(ASM) $< -o $@

# -------------------------------    clean    ------------------------------- #
.PHONY	: clean
clean	:
	@$(RM) $(DIR_BUILD)
	@$(RM) $(basename $(TEST_MAIN))
	@$(MSG_RULE)

# -------------------------------    fclean    ------------------------------- #
.PHONY	: fclean
fclean	: clean
	@$(RM) $(NAME_LIB)
	@$(MSG_RULE)

# -------------------------------      re      ------------------------------- #
.PHONY	: re
re		: fclean all
	@$(MSG_RULE)

# -------------------------------    bonus    ------------------------------- #
.PHONY	: bonus
bonus	:
	@$(MAKE) --no-print-directory BONUS=1
	@$(MSG_RULE)

# -------------------------------     test     ------------------------------- #
.PHONY	: test
test	: $(NAME)
	$(GCC) $(TEST_MAIN) $(NAME_LIB) -o $(basename $(TEST_MAIN))
	@$(MSG_RULE)

# -------------------------------     test     ------------------------------- #
.PHONY		: testbonus
testbonus	: $(NAME)
	$(GCC) $(TEST_MAIN_BONUS) $(NAME_LIB) -o $(basename $(TEST_MAIN_BONUS))
	@$(MSG_RULE)
