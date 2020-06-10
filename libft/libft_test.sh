#norminette -R CheckForbiddenSourceHeader | grep -E '^(Error|Warning)'
#make clean && make && make fclean && make && make clean
for test in p1_tests
do
    gcc -Wall -Wextra -Werror p1_tests/${test} -L. -lft
    ./a.out
done