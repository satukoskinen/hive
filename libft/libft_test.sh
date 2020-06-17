norminette -R CheckForbiddenSourceHeader | grep -E '^(Error|Warning)'
#make clean && make && make fclean && make && make clean
for test in p1_tests/*.c
do
	echo "Testing ${test}:"
	gcc -Wall -Wextra -Werror ${test} -L. -lft -o user_exe
    diff test_exe user_exe | cat -e
done