
# -------------------------------    source    ------------------------------- #

DIR_MANDATORY	= mandatory/
MANDATORY_SRC	= ft_read ft_strcmp ft_strcpy ft_strdup ft_strlen ft_write
MANDATORY_SRCS	= $(addprefix $(DIR_MANDATORY), $(MANDATORY_SRC))

DIR_BONUS	= bonus/
BONUS_SRC	= ft_atoi_base ft_list_push_front ft_list_remove_if ft_list_size ft_list_sort
BONUS_SRCS	= $(addprefix $(DIR_BONUS), $(BONUS_SRC))

SRCS	= $(MANDATORY_SRCS) $(BONUS_SRCS)

TEST_MAIN	= test_main.c