paint.out: main.o canvas.o command.o draw.o inputValidation.o resize.o
    gcc -g -Wall -Werror -o paint.out: main.o canvas.o command.o draw.o inputValidation.o resize.o
main.o: main.c canvas.h command.h draw.h inputValidation.h
    gcc -g -Wall -Werror -c main.c
canvas.o: canvas.c canvas.h
    gcc -g -Wall -Werror -c canvas.c
inputValidation.o: inputValidation.c inputValidation.h
    gcc -g -Wall -Werror -c inputValidation.c
command.o: command.c command.h inputValidation.h canvas.h
    gcc -g -Wall -Werror -c command.c
draw.o: draw.c draw.h
    gcc -g -Wall -Werror -c draw.c
resize.o: resize.c resize.h
    gcc -g -Wall -Werror -c draw.c
clean:
    rm -fr *.o *.out
