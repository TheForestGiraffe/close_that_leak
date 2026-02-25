clear
cc -Wall -Wextra -Werror -g main.c app.c item.c && \
valgrind \
--leak-check=full \
--show-leak-kinds=all \
--track-origins=yes \
--track-fds=yes \
./a.out