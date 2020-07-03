make -C libft/ fclean && make -C libft/ && make -C libft clean
clang -I libft/includes -o get_next_line.o -c get_next_line_new.c
clang -Wall -Wextra -Werror -I libft/includes -o main.o -c eval_tests/main_test.c
clang -o test_gnl main.o get_next_line.o -I libft/includes -L libft/ -lft
rm main.o get_next_line.o