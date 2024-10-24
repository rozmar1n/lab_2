CC = gcc
СFLAGS = -Wshadow -Winit-self -Wredundant-decls -Wcast-align -Wundef -Wfloat-equal -Winline -Wunreachable-code -Wmissing-declarations -Wmissing-include-dirs -Wswitch-enum -Wswitch-default -Weffc++ -Wmain -Wextra -Wall -g -pipe -fexceptions -Wcast-qual -Wconversion -Wctor-dtor-privacy -Wempty-body -Wformat-security -Wformat=2 -Wignored-qualifiers -Wlogical-op -Wno-missing-field-initializers -Wnon-virtual-dtor -Woverloaded-virtual -Wpointer-arith -Wsign-promo -Wstack-usage=8192 -Wstrict-aliasing -Wstrict-null-sentinel -Wtype-limits -Wwrite-strings -Werror=vla -D_DEBUG -D_EJUDGE_CLIENT_SIDE
all: hello

hello: main.o dev_exp_linear.o func1.o linear_equation.o model.o noise.o nonlinear_equation.o precision_analysis.o
	$(CC) main.o dev_exp_linear.o func1.o linear_equation.o model.o noise.o nonlinear_equation.o precision_analysis.o -o lab_2 -lm

%.o: %.c
	$(CC) -c $(CFLAFS) $< 

clean:./
	rm -rf *.o