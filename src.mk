
# -------------------------------    source    ------------------------------- #

DIR_MANDATORY	= mandatory/
MANDATORY_SRC	= ft_read ft_strcmp ft_strcpy ft_strdup ft_strlen ft_write
MANDATORY_SRCS	= $(addprefix $(DIR_MANDATORY), $(MANDATORY_SRC))

DIR_BONUS	= bonus/
BONUS_SRC	= ft_atoi_base_bonus ft_list_push_front_bonus ft_list_remove_if_bonus ft_list_size_bonus ft_list_sort_bonus
BONUS_SRCS	= $(addprefix $(DIR_BONUS), $(BONUS_SRC))

SRCS	= $(MANDATORY_SRCS) $(BONUS_SRCS)

TEST_MAIN		= test_main
TEST_MAIN_BONUS	= test_main_bonus