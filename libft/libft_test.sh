norminette -R CheckForbiddenSourceHeader #| grep -E '^(Error|Warning)'
make clean && make && make fclean && make && make clean
gcc -Wall -Wextra -Werror -L. -lft p1_tests/*.c -o test_part1
./test_part1
#gcc -Wall -Wextra -Werror -L. -lft p2_tests/*.c -o test_part2
#./test_part2

#for test in p1_tests/*.c
#do
#	echo "Testing ${test}:"
#	gcc -Wall -Wextra -Werror ${test} -L. -lft -o user_exe
#   diff test_exe user_exe | cat -e
#done