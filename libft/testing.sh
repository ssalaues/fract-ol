gcc -c *.c -Wextra -Werror -Wall
ar rc libft.a *.o
mv libft.a ~/Downloads/libft-testing-tools-master/alevier_files/assets
rm *.o
