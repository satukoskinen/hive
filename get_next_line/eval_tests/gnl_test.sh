make -C libft fclean && make -C libft && make -C libft clean
gcc -g -I libft/includes -o get_next_line.o -c get_next_line.c
gcc -g -Wall -Wextra -Werror -I libft/includes -o main.o -c eval_tests/main_test.c
gcc -g -o test_gnl main.o get_next_line.o -I libft/includes -L libft/ -lft
rm main.o get_next_line.o
#echo "--- test: ./test_gnl bible.txt ---"
#./test_gnl eval_tests/bible.txt > test_output
#diff test_output eval_tests/bible.txt > diff_output
#if [ -s diff_output ]
#then
#	echo "diff test_output bible.txt"
#	cat diff_output
#else
#	echo "diff test_output bible.txt\tOK"
#fi
